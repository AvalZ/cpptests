#include <iostream>

using namespace std;

class ArrayList {

    int size;
    int capacity;
    ListElement* content[];

    public:

    ArrayList() {
        this->size = 0;
        this->capacity = 1;
    }

    int getSize() {
        return this->size;
    }

    void addElement(ListElement *element) {
        if (isAtMaxCapacity()) {
            expandContentTo(this->capacity * 2);
        }
        this->content[this->size] = element;

        this->size++;
    }

    ListElement* getElements() {
        return content;
    }

    ListElement getElement(int i) {
        if (i < this->size) {
            return this->content[i];
        }
        throw invalid_argument("No such element exists in this list");
    }

    // Utilities
    private:

    // Has content reached the maximum capacity?
    bool isAtMaxCapacity() {
       return size >= this->capacity;
    }

    void expandContentTo(int new_size) {
        int old_size = this->capacity;

        ListElement* new_content = new ListElement[new_size];

        // Deep Copy (da implementare da zero,
        // visto che QUALCUNO qui non può usare std.. xD xD )
        for (int i = 0; i < old_size; i++) {
            new_content[i] = this->content[i];
        }

        delete [] content;

        this->capacity *= 2;

        this->content = new_content;

    }

};
