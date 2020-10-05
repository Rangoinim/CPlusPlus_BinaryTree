/***********************************************************
Name: Cory Munselle
Assignment: 05
Purpose: contains all of the necessary includes and function prototypes for bintree.cpp
Notes:
***********************************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include "data.h"
#include <algorithm>
#include <string>
#include <iostream>

using std::string;
using std::max;
using std::cout;
using std::endl;

class BinTree
{
    public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void clear();
    bool addNode(int, string);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();
    void displayTree();

    private:
    DataNode *root;
    int count;
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    DataNode* findSmallest(DataNode*);
};

#endif /* BINTREE_H */

