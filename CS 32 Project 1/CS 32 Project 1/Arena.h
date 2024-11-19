//
//  Arena.h
//  CS 32 Project 1
//
//  Created by Coco Li on 6/29/23.
//

#ifndef ARENA_H
#define ARENA_H

class Player; 
class Robot;

#include <string>
#include "globals.h"
#include "Previous.h" // using the class

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();
    // Accessors
    int rows() const;
    int cols() const;
    Player* player() const;
    int robotCount() const;
    int nRobotsAt(int r, int c) const;
    void display(std::string msg) const;
    // Mutators
    bool addRobot(int r, int c);
    bool addPlayer(int r, int c);
    void damageRobotAt(int r, int c);
    bool moveRobots();
    Previous& thePrevious(); 
        
private:
    Previous m_PreviousClass;
    
    int m_rows;
    int m_cols;
    Player* m_player;
    Robot* m_robots[MAXROBOTS];
    int m_nRobots;
};

#endif /* Arena_h */
