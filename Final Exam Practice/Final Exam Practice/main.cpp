//
//  main.cpp
//  Final Exam Practice
//
//  Created by Coco Li on 8/21/23.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape{
public:
    Shape(){};
    virtual int computeArea(int x, int y) = 0;
};

class square:public Shape{
public:
    square(int x, int y){m_x = x; m_y = y;};
    virtual int computeArea(int x, int y){
        return x*y;
    }
    int computePerimeterSquare(int x, int y){
        return (2*x) + (2*y);
    }
private:
    int m_x;
    int m_y;
};

class triangle:public Shape{
public:
    triangle(int x, int y){m_x = x; m_y = y;}
    virtual int computeArea(int x, int y){
        return (x*y)/2;
    }
private:
    int m_x;
    int m_y;
};

struct TreeNode
{
   double m_data;
   TreeNode* m_left;
   TreeNode* m_right;
};

double sumOfSingleParentNode(TreeNode *ptr){
    if (ptr == nullptr){return 0.0;} //base cases
    if (ptr -> m_left == nullptr || ptr -> m_right == nullptr){return ptr -> m_data;} //basecases
    int sum1 = sumOfSingleParentNode(ptr -> m_left);
    int sum2 = sumOfSingleParentNode(ptr -> m_right);
    return sum1 + sum2;
}
bool getYourKicksHelp(double target, TreeNode *ptr){
    if (ptr == nullptr){return false;}
    if (ptr -> m_left == nullptr || ptr -> m_right == nullptr){
        return ptr -> m_data;
    }
    int prod1 = ptr -> m_data * getYourKicksHelp(target, ptr -> m_left);
    int prod2 = ptr -> m_data * getYourKicksHelp(target, ptr -> m_right);
    if (prod1 == target || prod2 == target){return true;}
    return false;
}
//
//bool getYourKicksOnRoute66(double target){
//    return getYourKicksHelp(target,m_root);
//}

int main() {
    
    
//    vector <Shape*> test;
//    triangle t (6,6);
//    square s(2,8);
//
//    test.push_back(&t);
//    test.push_back(&s);
//
//    for (int i = 0; i < test.size();i++){
//        if (instanceof<triangle>(test[i])){
//            cout << "i am triangle" << endl;
//        }
//        if (instanceof<square>(test[i])){
//            cout << "i am square" << endl;
//        }
//    }
//    cout << 29%11 << endl;
    
    int x = -33;
    int y = 8;
    
    cout << floor(x/y) << endl;
    
}
