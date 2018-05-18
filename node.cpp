//
// Created by pj on 5/13/18.
//
#include "node.h"
#include <iostream>
#include<random>


using namespace std;


ostream &operator<<(ostream &out, const node &p) {
    out << "(" << p.x << ',' << p.y << ")" << endl;

    return out;
}


// define overloaded + (plus) operator
node node::operator+(const node &c) const {
    node result;
    result.x = (this->x + c.x);
    result.y = (this->y + c.y);
    return result;
}

// define overloaded - (minus) operator
node node::operator-(const node &c) const {
    node result;
    result.x = (this->x - c.x);
    result.y = (this->y - c.y);
    return result;
}

// define overloaded != (not equal) operator
bool node::operator!=(const node &c) const {
    {
        if ((this->x != c.x) && (this->y != c.y))
            return true;
    }
    return false;
}

// define overloaded == (equal) operator
bool node::operator==(const node &c) const {
    {
        if ((this->x == c.x) && (this->y == c.y))
            return true;
    }
    return false;
}


int node::getX() {
    return x;
}

int node::getY() {
    return y;
}
