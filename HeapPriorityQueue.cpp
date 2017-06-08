// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "HeapPriorityQueue.h"

HeapPriorityQueue::HeapPriorityQueue() {
    count = 0;
    Hpq = NULL;

}

HeapPriorityQueue::~HeapPriorityQueue() {
    // TODO: implement

}

void HeapPriorityQueue::changePriority(string value, int newPriority) {
    // TODO: implement

}

void HeapPriorityQueue::clear() {
    // TODO: implement

}

string HeapPriorityQueue::dequeue() {

    PQEntry *temp = new PQEntry[count]; // first one is empty, need one extra space
    temp = Hpq;
    Hpq[1] = temp[count];

    for (int i = 2; i < count; i++) {

        Hpq[i] = temp[i];
    }


    return "";
}

void HeapPriorityQueue::enqueue(string value, int priority) {

    PQEntry pqe;
    pqe.value = value;
    pqe.priority = priority;

    if (Hpq == NULL) {

        Hpq = new PQEntry[2];
        Hpq[1] = pqe;
        count ++;
        cout << "new first element: " << Hpq[count].value <<" priority: " << Hpq[count].priority << " count = " << count << endl;
    } else {

        PQEntry *temp = Hpq;
        Hpq = new PQEntry[count + 2];

        for (int i = 1; i <= count; i++) {

            Hpq[i] = temp[i];
        }
        Hpq[count + 1] = pqe;

        count++;

        cout << "new element: " << Hpq[count].value <<" priority: " << Hpq[count].priority << " count = " << count << endl;

        delete temp;
    }

    countAssist = count;

    bubbleUp(Hpq, countAssist);
    countAssist = 0;

    cout << "Head: " << Hpq[1].value << endl;
}

void HeapPriorityQueue::bubbleUp(PQEntry *Hpq, int countAssist) {

    if (Hpq[countAssist].priority < Hpq[countAssist/2].priority) {
        cout << "I'm in" << endl;
        PQEntry tempBox;
        tempBox.priority = Hpq[countAssist].priority;
        tempBox.value = Hpq[countAssist].value;

        Hpq[countAssist].priority = Hpq[countAssist/2].priority;
        Hpq[countAssist].value = Hpq[countAssist/2].value;

        Hpq[countAssist/2].priority = tempBox.priority;
        Hpq[countAssist/2].value = tempBox.value;

        bubbleUp(Hpq, countAssist/2);
    } else if (Hpq[countAssist].priority == Hpq[countAssist/2].priority) {

        if (Hpq[countAssist].value < Hpq[countAssist/2].value) {

            PQEntry tempBox;
            tempBox.priority = Hpq[countAssist].priority;
            tempBox.value = Hpq[countAssist].value;

            Hpq[countAssist].priority = Hpq[countAssist/2].priority;
            Hpq[countAssist].value = Hpq[countAssist/2].value;

            Hpq[countAssist/2].priority = tempBox.priority;
            Hpq[countAssist/2].value = tempBox.value;

            bubbleUp(Hpq, countAssist/2);
        }
    }
}

bool HeapPriorityQueue::isEmpty() const {
    // TODO: implement
    return false;   // remove this
}

string HeapPriorityQueue::peek() const {

    return Hpq[1].value;
}

int HeapPriorityQueue::peekPriority() const {
    // TODO: implement
    return 0;   // remove this
}

int HeapPriorityQueue::size() const {
    // TODO: implement
    return count;   // remove this
}

ostream& operator<<(ostream& out, const HeapPriorityQueue& queue) {
    // TODO: implement
    return out;
}
