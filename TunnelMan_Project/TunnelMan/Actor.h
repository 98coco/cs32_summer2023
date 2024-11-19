#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class StudentWorld;

//Global enumerations to help identify objects
enum GameObjectsEnums{
    TUNNELMAN,
    REGULAR_PROTESTOR,
    HARDCORE_PROTESTOR,
    SQUIRT,
    BOULDER,
    GOLD_NUGGETS,
    SONAR_KIT,
    BARREL_OF_OIL,
    EARTH,
    WATER
};

class GameObjects: public GraphObject{
public:
    GameObjects(int ImageID,int startX, int startY, Direction dir, double size, unsigned int depth,bool aliveStatus, StudentWorld *studentWorld);
    virtual ~GameObjects() = 0; //destructor
    virtual void doSomething() = 0;
    void setAliveState(bool aliveStatus); //each object will set their alive or dead state by calling this function --> items will have diff function because it can still be alive but not visible
    bool getAliveState();
    StudentWorld *studentWorldPtr; //can use this in any of our objects
    bool withinRadius(double radius, int x, int y); //calculate the euclidian distance --> for withing a radius
        
    virtual GameObjectsEnums getTypeOfObj() = 0; //give us a pointer to the gameObject
    
    void ticksCountdown();
    void setTicksForCountdown(int ticks); //protestors and items use this tick
    int getTicksPassed();

    void annoyMe(int deductHealth); //deducts the health of an object --> same implementation across classes because people will just lose points
    int getHealth();
    void setHealth(int h); 
    
    void setSound(bool onOrOff);
    bool getSound();
    
private:
    virtual bool canMove(int x, int y); //for objects that can move
    bool m_aliveStatus;
    int m_ticks;
    int m_health; //for the people class specifically
    bool m_soundOnOrOff;
};

class Earth:public GameObjects{
public:
    Earth(int startX, int startY, StudentWorld *studentWorld);
    ~Earth();
    void doSomething();
    GameObjectsEnums getTypeOfObj();

};

class TunnelMan:public GameObjects{
public:
    TunnelMan(StudentWorld *studentWorld);
    ~TunnelMan();
    void doSomething();
    GameObjectsEnums getTypeOfObj();
    
    //make setters a getters for items

    void setWaterSquirt(int s);
    int getWaterSquirt();
    void setGold(int g);
    int getGold();
    void setSonar(int s);
    int getSonar();
    
    //checking if TM can add squirt at location x y --> will also be used by squirt
    bool tunnelManDirectSquirt(int x, int y);

private:
    bool canMove(int x , int y); //checks if tunnelMan can move to the next coordinate
    void tunnelManSquirts(); //func that allows tm to squirt
    void tunnelManLeaveGold(); //func that tunnelman uses to drop gold
    void useSonarKit();
    int m_waterForSquirt;
    int m_SonarSupply;
    int m_goldNuggets;
    int m_oil;
};


//(int ImageID,int startX, int startY, Direction dir, double size, unsigned int depth,bool aliveStatus, StudentWorld *studentWorld)

class Protestors:public GameObjects{ //have to have this class because protestors are two subclasses that share some common functionality  but also has some differing functionality
public:
    Protestors(int ImageID, double size, unsigned int depth,bool aliveStatus, StudentWorld *studentWorld, int health);
    ~Protestors();
    void moveBackAndForth();
    
    bool getRestingState();
    void setRestingState(bool resting);

    int getYellTick();
    void setYellTick(int t); //have ro reset
    
    void doSomething();
    
private:
    int m_amtToWalk;
    bool m_leaveOilState;
    bool m_restingState;
    bool m_nonRestingState;
    int m_currLevel;
    
    int m_yellTick;
    
};

class RegularProtestor:public Protestors{
public:
    RegularProtestor(StudentWorld *studentWorld);
    //CONSTRUCTOR HEALTH POINTS ARE DIFF
   ~ RegularProtestor();
    GameObjectsEnums getTypeOfObj();
};

class HardCoreProtestor:public Protestors{
public:
    HardCoreProtestor(StudentWorld *studentWorld);
    //CONSTRUCTOR HEALTH POINTS ARE DIFF
    ~HardCoreProtestor();
    GameObjectsEnums getTypeOfObj();
};


class Items: public GameObjects{
public:
    Items(int ImageID,int startX, int startY, Direction dir, double size, unsigned int depth, bool aliveStatus, bool tempState, bool permanentState,StudentWorld *studentWorld,bool pickUpTM); //constructor
    virtual ~Items(); //destructor
//    void setPickUpStatusTM(bool shouldIBePickedUpByTM); //will set the pickUp status if item was picked up by TM
    bool getPickUpStatusTM(); //will get the pickUp status if item was picked up by TM
//    void setTempState(bool tempState); // set if object is in a temp state
    bool getTempState(); //check if object is in a temp state
//    void setPermanentState(bool permanentState); //set if object is in a permanent state
    bool getPermanentState(); //cgecj if object is in a permanent state
    
private:
    bool m_pickByTM;
    bool m_tempState;
    bool m_permanentState;
};

class Squirt:public GameObjects{
public:
    Squirt(StudentWorld *studentWorld, int startX, int startY, Direction dir);
    ~Squirt();
    void doSomething();
    GameObjectsEnums getTypeOfObj();
private:
    int m_distanceLeft;
};

class Boulder:public GameObjects {
public:
    Boulder(StudentWorld *studentWorld,int startX, int startY);
    ~Boulder();
    virtual void doSomething();
    GameObjectsEnums getTypeOfObj();
    
private:
    bool m_stableState; //these states are only specific to the boulder
    bool m_fallingState;
    bool m_waitingState;
};


//temp state for protestors
    //when created by pressing x the gold nugget is in a temp state
//permanent state for tm
    //when created in student would it is in a permanent state
class GoldNuggets:public Items{
public:
    GoldNuggets(int startX, int startY, bool permState,bool tempState, bool tmPickup, bool pPickup, StudentWorld* studentWorld);
    ~GoldNuggets();
    virtual void doSomething();
    GameObjectsEnums getTypeOfObj();
private:
    bool m_pickByProtestor;
};

class Water : public Items{
public:
    Water(int startX,int startY, StudentWorld *studentWorld);
    ~Water();
    virtual void doSomething();
    GameObjectsEnums getTypeOfObj();
};

class SonarKit:public Items{
public:
    SonarKit(int startX, int startY, StudentWorld *studentWorld);
    ~SonarKit();
    virtual void doSomething();
    GameObjectsEnums getTypeOfObj();
};

class BarrelOfOil:public Items{
public:
    BarrelOfOil(StudentWorld *studentWorld,int startX, int startY);
    ~BarrelOfOil();
    virtual void doSomething();
    GameObjectsEnums getTypeOfObj();
};


#endif // ACTOR_H_
