//
//  main.cpp
//  Midterm 1 Review
//
//  Created by Coco Li on 7/13/23.
//

#include <iostream>
#include <string>
using namespace std;

int* minimart(int* a, int* b)
{
    if (*a < *b)
    return a;
    else
    return b;
}

void swap1(int* a, int *b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int *b) //pointers to a and b
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//class A {
//public:
//      A()
//      { cout << "DC" << endl; }
//      A(const A& other)
//      { cout << "CC" << endl; }
//      A& operator=(const A& other)
//      { cout << "AO" << endl; return *this; }
//      ~A()
//      { cout << "Destructor!" << endl;}
//};

class B {
        int m_val;
public:
    B(int x): m_val(x) { cout << "Wow such " << x << endl; } B(const B& other) {
               cout << "There's another me???" << endl;
               m_val = other.m_val;
         }
         ~B() {
               cout << "Twas a good life" << endl;
    }
};

class A {
     int m_count;
     B* m_b;
public:
     A(): m_count(9.5) {
           cout << "Construct me with " << m_count << endl;
           m_b = new B(m_count+10);
     }
     A(const A& other) {
           cout << "Copy me" << endl;
           m_count = other.m_count;
           m_b = (other.m_b != nullptr) ? new B(*other.m_b)
: nullptr;
} ~A() {
           cout << "Goodbye cruel world" << endl;
           if (m_b)
delete m_b;
}
     int getCount() { return m_count; }
};

struct Node{
public:
    int val;
    Node* next;
};

typedef std:: string ItemType;

class LinkedList{

public:
    Node *head; //will point to the first node
    
public:
    LinkedList(); //default constructor
    ~LinkedList(); //destroys all dynamically allocated memory in the list
    void insertToFront(int val); //Inserts val at the front of the list
    void printList() const;
    int findNthFromLast(int n);
};
    
LinkedList::LinkedList(){ //constructor
    head = nullptr;
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

void LinkedList:: insertToFront(int val){ //insert the value to the front of the list
    
    Node* newFirstNode;
    newFirstNode = new Node; //create a newNode to add to the front
    newFirstNode -> val = val; //adding the val passed in as the value in this new node
    newFirstNode -> next = head; //head stores the address of the current first node; need to make the newFirstNode next value equal to that address; connecting old first node with the new one
    head = newFirstNode; //change the head to store the address of the new Node we created
}

void LinkedList :: printList() const{
    
    Node *temp = head;
    if (head == nullptr && temp == nullptr){
        //print nothing
    }
    while (temp != nullptr && temp -> next != nullptr){ //not that last element
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    if (temp != nullptr && temp -> next == nullptr){ //reached the last element of the linkedlist
        cout << temp -> val << endl;
    }
    
}

int LinkedList :: findNthFromLast(int n){
    Node *p = head;
    int size = 0;
    
    // checking size of LinkedList
    while (p != nullptr && p -> next != nullptr){
        size++;
        p = p-> next;
    }
    if( p != nullptr && p -> next == nullptr){
        size++;
    }
    
    if (size - n < 0){
        return -1;
    }
    else{
        int locationOfNth = size - n;
        p = head;
        while (locationOfNth != 1){ //found our target
                p = p-> next;
                locationOfNth--;
        }
        return p -> val;
    }
    return -1;
}




int cmpr (Node* head, int* arr, int arr_size){
    Node* p = head;
    int index = -1;
    if (head == nullptr){
        return -1; //empty
    }
    for (int i = 0; i <= arr_size; i++){
        if (p != nullptr && p -> next != nullptr){
            if (arr[i] == p-> val){
                index++;
                p = p -> next;
            }
            else{
                break;
            }
        }
        if (p -> next == nullptr){ //incase it goes all the way to the end
            if (arr[i] == p-> val){
                index++;
                return index;
            }
        }
    }
    return index;
};


class character{
 int size;
 public:
// Uncomment this section and check if you get output without errors
// default constructor
 character(){

}
    
character(int sz) {
size = sz;
};
    
};
class Game{
int gaming;
character ch;
public:
Game(int g, int sz){
gaming = g;
ch = character(sz);
}
};

void mystery (int* ptr, int& a, int& b) {
a++;
b--;
    cout << ptr << endl;
    if (a > b){
        ptr = &a;
        cout << ptr << endl;
    }
    else{
        ptr = &b;
        cout << ptr << endl;
    }
*ptr += 10;
return;
}

int main() {
  
    
//    LinkedList p3;
//        p3.insertToFront(5);
//        p3.insertToFront(4);
//        p3.insertToFront(3);
//        p3.insertToFront(2);
//        p3.insertToFront(1);
//
//    cout << p3.findNthFromLast(2) << endl;;
    
//    LinkedList e;
//    e.insertToFront(6);
//    e.insertToFront(5);
//    e.insertToFront(3);
//    e.insertToFront(2);
//    e.insertToFront(1);
//
//
//
//    int a[6] = {1, 2, 3, 4, 5, 6};
//    cout << cmpr(e.head, a, 6) << endl;
//
//    int b[7] = {1, 2, 3, 5, 6, 7, 5};
//    cout << cmpr(e.head, b, 7) << endl;
//
//    int c[3] = {5, 1, 2};
//         cout << cmpr(e.head, c, 3) << endl; // Should print -1
//
//    int d[3] = {1, 2, 3};
//    cout << cmpr(e.head, d, 3) << endl; // Should print 2
//
//    int t[5] = {1,2,3,5,6};
//    cout << cmpr(e.head, t, 5) << endl; //should print 4
    
    

    //header files
    
    // if one file needs 3 header files and one header file alr includes one of the other headers w do not need
    //to break circular dependency find smth that doesnt need the implementation
    //last in first out
    
    //infix -> post fix
    //EX 1:
    // 4 * 2 + 1 / ( 2 + 3 ) / 6
    // stack:
    // string: 4 2 * 1 2 3 + / 6 / +
    
    //more than 2 numbers next to each other means that it is implied that there is a paranthesis
    // no need to put closing paranthesis on postfix expression
    
    //post fixmath:
    // var 1: second one to pop off goes to var 1
    //var 2: first one to pop off goes to var 2

// EX 2:
    
// 2 - ( 5 + ( 2 * 3 - ( 4 ) / 6 ) ) / 4
    
//stack:
//string: 2 5 2 3 * 4 6 / - + 4 / -
//

    
//evaluation:

    
//stack: 2 (31/12)
// var 1: 24/12
// var 2: 31/12
//var 1 op var 2

    // ans : -7 / 12
    
//depth first search (stacks)
// as far down as possible in one direction --> this happens with a stack
// when one direction is done we go another direction
//
//breadth first search (queue)
// radially --> looking at each direction first before moving on; not going all the way in one direction
// going thru a radius
//
//
    
// . is the accessor operator
//
//field is a data in the struct
    
// -> is the same thing as dereferencing and using a dot (dot is the accessor operator)
    
    
//order of construction
//
// 1) ignore for now
// 2) initialize the member variables according to the initializer list
//  if the member vars are not initialize in the initializer list, then default construct them
// 3) execute the constructor body
//
//default for string is empty string
//
//

//    class student{
//        student() : m_x(2), m_tall(false){
//            m_x =4;
//        }
//        student (int x, bool tall): m_x(x),m_tall(tall){
//            m_name = "henry";
//        }
//
//        int m_x;
//        bool m_tall;
//        std :: string m_name;
//    };
    
//step 2
//m_x = 2
//m_tall = false
//m_name = "" (because no name was passed  and default is empty string)

//step 3
//m_x = 2
//m_tall = false
//m_name = "henry" (because no name was passed  and default is empty string)
//
//
    
//
//
//worksheet pointers
//
// problem 2)
//
//    string *fp;
//    string fish[5];
//    fp = fish + 4; //pointing to last element
//    *fp = "tilapia";
//    *(fish +3) = "salmon";
//    fp = fp - 3; //move back three strings
//    fp[1] = "tuna"; //fp[1] == *(fp+1) --> brackets is a shortcut for saying
//    fp[0] = "ono"; //whereever position  pointer is at that is 0
////    bool d = (fp == fish);
////    bool b = (*fp == *(fp+1));
//    fish[0] = "fishes: ";
//
//    for (int i = 0; i < 5; i++){
//        cout << fish[i] <<endl;
//    }

//problem 4
    
//    int array[6] = { 5, 3, 4, 17, 22, 19 };
//    int* ptr = minimart(array, &array[2]); //ptr = array[2]
//    ptr[1] = 9; //array[3] = 9
//    ptr += 2;
//    *ptr = -1; // array[4] = -1
//    *(array+1) = 79;
//    cout << "diff=" << &array[5] - ptr << endl; // & means address; &*(array +5); address of array minus address of ptr which is 1
//    swap1(&array[0], &array[1]); //5,79,4,9,-1,19 --> swaps the two pointers locally, does change outside
//    swap2(array, &array[2]); //4,79,5,9,-1,19 --> swaps the two values bc derederncing pointer
//    for (int i = 0; i < 6; i++)
//    cout << array[i] << " "; //4,79,5,9,-1,19
//    cout <<endl;
//    return 0;
    
    
//worksheet 1
//
//problem 1
//
    
//    A arr[3];
//    arr[0] =arr[1];
//    A x = arr[0];
//    x = arr[1];
//    A y (arr[2]);
//    cout << "Done" << endl;
    
//note --> copy constructor gets called for each element in an array
    
// DC --> creating a constructor for each element in the array
// DC --> creating a constructor for each element in the array
// DC --> creating a constructor for each element in the array
// AO --> assigning one elemnet in the array to another
// CC --> copy constructor for A x = arr[0];  --> arr[0] alr constructed
// AO --> changing x to smth else created
// CC --> passing in arr[2] to create y
// Done --> we r done
// Destructor --> destroying y
// Destructor --> destroying arr[2]
// Destructor --> destroying x
// Destructor --> destroyin arr[1]
// Destructor --> destroying arr[0]
//
    
    
//        A a1, a2;
//        A a3 = a2;
//        B b1(a3.getCount());
//        cout << "Where are we?" << endl;
//
//
//
//
//  Construct me with 9 --> m_b = new B(m_count+10) //becuase int
// Wow such 19 --> 10 + 9
//  Construct me with 9 --> m_b = new B(m_count+10)
// Wow such 19 --> 10 + 9
//  Copy Me --> m_count = 9
// There's another me??? m_val = 19
//wow such a 9
// Where are we
    
// twas a good life (destroying b1)
// goodbye cruel world (destroying a3)
// twas a good life (destroying b in a3)
// goodbye cruel world (destroying a2)
// twas a good life (destroying b in a2)
// goodbye cruel world (destorying a1)
//twas a good life (destroying b in a1)

//    int    i[] = {1,   2,   3,   4  };
//        double d[] = {1.1, 2.2, 3.3, 4.4};
//
//        int*    pi = &i[0];
//        double* pd = &d[0];
//
//        cout << pi     << ' ' << (pi     == &i[0]) << endl;  //pi is giving us the address of each element --> 1 indicates that it is true that the ptr's address is equal to that element of the arrays address
//        cout << pi + 1 << ' ' << (pi + 1 == &i[1]) << endl;
//        cout << pi + 2 << ' ' << (pi + 2 == &i[2]) << endl;
//        cout << pi + 3 << ' ' << (pi + 3 == &i[3]) << endl << endl;
//
//        cout << pd     << ' ' << (pd     == &d[0]) << endl;
//        cout << pd + 1 << ' ' << (pd + 1 == &d[1]) << endl;
//        cout << pd + 2 << ' ' << (pd + 2 == &d[2]) << endl;
//        cout << pd + 3 << ' ' << (pd + 3 == &d[3]) << endl << endl;
    
//Study Guide
//
// 18) convert to post fix
// A + (B – C) / D
//
// postfix: A B C - D / +
// stack:
//
//
//
//
//
//
//
//
//
//
//

//    int nums[] = {2, 4, 6, 1, 2, 3};
//    cout << nums << endl;
//    int *p = nums;
//    cout << p << endl;
//    while (p < nums + 6)
////        cout << p << " " << nums + 6 << endl;
//    {
//        if (*p % 3 == 0){
//            *p = *p + 1;        }
//    else if(*p % 2 == 0) {
//        *p += 2;
//        cout << *p << endl;
//        p = p + 1;
//        cout << p << endl;
//    }
//    p = p + 1;
//        cout << p << endl;
//    }
//    for (int i=0; i<6; i++) cout << nums[i] << " ";
    
//    int v1 = 10;
//    int v2 = 25;
//    int *p1 = &v1;
//    int *p2 = &v2;
//    *p1 += *p2;
//    p2 = p1;
//    *p2 = *p1 + *p2;
//    cout << "*p1 = " << *p1 << " *p2 = " << *p2
//    << " v1 = " << v1 << " v2 = " << v2 << endl;
    
    int num1 = 0, num2 = 14, num3 = 17;
    int *p = &num1;
    cout << p << endl;
    mystery(p, num2, num3);
    cout << "num1: " << num1 << " num2: " << num2
    << " num3: " << num3 << endl;
    if (p == &num1) cout << " num1";
    else if (p == &num2) cout << " num2";
    else if (p == &num3) cout << " num3";    
}
