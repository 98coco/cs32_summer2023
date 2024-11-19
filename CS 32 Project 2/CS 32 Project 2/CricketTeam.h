//
//  CricketTeam.h
//  CS 32 Project 2
//
//  Created by Coco Li on 7/15/23.
//

#ifndef CRICKETTEAM_H
#define CRICKETTEAM_H

#include <iostream>
#include <string>

typedef std::string CricketType; //can name whatever and change it
//typedef int CricketType; //can name whatever and change it
//typedef double CricketType; //can name whatever and change it

class CricketTeam
{
public:
    CricketTeam();
    CricketTeam(const CricketTeam& rhs);
    const CricketTeam& operator=(const CricketTeam& rhs);
    ~CricketTeam();
    bool noTeam() const;
    int cricketerCount() const;
    bool addCricketer(const std::string& firstName, const std::string& lastName, const CricketType& value);
    bool substituteCricketer(const std::string& firstName, const std::string& lastName, const CricketType & value);
    bool addOrSubstitute(const std::string& firstName, const std::string& lastName, const CricketType& value);
    bool releaseCricketer(const std::string& firstName, const std::string& lastName);
    bool rosteredOnCricketTeam(const std::string& firstName, const std::string& lastName) const;
    bool searchForCricketer(const std::string& firstName, const std::string& lastName, CricketType& value) const;
    bool checkTeamForCricketer(int i, std::string& firstName, std::string& lastName, CricketType & value) const;
    void tradeCricketTeams(CricketTeam& other);
        
private:
    
    struct Node{
        std::string m_firstName;
        std::string m_lastName;
        CricketType m_jerseyNumber;
        Node *next; //next element
        Node *prev; //prev element
        
    };
    
    Node *head; //will point to the beginning of the linked list
    Node *tail; //will point to the end of the linked list
    
};

bool mergeCricketers(const CricketTeam & odOne,const CricketTeam & odTwo, CricketTeam & odJoined);
void checkCricketers (const std::string& fsearch, const std::string& lsearch, const CricketTeam& odOne, CricketTeam& odResult);

#endif /* CricketTeam_h */
