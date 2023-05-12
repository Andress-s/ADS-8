// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>
using namespace std;

Train::Train() {
        first = nullptr;
        countOp = 1;
}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage();
        first->light = light;
        first->next = first;
        first->prev = first;
    } else {
        Cage* newCage = new Cage();
        newCage->light = light;
        newCage->prev = first->prev;
        newCage->next = first;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}
int Train::getLength() {
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
int Train::getOpCount() {
    return countOp;
}
void Train::moveNext() {
    first = first->next;
    countOp++;
}
void Train::movePrev() {
    first = first->prev;
    countOp++;
}
