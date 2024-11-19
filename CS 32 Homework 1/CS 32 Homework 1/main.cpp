//
//  main.cpp
//  CS 32 Homework 1
//
//  Created by Coco Li on 7/8/23.
//

#include "LinkedList.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
    
//    LinkedList BaoBao;
//
//    BaoBao.insertToFront("dog.");
//    BaoBao.insertToFront("cutest");
//    BaoBao.insertToFront("the");
//    BaoBao.insertToFront("is");
//    BaoBao.insertToFront("BaoBao");
//
//    LinkedList Owners;
//    Owners.insertToFront("owners.");
//    Owners.insertToFront("BaoBao's ");
//    Owners.insertToFront("are");
//    Owners.insertToFront("Ruoyi");
//    Owners.insertToFront("and");
//    Owners.insertToFront("Coco");
    
    //copy constructor and print list testing
    
//        LinkedList ls;
//        ls.insertToFront("Hawkeye");
//        ls.insertToFront("Thor");
//        ls.insertToFront("Hulk");
//        ls.insertToFront("Black Widow");
//        ls.insertToFront("Iron Man");
//        ls.insertToFront("Captain America");
//        ls.printList();
//        cout << endl;
//
//        LinkedList ls2 = ls; //checking copy constructor
//        ls2.printList();
    
    //assignment operator testing
    
//    LinkedList ls;
//    ls.insertToFront("Hawkeye");
//    ls.insertToFront("Thor");
//    ls.insertToFront("Hulk");
//    ls.insertToFront("Black Widow");
//    ls.insertToFront("Iron Man");
//    ls.insertToFront("Captain America");
//    cout << "print: captain america....hawkeye: " << endl;
//    ls.printList();
//    //    cout << endl;
//
//        LinkedList assignLS;
//        assignLS.insertToFront("beg");
//        assignLS.insertToFront("i");
//        assignLS.insertToFront("work");
//        assignLS.insertToFront("please");
    
    //assigning assignLS to ls
    
//    cout << "print: captain america....hawkeye" << endl;
//    assignLS = ls;
//    assignLS.printList();
//
    
    //assigning ls to assignLS
    
//    cout << "assignLS: please work i beg" << endl;
//        assignLS.printList();
//        ls = assignLS;
//    cout << "ls: please work i beg" << endl;
//        ls.printList();
//        LinkedList LSEmpty;
//    LSEmpty = ls;
//    LSEmpty.reverseList(); //changed the linked list
//    cout << "LSEmpty should print out please work i beg "<< endl;
//    LSEmpty.printReverse();
//
//    cout << "should print beg i work please: " << endl;
//    LSEmpty.printList(); //this is because printReverse does not change the linkedlist
//
//    LinkedList ls2;
//    ls2.insertToFront("beg");
//    ls2.insertToFront("i");
//    ls2.insertToFront("work");
//    ls2.insertToFront("please");
//
//    ls2 = ls; //checking aliasing
//    cout << "should print out please work i beg" << endl;
//    ls2.printList();

    
    //test get and size function
//        LinkedList ls;
//        ls.insertToFront("Hawkeye");
//        ls.insertToFront("Thor");
//        ls.insertToFront("Hulk");
//        ls.insertToFront("Black Widow");
//        ls.insertToFront("Iron Man");
//        ls.insertToFront("Captain America");
//        for (int k = 0; k < ls.size(); k++)
//        {
//        string x;
//        ls.get(k, x);
//        cout << x << endl;
//        }
//
//    cout << "print: BaoBao is the cutest dog" << endl;
//    BaoBao.printList();
//    string l;
//    assert(BaoBao.get(6, l) == false); //there isnt 6 items
//    assert(BaoBao.get(4, l) == true);
//    cout << "should print out dog: " << endl;
//    cout << l << endl;
//    assert(BaoBao.size() == 5);

//    string m = "happy";
//    assert(Owners.get(6,m) == false); //bc linked list starts w 0 index?
//    cout << "print: happy" << endl;
//    cout << m << endl;
//    assert(Owners.get(5,m) == true);
//    cout << "print: owners." << endl;
//    cout << m << endl;
//    assert(Owners.get(4,m) == true);
//    cout << "print: BaoBao's" << endl;
//    cout << m << endl;
    
    //test reverse
    
//
//    BaoBao.reverseList();
//    cout << "print: dog cutest the is BaoBao" << endl;
//    BaoBao.printList();
//    cout << "print: BaoBao is the cutest dog" << endl;
//    BaoBao.printReverse();
//    cout << "print: dog cutest the is BaoBao bc printReverse shouldn't change linkedlist" << endl;
//    BaoBao.printList();
//
//    ls.reverseList();
//    ls.printList();

//    LinkedList e1;
//    e1.insertToFront("Jim");
//    e1.insertToFront("Oz");
//    e1.insertToFront("Paul");
//    e1.insertToFront("Kevin");
//    e1.reverseList(); // reverses the contents of e1
//
//    e1.printList();
    
    //test print reverse and print list function
//    LinkedList ls;
//    ls.insertToFront("The Mandalorian");
//    ls.insertToFront("Baby Yoda");
//    ls.insertToFront("Cara Dune");
//    ls.insertToFront("Greef Karga");
//    ls.printList();
//    ls.printReverse();
//
    
    //test append
//    LinkedList e1;
//    e1.insertToFront("Athos");
//    e1.insertToFront("Porthos");
//    e1.insertToFront("Aramis");
//    LinkedList e2;
//    e2.insertToFront("Robin");
//    e2.insertToFront("Batman");
//    e1.append(e2); // adds contents of e2 to the end of e1
//    string s;
//    assert(e1.size() == 5 && e1.get(3, s) && s == "Batman");
//    assert(e2.size() == 2 && e2.get(1, s) && s == "Robin");

    
//    assert(BaoBao.size() == 5 && Owners.size() == 6);
//    cout << "print: BaoBao is the cutest dog." << endl;
//    BaoBao.printList();
//    cout<< "print: Coco and Ruoyi are BaoBao's owners. " << endl;
//    Owners.printList();
//    BaoBao.append(Owners);
//    cout << "print: BaoBao is the cutest dog. Coco and Ruoyi are BaoBao's owners. " << endl;
//    BaoBao.printList();
//    assert(BaoBao.size() == 11 && Owners.size() == 6);
    
    //test reverse list
    
//    LinkedList e1;
//    e1.insertToFront("Jim");
//    e1.insertToFront("Oz");
//    e1.insertToFront("Paul");
//    e1.insertToFront("Kevin");
//    e1.reverseList(); // reverses the contents of e1
//    string s;
//    assert(e1.size() == 4 && e1.get(5, s) == false && s == "");
//    assert(e1.size() == 4 && e1.get(0, s) && s == "Jim");
//    assert(e1.get(1,s) == true && s == "Oz");
//    assert(e1.get(5,s) == false && s == "Oz");

    
    //test swap
    
//    LinkedList e1;
//    e1.insertToFront("A");
//    e1.insertToFront("B");
//    e1.insertToFront("C");
//    e1.insertToFront("D");
//    LinkedList e2;
//    e2.insertToFront("X");
//    e2.insertToFront("Y");
//    e2.insertToFront("Z");
//    e1.swap(e2); // exchange contents of e1 and e2
//    string s;
//    assert(e1.size() == 3 && e1.get(0, s) && s == "Z");
//    assert(e2.size() == 4 && e2.get(2, s) && s == "B");

//    BaoBao.swap(Owners);
//    cout << "print: Coco and Ruoyi are BaoBao's owners. " << endl;
//    BaoBao.printList();
//    cout << "print: BaoBao is the cutest dog." << endl;
//    Owners.printList();
//    assert(BaoBao.size() == 6 && Owners.size() == 5);
//
//    string x = "happy";
//    assert(BaoBao.get(11,x) == false);
//    assert(BaoBao.get(10,x) == true);
//    cout << "print: owners." << endl;
//    cout << x << endl;
//    assert(BaoBao.get(2,x) == true);
//    cout << "print: the" << endl;
//    cout << x << endl;
    
    LinkedList cc1;
    
    cc1.insertToFront("happy");
    
    LinkedList cc2 = cc1;
    
    cc2.printList();
    
    cout << "all the test past!" << endl;
}
