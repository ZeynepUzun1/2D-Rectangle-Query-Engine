//
//  TwoDimTreeNode.h
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 9.11.2025.
//

#ifndef _TWODIMTREENODE_H
#define _TWODIMTREENODE_H

#include "Rectangle.h"
#include "LinkedList.h"

class TwoDimTreeNode {
public:
    TwoDimTreeNode(const Rectangle & extent); // constructor
    ~TwoDimTreeNode(); // destructor

    void insertRectangle(const Rectangle & r_object); // inserts a rectangle into this subtree
    void search(int x, int y, LinkedList<Rectangle> & result); // finds all rectangles containing (x,y)

private:
    Rectangle Extent; // root
    LinkedList<Rectangle> Vertical; // rectangles that cross the vertical line
    LinkedList<Rectangle> Horizontal; // rectangles that cross the horizontal line
    /* Quadrants */
    TwoDimTreeNode* TopLeft;
    TwoDimTreeNode* TopRight;
    TwoDimTreeNode* BottomLeft;
    TwoDimTreeNode* BottomRight;

    int centerX() const;
    int centerY() const;

    bool intersectsVertical(const Rectangle& rect, int x_center) const;
    bool intersectsHorizontal(const Rectangle& rect, int y_center) const;
    Rectangle getChildren(int quadrant, int x_center, int y_center) const;
};

#endif
