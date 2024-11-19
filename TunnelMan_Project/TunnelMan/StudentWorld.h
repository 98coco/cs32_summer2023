#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"

#include <cstdlib>
#include <algorithm>

#include <string>
#include <vector>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir); //constructor
    ~StudentWorld(); //destructor

    //mandatory implementation
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
    //earth removal function
    bool digEarth(int x, int y);
    //check earth
    bool checkEarth(int x,int y);
    
    //checks outer boundaries
    bool outerBoundaries(int x, int y);
    
    //accessors and additions
    const std::vector<GameObjects*> getGameObjVec(); //giving us the whole vector
    void addObjToVec(GameObjects* objs);
    TunnelMan* getTunnelManPtr();
    Earth* getEarthArr(int x, int y); //pass in 2 parameters
    
    //oil
    void studentsetOil(int L); //will be called in actor cpp
    
    void setSonarField(int s); //for when TM finds the sonar

    
private:
    int m_currLevel;
    int m_probabilityOfHardCore;
    int m_numsOfProtestor;
        
    //helps validate and change a coordinate as we intialize
    void validChangeCoor(int boundX, int boundY, int &coorX, int &coorY);
    
    int m_AddProtestorTick; 
    
    //add data structure that can keep our objects here
    TunnelMan *tunnelManPtr;
    Earth *earthLayoutArr[64][64]; //contains earth objects
    std::vector <GameObjects*> gameObjects;
    
    //creating earth
    void fillWholeEarth();
    void createMineShaft();
    void makeTopEmpty();
    
    //distribution objects
    void spreadGold(int G);
    void spreadOil(int L);
    void spreadBoulder(int B);
    
    //amount of sonar and water and oild
    int m_sonarNeeded;
    
    int m_sonarOnField; //has to always be 1 in chance
    int m_oilOnField; //represents the oil we have created for this world

    //boundaries for generating objects
    bool objMineShaftBounds(int x, int y);
        
    //Display Text Of TM information
    void setDisplay();
    std::string stringFormat(unsigned int level,int lives,int health,int squirts,int gold,int barrelsLeft,int sonar,int score);
    
    bool earthOrBoulder(int x, int y); //check to see if overlapping will occur

    
};

#endif // STUDENTWORLD_H_
