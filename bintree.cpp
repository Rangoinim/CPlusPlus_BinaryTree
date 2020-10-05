/***********************************************************
Name: Cory Munselle
Assignment: 05
Purpose: bintree class that does all of the processing for a binary tree
Notes: Huge thank you to Prof. Katrompas, who helped me with removeNode and addNode
as well as general structuring for how to do recursion properly.
A thanks goes out to Diego as well, who helped me get through some parts I was stuck on.
***********************************************************/

#include "bintree.h"

//public member functions
BinTree::BinTree() {
    count = 0;
    root = nullptr;
}

BinTree::~BinTree() {
    clear(root);
}

bool BinTree::isEmpty() {
    bool empty = false;
    if (count == 0) {
        empty = true;
    }
    return empty;
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data* tempData) {
    bool success = false;
    if (root != nullptr) {
        tempData->id = root->data.id;
        tempData->information = root->data.information;
        success = true;
    }
    else {
        tempData->id = -1;
        tempData->information = "";
    }
    return success;
}

void BinTree::clear() {
    clear(root);
}

bool BinTree::addNode(int id, string data) {
    bool success = false;
    DataNode * newNode = new DataNode;
    newNode->data.id = id;
    newNode->data.information = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    if (addNode(newNode, &root) == true) {
        success = true;
    }
    return success;
}

bool BinTree::removeNode(int id) {
    bool success = false;
    int tempcount = count;
    root = removeNode(id, root);
    if (tempcount > count) {
        success = true;
    }
    return success;
}

bool BinTree::getNode(Data *tempdata, int id) {
    bool success = false;
    if (getNode(tempdata, id, root) == true) {
        success = true;
    }
    return success;
}

bool BinTree::contains(int id) {
    bool success = false;
    if (contains(id, root) == true) {
        success = true;
    }
    return success;
}

int BinTree::getHeight() {
    return getHeight(root);
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void BinTree::displayInOrder() {
    displayInOrder(root);
}

void BinTree::displayTree() {
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    if (isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Tree is not empty" << endl;
    }
    cout << "Height is " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
    cout << endl;
    cout << "Pre-order Traversal" << endl;
    displayPreOrder();
    cout << endl;
    cout << "In-order Traversal" << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-order Traversal" << endl;
    displayPostOrder();
}

//private member functions
void BinTree::clear(DataNode* temproot) {
    if (temproot != nullptr) {
        if (temproot->left != nullptr) {
            clear(temproot->left);
        }
        if (temproot->right != nullptr) {
            clear(temproot->right);
        }
        delete temproot;
    }
    root = nullptr;
    count = 0;
}

bool BinTree::addNode(DataNode * newNode, DataNode** temproot) {
    bool success = false;
    if ((*temproot) == nullptr) {
        *(temproot) = newNode;
        success = true;
        count++;
    }
    else {
        if ((*temproot)->data.id > newNode->data.id) {
            success = addNode(newNode, &(*temproot)->left);
        }
        else if ((*temproot)->data.id < newNode->data.id) {
            success = addNode(newNode, &(*temproot)->right);
        }
    }
    return success;
}

DataNode* BinTree::removeNode(int id, DataNode* temproot) {
    if (temproot != nullptr) {
        if (temproot->data.id > id) {
            temproot->left = removeNode(id, temproot->left);
        }
        else if (temproot->data.id < id) {
            temproot->right = removeNode(id, temproot->right);
        }
        else {
            DataNode * temp;
            if (temproot->left == nullptr) {
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }
            else if (temproot->right == nullptr) {
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }
            else {
                temp = findSmallest(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
}

bool BinTree::getNode(Data* tempData, int id, DataNode* temproot) {
    bool success = false;
    if (temproot != nullptr) {
        if (temproot->data.id == id) {
            tempData->id = temproot->data.id;
            tempData->information = temproot->data.information;
            success = true;
        }
        else if (temproot->data.id > id ) {
            success = getNode(tempData, id, temproot->left);
        }
        else if (temproot->data.id < id ) {
            success = getNode(tempData, id, temproot->right);
        }
    }
    return success;
}

bool BinTree::contains(int id, DataNode* temproot) {
    bool success = false;
    if (temproot != nullptr) {
        if (temproot->data.id == id) {
            success = true;
        }
        else if (temproot->data.id > id ) {
            success = contains(id, temproot->left);
        }
        else if (temproot->data.id < id ) {
            success = contains(id, temproot->right);
        }
    }
    return success;
}

int BinTree::getHeight(DataNode* temproot) {
    int height = 0;
    if (temproot != nullptr) {
        height = 1 + max(getHeight(temproot->left), getHeight(temproot->right));
    }
    return height;
}

void BinTree::displayPreOrder(DataNode* temproot) {
    if (temproot != nullptr)
    {
        cout << temproot->data.id << ": " << temproot->data.information << endl;
        if (temproot->left != nullptr) {
            displayPreOrder(temproot->left);
        }
        if (temproot->right != nullptr) {
            displayPreOrder(temproot->right);
        }
    }
}

void BinTree::displayPostOrder(DataNode* temproot) {
    if (temproot != nullptr)
    {
        if (temproot->left != nullptr) {
            displayPostOrder(temproot->left);
        }
        if (temproot->right != nullptr) {
            displayPostOrder(temproot->right);
        }
        cout << temproot->data.id << ": " << temproot->data.information << endl;
    }
}

void BinTree::displayInOrder(DataNode* temproot) {
    if (temproot != nullptr)
    {
        if (temproot->left != nullptr) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << ": " << temproot->data.information << endl;
        if (temproot->right != nullptr) {
            displayInOrder(temproot->right);
        }
    }
}

DataNode* BinTree::findSmallest(DataNode* temproot) {
    while (temproot != nullptr && temproot->left != nullptr) {
        temproot = temproot->left;
    }
    return temproot;
}
