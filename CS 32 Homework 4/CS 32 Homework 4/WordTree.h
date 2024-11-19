//
//  WordTree.h
//  CS 32 Homework 4
//
//  Created by Coco Li on 8/18/23.
//

#ifndef WordTree_h
#define WordTree_h
#include <iostream>
#include <string>

typedef std::string WordType;

class WordTree;
std::ostream& operator << (std::ostream& stream, const WordTree& obj);

struct WordNode {
    WordNode(WordType data); //constructor
    WordType m_data;
    int m_dataCount; //repeating words increment this var
    WordNode *m_left;
    WordNode *m_right;
// You may add additional data members and a constructor
// in WordNode
};

class WordTree {
private:
    WordNode *root;
    WordNode* copyConstructHelp(const WordNode *rhs);
    void destructionHelp(const WordNode *root);
    void dwRecursively(int &count, WordNode *ptr) const; //need to see if i should past this as const or not
    void twRecursively(int &count, WordNode *ptr) const;
    std::ostream& printRecursively(std::ostream &out,WordNode *ptr) const;
public:
    // default constructor
    WordTree();
    
    // copy constructor
    WordTree(const WordTree& rhs);
    
    // assignment operator
    const WordTree& operator=(const WordTree& rhs);
    
    // Destroys all the dynamically allocated memory in the
    // tree
    ~WordTree();
    
    // Inserts v into the WordTree
    void add(WordType v);
    
    // Returns the number of distinct words / nodes
    int distinctWords() const;
    
    // Returns the total number of words inserted, including
    // duplicate values
    int totalWords() const;
    
    // Prints the WordTree
    friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs); //refer to the document given in the assignment
   
};


#endif /* WordTree_h */
