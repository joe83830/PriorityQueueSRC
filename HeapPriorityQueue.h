// This is a .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#ifndef _heappriorityqueue_h
#define _heappriorityqueue_h

#include <iostream>
#include <string>
#include "PQEntry.h"
using namespace std;

/*
 * For documentation of each member, see VectorPriorityQueue.h.
 */
class HeapPriorityQueue {
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();
    void changePriority(string value, int newPriority);
    void clear();
    string dequeue();
    void enqueue(string value, int priority);
    bool isEmpty() const;
    string peek() const;
    int peekPriority() const;
    int size() const;
    friend ostream& operator <<(ostream& out, const HeapPriorityQueue& queue);
    void bubbleUp (PQEntry *Hpq, int countAssist);
    void bubbledown (PQEntry *Hpq, int bubbledownhelper);
    void reorder (PQEntry *Hpq, int reorderAssist);

private:

    PQEntry *Hpq;   // pointer to the array in which we represent the binary heap
    int count;
    int countAssist;
    int bubbledownhelper;
    int reorderAssist;
};

#endif
