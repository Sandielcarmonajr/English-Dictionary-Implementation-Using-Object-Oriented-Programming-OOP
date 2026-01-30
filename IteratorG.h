//IteratorG.h

#ifndef ITERATORG_H
#define ITERATORG_H

#include "DNodeG.h" 


template<typename K, typename V>
class NodeDictionaryG;

template<typename K, typename V>
class IteratorG{
    private:
    
    DNodeG<K, V>* v; 
    
    public:
   
    IteratorG(DNodeG<K, V>* u = nullptr) : v(u) {}
    
    
    const V& operator*() const {
        return v->elm.getV();  
    }
    
    
    const Entry<K, V>& entry() {
        return v->elm;  
    }
    
    
    bool operator==(const IteratorG& p) const {
        return v == p.v;
    }
    
    
    bool operator!=(const IteratorG& p) const {
        return v != p.v;
    }
    
    
    IteratorG& operator++() {
        v = v->next;     
        return *this;    
    }
    
    
    IteratorG& operator--() {
        v = v->prev;     
        return *this;
    }
    
    
    
    friend class NodeDictionaryG<K, V>;
};



#endif 