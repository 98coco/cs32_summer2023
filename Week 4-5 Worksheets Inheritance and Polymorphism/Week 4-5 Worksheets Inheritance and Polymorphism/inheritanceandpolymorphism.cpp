//
//  main.cpp
//  Week 4-5 Worksheets Inheritance and Polymorphism
//
//  Created by Coco Li on 7/29/23.
//

#include <iostream>
using namespace std;

//POLYMORPHISM AND INHERITANCE

//1) What does this print out? How do i make i print out I'm Gene (look at the main for what it prints out)

//class LivingThing {
//        public:
//      virtual  void intro() { cout << "I’m a living thing" << endl; }
//};
//
//class Person : public LivingThing {
//public:
//   virtual void intro() { cout << "I’m a person" << endl; }
//};
//
//class UniversityAdministrator : public Person {
//public:
//    virtual void intro()
//    {
//    cout << "I’m a university administrator" << endl;
//    }
//};
//
//class Chancellor : public UniversityAdministrator {
//
//public:
//    virtual void intro() { cout << "I’m Gene" << endl; }
//
//};

//2) create the complete implementation of each constructor so that the program compiles
//class Animal {
//       public:
//       Animal(string name);
//       private:
//       string m_name;
//};
//
//class Cat : public Animal {
//public:
//    Cat(string name, int amountOfYarn): Animal(name), m_amountOfYarn(amountOfYarn){};
//private:
//    int m_amountOfYarn;
//};
//
//class Himalayan : public Cat {
//    public:
//    Himalayan(string name, int amountOfYarn): Cat(name, amountOfYarn){};
//};
//
//class Siamese: public Cat {
//public:
//    Siamese(string name, int amountOfYarn, string toyName): Cat(name,amountOfYarn), m_toyName(toyName){};
//       private:
//             string m_toyName;
//};

//3)What is the output of the following code?


//class Pet {
// public:
//      Pet() { cout << "Pet" << endl; }
//      ~Pet() { cout << "~Pet" << endl; }
// };
//
//// This is an unusual class that derives from Pet but also
//// contains a Pet as a data member.
// class Dog : public Pet {
// public:
//      Dog() { cout << "Woof" << endl; }
//      ~Dog() { cout << "Dog ran away!" << endl; }
// private:
//     Pet buddy;
// };

// Pet --> base class
// Pet --> Pet provate member is Dog
// Woof --> construction of Dog
// ~Pet
//undefined behavior bc pet's destructor isnt virtual --> why isnt it the other way around (outside in)

//4) suppose we change some stuff to class pet. What is the output of this?

//class Pet {
//  public:
//       Pet() { cout << "Pet" << endl; }
//       virtual ~Pet() { cout << "~Pet" << endl; }
//  };
//
//class Dog : public Pet {
//public:
//     Dog() { cout << "Woof" << endl; }
//    virtual ~Dog() { cout << "Dog ran away!" << endl; }
//private:
//    Pet buddy;
//};

//Pet base class
//Pet member variable
//Woof dog
//Dog ran away destruct dof
//~Pet member var
//~Pet base class


// 5.) The following code has several errors. Rewrite the code so that it would successfully compile. Try to catch the errors without the use of a compiler.

//BEfore
//class LivingThing {
//   private:
//    int age;
//};
//   class Person : public LivingThing {
//   public:
//        Person(int a) { age = a; }
//        void birthday() {
//age++; }
//};

//error --> age is a private member of Living Thing

//After
//class LivingThing {
//public:
//    LivingThing(int a) : age(a){};
//    void mybirthday(){age++; }
//private:
//    int age;
//};
//   class Person : public LivingThing {
//   public:
//       Person(int a):LivingThing(a){};
//       void birthday(){mybirthday();}; // can do this because caling to base class
//};

//6) Would this compile in c++
//Initial answer --> not because you are trying to have class A be a derived class of B and class B to be a dervived class of A

//class B;
//class A : public B { ... code for A ... };
//class B : public A { ... code for B ... };

//7 Examine the following code and determine its output.

class A {
public:
A() : m_val(0) {
     cout << "What a wonderful world! " << m_val << endl;
}
virtual ~A() { cout << "Guess this is goodbye " << endl; }
virtual void saySomething() = 0;
    virtual int giveMeSomething() = 0;
    private:
         int m_val;
};

class B : public A {
public:
     B() : m_str("me"), m_val(1) {
           cout << m_str << " has just been birthed."  << endl;
     }
     B(string str, int val) : m_str(str), m_val(val) {
           cout << "More complex birth " << m_str << endl;
     }
     ~B() {
           cout << "Why do I have to leave this world!" << endl;
     }
     virtual void saySomething() {
           cout << "Coming in from " << m_str << " with "
                << giveMeSomething() << endl;
}
virtual int giveMeSomething() { return m_val*5; } private:
int m_val;
string m_str;
};

class C {
public:
    C() : m_val(2) {
        m_b = new B("C", m_val);
        cout << "Hello World!!" << endl;
    }
    C(const B& b, int val) :  m_val(val) {
        m_b = new B(b);
        cout << m_b->giveMeSomething() << endl;
    }
    ~C() {
        m_b->saySomething();
        delete m_b;
        cout << "Goodbye world!" << endl;
    }
private:
    B* m_b;
    int m_val;
};

//
//
//


int main() {
    
//    LivingThing* thing = new Chancellor();
//    thing->intro();  //im a living thing without the virtual keyword; I'm Gene with virtual
    
//    Pet* milo = new Dog;
//    delete milo;

    B* b_arr = new B[3];
         for(int i = 0; i < 3; i++) {
               b_arr[i].saySomething();
         }
         B b("B", 5);
         A* a = &b;
         cout << a->giveMeSomething() << endl;
         C c;
         C c2(b, b.giveMeSomething());
         delete [] b_arr;

    
}
