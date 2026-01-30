//EnglishDictionary.h

#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include "NodeDictionaryG.h"
#include <string>
#include <iostream>



class EnglishDictionary {
private:
    
    
    std::string name;  
    

    NodeDictionaryG<std::string, std::string> dictionary;
    
    
    void printForwardRecursive(IteratorG<std::string, std::string> it, 
                               IteratorG<std::string, std::string> end) {
        
        if (it == end) {
            return;
        }
        
        
        std::cout << it.entry().getK() << " -> " 
                  << it.entry().getV() << std::endl;
        
       
        ++it;
        printForwardRecursive(it, end);
    }
    
   
    void printBackwardRecursive(IteratorG<std::string, std::string> it,
                                IteratorG<std::string, std::string> start) {
        
        if (it == start) {
            return;
        }
        
        
        std::cout << it.entry().getK() << " -> " 
                  << it.entry().getV() << std::endl;
        
       
        --it;
        printBackwardRecursive(it, start);
    }
    
public:
    
    EnglishDictionary(std::string n) : name(n), dictionary() {
        std::cout << "Created dictionary: " << name << std::endl;
    }
    
    
    ~EnglishDictionary() {
        std::cout << "Destroying dictionary: " << name << std::endl;
    }
    
    
    int words() const {
        return dictionary.size();
    }
    
    
    int uniqueWords() const {
        return dictionary.uniqueKeys();
    }
    
    
    bool empty() const {
        return dictionary.empty();
    }
    
    
    void add(Entry<std::string, std::string> entry) {
        dictionary.put(entry.getK(), entry.getV());
    }
    
    
    void deleteFirst(std::string word) {
        dictionary.erase(word);  
    }
    
    
    void deleteWord(std::string word) {
        Range<std::string, std::string> r = dictionary.findAll(word);
        dictionary.erase(r);  
    }
    
   
    void printDictionary(bool forward) {
        if (forward) {
            std::cout << "\n=== Dictionary (Forward) ===" << std::endl;
            printForwardRecursive(dictionary.begin(), dictionary.end());
        } else {
            std::cout << "\n=== Dictionary (Reverse) ===" << std::endl;
            
            IteratorG<std::string, std::string> last = dictionary.end();
            --last; 
            printBackwardRecursive(last, dictionary.begin());
        }
        std::cout << std::endl;
    }
    
    
    void printDictionary(std::string word) {
        std::cout << "\n=== Definitions of '" << word << "' ===" << std::endl;
        
        Range<std::string, std::string> r = dictionary.findAll(word);
        
        // Check if word exists
        if (r.getB() == r.getE()) {
            std::cout << "Word not found in dictionary." << std::endl;
        } else {
            dictionary.print(r);
        }
        
        std::cout << std::endl;
    }
    
    
    Entry<std::string, std::string> find(std::string word) {
        IteratorG<std::string, std::string> it = dictionary.find(word);
        
        if (it != dictionary.end()) {
            return it.entry();  
        } else {
            return Entry<std::string, std::string>("", "");
        }
    }
};



#endif // ENGLISHDICTIONARY_H