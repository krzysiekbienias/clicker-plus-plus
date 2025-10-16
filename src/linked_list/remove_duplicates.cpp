#include "linked_list/coding_platform_setup.hpp"



// Implement your remove_duplicates logic here.

LinkedListCodingPlatform* removeDuplicatesFromLinkedList(LinkedListCodingPlatform* head) {
    LinkedListCodingPlatform* current=head;
    while (current!=nullptr && current->next!=nullptr) {
        if (current->value==current->next->value) {
            LinkedListCodingPlatform* duplicate=current->next;
            current->next=current->next->next;
            delete duplicate;
        }
        else
            current=current->next;
    }
    return head;

}