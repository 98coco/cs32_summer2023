#include "StudentWorld.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
}

StudentWorld::StudentWorld(string assetDir) //constructor
: GameWorld(assetDir)
{
    m_sonarOnField = 0;
    m_oilOnField = 0; //initially 0 until we intialize
    m_currLevel = getLevel();
    m_AddProtestorTick = 0;
    m_probabilityOfHardCore = min(90,m_currLevel * 10 + 30);
}

StudentWorld:: ~StudentWorld(){
    //destructor --> empty because cleanUp already does everything
}


int StudentWorld:: init()
{
    //create tunnelMan
    tunnelManPtr = new TunnelMan(this);
    
    //create Earth
    //would reintializing the points be here?
    fillWholeEarth();
    makeTopEmpty();
    createMineShaft();
    
    
    //randomly place boulder
    int currLevel = getLevel();
    int B = min(currLevel/ 2 + 2,9);
    spreadBoulder(B);
    
    //randomly place gold
    int G = max(5-currLevel/ 2, 2);
    spreadGold(G);
    
    //randomly place oil
    int L =(min(2 + currLevel, 21));
    studentsetOil(L); //set out private member that keeps track of the amt of oil we have on the oil field
    spreadOil(L);
 
    return GWSTATUS_CONTINUE_GAME;
}


//init helper functions
void StudentWorld::fillWholeEarth(){
    for(int r = 0; r < 64; r++){
        for (int c = 0; c < 64; c++){
            earthLayoutArr[r][c] = new Earth(c,r,this);
        }
    }
}

void StudentWorld::makeTopEmpty(){
    for (int r = 60; r < 64; r++){
        for (int c = 0; c < 64 ; c++){
            earthLayoutArr[r][c] -> setAliveState(false);
            earthLayoutArr[r][c] -> setVisible(false);
        }
    }
}

void StudentWorld:: createMineShaft(){
    for (int c = 30; c < 34; c++){
        for(int r = 4; r <60; r++){
            earthLayoutArr[r][c] -> setAliveState(false);
            earthLayoutArr[r][c] -> setVisible(false);
        }
    }
}
        

int StudentWorld::move(){
  
    setDisplay();
    
    //chance add protest
    int temp = 2 + m_currLevel*1.5;
    m_numsOfProtestor = min(15,temp);
    
    if (m_AddProtestorTick == 0){
        m_AddProtestorTick = max(25,200-m_currLevel); //reset
        if (m_numsOfProtestor != 0){ //the amt we need to add is in the constructor and as we add we will decrement
            int randValue  = rand()%101;
            if (randValue <= m_probabilityOfHardCore){
                //add a hardcore protestor
                gameObjects.push_back(new HardCoreProtestor(this));
                m_numsOfProtestor--;
            }
            else{
                //add regular protestor
                gameObjects.push_back(new RegularProtestor(this));
                m_numsOfProtestor--;
            }
        }
    }
    else{
        m_AddProtestorTick--; //decrement cuz we do nto add the protestor yet
    }
    
    //chance add items
    int g = m_currLevel*25 +300;
    int randVal = rand()%g; //number between 0 and G
    if (randVal == 0){
        int x = rand()%61;
        int y = rand()%57;
        int secRandVal = rand()%5;
        if (secRandVal == 0){ //1/5 chance of sonar
            gameObjects.push_back(new SonarKit(0,60,this));
        }
        else{
           //need to make sure it doesnt overlap earth
            
            gameObjects.push_back(new Water(x,y,this));
            digEarth(x, y); //dig around water
        }
    }
            for (int i = 0; i < gameObjects.size(); i++){
                tunnelManPtr -> doSomething();
                gameObjects[i] -> doSomething(); //have each game object call their do smth method
                if (tunnelManPtr -> getAliveState() == false && getLives() == 0){
                    return GWSTATUS_PLAYER_DIED;
                }
                if (m_oilOnField == 0 && tunnelManPtr -> getAliveState() == true){
                    //advance to next level
                    return GWSTATUS_FINISHED_LEVEL;
                }
                if (tunnelManPtr -> getAliveState() == false && getLives() != 0){
                    decLives();
                    return GWSTATUS_PLAYER_DIED;
                }
            }
            
           
    if (tunnelManPtr -> getAliveState() == false && getLives() != 0){
        decLives();
        return GWSTATUS_PLAYER_DIED;
    }
            if (tunnelManPtr -> getAliveState() == false && getLives() == 0){ //player died
                return GWSTATUS_PLAYER_DIED;
            }
            
            
            //initialize lives to three
            if (m_oilOnField == 0 && tunnelManPtr -> getAliveState() == true && getLives() != 0){
                //advance to next level
                playSound(SOUND_FINISHED_LEVEL);
                return GWSTATUS_FINISHED_LEVEL;
            }
            
            return GWSTATUS_CONTINUE_GAME;
        }

void StudentWorld:: cleanUp()
{
    for (int r = 0; r < 60; r++){ //clean earth
        for (int c = 0; c < 64; c++){
            if (earthLayoutArr[r][c] != nullptr){
                Earth *temp = earthLayoutArr[r][c];
                earthLayoutArr[r][c] = nullptr;
                delete temp;
            }
        }
    }
    
    if (tunnelManPtr != nullptr){
        TunnelMan *temp = tunnelManPtr;
        tunnelManPtr = nullptr;
        delete temp;
    }
    
    //add destructor for the vector
    for (int i = 0; i < gameObjects.size(); i++){
        if (gameObjects[i] -> getAliveState() == true){
            gameObjects[i] -> setAliveState(false);
            gameObjects[i] -> setVisible(false);
        }
    }
    vector <GameObjects*>::iterator it;
    it = gameObjects.begin();
    while (it != gameObjects.end()){
        it = gameObjects.erase(it);
    }

}

const vector<GameObjects*> StudentWorld:: getGameObjVec(){
    return gameObjects;
}

void StudentWorld::addObjToVec(GameObjects* objs){
    gameObjects.push_back(objs);
}

TunnelMan* StudentWorld::getTunnelManPtr(){
    return tunnelManPtr;
}

Earth* StudentWorld:: getEarthArr(int x, int y){
    return earthLayoutArr[x][y];
}
    
void StudentWorld::setDisplay(){
    unsigned int level = getLevel();
    int lives = getLives();
    int health = tunnelManPtr -> getHealth(); //REMEMBER MULTIPLE BY 10 FOR PERCENTAGE
    int squirts = tunnelManPtr -> getWaterSquirt();
    int gold = tunnelManPtr -> getGold();
    int barrelsLeft = m_oilOnField;
    int sonar = tunnelManPtr -> getSonar();
    int score = getScore();
    
    string s = stringFormat(level, lives, health, squirts, gold, barrelsLeft, sonar, score);
    setGameStatText(s);
}

string StudentWorld::stringFormat(unsigned int level,int lives,int health,int squirts,int gold,int barrelsLeft,int sonar,int score){

    string levelStr = to_string(level);
    string livesStr = to_string(lives);
    int percentageHealth = 10 * health;
    string healthStr = to_string(percentageHealth);
    string squirtStr = to_string(squirts);
    string goldStr = to_string(gold);
    string barrelStr = to_string(barrelsLeft);
    string sonarStr = to_string(sonar);
    string scoreStr = to_string(score);
   
    //1
    while (scoreStr.length() < 6){
        scoreStr = "0" + scoreStr;
    }
    //2
    while (levelStr.length()<2){
        levelStr = " " + levelStr;
    }
    //3
    livesStr = " " + livesStr + "%";
    //4
    while (squirtStr.length()<2){
        squirtStr = " " + squirtStr;
    }
    //5
    while (goldStr.length()<2){
        goldStr = " " + goldStr;
    }
    //6
    while (barrelStr.length()<2){
        barrelStr = " " + barrelStr;
    }
    //7
    while (sonarStr.length()<2){
        sonarStr = " " + sonarStr;
    }
    //8
    while (scoreStr.length()<2){
        scoreStr = " " + scoreStr;
    }
    
    string finalStr = "Lvl: " + levelStr + " Lives: " + livesStr + " Hlth: " + healthStr + " Wtr: " + squirtStr + " Gld: " + goldStr + " Oil Left: " + barrelStr + " Sonar: " + sonarStr + " Score: " + scoreStr;
    
    return finalStr;
}

bool StudentWorld::outerBoundaries(int x, int y){  //because rows by cols
    if (x >= 61 || x < 0 || y >= 61 || y < 0){
        return false; //out of bounds
    }
    return true; //within bounds
}

bool StudentWorld::objMineShaftBounds(int x, int y){
    if ((x >= 25 && x <= 38) && (y >= 0 && y <= 59)){
        return true; //within mineshaft bounds
     }
    return false;
}

bool StudentWorld:: earthOrBoulder(int x, int y){ //check if overlapping occurs for only Earth And Boulder 
    for (int c = x; c <= x+3; c++){
        for (int r = y; r <= y+3; y++){
            if (earthLayoutArr[r][c] -> getAliveState() == true){
                return true; //blocked by earth
            }
        }
    }
    for (int i = 0; i < gameObjects.size(); i++){
        if (gameObjects[i] -> getTypeOfObj() == BOULDER){
            if (gameObjects[i] -> withinRadius(3,x,y)){
                return true; //blocked by boulder
            }
        }
    }
    return false;
}

void StudentWorld::setSonarField(int s){
    m_sonarOnField+=s;
}

void StudentWorld::spreadGold(int g){
    for (int i = 0; i < g; i++){ //for each boulder
        int x = rand() % 60; //give it a random x coordinate
        int y = rand() % 56; //give it a random y coordinate
        validChangeCoor(60, 56, x, y);
        gameObjects.push_back(new GoldNuggets(x,y,true,false,true,false,this));
    }
}

void StudentWorld::spreadOil(int L){
    for (int i = 0; i < L; i++){ //for each boulder
        int x = rand() % 60; //give it a random x coordinate
        int y = rand() % 56; //give it a random y coordinate
        validChangeCoor(60, 56, x, y);
        gameObjects.push_back(new BarrelOfOil(this,x,y));
    }
}

void StudentWorld:: validChangeCoor(int boundX, int boundY, int &coorX, int &coorY){
    while (objMineShaftBounds(coorX, coorY) == true){ //if the coordinates we passed in are in the mineshaft regenerate coordinates
        coorX = rand()% boundX + 1;
        coorY = rand()% boundY + 1;
        for (int a = 0;a < gameObjects.size(); a++){
            while (gameObjects[a] -> withinRadius(6.0, coorX, coorY) == true){ //once we regenerate make sure it is within rad 6 of everything
                coorX = rand()% boundX + 1;
                coorY = rand()% boundY + 1;
            }
        }
    }
    //we did not enter the mineshaft --> still have to make sure within 6 rad of everything
    for (int a = 0; a < gameObjects.size(); a++){
        while (gameObjects[a] -> withinRadius(6.0, coorX, coorY) == true){ //once we regenerate make sure it is within rad 6 of everything
            coorX = rand()% boundX + 1;
            coorY = rand()% boundY + 1;
        }
    }
}



void StudentWorld::spreadBoulder(int B){
    for (int i = 0; i < B; i++){ //for each boulder
        int x = rand() % 59 + 1; //give it a random x coordinate
        int y = rand() % 55 + 1; //give it a random y coordinate above y = 20
        validChangeCoor(59, 55, x, y);
        gameObjects.push_back(new Boulder(this,x,y));
    }
}

void StudentWorld::studentsetOil(int L){
    m_oilOnField += L;
}

//TunnelMan uses this function to digEarth
//Implementation in Student World because the earthLayout is a private member of student World
bool StudentWorld:: digEarth(int x, int y){
    bool deletedEarth = false;
    for (int c = x; c <= x+3; c++){
        for (int r = y; r <= y+3; r++){
            if( r >= 61 || r < 0 || c >= 60 || c < 0){ //out of bounds

            }
            if (earthLayoutArr[r][c] -> getAliveState() == false){

            }
            if (earthLayoutArr[r][c] -> getAliveState() == true){//indexing is still rows to cols
                earthLayoutArr[r][c] -> setAliveState(false); //x means cols and y means row
                earthLayoutArr[r][c] -> setVisible(false);
                deletedEarth = true;
            }
        }
    }
    return deletedEarth;
}

bool StudentWorld:: checkEarth(int x,int y){ //return true if there is an earth below it
    if (outerBoundaries(x,y) == false){
        return false; //out of bounds dont go out
    }
    else{
        if (earthLayoutArr[y][x] -> getAliveState() == true){ //there is an earth below us
            return true;
        }
    }
    return false;
}


