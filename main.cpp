#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    DoublyLinkedList list = DoublyLinkedList();

    cout << list.getSize() << endl;

    list.append(new ListElement(true, "boh"));

    cout << list.getSize() << endl;

    cout << list.getHead()->getElement()->getIdentifier() << endl;
    cout << list.getHead()->getElement()->isValid() << endl;

    list.append(new ListElement(true, "boh2"));
    list.append(new ListElement(false, "boboboh"));
    list.append(new ListElement(false, "ecciao proprio"));
    list.append(new ListElement(true, "cose"));
    list.append(new ListElement(false, "mah"));
    list.append(new ListElement(true, "boh3"));

    cout << list.getSize() << endl;

    for (int i = 0; i < list.getSize(); i++) {

        cout << "Element " << i << ":" << endl;
        cout << list.get(i)->getElement()->getIdentifier() << endl;
        cout << list.get(i)->getElement()->isValid() << endl;
    }
}
