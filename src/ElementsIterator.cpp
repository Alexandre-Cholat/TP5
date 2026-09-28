#include <memory>
#include <vector>
#include "subset.hpp"
#include "ElementsIterator.hpp"


ElementsIterator::ElementsIterator(Subset& parent_ref): parent(parent_ref){
    currentElem = 0;

    // find begining index of subset
    while(parent.contains(currentElem) == false){
        currentElem++;
    }
}

ElementsIterator::ElementsIterator(Subset& parent_ref, type_t end): parent(parent_ref){
    // points to end idx of subset
    currentElem = end;
}

void ElementsIterator::operator++(){
    currentElem++;
    while (!parent.contains(currentElem) || currentElem < parent.getSubSize() ) {
            currentElem++;
        }

}


bool ElementsIterator::operator!=(ElementsIterator x){
    // return (currentElem == x.currentElem) && (parent.contains(x.parent));
    return (currentElem != x.currentElem) || (&parent != &x.parent);
}