#include "Actor.h"
#include "StudentWorld.h"
#include "GameController.h"
#include <iostream>

using namespace std;

//Implementaion for Game Objects class
GameObjects::GameObjects(int ImageID,int startX, int startY, Direction dir, double size, unsigned int depth,bool aliveStatus,StudentWorld *studentWorld): GraphObject(ImageID, startX, startY,dir,size,depth) //constructor
{
    setVisible(true); //because all game objects are visible when they are intially created
    studentWorldPtr = studentWorld; //pointing to the world we are at
    m_aliveStatus = aliveStatus;
//    m_health = 100;
    m_soundOnOrOff = false; //sound always false when intialized
}

GameObjects::~GameObjects(){ //destructor for GameObjects --> can i leave like this since it is a pvf in our class declaration
    
}


void GameObjects::ticksCountdown(){ //help us countDown
    int currTicks = getTicksPassed();
    currTicks = currTicks -1;
    setTicksForCountdown(currTicks);
}

bool GameObjects::canMove(int x, int y){
    //derived classes that can move will ahve their own checks based on their do smth method
    return true;
}

void GameObjects::setAliveState(bool setAliveState){
    m_aliveStatus = setAliveState;
}

bool GameObjects::getAliveState(){
    return m_aliveStatus;
}

bool GameObjects::withinRadius(double radius, int x, int y){ //find distance between curr object and other object
    //check this
    int x2 = x+2; //other object ==> plus 2 for center
    int y2 = y+2;
    int x1 = getX()+2; //curr object
    int y1 = getY()+2;
    double distanceBetween = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    if (distanceBetween <= radius){ //within the radius of each other
        return true;
    }
    return false;
}

int GameObjects::getHealth(){
    return m_health;
}

void GameObjects::setHealth(int h){
    m_health += h;
}

void GameObjects:: annoyMe(int deductHealth){
    setHealth(deductHealth);
}

void GameObjects::setSound(bool onOrOff){
    m_soundOnOrOff = onOrOff;
}

bool GameObjects::getSound(){
    return m_soundOnOrOff;
}

//implementation for Earth

//x and y is being specified by studentWorld  class
//constructor
Earth::Earth(int x, int y,StudentWorld *studentWorld): GameObjects(TID_EARTH, x, y, right, 0.25, 3, true,studentWorld){ //true for alive
}

Earth::~Earth(){
    //destructor for Earth
}

void Earth:: doSomething(){ //because it does nothing
    return;
}

GameObjectsEnums Earth::getTypeOfObj(){
    return EARTH;
}

TunnelMan::TunnelMan(StudentWorld *studentWorld) : GameObjects(TID_PLAYER, 30, 60, right, 1.0, 0, true,studentWorld){ //true for alive status, false for being annoyed bc a TM cant be annoyed when it is in its default state
    m_waterForSquirt = 5; //move function increments the water in studentworld fromp previous level
    m_SonarSupply = 1;
    m_goldNuggets = 0; //move function increments the gold in studentworld fromp previous level
    setHealth(10);
}

TunnelMan :: ~TunnelMan(){
    //destructor
}

GameObjectsEnums TunnelMan::getTypeOfObj(){
    return TUNNELMAN;
}

void TunnelMan::setWaterSquirt(int s){
    m_waterForSquirt += s;
}

int TunnelMan::getWaterSquirt(){
    return m_waterForSquirt;
}

void TunnelMan::setGold(int g){
    m_goldNuggets += g;
}

int TunnelMan::getGold(){
    return m_goldNuggets;
}

void TunnelMan::setSonar(int s){
    m_SonarSupply += s;
}

int TunnelMan::getSonar(){
    return m_SonarSupply;
}

bool TunnelMan::canMove(int x, int y){
    //checks out of bounds
    bool canMove = true; //can move unless we find smth that block
    if (studentWorldPtr -> outerBoundaries(x, y) == false){
        canMove = false; //in bounds
    }
    //move around boulders
    for (int i = 0; i < studentWorldPtr -> getGameObjVec().size(); i++){
        if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == BOULDER){
            if (studentWorldPtr -> getGameObjVec()[i] -> withinRadius(3.0, x, y)){
                canMove = false;
            }
        }
    }
    return canMove;
}

bool TunnelMan:: tunnelManDirectSquirt(int x, int y){
    bool earthOrBoulder = false;
    for (int i = 0; i < studentWorldPtr -> getGameObjVec().size(); i++){
        if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == BOULDER){
            if (x == studentWorldPtr -> getGameObjVec()[i] ->getX() && y ==  studentWorldPtr -> getGameObjVec()[i] ->getY()){
                earthOrBoulder = true; //there is an earth or boulder at that location
            }
        }
    }
    if (studentWorldPtr -> getEarthArr(y, x)-> getAliveState() ==true){
        earthOrBoulder = true;
    }
    if (studentWorldPtr -> outerBoundaries(x, y) == false){ //out of grid bounds
        earthOrBoulder = true;
    }
    return earthOrBoulder;
}

void TunnelMan::tunnelManSquirts(){
    bool playSquirt = false;
    if (m_waterForSquirt != 0){
        if (getDirection() == left){
            if (tunnelManDirectSquirt(getX() - 4, getY())== false){
                Squirt* leftSquirt = new Squirt(studentWorldPtr, getX()-4, getY(), left);
                studentWorldPtr -> addObjToVec(leftSquirt);
                playSquirt = true;
            }
        }
        if (getDirection() == right){
            if (tunnelManDirectSquirt(getX() + 4, getY()) == false){
                Squirt* rightSquirt = new Squirt(studentWorldPtr, getX()+4, getY(), right);
                studentWorldPtr -> addObjToVec(rightSquirt);
                playSquirt = true;
            }
        }
        if (getDirection() == up){
            if (tunnelManDirectSquirt(getX(), getY() + 4) == false){
                Squirt* upSquirt = new Squirt(studentWorldPtr, getX(), getY()+4, up);
                studentWorldPtr -> addObjToVec(upSquirt);
                playSquirt = true;
            }
        }
        if (getDirection() == down){
            if (tunnelManDirectSquirt(getX(), getY() - 4) == false){
                Squirt* downSquirt = new Squirt(studentWorldPtr, getX(), getY()-4, down);
                studentWorldPtr -> addObjToVec(downSquirt);
                playSquirt = true;
                
            }
        }
    }
    if (playSquirt == true && m_waterForSquirt != 0){
        GameController::getInstance().playSound(SOUND_PLAYER_SQUIRT);
        playSquirt = false;
        m_waterForSquirt--;
    }
}
  
void TunnelMan::useSonarKit(){
    if (m_SonarSupply > 0){
        for (int i = 0; i< studentWorldPtr -> getGameObjVec().size(); i++){
            if (withinRadius(12.0, studentWorldPtr ->getGameObjVec()[i] -> getX(), studentWorldPtr ->getGameObjVec()[i] -> getY()) == true){
                //obj has to be alive to see
                if (studentWorldPtr ->getGameObjVec()[i] -> getAliveState() == true){
                    studentWorldPtr ->getGameObjVec()[i] -> setVisible(true);
                }
                m_SonarSupply = m_SonarSupply -1;
            }
        }
    }
    else if(m_SonarSupply == 0){
        return;
    }
}

void TunnelMan::tunnelManLeaveGold(){
    if (studentWorldPtr -> getTunnelManPtr() -> getGold() > 0){
        setGold(-1); //subtract one piece of gold from the inventory
        GoldNuggets *protestorsBribe = new GoldNuggets(studentWorldPtr ->getTunnelManPtr() ->getX(),studentWorldPtr ->getTunnelManPtr() ->getY(),false,true,false,true,studentWorldPtr);
        //permState = false; tempState = true; tmPickUp = false; pPickUp = true
        studentWorldPtr -> addObjToVec(protestorsBribe);
    }
}

void TunnelMan:: doSomething(){
    if (getAliveState() == false){
        return; //dont need to make visibility false because we alr turned it off
    }
    else{ //because TM is not dead yet we have to do something
        //have to make sure it does not overlap with a boulder
        //check the keys
        int ch;
        if (studentWorldPtr -> getKey(ch) == true){
            switch(ch){
                case KEY_PRESS_LEFT:
                    if (getDirection() == left){
                        if (canMove(getX()-1,getY())){ //validating the next spot using center
                            setSound(studentWorldPtr -> digEarth(getX()-1,getY())); //check to see if we can dig earth
                            if (getSound() == true){
                                GameController::getInstance().playSound(SOUND_DIG);
                                setSound(false);
                            }
                            moveTo(getX()-1,getY());
                            break;
                        }
                        break;
                    }
                    setDirection(left);
                    break;
                case KEY_PRESS_RIGHT:
                    if (getDirection() == right){
                        if (canMove(getX()+1,getY()) == true){ //validating the next spot using center
                            setSound(studentWorldPtr -> digEarth(getX()+1,getY()));
                            if (getSound() == true){
                                GameController::getInstance().playSound(SOUND_DIG);
                                setSound(false);
                            }
                            moveTo(getX()+1,getY());
                            break;
                        }
                        break;
                    }
                    setDirection(right);
                    break;
                case KEY_PRESS_UP:
                    if (getDirection() == up){
                        if (canMove(getX(),getY()+1) == true){ //validating the next spot using center
                            setDirection(up);
                            setSound(studentWorldPtr -> digEarth(getX(),getY()+1));
                            if (getSound() == true){
                                GameController::getInstance().playSound(SOUND_DIG);
                                setSound(false);
                            }
                            moveTo(getX(),getY()+1);
                            break;
                        }
                        break;
                    }
                    setDirection(up);
                    break;
                case KEY_PRESS_DOWN:
                    if (getDirection() == down){
                        if (canMove(getX(),getY()-1) == true){  //validating the next spot using center
                            setSound(studentWorldPtr -> digEarth(getX(),getY()-1));
                            if (getSound() == true){
                                GameController::getInstance().playSound(SOUND_DIG);
                                setSound(false);
                            }
                            moveTo(getX(),getY()-1);
                            break;
                        }
                        break;
                    }
                    setDirection(down);
                    break;
                    break;
                case KEY_PRESS_TAB:
                    tunnelManLeaveGold();
                    break;
                case KEY_PRESS_SPACE:
                    tunnelManSquirts();
                    break;
                case 'Z':
                    useSonarKit();
                    break;
                case 'z':
                    useSonarKit();
                    break;

            
                    break;
            } //end of switch statement
        }//end of if statement
    }//end of else statement
}


//may need to fix when it comes to the radius --> constructor
//constructor
Items::Items(int ImageID,int startX, int startY, Direction dir, double size, unsigned int depth, bool aliveStatus, bool tempState, bool permanentState,StudentWorld *studentWorld,bool pickUpTM): GameObjects(ImageID, startX, startY, dir, size, depth, aliveStatus, studentWorld)
{
    m_tempState = tempState;
    m_permanentState = permanentState;
    m_pickByTM = pickUpTM; //objects will set later
}

Items:: ~Items(){
    //destructor
}

bool Items:: getPickUpStatusTM(){
    return m_pickByTM;
}

bool Items:: getTempState(){
    return m_tempState;
}

bool Items:: getPermanentState(){
    return m_permanentState;
}

void GameObjects::setTicksForCountdown(int ticks){ //ticks for specific objects - each object in the inherited class has its own tick countdown
    m_ticks = ticks;
}

int GameObjects::getTicksPassed(){
    return m_ticks;
}


//startX and startY will be passed in when called from the student world
Boulder :: Boulder(StudentWorld *studentWorld,int startX, int startY): GameObjects(TID_BOULDER, startX, startY,down, 1.0, 1, true,studentWorld){
    m_stableState = true; //boulders always start out in a stable state
    m_fallingState = false;
    m_waitingState = false;
    studentWorldPtr -> digEarth(getX(), getY()); //dig earth around it
} //constructor

Boulder::~Boulder(){
    //destructor
}

GameObjectsEnums Boulder::getTypeOfObj(){
    return BOULDER;
}

void Boulder::doSomething(){
    if (getAliveState() == false){
        return;
    }
    else{
        
        if (m_stableState == true){
            //x is cols, y is rows
            //check to see if there is an earth below
            if (studentWorldPtr -> checkEarth(getX(), getY()-1) == true || studentWorldPtr -> checkEarth(getX()+1, getY()-1) == true || studentWorldPtr -> checkEarth(getX()+2, getY()-1) == true || studentWorldPtr -> checkEarth(getX()+3, getY()-1) == true){
                return; //there is an earth below boulder do nothing
            }
            else{ //there is no earth below the boulder
                m_stableState = false;
                m_waitingState = true;
                setTicksForCountdown(31);
            }
        }//end of outer if statement for if the boulder is in a stable state
        if (m_waitingState == true && getTicksPassed() != 0){
            ticksCountdown();
        }
        if (getTicksPassed() == 0){
            m_waitingState = false;
            m_fallingState = true; //enter falling state
        }
        if (m_fallingState == true && getSound() == false){
            //Check the Object
            if (withinRadius(3.0,studentWorldPtr -> getTunnelManPtr() ->getX(),studentWorldPtr -> getTunnelManPtr() ->getY())){
                studentWorldPtr -> getTunnelManPtr() -> setAliveState(false);
                setVisible(false);
                //killed TM because we are within 3 rad and it got it by a boulder
            }
            for(int i = 0; i < studentWorldPtr -> getGameObjVec().size(); i++){ //doesnt contain earth
                if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == (REGULAR_PROTESTOR && getAliveState() != false) || studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == (HARDCORE_PROTESTOR && getAliveState() != false)){
                    if (withinRadius(3.0,studentWorldPtr ->getGameObjVec()[i] ->getX(), studentWorldPtr -> getGameObjVec()[i] ->getY()))
                        studentWorldPtr -> getGameObjVec()[i] -> setAliveState(false); //die cuz bonked in head
                    
                    
                }
                if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == BOULDER && getAliveState() != false){
                    //check if our current Boulder lands on another boulder
                    //if the boulders next step is going to collide with the top of another boulder
                    if ((getY()-1 == studentWorldPtr -> getGameObjVec()[i] -> getY()+3) && getX() == studentWorldPtr -> getGameObjVec()[i] -> getX()){  //plus 3 for the top of the boulder
                        setSound(true);
                        studentWorldPtr -> getGameObjVec()[i] -> setAliveState(false); //make this boulder dead
                        setVisible(false);
                    }
                }
            }
            //no earth in current row
            //check to see if there is an earth below us
            if (studentWorldPtr -> checkEarth(getX(), getY()-1) == false && studentWorldPtr -> checkEarth(getX()+1, getY()-1) == false && studentWorldPtr -> checkEarth(getX()+2, getY()-1) == false && studentWorldPtr -> checkEarth(getX()+3, getY()-1) == false){
                int currY = getY(); //the boulders current Y
                if (currY == 0){
                    setSound(true);
                }
                if (studentWorldPtr ->checkEarth(getX(),getY()-2) == true || studentWorldPtr ->checkEarth(getX()+1,getY()-2) == true || studentWorldPtr ->checkEarth(getX()+2,getY()-1) == true || studentWorldPtr ->checkEarth(getX()+3,getY()-2) == true){
                    setSound(true);
                }
                moveTo(getX(), getY()-1);
            }
            
        }//end of falling state
        if (getSound() == true){
            GameController::getInstance().playSound(SOUND_FALLING_ROCK);
            setAliveState(false);
            setVisible(false);
            setSound(false); //reset
        }
    } //outer else statement
}

//x,y, dir will be specified when created by TM getX() and getY() and dir
Squirt::Squirt(StudentWorld *studentWorld, int startX, int startY, Direction dir): GameObjects(TID_WATER_SPURT, startX, startY, dir, 1.0, 1, true, studentWorld){ //constructor
    m_distanceLeft = 4;
    setSound(false); //for if annoying TM
    setVisible(true);
}

Squirt :: ~Squirt(){
    //destructor
}
    
void Squirt::doSomething(){
    bool protestRDied = false;
    bool protestRAnnoyed = false;
    bool protestHCDied = false;
    bool protestHCAnnoyed = false;
    if (getAliveState() == false){return;}
    if (studentWorldPtr -> getTunnelManPtr() -> getWaterSquirt() == 0){
        setAliveState(false);
        setVisible(false);
    }
    for (int i = 0; i < studentWorldPtr -> getGameObjVec().size();i++){
        if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == REGULAR_PROTESTOR){
            if (withinRadius(3.0, studentWorldPtr -> getGameObjVec()[i] -> getX(), studentWorldPtr -> getGameObjVec()[i] -> getY()) && studentWorldPtr -> getGameObjVec()[i] ->getAliveState() == true && getHealth() > 0 && getAliveState() == true){ //within 3 rad
                studentWorldPtr -> getGameObjVec()[i]  -> annoyMe(-2); //if within rad 3 then annoy any protestor
                setVisible(false);
                protestRAnnoyed = true;
                if (studentWorldPtr -> getGameObjVec()[i]  -> getHealth() <= 0){
                    studentWorldPtr -> getGameObjVec()[i]  -> setVisible(false);
                    studentWorldPtr -> getGameObjVec()[i]  -> setAliveState(false);
                    protestRDied = true;
                    studentWorldPtr -> increaseScore(100);
                }
            }
        }
        if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == HARDCORE_PROTESTOR){
            if (withinRadius(3.0, studentWorldPtr -> getGameObjVec()[i] -> getX(), studentWorldPtr -> getGameObjVec()[i] -> getY()) && studentWorldPtr -> getGameObjVec()[i] ->getAliveState() == true && getHealth() > 0 && getAliveState() == true){ //within 3 rad
                studentWorldPtr -> getGameObjVec()[i]  -> annoyMe(-2); //if within rad 3 then annoy any protestor
                setVisible(false);
                protestHCAnnoyed = true;
                if (studentWorldPtr -> getGameObjVec()[i]  -> getHealth() <= 0){
                    studentWorldPtr -> getGameObjVec()[i]  -> setVisible(false);
                    studentWorldPtr -> getGameObjVec()[i]  -> setAliveState(false);
                    protestHCDied = true;
                    studentWorldPtr -> increaseScore(250);
                }
            }
        }
    }
    //need to check squirts direction to see if it can move in that direction
    if (getDirection() == left && m_distanceLeft != 0){
        if (studentWorldPtr -> getTunnelManPtr() -> tunnelManDirectSquirt(getX() - 1, getY()) == false && getAliveState() == true){
            moveTo(getX()-1, getY());
            m_distanceLeft--;
            setVisible(true);
            return;
        }
        else{
            setAliveState(false);
            setVisible(false);
        }
    }
    
    if (getDirection() == right && m_distanceLeft != 0){
        if (studentWorldPtr -> getTunnelManPtr() -> tunnelManDirectSquirt(getX() + 1, getY()) == false && getAliveState() == true){
            moveTo(getX()+1, getY());
            m_distanceLeft--;
            setVisible(true);
            return;
        }
        else{
            setAliveState(false); //because theres an earth or boulder
            setVisible(false);
        }
    }
    if (getDirection() == up && m_distanceLeft != 0){
        if (studentWorldPtr -> getTunnelManPtr() -> tunnelManDirectSquirt(getX(), getY()+1) == false && getAliveState() == true){
            moveTo(getX(), getY()+1);
            m_distanceLeft--;
            setVisible(true);
            return;
        }
        else{
            setAliveState(false);
            setVisible(false);
        }
    }
    if (getDirection() == down && m_distanceLeft != 0){
        if (studentWorldPtr -> getTunnelManPtr() -> tunnelManDirectSquirt(getX(), getY()-1) == false && getAliveState() == true){
            moveTo(getX(), getY()-1);
            setVisible(true);
            m_distanceLeft--;
            return;
        }
        else{
            setAliveState(false);
            setVisible(false);
        }
    }
    if (protestRAnnoyed == true || protestHCAnnoyed == true){
        setAliveState(false); //setting squirts alive stae
        GameController::getInstance().playSound(SOUND_PROTESTER_ANNOYED);
        protestRAnnoyed = false; //reset so doesnt keep playing
    }
    if (protestRDied == true || protestHCDied == true){
        GameController::getInstance().playSound(SOUND_PROTESTER_GIVE_UP);
        setAliveState(false);
        protestRDied = false; //reset so doesnt keep playing
    }
    setVisible(false);
}


GameObjectsEnums Squirt::getTypeOfObj(){
    return SQUIRT;
}

BarrelOfOil::BarrelOfOil(StudentWorld *studentWorld,int startX, int startY): Items(TID_BARREL, startX, startY, right, 1.0, 2, true, false, true, studentWorld, true){ //set alive is false because it starts out invisible first
    setAliveState(true);
    setVisible(false);
}
    
BarrelOfOil:: ~BarrelOfOil(){
 //destructor
}
    
GameObjectsEnums BarrelOfOil::getTypeOfObj(){
    return BARREL_OF_OIL;
}
    
void BarrelOfOil::doSomething(){
    if (getAliveState() == false){return;}
    
    if (withinRadius(4.0, studentWorldPtr -> getTunnelManPtr() ->getX(), studentWorldPtr -> getTunnelManPtr() ->getY())){
        setVisible(true);
    }
    if (withinRadius(3.0, studentWorldPtr -> getTunnelManPtr() ->getX(), studentWorldPtr -> getTunnelManPtr() ->getY())){
        setAliveState(false); //because tunnel man picked up the boulder
        setVisible(false);
        setSound(true);
        studentWorldPtr -> increaseScore(1000);
        studentWorldPtr -> studentsetOil(-1); //oil has been found, decrement supply in gamworld
    }
    if (getSound() == true){
        GameController::getInstance().playSound(SOUND_FOUND_OIL);
        setSound(false); //reset so doesnt keep
    }
    
}

//temp state for protestors
    //when created by pressing x the gold nugget is in a temp state
//alive status on
//permanent state for tm
    //when created in student would it is in a permanent state
    //alive status not on

GoldNuggets::GoldNuggets(int startX, int startY, bool permState,bool tempState, bool tmPickup, bool pPickup,StudentWorld* studentWorld): Items(TID_GOLD, startX, startY, right,1.0, 2, true, tempState, permState,studentWorld, tmPickup){
    m_pickByProtestor = pPickup;
    if (getPermanentState() == true){ //tunnelman
        setVisible(false);
    }
    if (getTempState() == true){ //protestor
        setVisible(true);
    }
    setTicksForCountdown(100); //reintialize the ticks for every protestor when a gold is dropped for them
}

GoldNuggets::~GoldNuggets(){
    //destructor
}

GameObjectsEnums GoldNuggets:: getTypeOfObj(){
    return GOLD_NUGGETS;
}

void GoldNuggets::doSomething(){
    if (getAliveState() == false){
        return; //dead rn so do nothing
    }
    //only TM can pick up this gold
    if (getPickUpStatusTM() == true && getAliveState() == true && withinRadius(4.0, studentWorldPtr -> getTunnelManPtr() -> getX(), studentWorldPtr -> getTunnelManPtr() -> getY()) == true){
            setVisible(true);
    }
    if (getPickUpStatusTM() == true && getAliveState() == true && withinRadius(3.0, studentWorldPtr -> getTunnelManPtr() -> getX(), studentWorldPtr -> getTunnelManPtr() -> getY()) == true){
            setAliveState(false);
            setVisible(false);
            studentWorldPtr -> getTunnelManPtr() -> setGold(1); //update invetory
            studentWorldPtr -> increaseScore(10); //increase score
        setSound(true);
        }
    if (getSound() == true){
        GameController::getInstance().playSound(SOUND_GOT_GOODIE);
        setSound(false);
    }
//only Protestors can pick up this gold
    if (m_pickByProtestor == true && getAliveState() == true){
        if (getTicksPassed() != 0){
            //decrement the ticks everytime move func calls this
            ticksCountdown(); //help decrement ticks everytime move() is called
            for (int i = 0; i < studentWorldPtr -> getGameObjVec().size();i++){
                if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == REGULAR_PROTESTOR){
                    //implement: do what regular protestor does for gold -- leave oil
                    if (withinRadius(3.0, studentWorldPtr -> getGameObjVec()[i] -> getX(), studentWorldPtr -> getGameObjVec()[i] -> getY())){ //protestor can still get temp gold because it is not gone
                        studentWorldPtr -> increaseScore(25); //protestor pick up so TM gets the score
                        setAliveState(false);
                        setVisible(false);
                        setSound(true);
                    }
                }
                if (studentWorldPtr -> getGameObjVec()[i] -> getTypeOfObj() == HARDCORE_PROTESTOR){
                    //implement: do what regular protestor does for gold -- leave oil
                    if (withinRadius(3.0, studentWorldPtr -> getGameObjVec()[i] -> getX(), studentWorldPtr -> getGameObjVec()[i] -> getY())){ //protestor can still get temp gold because it is not gone
                        studentWorldPtr -> increaseScore(50); //protestor pick up so TM gets the score
                        setAliveState(false);
                        setVisible(false);
                        setSound(true);
                    }
                }
            } //end of for loop
            if (getSound() == true){
                GameController::getInstance().playSound(SOUND_PROTESTER_FOUND_GOLD);
            }
        } //end of if statement for if ticks = 0
        if (getTicksPassed() == 0){
            setAliveState(false);
            setVisible(false);
        }
    }//end of if statement if tm can pick up the gold
}//end of do something


//make ticks a parameter so we can count down in gameobjects --> countdown in do something?
//setalive and visibility to false once the ticks is ddone in do smth DUH
//may need to check alive status contiously

SonarKit::SonarKit(int startX, int startY, StudentWorld *studentWorld): Items(TID_SONAR,startX, startY, right, 1.0, 2, true, true, false, studentWorld, true){
    int currLevel = studentWorldPtr -> getLevel();
    int t = max(100, 300 -10*currLevel);
    setTicksForCountdown(t);
    setAliveState(true);
    setVisible(true);
    setSound(false);
}

SonarKit::~SonarKit(){
    //destructor
}

GameObjectsEnums SonarKit::getTypeOfObj(){
    return SONAR_KIT;
}

void SonarKit::doSomething(){
    if (getAliveState() == false){return;} //do nothing for being dead
    if (getTicksPassed() == 0){ //lifetime of sonar kit is up
        setAliveState(false);
        setVisible(false);
    }
    if (getTicksPassed() != 0 && withinRadius(3.0, studentWorldPtr->getTunnelManPtr()->getX(), studentWorldPtr->getTunnelManPtr()->getY()) == true){
        //no need to countdown ticks cuz we alr found the sonar
        setAliveState(false);
        setVisible(false);
        setSound(true);
        studentWorldPtr ->getTunnelManPtr() -> setSonar(2); //increase TM Sonar Inventory
        studentWorldPtr -> setSonarField(-1); //decrease amt on field
        studentWorldPtr -> increaseScore(75);
    }
    else if (getTicksPassed() != 0 && getAliveState() == true){ //decrease whil it stil alive
        ticksCountdown();
    }
    else if (getTicksPassed() == 0){
        setAliveState(false);
        setVisible(false);
    }
    if (getSound() == true){
        GameController::getInstance().playSound(SOUND_GOT_GOODIE);
        setSound(false);
    }
}

Water::Water(int startX,int startY, StudentWorld *studentWorld) : Items(TID_WATER_POOL, startX, startY, right, 1.0, 2, true, true, false, studentWorld, true){
    int currLevel = studentWorldPtr -> getLevel();
    int t = max(100, 300 -10*currLevel);
    setTicksForCountdown(t);
    setVisible(true); //only true when within rad 3 of TM
}

Water::~Water(){
    //destructor
}

GameObjectsEnums Water::getTypeOfObj(){
    return WATER;
}

void Water::doSomething(){
    if (getAliveState() == false){return;}
    if (withinRadius(3.0, studentWorldPtr -> getTunnelManPtr() ->getX(), studentWorldPtr -> getTunnelManPtr() ->getY()) && getTicksPassed() != 0){
        setVisible(false);
        setAliveState(false);
        setSound(true);
        studentWorldPtr->getTunnelManPtr()-> setWaterSquirt(5);
        studentWorldPtr -> increaseScore(100);
    }
    else if (getTicksPassed() != 0){
        ticksCountdown();
    }
    else if (getTicksPassed() == 0){
        setAliveState(false);
        setVisible(false);
    }
    if (getSound() == true){
        GameController::getInstance().playSound(SOUND_GOT_GOODIE);
        setSound(false);
    }
}

Protestors:: Protestors(int ImageID, double size, unsigned int depth,bool aliveStatus,StudentWorld *studentWorld, int health):GameObjects(ImageID, 60, 60, left, size, depth, aliveStatus, studentWorld){
    m_amtToWalk = 60;
    m_currLevel = studentWorldPtr -> getLevel();
    m_leaveOilState = false;
    m_restingState = false; //when starting
    setTicksForCountdown(max(0, 3-m_currLevel/4));
    setHealth(health);
    m_yellTick = 15; //always start at 15 and decrement as ticks go on
}

Protestors::~Protestors(){
    //destruct
}

bool Protestors::getRestingState(){
    return m_restingState;
}

void Protestors::setRestingState(bool resting){ //squirts will make it go into ressting state
    m_restingState = resting;
}

void Protestors::moveBackAndForth(){
    if(getDirection() == left){
        if (m_amtToWalk != 0){
            moveTo(getX()-1, getY());
            m_amtToWalk--;
        }
        else {
            setDirection(right);
            m_amtToWalk = 60;
        }
    }
    if (getDirection() == right){
        if (m_amtToWalk != 0){
            moveTo(getX()+1, getY());
            m_amtToWalk--;
        }
        else {
            setDirection(left);
            m_amtToWalk = 60;
        }
    }
}

void Protestors::doSomething(){
    bool yell =true;
    bool playerDied = true;
    if (getAliveState() == false){return;}
    if (getRestingState() == true && getTicksPassed() != 0){
        ticksCountdown();
    }
    else{
        int tmX = studentWorldPtr -> getTunnelManPtr() ->getX();
        int tmY = studentWorldPtr -> getTunnelManPtr() ->getY();
        if((getYellTick() == 0 || getYellTick() != 0) && studentWorldPtr -> getTunnelManPtr() -> getAliveState() ==true && ((getX() + 4 == tmX && getY() == tmY) || (getX() - 4 == tmX && getY() == tmY))){
            yell = true;
            studentWorldPtr -> getTunnelManPtr() -> annoyMe(-2);
            setYellTick(15); //reset back to 15
            if (yell == true){
                GameController::getInstance().playSound(SOUND_PROTESTER_YELL);
                yell = false;
            }
            if (studentWorldPtr -> getTunnelManPtr() -> getHealth() == 0){
                playerDied = true;
                if (playerDied == true){
                    GameController::getInstance().playSound(SOUND_PLAYER_GIVE_UP);
                    playerDied = false;
                }
                studentWorldPtr -> getTunnelManPtr() -> setAliveState(false);
            }
        }
        if (getYellTick() != 0){
            int tempYellTick = getYellTick() - 1;
            setYellTick(tempYellTick);
        }
        if (getYellTick() == 0){
            setYellTick(15);
        }
        moveBackAndForth();
        setRestingState(true);
        
        int currLevel = studentWorldPtr -> getLevel();
        setTicksForCountdown(max(0, 3-currLevel/4));
    }
}
int Protestors::getYellTick(){
    return m_yellTick;
}

void Protestors::setYellTick(int t){
    m_yellTick = t;
}

RegularProtestor::RegularProtestor(StudentWorld *studentWorld):Protestors(TID_PROTESTER, 1.0, 0, true, studentWorld,5){
}

RegularProtestor::~RegularProtestor(){
    //destruct
}

GameObjectsEnums RegularProtestor:: getTypeOfObj(){
    return REGULAR_PROTESTOR;
}

HardCoreProtestor::HardCoreProtestor(StudentWorld *studentWorld): Protestors(TID_HARD_CORE_PROTESTER,1.0, 0, true, studentWorld,20){
//    setHealth(20);
}

HardCoreProtestor::~HardCoreProtestor(){
    //destructor
}

GameObjectsEnums HardCoreProtestor::getTypeOfObj(){
    return HARDCORE_PROTESTOR;
}

