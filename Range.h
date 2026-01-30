//Range.h

#ifndef RANGE_H
#define RANGE_H

#include "IteratorG.h"  



template<typename K, typename V>
class Range {
private:
    
    
    IteratorG<K, V> b;  
    IteratorG<K, V> e;  
    
public:
    
    Range(const IteratorG<K, V>& begin, const IteratorG<K, V>& end) 
        : b(begin), e(end) {}
    
    IteratorG<K, V>& getB() { 
        return b; 
    }
    
    IteratorG<K, V>& getE() { 
        return e; 
    }
};



#endif 