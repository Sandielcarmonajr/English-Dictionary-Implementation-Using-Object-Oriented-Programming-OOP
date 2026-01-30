//Entry.h

#ifndef ENTRY_H
#define ENTRY_H




template <typename K, typename V>  
class Entry {
private:
    
    
    K _key;      
    V _value;    
    
    

public:
    
    
    Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {
        
    }
    
    
    ~Entry() {
        
    }
     
    const K& getK() const { 
        return _key;
    }
    
    
    const V& getV() const {
        return _value;
    }  
     
    
    void setK(K k) {  
        _key = k;
    }
     
    
    void setV(V v) {  
        _value = v;
    }
};




#endif  