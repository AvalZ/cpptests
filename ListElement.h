#include <iostream>

using namespace std;

class ListElement {

    string identifier;
    bool valid;

    public:

    ListElement() {
        this->valid = false;
        this->identifier = "";
    }

    ListElement(bool valid, string identifier) {
        this->valid = valid;
        this->identifier = identifier;
    }

    ListElement(const ListElement &other) {
        this->valid = other.valid;
        this->identifier = other.identifier;
    }


    virtual ~ListElement() { }

    bool isValid() {
        return this->valid;
    }

    string getIdentifier() {
        return this->identifier;
    }

};
