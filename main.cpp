//main.cpp

//main.cpp

#include "EnglishDictionary.h"
#include "Entry.h"
#include <iostream>



int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "ENGLISH DICTIONARY TEST PROGRAM" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    
    std::cout << "--- Step 1: Creating Dictionary ---" << std::endl;
    EnglishDictionary myDict("Student's English Dictionary");
    std::cout << std::endl;
    
    
    std::cout << "--- Step 2: Adding Words ---" << std::endl;
    
   
    myDict.add(Entry<std::string, std::string>("set", "a collection of distinct objects"));
    myDict.add(Entry<std::string, std::string>("set", "to put or place something"));
    myDict.add(Entry<std::string, std::string>("set", "ready or prepared"));
    std::cout << "Added 'set' with 3 definitions" << std::endl;
    
   
    myDict.add(Entry<std::string, std::string>("run", "to move at a speed faster than walking"));
    myDict.add(Entry<std::string, std::string>("run", "to operate or function"));
    myDict.add(Entry<std::string, std::string>("run", "to manage or direct"));
    myDict.add(Entry<std::string, std::string>("run", "to flow or extend"));
    std::cout << "Added 'run' with 4 definitions" << std::endl;
    
    
    myDict.add(Entry<std::string, std::string>("apple", "a round fruit with red or green skin"));
    std::cout << "Added 'apple' with 1 definition" << std::endl;
    
    
    myDict.add(Entry<std::string, std::string>("bank", "a financial institution"));
    myDict.add(Entry<std::string, std::string>("bank", "the land alongside a river"));
    std::cout << "Added 'bank' with 2 definitions" << std::endl;
    
    std::cout << "\nTotal words: " << myDict.words() << std::endl;
    std::cout << "Unique words: " << myDict.uniqueWords() << std::endl;
    std::cout << std::endl;
    
    
    std::cout << "\n--- Operation 1: Print All (Forward) ---" << std::endl;
    myDict.printDictionary(true);
    
    
    std::cout << "\n--- Operation 2: Print All (Reverse) ---" << std::endl;
    myDict.printDictionary(false);
    
    
    std::cout << "\n--- Operation 3: Print 'bank' Definitions ---" << std::endl;
    myDict.printDictionary("bank");
    

    std::cout << "Note: Individual word printing shown above (same for reverse)" << std::endl;
    
  
    std::cout << "\n--- Operation 5: Delete First 'set' Definition ---" << std::endl;
    std::cout << "Before deletion:" << std::endl;
    myDict.printDictionary("set");
    
    myDict.deleteFirst("set");
    std::cout << "After deletion:" << std::endl;
    myDict.printDictionary("set");
    
    std::cout << "Total words: " << myDict.words() << " (should be 9)" << std::endl;
    std::cout << "Unique words: " << myDict.uniqueWords() << " (should be 4)" << std::endl;
    
  
    std::cout << "\n--- Operation 6: Search and Print 'run' ---" << std::endl;
    Entry<std::string, std::string> found = myDict.find("run");
    if (found.getK() != "") {
        std::cout << "Found: " << found.getK() << " -> " << found.getV() << std::endl;
    }
    std::cout << "\nAll definitions of 'run':" << std::endl;
    myDict.printDictionary("run");
    
  
    std::cout << "\n--- Operation 7: Delete First 'run' Definition ---" << std::endl;
    std::cout << "Before deletion:" << std::endl;
    myDict.printDictionary("run");
    
    myDict.deleteFirst("run");
    std::cout << "After deletion:" << std::endl;
    myDict.printDictionary("run");
    
    std::cout << "Total words: " << myDict.words() << " (should be 8)" << std::endl;
    std::cout << "Unique words: " << myDict.uniqueWords() << " (should be 4)" << std::endl;
    
   
    std::cout << "\n--- Operation 8: Delete All 'bank' Definitions ---" << std::endl;
    std::cout << "Before deletion:" << std::endl;
    myDict.printDictionary("bank");
    
    myDict.deleteWord("bank");
    std::cout << "After deletion (should show 'not found'):" << std::endl;
    myDict.printDictionary("bank");
    
    std::cout << "Total words: " << myDict.words() << " (should be 6)" << std::endl;
    std::cout << "Unique words: " << myDict.uniqueWords() << " (should be 3)" << std::endl;
    
    
    std::cout << "\n--- Operation 9: Print All After Deletions (Forward) ---" << std::endl;
    myDict.printDictionary(true);
    
 
    std::cout << "\n--- Operation 10: Print All After Deletions (Reverse) ---" << std::endl;
    myDict.printDictionary(false);
    
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "FINAL STATISTICS" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Total entries: " << myDict.words() << std::endl;
    std::cout << "Unique words: " << myDict.uniqueWords() << std::endl;
    std::cout << "Empty? " << (myDict.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
    
   
    std::cout << "--- Additional Test: Search Non-Existent Word ---" << std::endl;
    Entry<std::string, std::string> notFound = myDict.find("computer");
    if (notFound.getK() == "") {
        std::cout << "Word 'computer' not found (as expected)" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "========================================" << std::endl;
    std::cout << "TEST COMPLETE" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}

