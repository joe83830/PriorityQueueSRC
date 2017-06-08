// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// The only private member variables this class is allowed to have inside it
// are a pointer to your internal array of elements, and integers for the array's capacity and the priority queue's size.

#include "ArrayPriorityQueue.h"
#include "iostream"

ArrayPriorityQueue::ArrayPriorityQueue() {  //What's the use of this?

    count = 0;
    Apq = NULL;

}

ArrayPriorityQueue::~ArrayPriorityQueue() {  // How do I use this?

    delete [] Apq;

}

void ArrayPriorityQueue::changePriority(string value, int newPriority) {

    for (int i = 0; i < count; i++) {

        if (Apq[i].value == value && Apq[i].priority > newPriority) {

            Apq[i].priority = newPriority;
            break;
        }

        if (i == count - 1) {

            throw (string("Nope"));
        }
    }

}

void ArrayPriorityQueue::clear() {
    delete [] Apq;

}

string ArrayPriorityQueue::dequeue() {         // Throw exn?

    if (count == 0) {

        throw 20;
    }

    PQEntry temp = Apq[0];
    int firsthalf;

    for (int i = 1; i < count; i++) {

        if (Apq[i].priority < temp.priority) {

            temp = Apq[i];
            firsthalf = i;

        } else if (Apq[i].priority == temp.priority) {

            if (Apq[i].value < temp.value) {

                temp = Apq[i];
                firsthalf = i;
            }
        } else {

            firsthalf = 0;
        }
    }

    PQEntry *tempArrayPtr1 = Apq;
    Apq = new PQEntry[count - 1];

    for (int j = 0; j < firsthalf; j++) {

        Apq[j] = tempArrayPtr1[j];
    }

    for (int k = firsthalf + 1; k < count ; k++) {

        Apq[k - 1] = tempArrayPtr1[k];
    }

    count--;
    delete[] tempArrayPtr1;
    return temp.value;
}

void ArrayPriorityQueue::enqueue(string value, int priority) {

    PQEntry pqe;
    pqe.value = value;
    pqe.priority = priority;

    if (Apq == NULL) {

        Apq = new PQEntry[1];
        Apq[0] = pqe;
        count ++;
    } else {

        PQEntry *temp = Apq;
        Apq = new PQEntry[count +1];

        for (int i = 0; i < count; i++) {

            Apq[i] = temp[i];
        }
        Apq[count] = pqe;
        count ++;
        delete[] temp;
    }

}



bool ArrayPriorityQueue::isEmpty() const {

    if (Apq == NULL) {
        return true;

    } else {
        return false;
    }
}

string ArrayPriorityQueue::peek() const {   // Throw exn?

    PQEntry temp = Apq[0];

    for (int i = 1; i < count; i++) {

        if (Apq[i].priority < temp.priority) {

            temp = Apq[i];

        } else if (Apq[i].priority == temp.priority) {

            if (Apq[i].value < temp.value) {

                temp = Apq[i];
            }
        }
    }
    return temp.value;

}
int ArrayPriorityQueue::peekPriority() const {   // Throw exn?

    PQEntry temp = Apq[0];

    for (int i = 1; i < count; i++) {

        if (Apq[i].priority < temp.priority) {

            temp = Apq[i];

        } else if (Apq[i].priority == temp.priority) {

            if (Apq[i].value < temp.value) {

                temp = Apq[i];
            }
        }
    }

    return temp.priority;
}

int ArrayPriorityQueue::size() const {

    return count;
}

ostream& operator<<(ostream& out, const ArrayPriorityQueue& queue) {

    for (int i = 0; i < queue.count; i ++){

        if ((i == queue.count - 1) && queue.count == 1){
            out << "{" << queue.Apq[i] << "}";
        } else if ((i == 0) && queue.count == 1) {
            out << "{" << queue.Apq[i] << "}";
        } else if (i == queue.count - 1) {
            out << queue.Apq[i] << "}";
        } else if (i == 0) {
            out << "{" << queue.Apq[i] << ",";
        } else {
            out << queue.Apq[i] << ",";
        }
    }
    return out;
}
