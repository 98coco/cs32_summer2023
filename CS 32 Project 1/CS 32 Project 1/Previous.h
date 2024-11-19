//
//  Previous.h
//  CS 32 Project 1
//
//  Created by Coco Li on 6/30/23.
//

#ifndef PREVIOUS_H
#define PREVIOUS_H
#include "globals.h"

class Previous
{
public:
    Previous(int nRows, int nCols);
    bool dropACrumb(int r, int c);
    void showPreviousMoves() const;
    
private:
    int amtRows;
    int amtCols;
    char m_grid[MAXROWS][MAXCOLS];
};


#endif /* Previous_h */
