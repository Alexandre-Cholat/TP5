#include <memory>
#include <vector>
#include "subset.hpp"
#include <bit>
#include "ElementsIterator.hpp"

subset::Subset::Subset(size_t k, size_t n): _sub_size(k), _super_size(n), _representation((1ULL<<n) - 1ULL){

    if (k > n){
        throw std::runtime_error("Error: k > n");
    }

    if(n > 64){
        throw std::runtime_error("Error: n larger than 64");
    }

}

std::ostream& subset::operator<<(std::ostream& os, Subset& s){
    os << '{';

    bool prem = true;
    for(size_t i = 0; i < s._super_size; i++){
        // Test if the i-th bit is set
        if ((s._representation >> i) & 1ULL){
            if (!prem){
                os<< ", ";

            }
            prem = false;
            os << i;
        }


    }

    os << '}';
    return os;
}

// check if an item belongs to a subset
bool subset::Subset::contains(const size_t i) const{
    if(i >= _super_size){
        throw std::runtime_error("Error: i > n");
    }

    return (_representation >> i) & 1ULL;
  
}

// add an item 
void subset::Subset::add(const size_t i){
    if(i > _super_size){
        throw std::runtime_error("Error: i > n");
    }

    // Check if the bit isn't already set, to maintain accurate _sub_size
    if (!((_representation >> i) & 1ULL)) {
        _representation = _representation + (1ULL << i);  // Turn ON bit i
        ++_sub_size;
    }

}

// substract an item from a subset
void subset::Subset::minus(const size_t i){
    if(i > _super_size){
        throw std::runtime_error("Error: i > n");
    }

    // Check if the bit is already set
    if ((_representation >> i) & 1ULL) {
        _representation = _representation & ~(1ULL << i);  // Turn OFF bit i
        --_sub_size;
    }


}

bool subset::Subset::contains(const Subset& other){
    if(_super_size != other._super_size){
        throw std::invalid_argument("Error : can't compare subsets from different supersets");
    }
    // union of this and other = other 
    return (_representation & other._representation) == other._representation;


}
void subset::Subset::add(const Subset& other){
    if(_super_size != other._super_size){
        throw std::invalid_argument("Error : can't compare subsets from different supersets");
    }

    // no need to add
    if (contains(other)){
        return;
    }

    // this OR other
    _representation = _representation | other._representation;

    // Recalculate the subset size
    _sub_size = std::popcount(_representation);



}

void subset::Subset::minus(const Subset& other){
    if(_super_size != other._super_size){
        throw std::invalid_argument("Error : can't compare subsets from different supersets");
    }

    // this & not other
    _representation = _representation & (~other._representation);

    // Recalculate the subset size
    _sub_size = std::popcount(_representation);


}

subset::ElementsIterator subset::Subset::begin(){
    ElementsIterator it = ElementsIterator(*this);
    return it;
}

subset::ElementsIterator subset::Subset::end(){
    // create dummy end iterator where currentElem = _sub_size
    return ElementsIterator(*this, _sub_size);
}




