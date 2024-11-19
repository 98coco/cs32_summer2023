//
//  CricketTeam.cpp
//  CS 32 Project 2
//
//  Created by Coco Li on 7/15/23.
//

#include "CricketTeam.h"
using namespace std;



CricketTeam :: CricketTeam(){  //constructor --> creating an empty list
    head = nullptr;
    tail = nullptr; //check tail
    
}

CricketTeam :: CricketTeam(const CricketTeam& rhs){ // copy constructor
    
    Node *rhsTracker = rhs.head; //helping us keep track
    Node *lhsPrevNode;
    if (rhs.head == nullptr && rhs.tail == nullptr){ // if rhs is an empty list
        head = nullptr; //make this an empty list
        tail = nullptr;
    }
    else{
        Node *createFirstNode = new Node;
        head = createFirstNode; //link this list's head to the first node
        createFirstNode -> m_firstName = rhsTracker -> m_firstName; //copy the values from the first rhs node to this list
        createFirstNode -> m_lastName = rhsTracker -> m_lastName;
        createFirstNode -> m_jerseyNumber = rhsTracker -> m_jerseyNumber;
        createFirstNode -> prev = nullptr; //since it is first on the list it does not point to anything above
        Node *createNewNode = new Node;
        createFirstNode -> next = createNewNode;
        lhsPrevNode = createFirstNode; //helps us keep track of our previous node of the lhs as we move on
        rhsTracker = rhsTracker -> next; //move to next element
        while (rhsTracker != nullptr && rhsTracker -> next != nullptr){
            createNewNode -> m_firstName = rhsTracker -> m_firstName;  //copy first name
            createNewNode -> m_lastName = rhsTracker -> m_lastName; //copy last name
            createNewNode -> m_jerseyNumber = rhsTracker -> m_jerseyNumber;
            createNewNode -> next = new Node; //have the next point to a new node
            createNewNode -> prev = lhsPrevNode; //have previous take the address of previous node
            lhsPrevNode = createNewNode; //helps us keep track of our previous node of the lhs as we move on
            rhsTracker = rhsTracker -> next; //copy next element
            createNewNode = createNewNode -> next; //update createNewNode to be in the next node
        }
        if (rhsTracker != nullptr && rhsTracker -> next == nullptr){ //we have reached the last element
            createNewNode -> m_firstName = rhsTracker -> m_firstName;
            createNewNode -> m_lastName = rhsTracker -> m_lastName;
            createNewNode -> m_jerseyNumber = rhsTracker -> m_jerseyNumber;
            createNewNode -> prev = lhsPrevNode;
            createNewNode -> next = nullptr;
            tail = createNewNode;
        }
    }
}

CricketTeam :: ~CricketTeam(){
    Node *p = head;
    while (p != nullptr){
        Node *n = p -> next; //keeps the next node's address as we delete the current node's address
        delete p; //delete the current node we are at
        p = n;
    }
}

const CricketTeam& CricketTeam:: operator= (const CricketTeam& rhs){ //assignment operator
    if(&rhs == this){
        return *this;
    }
    
    //destruct lhs
    while (head != nullptr && head -> next != nullptr){
        Node *deleteLHSNode = head;
        head = head -> next;
        delete deleteLHSNode;
        deleteLHSNode = head;
    }
    if (head != nullptr && head -> next == nullptr){  //last node
        Node *lastDeleteLHS = head;
        delete lastDeleteLHS;
    }
    //copy construct
    Node *rhsTracker = rhs.head; //helping us keep track
    Node *lhsPrevNode;
    if (rhs.head == nullptr && rhs.tail == nullptr){ // if rhs is an empty list
        head = nullptr; //make this an empty list
        tail = nullptr;
    }
    else{
        Node *createFirstNode = new Node;
        head = createFirstNode; //link this list's head to the first node
        createFirstNode -> m_firstName = rhsTracker -> m_firstName; //copy the values from the first rhs node to this list
        createFirstNode -> m_lastName = rhsTracker -> m_lastName;
        createFirstNode -> m_jerseyNumber = rhsTracker -> m_jerseyNumber;
        if (rhs.cricketerCount() == 1){
            createFirstNode -> prev = nullptr;
            createFirstNode -> next = nullptr;
        }
        else{
            createFirstNode -> prev = nullptr; //since it is first on the list it does not point to anything above
            Node *createNewNode = new Node;
            createFirstNode -> next = createNewNode;
            lhsPrevNode = createFirstNode; //helps us keep track of our previous node of the lhs as we move on
            rhsTracker = rhsTracker -> next; //move to next element
            while (rhsTracker != nullptr && rhsTracker -> next != nullptr){
                createNewNode -> m_firstName = rhsTracker -> m_firstName;  //copy first name
                createNewNode -> m_lastName = rhsTracker -> m_lastName; //copy last name
                createNewNode -> m_jerseyNumber = rhsTracker -> m_jerseyNumber;
                createNewNode -> next = new Node; //have the next point to a new node
                createNewNode -> prev = lhsPrevNode; //have previous take the address of previous node
                lhsPrevNode = createNewNode; //helps us keep track of our previous node of the lhs as we move on
                rhsTracker = rhsTracker -> next; //copy next element
                createNewNode = createNewNode -> next; //update createNewNode to be in the next node
            }
            if (rhsTracker != nullptr && rhsTracker -> next == nullptr){ //we have reached the last element
                createNewNode -> m_firstName = rhsTracker -> m_firstName;
                createNewNode -> m_lastName = rhsTracker -> m_lastName;
                createNewNode -> m_jerseyNumber = rhsTracker -> m_jerseyNumber;
                createNewNode -> prev = lhsPrevNode;
                createNewNode -> next = nullptr;
                tail = createNewNode;
            }
        }
    }
    return *this;
}

bool CricketTeam :: noTeam() const{
    if (head == nullptr && tail == nullptr){
        return true;
    }
    return false;
}

int CricketTeam:: cricketerCount() const{
    int sizeOfTeam = 0;
    Node *p = head;
    if (p == nullptr){
        return sizeOfTeam;
    }
    while (p != nullptr){
        sizeOfTeam++;
        p = p-> next;
    }
    return sizeOfTeam;
}

bool CricketTeam:: addCricketer(const string& firstName, const string& lastName, const CricketType& value){ //value here is the jersey number

    Node *p = head;
    Node *newNode;
    if (head == nullptr && tail == nullptr){ //empty list
        p = new Node;
        p -> m_lastName = lastName;
        p -> m_firstName = firstName;
        p -> m_jerseyNumber = value;
        p -> prev = nullptr; //because it is the only node in the list and has nothing to point above
        p -> next = nullptr; //nothing to point to
        head = p;
        tail = p;
        return true;
    }
    else{ //list isn't empty
        while (p != nullptr && p -> next != nullptr){ //not at the last element
            if ((lastName > p -> m_lastName && lastName < p -> next -> m_lastName) || (lastName == p -> m_lastName && firstName > p -> m_firstName && firstName < p -> next -> m_firstName)){ // found our target node want to insert below p
                newNode = new Node;
                newNode -> m_lastName = lastName; //assigning last name to the new node
                newNode -> m_firstName = firstName; //assigning first name to the new node
                newNode -> m_jerseyNumber = value; //assigning jersey num to the new node
                newNode -> prev = p;  //making the prev in the newNode the curr node p is pointing to
                newNode -> next = p -> next; //making the next in the new node the next adress node p holds
                p -> next -> prev = newNode; //the node below p before we created the new node will now have the address of the newNode for its prev
                p -> next = newNode; //p pointing to next will now hold the address of the new node
                if (newNode -> prev == nullptr){
                    head = newNode; //first on the list
                }
                if (newNode -> next == nullptr){
                    tail = newNode; //last on the list
                }
                return true;
            }
            else if ((lastName < p -> m_lastName)|| (lastName == p -> m_lastName && firstName < p -> m_firstName)){
                newNode = new Node;
                newNode -> m_lastName = lastName; //assigning last name to the new node
                newNode -> m_firstName = firstName; //assigning first name to the new node
                newNode -> m_jerseyNumber = value; //assigning jersey num to the new node
                newNode -> prev = p -> prev;
                newNode -> next = p;
                p -> prev = newNode;
                if (newNode -> prev == nullptr){
                    head = newNode; //first on the list
                }
                if (newNode -> next == nullptr){
                    tail = newNode; //first on the list
                }
                return true;
            }
            else if (lastName == p -> m_lastName && firstName == p ->m_firstName){
                return false;
            }
            p = p-> next;
        }
        if (p != nullptr && p -> next == nullptr){ //add to last element of the lsit
            if (lastName == p -> m_lastName && firstName == p ->m_firstName){
                return false;
            }
            newNode = new Node;
            newNode -> m_lastName = lastName; //assigning last name to the new node
            newNode -> m_firstName = firstName; //assigning first name to the new node
            newNode -> m_jerseyNumber = value; //assigning jersey num to the new node
            if ((lastName < p -> m_lastName) ||(lastName == p -> m_lastName && firstName < p -> m_firstName) ){ //add this new node before the last item of our list
                if (this -> cricketerCount() == 1){
                    newNode -> prev = nullptr;
                    newNode -> next = p;
                    p -> prev = newNode;
                    head = newNode;
                    return true;
                }
                Node *nodeAbove = p -> prev;
                newNode -> prev = nodeAbove;
                newNode -> next = p;
                nodeAbove -> next = newNode;
                p -> prev = newNode;
                return true;
            }
            else if ((lastName > p -> m_lastName) || (lastName == p -> m_lastName && firstName > p -> m_firstName)){ //add this new node to the bottom of our list
                newNode -> prev = p;
                newNode -> next = nullptr; //bc this is now the last item in our list
                p -> next = newNode;
                tail = newNode;
                return true;
            }
        }
    }
    return false;
}

bool CricketTeam:: substituteCricketer(const std::string& firstName, const std::string& lastName, const CricketType & value){
    Node *curr =head;
    while (curr != nullptr ){
        if (curr -> m_firstName == firstName && curr -> m_lastName == lastName){
            curr -> m_jerseyNumber = value; //changing the value it maps to to the third parameter
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

bool CricketTeam::addOrSubstitute(const std::string& firstName, const std::string& lastName, const CricketType& value){
    if (substituteCricketer(firstName, lastName, value) == true){
        return true;
    }
    else{
        addCricketer(firstName, lastName, value);
        return true;
    }
    return true;
}

bool CricketTeam::releaseCricketer(const std::string& firstName, const std::string& lastName){
    Node *curr = head;
    if (head == nullptr && tail == nullptr){ //empty list
        return false;
    }
    if (head -> m_firstName == firstName && head -> m_lastName == lastName){
        Node *temp = head;
        head = head -> next; //go to the next item of the list to change the previous in that node
        delete temp; //temp is currently pointing at the first item and we want to delete that first item
        return true;
    }
    while (curr != nullptr && curr -> next != nullptr){
        if (curr -> m_firstName == firstName && curr -> m_lastName == lastName){ //found the node we want to delete
            Node* tempAbove = curr -> prev;
            Node* tempBelow = curr -> next;
            tempAbove -> next = tempBelow;
            tempBelow -> prev = tempAbove;
            delete curr; //delete our current element
            curr = tempBelow;
            return true;
        }
        curr = curr -> next;
    }
    if (curr != nullptr && curr -> next == nullptr){
        if (curr -> m_firstName == firstName && curr -> m_lastName == lastName){
            Node *temp = tail;
            tail = tail -> prev; //node above will become the new last node
            tail -> next = nullptr; //node above 's next will be node bc nothing to point to at bottom
            delete temp;
            return true;
        }
    }
    return false;
}

bool CricketTeam::rosteredOnCricketTeam(const std::string& firstName, const std::string& lastName)const {
    Node *p = head;
    if (head == nullptr && tail == nullptr){
        return false; //no elements
    }
    while (p != nullptr){
        if (firstName == p -> m_firstName && lastName == p-> m_lastName){
            return true;
        }
        p = p-> next;
    }
    return false;
}

bool CricketTeam::searchForCricketer(const std::string &firstName, const std::string &lastName, CricketType &value) const{
    Node *p = head;
    if (head == nullptr && tail == nullptr){
        return false; //no elements
    }
    while (p!= nullptr){
        if(firstName == p -> m_firstName && lastName == p-> m_lastName){
            value = p -> m_jerseyNumber;
            return true;
        }
        p = p -> next;
    }
    return false;
}

bool CricketTeam::checkTeamForCricketer(int i, std::string &firstName, std::string &lastName, CricketType &value)const {
    int elemInList = this -> cricketerCount(); //get elems in list
    Node *p = head;
    if ( 0 > i || i > elemInList){
        return false; //out of bounds
    }
    else if (head == nullptr && tail == nullptr){
        return false; //no elements
    }
    else{
        int numTracker = 0;
        for (int k = 0; k < elemInList; k++){
            if (numTracker == i){
                firstName = p-> m_firstName;
                lastName = p-> m_lastName;
                value = p->m_jerseyNumber;
                return true;
            }
            numTracker++;
            p = p -> next;
        }
    }
    return false;
}

void CricketTeam::tradeCricketTeams(CricketTeam &other){
    Node *tempHead = head;
    Node *tempTail = tail;
    head = other.head;
    tail = other.tail;
    other.head = tempHead;
    other.tail = tempTail;
}

bool mergeCricketers(const CricketTeam & odOne,const CricketTeam & odTwo, CricketTeam & odJoined){
    //return true unless the full names are the same but values are different
    int sizeOdOne = odOne.cricketerCount();
    int sizeOdTwo = odTwo.cricketerCount();
    int sizeOdJoined = odJoined.cricketerCount();
    string odOneFN, odOneLN, odTwoFN, odTwoLN, odJoinedFN, odJoinedLN;
    CricketType odOneV,odTwoV, odJoinedV;
    //null safety check
    if (sizeOdOne == 0 && sizeOdTwo == 0){ //if both empty, odJoined should be empty and return true
        while (sizeOdJoined > 0){
            int i = 0;
            odJoined.checkTeamForCricketer(i,odJoinedFN, odJoinedLN,odJoinedV); //getting the names
            odJoined.releaseCricketer(odJoinedFN, odJoinedLN); //removing the names
            sizeOdJoined--;
        }
        return true;
    }
    else if (sizeOdOne != 0 && sizeOdTwo == 0){
        odJoined = odOne; // assignment operator --> assignment operator deals w aliasing
        return true;
    }
    else if (sizeOdOne == 0 && sizeOdTwo != 0){
        odJoined = odTwo; // assignment operator --> assignment operator deals w aliasing
        return true;
    }
    else{
        CricketTeam temp;
        int i = 0, j = 0; // i tracks one, j tracks 2, diff track if we have same full name but diff v
        bool diff = false;
        while (i < sizeOdOne || j < sizeOdTwo){
                odOne.checkTeamForCricketer(i, odOneFN, odOneLN, odOneV);
                odTwo.checkTeamForCricketer(j, odTwoFN, odTwoLN, odTwoV);
                if ((odOneFN == odTwoFN) && (odOneLN == odOneLN) && (odOneV == odTwoV)){
                    temp.addCricketer(odOneFN, odOneLN, odOneV);
                    i++;
                    j++;
                }
                else if(odTwoLN == odOneLN && odOneFN == odTwoFN && odTwoV != odOneV){ //dont add if diff values
                    i++;
                    j++;
                    diff = true;
                }
                else if((odOneLN < odTwoLN) || (odOneLN == odTwoLN && odOneFN < odTwoFN)){
                    temp.addCricketer(odOneFN, odOneLN, odOneV);
                    i++;
                }
                else if((odTwoLN < odOneLN) || (odOneLN == odTwoLN && odTwoFN < odOneFN)){
                    temp.addCricketer(odTwoFN, odTwoLN, odTwoV);
                    j++;
                }
                if (i >= sizeOdOne){
                    break;
                }
                if (j >= sizeOdTwo){
                    break;
                }
            }
            //out of the loop
            while (i < sizeOdOne){
                odOne.checkTeamForCricketer(i, odOneFN, odOneLN, odOneV);
                temp.addCricketer(odOneFN, odOneLN, odOneV);
                i++;
            }
            while (j < sizeOdTwo){
                odTwo.checkTeamForCricketer(j, odTwoFN, odTwoLN, odTwoV);
                temp.addCricketer(odTwoFN, odTwoLN, odTwoV);
                j++;
            }
            odJoined = temp; //assign odJoined to temp
            if (diff == true){
                return false; //because we had an element that was the same but diff value
            }
            return true;
    }
    return false;
}

void checkCricketers (const std::string& fsearch, const std::string& lsearch, const CricketTeam& odOne, CricketTeam& odResult){
    CricketTeam temp;
    int sizeofOdOne = odOne.cricketerCount();
    string odOneFN, odOneLN;
    CricketType odOneV;
    int i = 0;
    while (i < sizeofOdOne){
        odOne.checkTeamForCricketer(i,odOneFN,odOneLN, odOneV);
        if ((odOneFN == fsearch && odOneLN == lsearch) || (odOneFN == fsearch && lsearch == "*") || (fsearch == "*" && odOneLN == lsearch) || (fsearch == "*" && lsearch == "*")){
            temp.addCricketer(odOneFN, odOneLN, odOneV);
        }
        i++;
    }
    odResult = temp;
}


