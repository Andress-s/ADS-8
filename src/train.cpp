// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

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
    int count = 0, final = 0;
    Cage* cur = first;
    if (first->light == false) {
        first->light = true;
    }
    while (true) {
        cur = cur->next;
        ++countOp;
        ++count;
        check(cur, count);
        cur->light = false;
        final = count;
        back(cur, count);
        if (cur->light == false)
            return final;
    }
}

int Train::getOpCount() {
    if (countOp == 0) {
        getOpCount();
    }
    return countOp;
}

void Train::check(Cage* cur, int& count) {
    while (cur->light == false) {
        cur = cur->next;
        --count;
        ++countOp;
    }
}

void Train::back(Cage* cur, int& count) {
    while (count != 0) {
        cur = cur->prev;
        --count;
        countOp++;
    }
}
