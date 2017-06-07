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
    // TODO: implement

}

void LinkedPriorityQueue::changePriority(string value, int newPriority) {
    // TODO: implement

}

void LinkedPriorityQueue::clear() {
    // TODO: implement

}

string LinkedPriorityQueue::dequeue() {

    return "";
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
    // TODO: implement
    return out;
}
