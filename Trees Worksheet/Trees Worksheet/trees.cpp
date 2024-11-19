//
//  main.cpp
//  Trees Worksheet
//
//  Created by Coco Li on 8/16/23.
//

#include <iostream>
#include <vector>
using namespace std;

//3 Implement all of the following depth-first-search (DFS) traversals of a binary tree, and write the time complexity of each:

struct Node{
    int val;
    Node *left, *right;
};

void helpInOrderTraversal(Node *root, vector<int> &nodes){
    if (root == nullptr){return;}
    helpInOrderTraversal(root -> left, nodes); //left
    nodes.push_back(root -> val); //cur
    helpInOrderTraversal(root -> right,nodes); //right
}

//inOrder Traversal --> left, current, and right
vector<int> inorderTraversal(Node* root) { // Fill in code
    vector <int> nodesI;
    helpInOrderTraversal(root, nodesI);
    return nodesI; //everything is inOrder traversal
}


void helpPreOrderTraversal(Node *root, vector <int> &nodes){  //we want to pass by reference because we will return the bector
    if (root == nullptr){return;}
    nodes.push_back(root -> val);
    helpPreOrderTraversal(root -> left, nodes);
    helpPreOrderTraversal(root -> right, nodes);
}

//pre order traversal is current node, left, then right
vector<int> preorderTraversal(Node* root) {
    vector <int> nodesP;
    helpPreOrderTraversal(root, nodesP);
    return nodesP;
}

void helpPostOrderTraversal(Node *root, vector<int> &nodes){
    if (root == nullptr){return;}
    helpPostOrderTraversal(root -> left, nodes);
    helpPostOrderTraversal(root ->right, nodes);
    nodes.push_back(root -> val);
}

//post order is left to right ot current

vector<int> postorderTraversal(Node* root) {
    vector <int> nodesPO;
    helpPostOrderTraversal(root, nodesPO);
    return nodesPO;
}

//4. Given an in-order and post-order traversal of the same tree, draw the binary tree.
//in-order: 4,2,5,1,6,7,3,8
//post-order: 4, 5, 2, 6, 7, 8, 3, 1
//have ipad

//5.

//potential has left and right

bool isSubtree(Node* main, Node* potential){
    if (potential == nullptr){
        return true;
    }
    if (main == nullptr){
        return false;
    }
    if (main -> val == potential -> val && main -> left -> val == potential -> left -> val && main -> right -> val == potential -> right -> val){
        return true;
    }
    bool res = isSubtree(main -> left, potential);
    if (res == true) //found the subtree in the left
        return true;
    return isSubtree(main -> right, potential);
}

void reverse(Node* root){
    if (root != nullptr){
        Node *temp = root;
        root -> left = root -> right;
        root -> right = temp;
        reverse(root -> left);
        reverse(root -> right);
    }
}


int main() {
    
    cout << min(1/2+2,9) << endl;
    
}


