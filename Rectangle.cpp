//
//  Rectangle.cpp
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 15.11.2025.
//

#include "Rectangle.h"

// Default constructor
Rectangle::Rectangle() : Top(0), Left(0), Bottom(0), Right(0) {}

// Parametric constructor
Rectangle::Rectangle(int top, int left, int bottom, int right)
    : Top(top), Left(left), Bottom(bottom), Right(right) {}


// Getter functions (because top, bottom, left and right are private)
int Rectangle::getTop() const {
    return Top;
}

int Rectangle::getLeft() const {
    return Left;
}

int Rectangle::getBottom() const {
    return Bottom;
}

int Rectangle::getRight() const {
    return Right;
}


// To check whether a point is inside the rectangle or not
bool Rectangle::contains(int x, int y) const {
    return (Left <= x && x < Right && Top <= y && y < Bottom); // Boundaries given in the document
}

// A Bool function that checks if a vertical line crosses the rectangle
bool Rectangle::intersectsVerticalLine(int x) const {
    return (Left <= x && x < Right);
}

// A Bool function that checks if a horizontal line crosses the rectangle
bool Rectangle::intersectsHorizontalLine(int y) const {
    return (Top <= y && y < Bottom);
}

// Prints all the values
void Rectangle::print() const {
    cout << Top << " " << Left << " " << Bottom << " " << Right;
}
