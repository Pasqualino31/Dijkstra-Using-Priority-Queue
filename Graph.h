//
// Created by pj on 5/13/18.
//

#ifndef PRIORITY_QUEUE_METHOD_GRAPH_H
#define PRIORITY_QUEUE_METHOD_GRAPH_H


using namespace std;


#include<bits/stdc++.h>
#include <iostream>
#include <random>
#include <set>
#include <vector>
#include <utility>
#include <iterator>
#include <list>
#include <functional>
#include "node.h"




class Graph {

private:

    int n;
    list< node > *graph;  // graph is an array of lists of edges
    bool **ConnMtx;



public:

    Graph() : n(), graph(), ConnMtx() {};

    explicit Graph(int n);

    ~Graph();

    //void initGraph(int n);

    //    add_edge(G, x, y): adds the edge from the vertex x to the vertex y, if it is not there;
    void addEdge(int srcNode, int targNode, int weight);

    //    addNode(G, x): adds the vertex x, if it is not there;
    void addNode(node newNode);

    //    deledge(G, x, y): removes the edge from the vertex x
    // to the vertex y, if it is there (or not);
  //  void delEdge(int srcNode, int targNode);



 //   void delNode(node newNode);

    // getNode_value(G, x): returns the point associated with
    // the NodeList index x  ( Nodelist(x) );
 //   node getNode(int srcNode) const;


    //    getEdge(G: x, y): returns the value associated with the edge (x, y);
//    int getEdge(int srcNode, int targNode) const;


 //   int getClosestNode(int srcNode) const ;

    //EdgeCheck(G: x, y): tests whether there is an edge
    // from the vertex x to the vertex y
    bool EdgeCheck(int srcNode, int targNode) const;

    //neighbors(G: x): lists all vertices y such that there is
    // an edge from the vertex x to the vertex y;
 //   vector<int> neighbors(int srcNode) const;

    // Dijkstra Funtion
    // Returns shortest paths from srcNode to all other vertices
    //priority_queue< pair<int, int> >
    void Dijkstra(int srcNode);


};




#endif //PRIORITY_QUEUE_METHOD_GRAPH_H
