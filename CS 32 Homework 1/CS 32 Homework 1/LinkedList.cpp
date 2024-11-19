//
//  LinkedList.cpp
//  CS 32 Homework 1
//
//  Created by Coco Li on 7/8/23.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(){ //constructor
    head = nullptr;
}

LinkedList :: LinkedList(const LinkedList &rhs){ //copy constructor
    //initalize a new variable with an old variable
    
    Node *prev = rhs.head;
    if (rhs.head == nullptr){
        head = nullptr; //empty list
    }
    else{ //not an empty linked list
        Node *createFirstNode = new Node; //first node in the linked list
        head = createFirstNode; // the head now points ot the first node of the list
        createFirstNode -> value = prev -> value; //copying the first value of the linked list
        Node *createNewNode;
        createFirstNode -> next = createNewNode = new Node; //trying to point the first node to the next node
        prev = prev -> next; //next item on the list
        while (prev != nullptr && prev -> next != nullptr){
            createNewNode -> value = prev -> value; //copy values
            createNewNode -> next = new Node; //pointing to the next new node until we reach the end of the list we are copying --> creating a new node
            prev = prev -> next; //iterating thru old list
            createNewNode = createNewNode -> next;
        }
        if (prev != nullptr && prev -> next == nullptr){
            createNewNode -> value = prev -> value;
            createNewNode -> next = nullptr;
        }
    }
}

LinkedList :: ~LinkedList(){ //destructor
    Node *p;
    p = head;
    while (p != nullptr){
        Node *n = p -> next; 
        delete p;
        p = n;
    }
}

const LinkedList& LinkedList::operator=(const LinkedList &rhs){  //assignment operator
    // not creating another object; just copying object over
    //delete lhs side then copy construct lhs using rhs
    
    if (this == &rhs){ //help with aliasing
        return *this;
    }
        
        //destructing lhs
        
        while(head != nullptr && head -> next != nullptr){ //continuing to delete the first item
            Node *deleteLHSNode = head;
            head = head -> next;
            delete deleteLHSNode;
            deleteLHSNode = head;
        }
        if (head != nullptr && head -> next == nullptr){ //have reached the end of the list
            Node *lastDeleteLHS = head;
            delete lastDeleteLHS;
        }
        
//        now copy construct
    if (rhs.head == nullptr){ //list is empty
        head = nullptr;
        
    }
    else{
        Node *prev = rhs.head; //track rhs
        Node *createFirstNode = new Node; //first node in the linked list
        head = createFirstNode; // the head now points ot the first node of the list
        createFirstNode -> value = prev -> value; //copying the first value of the linked list
        Node *createNewNode;
        createFirstNode -> next = createNewNode = new Node; //trying to point the first node to the next node
        prev = prev -> next; //next item on the list
        while (prev != nullptr && prev -> next != nullptr){
            createNewNode -> value = prev -> value; //copy values
            createNewNode -> next = new Node; //pointing to the next new node until we reach the end of the list we are copying --> creating a new node
            prev = prev -> next; //iterating thru old list
            createNewNode = createNewNode -> next;
        }
        if (prev != nullptr && prev -> next == nullptr){ //last node
            createNewNode -> value = prev -> value;
            createNewNode -> next = nullptr;
        }
    }
    return *this;
}

void LinkedList:: insertToFront(const ItemType &val){ //insert the value to the front of the list
    
    Node* newFirstNode;
    newFirstNode = new Node; //create a newNode to add to the front
    newFirstNode -> value = val; //adding the val passed in as the value in this new node
    newFirstNode -> next = head; //head stores the address of the current first node; need to make the newFirstNode next value equal to that address; connecting old first node with the new one
    head = newFirstNode; //change the head to store the address of the new Node we created
}

void LinkedList :: printList() const{

    Node *temp = head;
    if (head == nullptr && temp == nullptr){
        //print nothing
    }
    while (temp != nullptr && temp -> next != nullptr){ //not that last element
        cout << temp -> value << " ";
        temp = temp -> next;
    }
    if (temp != nullptr && temp -> next == nullptr){ //reached the last element of the linkedlist
        cout << temp -> value << endl;
    }

}


bool LinkedList :: get(int i, ItemType& item) const{
    int numberTracker = 0; //help us keep count at what node we are on --> first element of linked list
    Node *counterNode = head;
    if (head == nullptr){ //emptylist
        return false; //false bc nothing to iterate through
    }
    while(counterNode != nullptr && counterNode -> next != nullptr){ //middle of the list
        if (i == numberTracker){ //index exist in the linkedlist
            item = counterNode -> value;
            return true;
        }
        else{
            counterNode = counterNode -> next;
            numberTracker++;
        }
    }
    if (counterNode != nullptr && counterNode -> next == nullptr){
        if (i == numberTracker){
            item = counterNode -> value;
            return true;
        }
    }
    return false;
}

void LinkedList:: reverseList(){
    Node *current; //changes the address
    Node *holdPrevAddress; //hold previous address
    Node *temp; //moves to next address
    if (head == nullptr){
        return; //empty, nothing to reverse
    }
    temp = head;
    holdPrevAddress = head;
    current = head; //pointing to top of linkedlist
    temp = head -> next; //temp holds next address
    current -> next = nullptr; //first item now becomes last item
    current = temp;
    while (temp != nullptr && temp -> next != nullptr){
        temp = temp -> next;
        current -> next = holdPrevAddress; //holdPrevAddress has address of previous node
        holdPrevAddress = current; //now equals the current element
        current = temp;
    }
    if (temp != nullptr && temp -> next == nullptr){
        current -> next = holdPrevAddress;
        head = current; 
    }
    
}

void LinkedList::printReverse()const{
    for (int k = this -> size() - 1; k >= 0; k--){
        string p;
        this -> get(k,p);
        cout << p << " ";
        if (k == 0){
            cout << endl;
        }
    }
}


void LinkedList::append(const LinkedList &other){ //can we assume other is not empty
    
    //loop through to find the end of the linkedlist
    //then copy the other to the end
    
    Node *curr = head;
    Node *copyNode;
    if (other.head == nullptr){
        return; //returning nothing
    }
    while (curr != nullptr && curr -> next != nullptr){ //iterating until last item of the linkedlist
        curr = curr -> next;
    }
    if (curr != nullptr && curr -> next == nullptr){ //end of linked list
        copyNode = new Node; //create the first new node
        curr -> next = copyNode; //end of current list is now pointing to the first copy; starting to append the other list here
        Node *otherLoop = other.head; //will use this to copy values from LinkedList &other
        while (otherLoop != nullptr && otherLoop -> next != nullptr){
            copyNode -> value = otherLoop -> value;
            copyNode -> next = new Node;
            copyNode = copyNode -> next;
            otherLoop = otherLoop ->next; //have to update the element we are at in the other LinkedList
        }
        if (otherLoop != nullptr && otherLoop -> next == nullptr){ //last element of the otherLoop and making that the last element of the current linkedlist
            copyNode -> value = otherLoop -> value;
            copyNode -> next = nullptr;
        }
    }
}

void LinkedList :: swap(LinkedList &other){
    Node *tempNode = head;
    head = other.head;
    other.head = tempNode;
}

int LinkedList::size() const{
    int countList = 0;
    if (head == nullptr){
        return countList;
    }
    else{
        Node *ptr = head;
        while (ptr != nullptr){
            countList++;
            ptr = ptr -> next;
        }
    }
    return countList;
}
