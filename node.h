//
// Created by pj on 5/13/18.
//

#ifndef PRIORITY_QUEUE_METHOD_NODE_H
#define PRIORITY_QUEUE_METHOD_NODE_H



#include <iostream>
#include <cmath>
#include<vector>
#include<random>
#include <algorithm>
#include <iostream>
#include<cstdlib>

using namespace std;

const int VIRT_INF = INT16_MAX;
const int N = 50;  //Global constant for number of nodes
const int M = 1000;  //Global constant for number of nodes
// Point class tuple of 2-elements (x,y).  Could be a node on a monitor
// a point on a Cartesian plane or a Node in a Graph

class node {

private:

    int x;
    int y;

public:

    // node(int x = 0, int y = 0):x(x),y(y){} // constructor

    // required constructors.  This was necessary in lieu of
    // the above commented out constructor to do the comparison
    // operator overloading.  I'm not sure why.
    node() {
        x = 0;
        y = 0;
    }
    node(int u, int v) {
        x = u;
        y = v;
    }

    // ~node();

    // No destructor is required here.  compiler creates a default destructor for us.
    // The default destructor works fine unless we have dynamically allocated memory
    // or pointer in class. When a class contains a pointer to memory allocated in
    // class, we should write a destructor to release memory before the class
    // instance is destroyed. This must be done to avoid memory leaks

    // Class members
    int getX();
    int getY();
    void Set(int x, int y){this->x = x; this->y = y;}

    // int Edge(const node &) const;   // Define the Edge as the maggnitude of the difference btw pxs

    //Operator Overloders
    node operator+(const node &) const; // operator+()
    node operator-(const node &) const; // operator-()
    bool operator!=(const node &) const; // operator !=(not equal to)
    bool operator==(const node &) const; // operator==(equal to)
    // ostream overloader must be declared a friend of the class to access private memebers
    friend ostream&  operator<<(ostream &out,const node &p);

};

#endif //PRIORITY_QUEUE_METHOD_NODE_H
