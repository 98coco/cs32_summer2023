//
//  main.cpp
//  recursion worksheet
//
//  Created by Coco Li on 8/3/23.
//

#include <iostream>
#include <queue>
using namespace std;

//1. What does the following code output an what does the function LA_power do?

//int LA_power(int a, int b)
//{
//    if (b == 0)
//        return 0;
//    if (b % 2 == 0)
//        return LA_power(a+a, b/2);
//return LA_power(a+a, b/2) + a;
//}

//2. Given a singly-linked list class LL with a member variable head that points to
//the first Node struct in the list, write a function to recursively delete the whole
//list, void LL::deleteList(). Assume each Node object has a next pointer.

//struct Node {
//    int data;
//    Node* next;
//};
//
//class LL {
// public: // other functions such as insert not shown
//        void deleteList(); // implement this function
//    private: // additional helper allowed
//        Node* m_head;
//    void deleteListHelper(Node* &head);
//};
//
//void LL::deleteList(){
//    deleteListHelper(m_head);
//}
//
//void LL:: deleteListHelper(Node* &head){
//    if (head == nullptr){return;}
//    deleteListHelper(head->next); //will go all the way to the bottom and then return
//    delete head;
//    head = nullptr; //set this to nullptr because we return to previous node when we see nullptr
//}
//

//3. Implement the function getMax recursively. The function returns the maximum value in a, an integer array of size n. You may assume that n will be at least 1.

//int getMax(int a[], int n){
//    if (n == 1){
//        return a[0]; //last elem becomes first elem we compare
//    }
//    int currMax = getMax(a,n-1); //need to update currMax with the result
//    if (a[n-1] > currMax){
//        currMax = a[n-1];
//        return currMax;
//    }
//    return currMax;
//}

int min2(int a[],int k, int j){
    if (a[k]==a[j-1]){
        return a[k]; //last elem
    }
    int currMin = min2(a,k+1,j);
    if (a[k] < currMin){
        currMin = a[k];
    }
    return currMin;
}

int Min(int a[],int n){
    int k = 0; //iterator
    return min2(a,k,n);
}

int main() {
//    cout << LA_power(3, 4) << endl;
    
//    int a[] = {1,2,3};
//    cout << getMax(a, 4) << endl;
    
    int a[] = {5,2,3};
    cout <<  Min(a,3) << endl;;
    

    
    
    
    
    
    
    
    
}

