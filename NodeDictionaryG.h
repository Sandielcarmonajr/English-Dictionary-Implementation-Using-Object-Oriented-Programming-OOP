//NodeDictionaryG.h

#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "DNodeG.h"
#include "IteratorG.h"
#include "Range.h"
#include "Entry.h"
#include <iostream>



template<typename K, typename V>
class NodeDictionaryG {
private:
    
    
    int uKeys;    
                  
    
    int n;        
                  
    
    DNodeG<K, V>* header;   
    DNodeG<K, V>* trailer;  
    
public:
    
    NodeDictionaryG() : uKeys(0), n(0) {
        header = new DNodeG<K, V>();   
        trailer = new DNodeG<K, V>();  
        
        
        header->next = trailer;
        trailer->prev = header;
    }
    
    
    ~NodeDictionaryG() {
        
        DNodeG<K, V>* current = header->next;  
        while (current != trailer) {
            DNodeG<K, V>* next = current->next;  
            delete current;                       
            current = next;                       
        }
        
       
        delete header;
        delete trailer;
    }
    
    
    int size() const { 
        return n; 
    }
    
    
    int uniqueKeys() const { 
        return uKeys; 
    }
    
    
    bool empty() const { 
        return n == 0; 
    }
    
    
    IteratorG<K, V> begin() const {
        return IteratorG<K, V>(header->next);  
    }
    
    
    IteratorG<K, V> end() const {
        return IteratorG<K, V>(trailer);  
    }
    
    
    IteratorG<K, V> find(const K& k) const {
        
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            if (it.entry().getK() == k) {  
                return it;  
            }
        }
        return end();  
    }
    
    
    IteratorG<K, V> put(const K& k, const V& v) {
        
        DNodeG<K, V>* insertAfter = header;  
        bool keyExists = false;
        
       
        for (DNodeG<K, V>* curr = header->next; curr != trailer; curr = curr->next) {
            if (curr->elm.getK() == k) {
                insertAfter = curr;  
                keyExists = true;
            }
        }
        
        
        if (!keyExists) {
            insertAfter = trailer->prev;
            ++uKeys;  
        }
        
        
        Entry<K, V> newEntry(k, v);
        DNodeG<K, V>* newNode = new DNodeG<K, V>(newEntry);
        
        
        DNodeG<K, V>* nextNode = insertAfter->next;
        
        newNode->next = nextNode;
        newNode->prev = insertAfter;
        insertAfter->next = newNode;
        nextNode->prev = newNode;
        
        ++n;  
        
        return IteratorG<K, V>(newNode);  
    }
    
    
    void erase(const K& k) {
        IteratorG<K, V> it = find(k);  
        if (it != end()) {              
            erase(it);                  
        }
    }
    
    
    void erase(const IteratorG<K, V>& p) {
        if (p == end()) return;  
        
        
        DNodeG<K, V>* nodeToDelete = p.v;
        K key = nodeToDelete->elm.getK();
        
       
        DNodeG<K, V>* prevNode = nodeToDelete->prev;
        DNodeG<K, V>* nextNode = nodeToDelete->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        delete nodeToDelete;  
        --n;                   
        
        
        bool keyStillExists = false;
        for (DNodeG<K, V>* curr = header->next; curr != trailer; curr = curr->next) {
            if (curr->elm.getK() == key) {
                keyStillExists = true;
                break;
            }
        }
        
        if (!keyStillExists) {
            --uKeys; 
        }
    }
    
    
    void erase(Range<K, V>& r) {
        IteratorG<K, V> it = r.getB();
        while (it != r.getE()) {
            IteratorG<K, V> next = it;
            ++next;           
            erase(it);        
            it = next;        
        }
    }
    
    
    Range<K, V> findAll(const K& k) {
        IteratorG<K, V> start = end();  
        IteratorG<K, V> finish = end();
        
        bool found = false;
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            if (it.entry().getK() == k) {
                if (!found) {
                    start = it;  
                    found = true;
                }
                finish = it;  
            }
        }
        
        if (found) {
            ++finish;  
        }
        
        return Range<K, V>(start, finish);
    }
    
    
    void print() {
        std::cout << "--- Dictionary Contents ---" << std::endl;
        for (IteratorG<K, V> it = begin(); it != end(); ++it) {
            std::cout << it.entry().getK() << " -> " 
                      << it.entry().getV() << std::endl;
        }
    }
    
    
    void print(Range<K, V>& r) {
        std::cout << "--- Range Contents ---" << std::endl;
        for (IteratorG<K, V> it = r.getB(); it != r.getE(); ++it) {
            std::cout << it.entry().getK() << " -> " 
                      << it.entry().getV() << std::endl;
        }
    }
};



#endif 