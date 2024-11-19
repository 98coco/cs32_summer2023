
//  CS 32 Homework 2
//
//  Created by Coco Li on 7/25/23.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int productOfTheSystem(unsigned int m, unsigned int n)
{
    if (n==0){
        return n; //base case
    }
    int result = m + productOfTheSystem(m, n-1); //simplifying case
    return result;
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.

int accountForADigit(int num, int digit)
{
    int digitTrack = 0;
    if (num == 0){ //base case
        return digitTrack;
    }
    digitTrack = accountForADigit(num/10,digit);
    if (num%10 == digit){
       digitTrack++;
    }
    return digitTrack;
}

// Returns a string where the same characters next each other in
// string n are separated by "88" (you can assume the input
// string will not have 8’s)

string eightClap(string n){
    if (n.size() == 0 || n.size() == 1){
        return n; // no modifcations
    }
    if (n.substr(0,1) == n.substr(1,1)){ //compare first two
        string eight = "88";
        n = n.substr(0,1) + eight + eightClap(n.substr(1,n.size()-1)); //add between the two
        return n;
    }
    else{
        n = n.substr(0,1) + eightClap(n.substr(1,n.size()-1)); //look after first letter
        return n;
    }
    return n;
}

// str contains a single pair of the less than and greater than
// signs, return a new string made of only the less than and
// greater than sign and whatever is contained in between

string coneHeads(string str)
{
    if (str == ""){ //base case
        return str;
    }
    if (str.substr(0,1) == ">"){ //base case
        str = str.substr(0,1);
        return str;
    }
    string res = coneHeads(str.substr(1,str.size()-1)); //processing the results from the subproblem --> what we want to do with our res
    if (res.substr(0,1) == "<"){
        return res;
    }
    res = str.substr(0,1) + res;  //process the values
    return res;
}

// "hi<7>9;
//
//1st i<7>9  //return rest <7> 
//
//2nd <7>9 // return <7> --> res is not <7> yet
//
//3rd 7>9   //line 77 -->  return  7>
//
//4th >9 //gonna return > to 3rd call
//
//


// Return true if the total of any combination of elements in
// the array a equals the value of the target.


bool conglomerateOfNumbers(const int a[], int size, int target)
{
    //checking first # w everything else and then moving on
    if (size == 0){ //base case
        return target == 0;
    }
    if (target == 0){ //came in as 0 --> can return true bc null case is 0
        return true;
    }
    //function adds the head
    bool yes = conglomerateOfNumbers(a+1,size -1,target-a[0]);
    if (yes == true){
        return true;
    }
    
    //this means yes wasnt true if we included numbers
    return conglomerateOfNumbers(a+1,size -1,target);

}

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool findAWay(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    if (sr == er && sc == ec){return true;} //check if we reach our destination
    maze[sr][sc] = '#'; //mark the spot we are currently at
    //directions
    bool found = false;
    if (maze[sr-1][sc] == '.'){ //look up
       found = findAWay(maze,nRows,nCols,sr-1,sc,er,ec);
       if (found == true){return true;}  //immediately return true because we found out location
    }
    
    if (maze[sr+1][sc] == '.'){ //look down
      found = findAWay(maze,nRows,nCols,sr+1,sc,er,ec);
      if (found == true){return true;}
    }
    if (maze[sr][sc-1] == '.'){ //look left
        found = findAWay(maze,nRows,nCols,sr,sc-1,er,ec);
        if (found == true){return true;}
    }
    if (maze[sr][sc+1] == '.'){ //look right
      found = findAWay(maze,nRows,nCols,sr,sc+1,er,ec);
      if (found == true){return true;}
    }
    return false; // no spots
}

int main() {
    
    assert(productOfTheSystem(2, 2) == 4);
    assert(productOfTheSystem(5, 5) == 25);
    assert(productOfTheSystem(3, 2) == 6);
    assert(productOfTheSystem(7, 8) == 56);
    assert(productOfTheSystem(3, 8) == 24);
    assert(productOfTheSystem(2, 8) == 16);
    assert(productOfTheSystem(7, 9) == 63);
    assert(productOfTheSystem(32, 3) == 96);
    assert(productOfTheSystem(100, 100) == 10000);
    assert(productOfTheSystem(11, 12) == 132);
    assert(productOfTheSystem(0, 0) == 0);
    assert(productOfTheSystem(1, 0) == 0);
    assert(productOfTheSystem(0, 20) == 0);

    assert(accountForADigit(125, 2) == 1);
    assert(accountForADigit(18838, 8) == 3);
    assert(accountForADigit(55555, 3) == 0);
    assert(accountForADigit(0, 0) == 0);
    assert(accountForADigit(2, 0) == 0);
    assert(accountForADigit(122, 2) == 2);
    assert(accountForADigit(15623, 5) == 1);
    assert(accountForADigit(123489, 6) == 0);
    assert(accountForADigit(222222, 2) == 6);
    assert(accountForADigit(3232241, 2) == 3);

    assert(eightClap("aaaa") == "a88a88a88a");
    assert(eightClap("hello") == "hel88lo");
    assert(eightClap("no") == "no");
    assert(eightClap("lol") == "lol");
    assert(eightClap("goodbye") == "go88odbye");
    assert(eightClap("yyuu") == "y88yu88u");
    assert(eightClap("y8yuu") == "y8yu88u");
    assert(eightClap("cocososlay") == "cocososlay");
    assert(eightClap("pleaseletmepassthisclass") == "pleaseletmepas88sthisclas88s");

    assert(coneHeads("<>7") == "<>");
    assert(coneHeads("<x>7") == "<x>");
    assert(coneHeads("abc<x>7") == "<x>");
    assert(coneHeads("<baobaoli>") == "<baobaoli>");
    assert(coneHeads("wat<>") == "<>");
    assert(coneHeads("abc<ghj>789") == "<ghj>");
    assert(coneHeads("4agh<y>") == "<y>");
    assert(coneHeads("4agh<>") == "<>");
    assert(coneHeads("<>") == "<>");


    const int arr1[] = {2,4,8};
    assert(conglomerateOfNumbers(arr1, 3, 10) == true);
    assert(conglomerateOfNumbers(arr1, 3, 6) == true);
    assert(conglomerateOfNumbers(arr1, 3, 11) == false);
    assert(conglomerateOfNumbers(arr1, 3, 0) == true);  //bc u can also not include all numbers in the subset and return true
    const int arr2[] = {-3,2,4};
    assert(conglomerateOfNumbers(arr2, 3, 1) == true);
    assert(conglomerateOfNumbers(arr2, 3, 6) == true);
    assert(conglomerateOfNumbers(arr2, 3, 0) == true);
    assert(conglomerateOfNumbers(arr2, 3, 5) == false);
    assert(conglomerateOfNumbers(arr2, 3, -1) == true);
    const int arr3[] = {5,7};
    assert(conglomerateOfNumbers(arr3, 2, 12) == true);
    assert(conglomerateOfNumbers(arr3, 2, 0) == true);
    assert(conglomerateOfNumbers(arr3, 2, 14) == false);
    assert(conglomerateOfNumbers(arr3, 2, -11) == false);
    const int arr4[] = {-5,-74,-6,-9};
    assert(conglomerateOfNumbers(arr4, 4, -79) == true);
    assert(conglomerateOfNumbers(arr4, 4, -94) == true);
    assert(conglomerateOfNumbers(arr4, 4, -11) == true);
    assert(conglomerateOfNumbers(arr4, 4, -14) == true);
    assert(conglomerateOfNumbers(arr4, 4, -80) == true);
    assert(conglomerateOfNumbers(arr4, 4, -83) == true);
    assert(conglomerateOfNumbers(arr4, 4, -15) == true);
    assert(conglomerateOfNumbers(arr4, 4, 0) == true);
    assert(conglomerateOfNumbers(arr4, 4, 10) == false);
    assert(conglomerateOfNumbers(arr4, 4, -100) == false);
    assert(conglomerateOfNumbers(arr4, 4, 200) == false);
    
    const int arr5[] = {1};
    assert(conglomerateOfNumbers(arr5, 1, 1) == true);
    assert(conglomerateOfNumbers(arr5, 1, 0) == true);
    assert(conglomerateOfNumbers(arr5, 1, 3) == false);


    
    string maze1[10] = {
    "XXXXXXXXXX",
    "X.......@X",
    "XX@X@@.XXX",
    "X..X.X...X",
    "X..X...@.X",
    "X....XXX.X",
    "X@X....XXX",
    "X..XX.XX.X",
    "X...X....X",
    "XXXXXXXXXX"
    };

    if (findAWay (maze1, 10, 10, 6, 4, 1, 1))
    cout << "maze w 10 by 10 solvable!" << endl;
    else
    cout << "Out of luck! for 10 by 10 maze" << endl;

    cerr<<endl;

    string maze2[3] = {
    "XXX",
    "X.X",
    "XXX",
    };

    if (findAWay (maze2, 3, 3, 1, 1, 2, 1))
    cout << "maze w 2 by 2 solvable!" << endl;
    else
    cout << "Out of luck! for 2 by 2 maze" << endl;

    string maze3[5] = {
    "XXXXX",
    "X...X",
    "X...X",
    "X...X",
    "XXXXX",
    };

    cerr << "there is a way true for 5 by 5 maze" <<endl;
    if (findAWay (maze3, 5, 5, 1, 1, 3, 3))
    cout << "maze w 5 by 5 solvable!" << endl;
    else
    cout << "Out of luck! for 5 by 5 maze" << endl;
    if (findAWay (maze3, 5, 5, 2, 3, 2, 3))
    cout << "maze w 5 by 5 solvable!" << endl;
    else
    cout << "Out of luck! for 5 by 5 maze" << endl;
    cerr << endl;



    cerr << "new endpoint for 5 by 5  (out of luck expected res)" <<endl;
    if (findAWay (maze3, 5, 5, 1, 1, 4, 3))
    cout << "maze w 5 by 5 solvable!" << endl;
    else
    cout << "Out of luck! for 5 by 5 maze" << endl;
    if (findAWay (maze3, 5, 5, 1, 1, 0, 3))
    cout << "maze w 5 by 5 solvable!" << endl;
    else
    cout << "Out of luck! for 5 by 5 maze" << endl;
    cerr<<endl;

    string maze4[5] = {
    "XXXXX",
    "X..XX",
    "X@@XX",
    "X@X.X",
    "XXXXX",
    };

    if (findAWay (maze4, 5, 5, 1, 1, 1, 2))
    cout << "maze4 solvable!" << endl;
    else
    cout << "Out of luck! maze blocked" << endl;
    cerr << endl;
    cerr << "new coordinates for maze 4: (out of luck expected res)" << endl;
    if (findAWay (maze4, 5, 5, 1, 1, 4, 3))
    cout << "maze4 solvable!" << endl;
    else
    cout << "Out of luck! maze blocked" << endl;
    if (findAWay (maze4, 5, 5, 1, 1, 2, 1))
    cout << "maze4 solvable!" << endl;
    else
    cout << "Out of luck! maze blocked" << endl;
    if (findAWay (maze4, 5, 5, 1, 1, 3, 3))
    cout << "maze4 solvable!" << endl;
    else
    cout << "Out of luck! maze blocked" << endl;
    cerr << endl;
    
    cerr<<endl;
    cerr << "all test past!" << endl;
    return 0;
}
