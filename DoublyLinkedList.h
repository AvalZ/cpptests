#include <iostream>
#include "ListElement.h"

using namespace std;

class Link {
    Link* next;
    Link* prev;
    ListElement* element;


public:
    Link() { }

    Link(Link *prev, ListElement *element) : next(NULL), prev(prev), element(element) { }

    Link(ListElement *element) : element(element) {}
    Link *getNext() const {
        return next;
    }

    void setNext(Link *next) {
        Link::next = next;
    }

    Link *getPrev() const {
        return prev;
    }

    void setPrev(Link *prev) {
        Link::prev = prev;
    }

    ListElement *getElement() const {
        return element;
    }

    void setElement(ListElement *element) {
        Link::element = element;
    }

};
class DoublyLinkedList {
    Link* head;
    Link* tail;

    int size;


public:
    DoublyLinkedList() : head(NULL), tail(NULL), size(0) { }

    Link* getHead() {
        return head;
    }

    void append(ListElement *element) {

        // No element in list

        // NULL    NULL
        //  ^       ^
        //  |       |
        // head    tail
        if (head == NULL || tail == NULL) {

            // We create a new element
            // [ ]    NULL
            //  ^       ^
            //  |       |
            // head    tail
            head = new Link(element);

            // And point both head and tail to it
            // [ ]<-----+
            //  ^       |
            //  |       |
            // head    tail
            tail = head;
        } else if (head != NULL && tail != NULL) {
            // Save tail state
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]
            //  ^                             ^
            //  |                             |
            // head                          tail = temp
            Link *temp = tail;


            // Point tail to a new Link (not attached to current list)
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]        [ ]
            //  ^                             ^          ^
            //  |                             |          |
            // head                          temp       tail
            tail = new Link(temp, element);

            // Attach last Link to list
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]<------->[ ]
            //  ^                             ^           ^
            //  |                             |           |
            // head                          temp        tail
            temp->setNext(tail);
            tail->setPrev(temp);
        }

        // Update size
        size++;
    }

    void remove(int pos) {
        if (pos >= size) throw invalid_argument("Out of list size");

        // Removing first element
        if (pos == 0) {
            // [ ]<-----+
            //  ^       |
            //  |       |
            // head    tail
            if (head == tail) {
                // [ ]     NULL
                //  ^       ^
                //  |       |
                // head    tail
                tail->setPrev(NULL);
            }
            // Head moves forward
            // [ ]<->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]
            //        ^                        ^
            //        |                        |
            //       head                     tail
            head = head->getNext();

            // Remove reference to previous element
            // NULL<->[ ]->[ ]->[ ]->[ ]->[ ]
            //         ^                   ^
            //         |                   |
            //        head                tail
            head->setPrev(NULL);
        }
        // Removing last element
        else if (pos == size - 1) {
            // Get previous element
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]
            //  ^                        ^    ^
            //  |                        |    |
            // head                     prev tail
            Link *prev = DoublyLinkedList::get(pos);

            // Tail moves back
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]
            //  ^                        ^
            //  |                        |
            // head                     tail
            //                          prev
            tail = prev;

            // Remove pointer to last link
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->NULL
            //  ^                        ^
            //  |                        |
            // head                     tail
            prev->setNext(NULL);
        }
        // Removing "random" element
        else {
            // We need prev and next from desired pos
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]->[ ]
            //  ^                        ^    ^    ^              ^
            //  |                        |    |    |              |
            // head                     prev curr next           tail
            Link *curr = DoublyLinkedList::get(pos);
            Link *prev = curr->getPrev();
            Link *next = curr->getNext();

            // Bypass curr
            //                           +---------+
            //                           |         |
            //                           V         V
            // [ ]->[ ]->[ ]->[ ]->[ ]->[ ]  [ ]  [ ]->[ ]->[ ]->[ ]
            //  ^                        ^    ^    ^              ^
            //  |                        |    |    |              |
            // head                     prev curr next           tail
            //
            prev->setNext(next);
            next->setNext(prev);


            // Now curr has no reference to anything else, so it's cut out
            // Better destroy it too
            delete curr;

        }

        // Update size
        size--;
    }

    int getSize() {
        return size;
    }

    Link* get(int pos) {
        if (pos >= size) throw invalid_argument("Out of list size");

        Link* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->getNext();
        }

        return temp;
    }

};
