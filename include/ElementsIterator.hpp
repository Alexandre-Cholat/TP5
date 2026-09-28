#pragma once
#include <memory>
#include <vector>
#include "subset.hpp"


// an iterator is a sort of pointer
// this one points to values of a subset

class ElementsIterator{

    private:
    size_t currentElem;
    Subset& parent;

    ElementsIterator(Subset& parent_ref, type_t end);

    public:
    ElementsIterator(Subset& parent_ref);
    ~ElementsIterator();

    //size_t get_current_idx(){return currentElem};

    friend void operator++();

    //equivalent to get_current_idx
    friend size_t operator*(){return currentElem;};

    friend bool operator!=(ElementsIterator x);

}