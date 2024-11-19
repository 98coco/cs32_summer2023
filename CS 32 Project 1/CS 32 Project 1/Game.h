//
//  Game.h
//  CS 32 Project 1
//
//  Created by Coco Li on 6/29/23.
//

#ifndef GAME_H
#define GAME_H
class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();
    
    // Mutators
void play();
    
private:
    Arena* m_arena;
};

#endif /* Game_h */
