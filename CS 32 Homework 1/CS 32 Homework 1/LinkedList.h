//
//  LinkedList.h
//  CS 32 Homework 1
//
//  Created by Coco Li on 7/8/23.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

typedef std:: string ItemType; //

struct Node{
    ItemType value;
    Node *next;
};

class LinkedList{

private:
    Node *head; //will point to the first node
    
public:
    LinkedList(); //default constructor
    LinkedList(const LinkedList& rhs); //copy constructor
    ~LinkedList(); //destroys all dynamically allocated memory in the list
    const LinkedList& operator=(const LinkedList& rhs); //assignment operator
    void insertToFront(const ItemType &val); //Inserts val at the front of the list
    void printList() const; //Prints the LinkedList
    bool get(int i, ItemType& item) const; //sets item to the value at position i in this LinkedList and return true, returns false if there is no element i
    void reverseList(); //Reverses the LinkedList
    void printReverse() const;
    void append(const LinkedList &other); // Appends the values of other onto the end of the LinkedList
    void swap(LinkedList &other); //exchange the contents of this linkedlist with the other one
    int size()const; //returns the number of items in the linkedlist
};
    
#endif /* LinkedList_h */
