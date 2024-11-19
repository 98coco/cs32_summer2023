//
//  main.cpp
//  STL Worksheet
//
//  Created by Coco Li on 8/6/23.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

//2 in worksheet
void removeAllZeroes(list<int>&x){
    
    list<int>::iterator listIt;
    listIt = x.begin(); //iterator points to the first elem of the list
    while (listIt != x.end()){
        if (*listIt == 0){
            listIt = x.erase(listIt); //can do this because erase will just reset the iterator to the next element
            //have to do this because we are deleting the elem we are at
        }
        else{
            listIt++; //increment to the next item
        }
    }
    
}

void removeAllZeroes(vector<int>& x){
    vector <int>:: iterator vecIt;
    vecIt = x.begin();
    while (vecIt != x.end()){
        if (*vecIt == 0){
            vecIt = x.erase(vecIt); 
        }
        else{
            vecIt++;
        }
    }
}

void removeAllZeroes(vector<int*>& x){
    vector <int*>::iterator pointIt; //need pointer because that it the type inside the vector
    pointIt = x.begin();
    while (pointIt != x.end()){
        if (*pointIt == 0){
            pointIt = x.erase(pointIt);
        }
        else{
            pointIt++;
        }
    }
}

//3 in worksheet

template <typename T>
T max(T x, T y)
{
return (x > y) ? x : y; //ternary operator (if expression is true return x, otherwise return y)
    
    //condition ? expression 1: expression 2
    //if condition evaluate to true go tot expression 1
    //if condition evaluates to false go to expression 2
}

//will not compile because we are passing an int and a float in the last cout

//5 Implement a stack class Stack that can be used with any data type using
//templates. Use a linked list (not an STL list) to store the stack and
//implement the functions push(), pop(), top(), isEmpty(), a default constructor,
//and a destructor that deletes the linked list nodes.

template <typename stackClass>

class Stack{
public:
    Stack(): head(nullptr){}; //default constructor
//    void push(stackClass v){ //if i use this i am adding to the end so pop will have to go to the end --> we need to addd to beginning bc last in first out
//        Node *tempIt = head;
//        if (head == nullptr){ //empty list
//            Node *firstNode = new Node;
//            firstNode -> value = v;
//            head = firstNode;
//        }
//        while (tempIt -> next!= nullptr){
//            tempIt++;
//        }
//        if (tempIt -> next == nullptr){ //adding to end then popping it off
//            Node *secTemp = new Node;
//            secTemp -> value = v;
//            tempIt -> next == secTemp;
//            secTemp -> next == nullptr; // new node becomes last node
//        }
//    }
    void push(stackClass v){ //adding to the top
        Node *temp = new Node;
        temp -> value = v;
        temp -> next = head;
        head = temp;
    }
    
    void pop(){ //want to delete from the top
        if (head == nullptr){
            return; //because empty
        }
        Node *temp = head;
        head = head -> next;
        delete temp; //delete first in
    }
    
    int top(){
        if (head == nullptr){
            return stackClass();
        }
        return head -> value; //return first one because that was the last one in and will be the first one out
    }
    bool empty(){
        if (head == nullptr){
            return true;
        }
        return false;
    }
    
    ~Stack(){
        while (head != nullptr){
            Node *temp = head;
            head = head -> next;
            delete temp;
            temp = head;
        }
    }
    
private:
    struct Node{
        stackClass value; //will store any data type
        Node* next;
    };
    Node *head;
    
};

int main() {
    
    //3
//    std::cout << max(3, 7) << std::endl;  //when u run take out using namespace std because it will confuse the compiler since std has its own implementation of max
//    std::cout << max(3.0, 7.0) << std::endl;
//    std::cout << max(3, 7.0) << std::endl;
//
    
    
    
}
