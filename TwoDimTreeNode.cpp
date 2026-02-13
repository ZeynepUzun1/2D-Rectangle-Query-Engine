//
//  TwoDimTreeNode.cpp
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 15.11.2025.
//

#include "TwoDimTreeNode.h"
#include <iostream>
using namespace std;

TwoDimTreeNode::TwoDimTreeNode(const Rectangle& extent)
    : Extent(extent), TopLeft(NULL), TopRight(NULL),
      BottomLeft(NULL), BottomRight(NULL) {}  // Default constructor

// To avoid memory leak
TwoDimTreeNode::~TwoDimTreeNode() {
    delete TopLeft;
    delete TopRight;
    delete BottomLeft;
    delete BottomRight;
}

int TwoDimTreeNode::centerX() const {
    return (Extent.getLeft() + Extent.getRight()) / 2; // Computing vertical x
}

int TwoDimTreeNode::centerY() const {
    return (Extent.getTop() + Extent.getBottom()) / 2; // Computing horizontal y
}

bool TwoDimTreeNode::intersectsVertical(const Rectangle& rect, int x_center) const {
    return rect.intersectsVerticalLine(x_center); // Checking if rectangle crosses x_center
}

bool TwoDimTreeNode::intersectsHorizontal(const Rectangle& rect, int y_center) const {
    return rect.intersectsHorizontalLine(y_center); // Checking if rectangle crosses y_center
}

Rectangle TwoDimTreeNode::getChildren(int quadrant, int x_center, int y_center) const {
    if (quadrant == 1) {
        return Rectangle(Extent.getTop(), Extent.getLeft(), y_center, x_center);  // TopLeft
    }
    if (quadrant == 2) {
        return Rectangle(Extent.getTop(), x_center, y_center, Extent.getRight()); // TopRight
    }
    if (quadrant == 3) {
        return Rectangle(y_center, Extent.getLeft(), Extent.getBottom(), x_center); // BottomLeft
    }
    if (quadrant == 4) {
        return Rectangle(y_center, x_center, Extent.getBottom(), Extent.getRight()); // BottomRight
    }
    return Rectangle();
}

void TwoDimTreeNode::insertRectangle(const Rectangle& r_object) {
    // If node is too small to subdivide further
    if (Extent.getRight() - Extent.getLeft() <= 1 || Extent.getBottom() - Extent.getTop() <= 1) {
        Vertical.append(r_object); // This can also be horizontal, we just have to store it so we don't lose
        return;
    }

    int x_center = centerX(); // Determining center x
    int y_center = centerY(); // Determining center y
    bool intersect_v = intersectsVertical(r_object, x_center);  // Checks if intersects vertically
    bool intersect_h = intersectsHorizontal(r_object, y_center); // Checks if intersects horizontally

    if (intersect_v == true) { // if it intersects vertical line
        Vertical.append(r_object); // store in vertical list
        return;
    }

    if (intersect_h) { // if it intersects horizontal line
        Horizontal.append(r_object); // store in horizontal list
        return;
    }

    int quadrant = 0;

    if (r_object.getRight() <= x_center && r_object.getBottom() <= y_center) {
        quadrant = 1; // TopLeft
    }
    else if (r_object.getLeft() >= x_center && r_object.getBottom() <= y_center) {
        quadrant = 2; // TopRight
    }
    else if (r_object.getRight() <= x_center && r_object.getTop() >= y_center) {
        quadrant = 3; // BottomLeft
    }
    else if (r_object.getLeft() >= x_center && r_object.getTop() >= y_center) {
        quadrant = 4; // BottomRight
    }

    TwoDimTreeNode** child_node = NULL;   // setting pointer to the child

    if (quadrant == 1) {
        child_node = &TopLeft;
    }
    else if (quadrant == 2) {
        child_node = &TopRight;
    }
    else if (quadrant == 3) {
        child_node = &BottomLeft;
    }
    else if (quadrant == 4) {
        child_node = &BottomRight;
    }

    if (*child_node == NULL) { // A child subtree must exists
        *child_node = new TwoDimTreeNode(getChildren(quadrant, x_center, y_center));
    }

    (*child_node)->insertRectangle(r_object); // Using recursion to insert to the correct child
}

void TwoDimTreeNode::search(int x, int y, LinkedList<Rectangle> & result) {
    const Rectangle * rect_ptr; // Pointer used to iterate list nodes

    Vertical.reset(); // Setting current to head
    rect_ptr = Vertical.getNext();
    while (rect_ptr != NULL) {
        if (rect_ptr->contains(x, y)) { // If (x,y) exists
            result.append(*rect_ptr); // append it to the result
        }
        rect_ptr = Vertical.getNext(); // move to next rectangle
    }

    Horizontal.reset();  // Setting current to head
    rect_ptr = Horizontal.getNext();
    while (rect_ptr != NULL) {
        if (rect_ptr->contains(x, y)) {
            result.append(*rect_ptr); // append matching rectangle to result list
        }
        rect_ptr = Horizontal.getNext();    // next rectangle
    }

    if (Extent.getRight() - Extent.getLeft() <= 1 || Extent.getBottom() - Extent.getTop() <= 1) {
        return;
    }

    int x_center = centerX(); // Center x
    int y_center = centerY(); // Center y

    TwoDimTreeNode * next = NULL; // Next tree pointer

    if (x < x_center) {
        if (y < y_center) {
            next = TopLeft;
        }
        else {
            next = BottomLeft;
        }
    }
    else {
        if (y < y_center) {
            next = TopRight;
        }
        else {
            next = BottomRight;
        }
    }

    if (next != NULL) {
        next->search(x, y, result);   // Recursively searching the next quadrant
    }
}
