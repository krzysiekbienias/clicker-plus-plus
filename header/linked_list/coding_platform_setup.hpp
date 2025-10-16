#pragma once
#include <iostream>


class LinkedListCodingPlatform {
public:
    int value;
    LinkedListCodingPlatform* next = nullptr;

    LinkedListCodingPlatform(int value) { this->value = value; }
};

inline void printList(const LinkedListCodingPlatform* head) {
    const LinkedListCodingPlatform* cur = head;
    while (cur) {
        std::cout << cur->value;
        cur = cur->next;
        if (cur) std::cout << " -> ";
    }
    std::cout << '\n';
}