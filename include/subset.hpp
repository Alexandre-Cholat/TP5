#pragma once
#include <memory>
#include <vector>

namespace subset{
    
    // FORWARD DECLARATION
    // Now the compiler allows this return type
    class ElementsIterator;

    class Subset{
        private:

        size_t _sub_size;
        size_t _super_size;
        unsigned long long _representation;



        public:            
            //empty subset doesnt make sense
            Subset() = delete;
            Subset(size_t k, size_t n);
            ~Subset();


            // Friend declaration
            friend std::ostream& operator<<(std::ostream& os, Subset& s);

            // check if an item belongs to a subset
            bool contains(const size_t i) const;
            // add an item 
            void add(const size_t i);
            // substract an item from a subset
            void minus(const size_t i);

            //Overload your methods to handle subsets as parameters:
            bool contains(const Subset& other);
            void add(const Subset& other);
            void minus(const Subset& other);

            size_t getSubSize(){ return _sub_size;}


            // can access private atributes 
            friend class ElementsIterator;

            ElementsIterator begin();
            ElementsIterator end();


};




}
