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

    // private constructor for end()
    ElementsIterator(Subset& parent_ref, type_t end);

    friend class Subset;

    public:
    ElementsIterator(Subset& parent_ref);
    ~ElementsIterator()= default;

    //size_t get_current_idx(){return currentElem};

    void operator++();

    //equivalent to get_current_idx
    size_t operator*() const {return currentElem;};

    friend bool operator!=(ElementsIterator x);

};