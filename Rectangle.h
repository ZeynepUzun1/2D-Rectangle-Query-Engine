//
//  Rectangle.h
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 9.11.2025.
//

#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include <iostream>
using namespace std;

class Rectangle {
public:
    // Default constructor
    Rectangle();

    // Constructor
    Rectangle(int top, int left, int bottom, int right);

    // Getter functions
    int getTop() const;
    int getLeft() const;
    int getBottom() const;
    int getRight() const;
    /* Mentioned in the implementation file */
    bool contains(int x, int y) const;
    bool intersectsVerticalLine(int x) const;
    bool intersectsHorizontalLine(int y) const;
    void print() const;
    /* Mentioned in the implementation file */

private:
    int Top;
    int Left;
    int Bottom;
    int Right;
};

#endif
