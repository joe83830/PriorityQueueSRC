// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "HeapPriorityQueue.h"

HeapPriorityQueue::HeapPriorityQueue() {
    count = 0;
    Hpq = NULL;
    bubbledownhelper = 1;
    reorderAssist = 1;

}

HeapPriorityQueue::~HeapPriorityQueue() {
    delete[] Hpq;

}

void HeapPriorityQueue::changePriority(string value, int newPriority) {

    for (int i = 1; i <= count; i++) {

        if (Hpq[i].value == value && Hpq[i].priority > newPriority) {

            Hpq[i].priority = newPriority;
            break;
        }
        reorderAssist++;
    }

    reorder(Hpq, reorderAssist);
    reorderAssist = 1;

}

void HeapPriorityQueue::reorder(PQEntry *Hpq, int reorderAssist) {

    if (Hpq[reorderAssist].priority < Hpq[reorderAssist/2].priority){
        PQEntry temp;
        temp.priority = Hpq[reorderAssist].priority;
        temp.value = Hpq[reorderAssist].value;

        Hpq[reorderAssist].priority = Hpq[reorderAssist/2].priority;
        Hpq[reorderAssist].value = Hpq[reorderAssist/2].value;

        Hpq[reorderAssist/2].priority = temp.priority;
        Hpq[reorderAssist/2].value = temp.value;

        reorder(Hpq, reorderAssist/2);
    }
}

void HeapPriorityQueue::clear() {
    delete[] Hpq;

}

string HeapPriorityQueue::dequeue() {

    PQEntry *temp = Hpq;
    Hpq = new PQEntry[count];
    Hpq[1] = temp[count];

    string toBeReturned = temp[1].value;

    for (int i = 2; i < count; i++) {

        Hpq[i] = temp[i];
    }

    bubbledown(Hpq, bubbledownhelper);
    bubbledownhelper = 1;
    count--;
    return toBeReturned;
}

void HeapPriorityQueue::bubbledown(PQEntry *Hpq, int bubbledownhelper) {

    if ((Hpq[bubbledownhelper].priority > Hpq[(bubbledownhelper * 2 + 1)].priority) && (bubbledownhelper * 2 + 1) <= count) {

        PQEntry tempBox;
        tempBox.priority = Hpq[bubbledownhelper].priority;
        tempBox.value = Hpq[bubbledownhelper].value;

        Hpq[bubbledownhelper].priority = Hpq[(bubbledownhelper * 2 + 1)].priority;
        Hpq[bubbledownhelper].value = Hpq[(bubbledownhelper * 2 + 1)].value;

        Hpq[(bubbledownhelper * 2 + 1)].priority = tempBox.priority;
        Hpq[(bubbledownhelper * 2 + 1)].value = tempBox.value;
        bubbledownhelper = bubbledownhelper * 2 + 1;
        bubbledown(Hpq, bubbledownhelper);
    } else if ((Hpq[bubbledownhelper].priority == Hpq[(bubbledownhelper * 2 + 1)].priority) && (bubbledownhelper * 2 + 1) <= count) {

        if (Hpq[bubbledownhelper].value > Hpq[(bubbledownhelper * 2 + 1)].value) {


            PQEntry tempBox;
            tempBox.priority = Hpq[bubbledownhelper].priority;
            tempBox.value = Hpq[bubbledownhelper].value;

            Hpq[bubbledownhelper].priority = Hpq[(bubbledownhelper * 2 + 1)].priority;
            Hpq[bubbledownhelper].value = Hpq[(bubbledownhelper * 2 + 1)].value;

            Hpq[(bubbledownhelper * 2 + 1)].priority = tempBox.priority;
            Hpq[(bubbledownhelper * 2 + 1)].value = tempBox.value;
            bubbledownhelper = bubbledownhelper * 2 + 1;
            bubbledown(Hpq, bubbledownhelper);
        }
    } else if ((Hpq[bubbledownhelper].priority > Hpq[(bubbledownhelper * 2)].priority) && (bubbledownhelper * 2) <= count) {

        PQEntry tempBox;
        tempBox.priority = Hpq[bubbledownhelper].priority;
        tempBox.value = Hpq[bubbledownhelper].value;

        Hpq[bubbledownhelper].priority = Hpq[(bubbledownhelper * 2)].priority;
        Hpq[bubbledownhelper].value = Hpq[(bubbledownhelper * 2)].value;

        Hpq[(bubbledownhelper * 2)].priority = tempBox.priority;
        Hpq[(bubbledownhelper * 2)].value = tempBox.value;
        bubbledownhelper = bubbledownhelper * 2;
        bubbledown(Hpq, bubbledownhelper);
    } else if ((Hpq[bubbledownhelper].priority == Hpq[(bubbledownhelper * 2)].priority) && (bubbledownhelper * 2) <= count) {

        if (Hpq[bubbledownhelper].value > Hpq[(bubbledownhelper * 2)].value) {

            PQEntry tempBox;
            tempBox.priority = Hpq[bubbledownhelper].priority;
            tempBox.value = Hpq[bubbledownhelper].value;

            Hpq[bubbledownhelper].priority = Hpq[(bubbledownhelper * 2)].priority;
            Hpq[bubbledownhelper].value = Hpq[(bubbledownhelper * 2)].value;

            Hpq[(bubbledownhelper * 2)].priority = tempBox.priority;
            Hpq[(bubbledownhelper * 2)].value = tempBox.value;
            bubbledownhelper = bubbledownhelper * 2;
            bubbledown(Hpq, bubbledownhelper);
        }
    }
}

void HeapPriorityQueue::enqueue(string value, int priority) {

    PQEntry pqe;
    pqe.value = value;
    pqe.priority = priority;

    if (Hpq == NULL) {

        Hpq = new PQEntry[2];
        Hpq[1] = pqe;
        count ++;

    } else {

        PQEntry *temp = Hpq;
        Hpq = new PQEntry[count + 2];

        for (int i = 1; i <= count; i++) {

            Hpq[i] = temp[i];
        }
        Hpq[count + 1] = pqe;

        count++;

        delete temp;
    }

    countAssist = count;

    bubbleUp(Hpq, countAssist);
    countAssist = 0;

}

void HeapPriorityQueue::bubbleUp(PQEntry *Hpq, int countAssist) {

    if (Hpq[countAssist].priority < Hpq[countAssist/2].priority) {

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
    if (count == 0) {
        return true;
    }

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
    for (int i = 1; i <= queue.count; i ++){

        if ((i == queue.count) && queue.count == 1){
            out << "{" << queue.Hpq[i] << "}";
        } else if ((i == 1) && queue.count == 1) {
            out << "{" << queue.Hpq[i] << "}";
        } else if (i == queue.count) {
            out << queue.Hpq[i] << "}";
        } else if (i == 1) {
            out << "{" << queue.Hpq[i] << ",";
        } else {
            out << queue.Hpq[i] << ",";
        }
    }
    return out;
}
