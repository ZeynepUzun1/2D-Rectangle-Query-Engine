//
//  main.cpp
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 9.11.2025.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TwoDimTree.h"
#include "LinkedList.h"
using namespace std;

// Struct for storing inputs
struct QueryInp {
    int x;
    int y;
    
    QueryInp() : x(0), y(0) {} // default constructor
    QueryInp(int x_val, int y_val) : x(x_val), y(y_val) {} // stores given point
};

int main() {
    ifstream read("rectdb.txt");  // reading the file
    string line; // represents the lines of the file

    getline(read, line);
    istringstream iss(line); // parses the lines
    int extent_top, extent_left, extent_bottom, extent_right;  // coordinates of the extent (root)
    iss >> extent_top >> extent_left >> extent_bottom >> extent_right;
    // Setting a rectangle (Extent) variable
    Rectangle extent(extent_top, extent_left, extent_bottom, extent_right);
    
    TwoDimTree tree;
    tree.setExtent(extent);

    int top, left, bottom, right; // rectangle coordinates for each rectangle
    
    while (getline(read, line)) {
        istringstream r_iss(line);
        r_iss >> top;
        if (top == -1) { // If the first element of the line is equal to 1, we stop
            break;
        }
        
        r_iss >> left >> bottom >> right;
        Rectangle rect(top, left, bottom, right); // construct R object
        tree.insertRectangle(rect); // insert into tree
    }
    
    LinkedList<QueryInp> inputs;  // list storing all input (x,y) points
    int x, y; // variables to read each query
    
    while (cin >> x >> y) {
        inputs.append(QueryInp(x, y)); // storing query in a list
        if (x == -1) {
            break;
        }
    }
    
    inputs.reset(); // setting current to head
    const QueryInp * x_y = inputs.getNext();
    
    while (x_y != NULL) {
        if (x_y->x == -1) {
            break;
        }
        
        cout << x_y->x << " " << x_y->y << endl; // print queries
        
        LinkedList<Rectangle> results = tree.intersectingRect(x_y->x, x_y->y);
        cout << results.getSize() << endl; // print number of matches
        
        results.reset(); // reset iterator to head for results
        const Rectangle * rect = results.getNext(); // pointer to each matching rectangle
        while (rect != NULL) { // until the end of the list
            rect->print();
            cout << endl;
            rect = results.getNext();
        }
        
        x_y = inputs.getNext(); // moving to next query
    }
    read.close();
    return 0;
}
