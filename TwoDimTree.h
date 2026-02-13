//
//  TwoDimTree.h
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 9.11.2025.
//

#ifndef _TWODIMTREE_H
#define _TWODIMTREE_H

#include "TwoDimTreeNode.h"

class TwoDimTree {
private:
    // Pointer to the root node
    TwoDimTreeNode *  root;

public:
    // Constructor
    TwoDimTree();
    // Destructor
    ~TwoDimTree();
    // Initializes the root (extent) in our case
    void setExtent(const Rectangle & extent);

    // Inserts a rectangle into the tree
    void insertRectangle(const Rectangle & r_object);

    // Returns a list containing all rectangles
    LinkedList<Rectangle> intersectingRect(int x, int y) const;
};

#endif
