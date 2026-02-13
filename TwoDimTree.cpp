//
//  TwoDimTree.cpp
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 15.11.2025.
//

#include "TwoDimTree.h"
#include <iostream>
using namespace std;

// Default constructor
TwoDimTree::TwoDimTree() : root(NULL) {}

// Destructor:
TwoDimTree::~TwoDimTree() {
    delete root;
}

// Initializes the root (extent)
void TwoDimTree::setExtent(const Rectangle & extent) {
    if (root != NULL) {
        delete root;   // deletes old root
    }
    root = new TwoDimTreeNode(extent);  // creates new root
}

// Inserts a rectangle into the tree
void TwoDimTree::insertRectangle(const Rectangle & r_object) {
    if (root != NULL) {
        root->insertRectangle(r_object);
    }
}

// Returns a list containing all intersecting rectangles
LinkedList<Rectangle> TwoDimTree::intersectingRect(int x, int y) const {
    LinkedList<Rectangle> output;
    if (root != NULL) {
        root->search(x, y, output); // Recursively searching until the root is not NULL (base)
    }

    return output;
}
