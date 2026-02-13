//
//  LinkedList.h
//  cs300_h1.cpp
//
//  Created by Zeynep Uzun on 9.11.2025.
//

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

// Using course material, I declared 'template' classes type T
template <class T>
struct Node {
    T data; // value we store in the node
    Node<T>* next; // pointer to the next node in the list

    // constructor
    Node(const T& value) : data(value), next(NULL) {}
};

template <class T>
class LinkedList {
private:
    Node<T>* head; // pointer to the first node
    Node<T>* iterator; // node for iteration
    int size; // number of items in the list

public:
    // constructor
    LinkedList() : head(NULL), iterator(NULL), size(0) {}
    
    // destructor
    ~LinkedList() {
        Node<T>* temp = head;
        while (temp != NULL) {
            Node<T>* next = temp->next; // store next before deleting
            delete temp;
            temp = next;
        }
    }

    // Adds new element to the end of the list if the list is not empty, if empty sets the head
    void append(const T& val) {
        Node<T>* newNode = new Node<T>(val); // creates new node

        if (head == NULL) { // if list is empty
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            // Going until last node
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode; // attach new node
        }
        size++; // incrementing the count accordingly
    }

    // Returns number of nodes in the list
    int getSize() const {
        return size;
    }

    // Reset iterator to head
    void reset() {
        iterator = head;
    }
    
    const T* getNext() {
        if (iterator == NULL) { // to determine if we reached end
            return NULL;
        }
        T* result = &iterator->data; // get current node's data
        iterator = iterator->next; // moving the iterator
        return result;
    }

    // Print all items in the list
    void printList() const {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next; // goes to next node
        }
        cout << endl;
    }
};

#endif
