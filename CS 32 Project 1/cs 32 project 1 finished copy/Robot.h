//
//  Robot.h
//  CS 32 Project 1
//
//  Created by Coco Li on 6/29/23.
//

#ifndef ROBOT_H
#define ROBOT_H

class Arena; // This is needed to let the compiler know that Arena is a
            // type name, since it's mentioned in the Robot declaration.
class Robot
{
public:
    // Constructor
    Robot(Arena* ap, int r, int c);
    //Accessor
    int row() const;
    int col() const;
    
    //mutators
    void move();
    bool takeDamageAndLive();
    
private:
    Arena* m_arena;
    int m_row;
    int m_col;
    int m_health;
};

#endif /* Robot_h */
