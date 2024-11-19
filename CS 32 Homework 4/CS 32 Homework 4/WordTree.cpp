//
//  WordTree.cpp
//  CS 32 Homework 4
//
//  Created by Coco Li on 8/18/23.
//

#include "WordTree.h"
using namespace std;

//constructor for WordNode
WordNode::WordNode(WordType data){
    m_data = data;
    m_dataCount = 1; //because we inputted one of the words in
    m_left = nullptr;
    m_right = nullptr;
}

//constructor Implementation
WordTree:: WordTree() : root(nullptr) {
    
};

//recall that the difference between a copy constructor and the ao
// copy construction:  we want to create a new object and assign the values of an old object to this new object
//ao : we have two alr created objects and we want to reassign one object with the values of another one (process includes a destructors and a copy constructor)

//copy constructor
WordTree::WordTree(const WordTree& rhs){
    root = copyConstructHelp(rhs.root);
}

WordNode* WordTree::copyConstructHelp(const WordNode *rhs){ //returning a WordNode pointer
    if (rhs == nullptr){ //if node is nullptr
        return nullptr; //we return a nullptr because ts either the end (leaf) or the tree is empty
    } //have to go all the way to the end to copy data
    WordNode *createNewNode = new WordNode(rhs -> m_data);
    createNewNode -> m_dataCount = rhs -> m_dataCount; //copy value
    createNewNode -> m_left = copyConstructHelp(rhs -> m_left);  //call function again to copy left side nodes
    createNewNode -> m_right =  copyConstructHelp(rhs -> m_right); //call function again to copy right side nodes
    return createNewNode; //return the full node to the previous call
}

//assignment operator
//destruct then copy construct
const WordTree& WordTree:: operator=(const WordTree& rhs){
    if (&rhs == this){ //check for aliasing
        return *this;
    }
    destructionHelp(root); //destroy current binary search tree
    root = copyConstructHelp(rhs.root); //copy construct rhs to lhs
    return *this; //returning this copied lsit 
}

void WordTree::destructionHelp(const WordNode *root){ //not sure if should pass w a const --> because changing the list
    //would need to do a post order traversal (left, right, then curr
    if (root == nullptr){
        return; //do nothing because list is empty or we have reached the end
    }
    //recursively delete everthing
    destructionHelp(root -> m_left);
    destructionHelp(root -> m_right);
    delete root;
}

//destructor
WordTree::~WordTree(){
    destructionHelp(this -> root);
}

// Inserts v into the WordTree
void WordTree::add(WordType v){
    if (root == nullptr){ //empty tree
        root = new WordNode(v);
        return;
    }
    WordNode *cur = root;
    while(cur != nullptr){
        if (v == cur -> m_data){
            cur -> m_dataCount++;
            return;
        }
        if (v < cur -> m_data){ //add to the left if the word is smaller than current word the pointer is pointing at
            if (cur -> m_left != nullptr){
                cur = cur -> m_left;
            }
            else{
                cur -> m_left = new WordNode(v); //added the node to the left
                return;
            }
        }
        else if (v > cur -> m_data){ //add to the right because the word we want to add is bigger than the node
            if (cur -> m_right != nullptr){
                cur = cur -> m_right;
            }
            else{
                cur -> m_right = new WordNode(v);
                return;
            }
        }
    }
}

int WordTree:: distinctWords() const{
    int count = 0;
    WordNode *temp = root;
    dwRecursively(count,temp);
    return count;
}

void WordTree:: dwRecursively(int &count, WordNode *ptr) const{ //need const because the function we are going to call this function from will not change the object
    if (ptr == nullptr){
        return;
    }
    count++; //count the current node
    dwRecursively(count, ptr -> m_left);
    dwRecursively(count, ptr -> m_right);
}

int  WordTree:: totalWords() const{
    int count = 0;
    WordNode *temp = root;
    twRecursively(count, temp);
    return count;
}


void WordTree::twRecursively(int &count, WordNode *ptr) const{
    if (ptr == nullptr){
        return;
    }
    count += ptr -> m_dataCount;
    twRecursively(count, ptr -> m_left);
    twRecursively(count, ptr -> m_right);
}

//helper function
ostream& WordTree:: printRecursively(ostream &out,WordNode *ptr) const{
    if (ptr == nullptr){
        return out;
    }
    printRecursively(out, ptr -> m_left);
    out << ptr -> m_data << " " << ptr -> m_dataCount << endl;
    printRecursively(out, ptr -> m_right);
    return out;
}

//refer to the document given in the assignment
//function outside the class so do not need WordTree::
ostream& operator<<(ostream &out, const WordTree& rhs){
    WordNode *temp = rhs.root;
    rhs.printRecursively(out, temp);
    return out;
}

