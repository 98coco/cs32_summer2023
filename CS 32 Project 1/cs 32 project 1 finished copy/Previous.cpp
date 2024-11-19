//
//  Previous.cpp
//  CS 32 Project 1
//
//  Created by Coco Li on 6/30/23.
//

#include "Previous.h"
#include <iostream>
using namespace std;

Previous :: Previous(int nRows, int nCols){  //constructor
    if (nRows <= 0 || nCols <= 0 || nRows > MAXROWS || nCols > MAXCOLS)
    {
        cout << "***** Previous grid created with invalid size " << nRows << " by "
        << nCols << "!" << endl;
        exit(1);
    }
    amtRows = nRows;
    amtCols = nCols;
    
    for (int r = 0; r < nRows; r++){ //beginning grid -- filled with dots
        for (int c = 0; c < nCols; c++)
            m_grid[r][c] = '.';
    }
} 

bool Previous :: dropACrumb(int r, int c){ //check if ros and cols would exceed
    
    if ((amtRows-r) < 0 || (amtCols - c) < 0 || r > amtRows || c > amtCols){
        return false; //false because the position is not within the grid
    }
    else{
        char& gridChar = m_grid[r-1][c-1]; //marking the position as the player arrives; updating grid if the position is valid 
        switch (gridChar)
        {
        case '.': gridChar = 'A'; break;
        case 'Z': break;
        default: gridChar++; break;
        }
        return true;
    }
}

void Previous :: showPreviousMoves() const{ //gives us updated grid -- we get the updated grid because we passed by reference with dropACrumb
    clearScreen();
    for (int r = 0; r < amtRows; r++){
        for (int c = 0; c < amtCols; c++){            cout << m_grid[r][c];
        }
        cout << endl; //creating a new line
    }
    cout << endl;
}
