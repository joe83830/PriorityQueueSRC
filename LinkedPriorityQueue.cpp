// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "LinkedPriorityQueue.h"

LinkedPriorityQueue::LinkedPriorityQueue() {
    listHead = NULL;
    count = 0;

}

LinkedPriorityQueue::~LinkedPriorityQueue() {

    ListNode *prev = NULL;

    for (ListNode *cur = listHead; cur != NULL; cur = cur->next) {

        if (prev != NULL) {

            delete prev;
        }
        prev = cur;
    }

}

void LinkedPriorityQueue::changePriority(string value, int newPriority) {

    ListNode *toBeSwapped = new ListNode;
    toBeSwapped->value = value;
    toBeSwapped->priority = newPriority;
    ListNode *prev = new ListNode;
    prev = NULL;

    for (ListNode *cur = listHead; cur != NULL; cur = cur ->next) {

        if (cur->value == value) {

            toBeSwapped->next = cur->next;
            prev->next = toBeSwapped;
        }
        prev = cur;
    }

}

void LinkedPriorityQueue::clear() {

    ListNode *prev = new ListNode;
    prev = NULL;

    for (ListNode *cur = listHead; cur != NULL; cur = cur->next) {

        if (prev != NULL) {

            listHead = NULL;
            delete prev;
        }
        prev = cur;
    }

}

string LinkedPriorityQueue::dequeue() {

    ListNode *temp = listHead;
    string valueOfListHead = listHead->value;
    listHead = listHead->next;
    delete temp;

    return valueOfListHead;
}

void LinkedPriorityQueue::enqueue(string value, int priority) {

    ListNode *newOne = new ListNode;
    newOne->value = value;
    newOne->priority = priority;

    ListNode *cur, *prev = NULL; // first node has no previous
    for (cur = listHead; cur != NULL; cur = cur->next) {
        //cout << newOne->name << cur->name;
        if (cur->priority == newOne->priority) {

            if (cur->value > newOne->value) {
                break;
            }
        } else if (cur->priority > newOne->priority) {

            break;
        }
        prev = cur;
    }

    newOne->next = cur;
    count++;

    if (prev != NULL) {
        prev->next = newOne;
    } else {
        listHead = newOne;
    }

}


bool LinkedPriorityQueue::isEmpty() const {
    if (listHead == NULL) {

        return true;
    } else {

        return false;
    }
}

string LinkedPriorityQueue::peek() const {

    return listHead->value;
}

int LinkedPriorityQueue::peekPriority() const {

    return listHead->priority;
}

int LinkedPriorityQueue::size() const {

    return count;   // remove this
}

ostream& operator<<(ostream& out, const LinkedPriorityQueue& queue) {

    ListNode *prev = NULL;
    ListNode *adv;

    for (ListNode *cur = queue.listHead; cur != NULL; cur = cur->next) {

        adv = cur->next;

        if ((prev == NULL) && (adv == NULL)){
            out << "{" << cur->value << "," << cur->priority << "}";
        } else if (adv == NULL) {
            out << cur->value << "," << cur->priority << "}";
        } else if (prev == NULL) {
            out << "{" << cur->value << "," << cur->priority << ",";
        } else {
            out << cur->value << "," << cur->priority << ",";
        }

        prev = cur;
    }
    return out;
}
