// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>
using namespace std;

class Train {
private:
    struct Cage {
        bool light; // состояние лампочки
        Cage* next;
        Cage* prev;
    };
    int countOp; // счетчик шагов (число переходов из вагона в вагон)
    Cage* first; // точка входа в поезд (первый вагон)
public:
    Train() {
        first = nullptr;
        countOp = 0;
    }
    void addCage(bool light) {
        if (first == nullptr) {
            first = new Cage();
            first->light = light;
            first->next = first;
            first->prev = first;
        }
        else {
            Cage* newCage = new Cage();
            newCage->light = light;
            newCage->prev = first->prev;
            newCage->next = first;
            first->prev->next = newCage;
            first->prev = newCage;
        }
    }
    int getLength() {
        if (first == nullptr) {
            return 0;
        }
        int length = 1;
        Cage* current = first->next;
        while (current != first) {
            length++;
            current = current->next;
        }
        return length;
    }
    int getOpCount() {
        return countOp;
    }
    void moveNext() {
        first = first->next;
        countOp++;
    }
    void movePrev() {
        first = first->prev;
        countOp++;
    }
};
