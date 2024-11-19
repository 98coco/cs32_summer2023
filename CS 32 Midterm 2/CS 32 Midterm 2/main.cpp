//
//  main.cpp
//  CS 32 Midterm 2
//
//  Created by Coco Li on 8/6/23.
//

#include <iostream>
#include <queue>
using namespace std;


//class circularQueue{
//private:
//public:
//    //functions of a queue
//
//
//};

//class Person {
//public:
//virtual void eat() {cout << "Yummy" << endl;}
//virtual void speak() {cout << "Hello" << endl;}
//virtual void sleep() {cout << "ZZZZ" << endl;}
//virtual ~Person() {}
//};
//class Student : public Person {
//public:
//void speak() {cout << "I love school" << endl;}
//    void getReadyForTest () {
//    study();
//    sleep();
//    }
//    virtual ~Student() {}
//    };
//    class UCLAStudent : public Student {
//    public:
//    void speak() {cout << "Go Bruins!" << endl;}
//    void sleep() {cout << "ZZZ... CS32 ...ZZZZ"
//    << endl;}
//    void getReadyForCS32Test() {
//    study();
//    eat();
//    sleep();
//    }
//    virtual ~UCLAStudent() {}
//};

//bool theQuadSquad(int x[],int size,int total, int count){
//    if (total == 0 && count == 4){
//        return true; //because we found 4 numbers that give us the total
//    }
//    if (count > 4){
//        return false;
//    }
//    if (size == 0){ //empty
//        return total = 0;
//    }
//    bool includedNums = theQuadSquad(x+1, size-1, total - x[0], count+1);
//    if (includedNums == true){
//        return true;
//    }
//
//        return theQuadSquad(x+1, size-1, total, count); //since we excluded the number we do not need to include it in out count
//}

bool theQuadSquad(int x[],int size, int total, int count){
if (total == 0 && count == 4){
return true; //because we found 4 elements that give us the total
}
if (size == 0){
return total = 0;

}
    bool includedNums = theQuadSquad (x+1, size-1, total - x[0], count +1);
if (includedNums == true){
return true;
}
return theQuadSquad(x+1, size-1, total, count++);
}

bool dontStandSoCloseToMe(int x[],int size, int total, int start){
    if (size == 0){
        return total = 0;
    }
    if (total == 0){
        return true;
    }
    bool res = dontStandSoCloseToMe(x, size -1, total - x[start], start+2); //start is where to go next --> here we included the first elem in array
    if (res == true)
    {
        return true;
    }
    return dontStandSoCloseToMe(x, size-1, total, start+1); //did not include first elem

}

int main() {
 
    //implement circular queue --> would need to make a class
//        int arr[5] = {};
//        int *head;
//        int *tail;
//        int counter;
//
//        head = tail = arr; //all pointing to the first elem of arr
//        counter = 0; // first elem
    
//    Person* array[3];
//    array[0] = new Person();
//    array[1] = new Student();
//    array[2] = new UCLAStudent();
//    for (int i=0; i < 3; i++) {
//    array[i]->eat();
//    array[i]->speak();
//    array[i]->sleep();
//    }
//    Student * sp = new Student();
//    UCLAStudent *uclap = new UCLAStudent();
//    sp->getReadyForTest();
//    uclap->getReadyForCS32Test();
//    return 0;
//

    int x[] = {1,2,3,4};
    if (theQuadSquad(x, 4, 10, 0) == true){
        cout << "hello" <<endl;
    }

    if (theQuadSquad(x, 4, -1, 0) == true){
        cout << "theres smth wrong" <<endl;
    }

    int f[] = {5,-6,1,2};
    if (theQuadSquad(f, 4, -1, 0) == true){
        cout << "theres smth wrong" <<endl;
    }

    int l[] = {-4,-3,-2,-1};
    if (theQuadSquad(l, 4, -10, 0) == true){
        cout << "hi" <<endl;
    }

//    int x[] = {5,2,1,9};
//    if (dontStandSoCloseToMe(x, 4,11, 0) == true){
//        cout << "hello" <<endl;
//    }
//
//    int m[] = {7, 0, 4, 3};
//    if (dontStandSoCloseToMe(m, 4,7, 0) == true){
//        cout << "what" <<endl;
//    }
//
//    int k[] = {1, 9, 7, 9};
//    if (dontStandSoCloseToMe(k, 4,16, 0) == true){
//        cout << "smth is wrong" <<endl;
//    }
//
//    int n[] = {-2,-3,-4,-5};
//    if (dontStandSoCloseToMe(n, 4,-7, 0) == true){
//        cout << "yay" <<endl;
//    }
    
//    string s = "yum";
//    cout << "if im given" << s << "then its five times the fun to get " <<
//    for (int i = 0; i < 6; i++){
//    cout << s;
//    }
//    cout << endl;

//    int a = 10;
//////    --a;
////    a--;
////    cout << a << endl;
//
//    while (a > 5){
//        cout << a << endl;
//        --a;
//    }
    
}
