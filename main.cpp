//*********************************************************************
//         Graph Generator
//
//         One Giant mess of a program to verify the algorithms
//         To be used to generate the Graph for the Dijkstra Project
//
//    Patrick Donaldson  pasqualino31@gmail.com
//
//********************************  Main Program  **********************
#include <iostream>
#include <cmath>
#include<vector>
#include<random>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <utility>
#include "Graph.h"
#include "node.h"

using namespace std;


int main() {

    cout << "Welcome to Assignment #2!!!   Dysktra's Shortest Path Algorithm and The Graph ADT" << endl;
    cout << endl;


    Graph grph(N);   //declare var graph of ADT Graph

    //bool endPath = false;
    //bool Nlist[N] = {false};

    int x = 0;
    int y = 0;


    int StartNode = 0;

    int NodeCnt = 0;
    int EdgeCnt = 0;
    int DupliCount = 0;
    int RandInt = 0;


    int Ui = 0;
    int Vi = 0;
    int Uj = 0;
    int Vj = 0;

    int lowr = 400;
    int uppr = 600;

    node pt(0,0);
    node ptj(0,0);
    node pti(0,0);

    std::vector<int> Children(N);
    int *ch = Children.data();

    vector<node>  NodeList(N);    // declare Vector of N points init to 0
    node *p = NodeList.data();  // declare and set a ptr to point to the base loc of NodeList

// declare a vector of a vector of ints.  Not to be confused with a matrix of ints

    vector<int> EdgeList(N);     // list of edges for each point INT16_MAX=NC 0=self  Edge=distance
    int *Edge = EdgeList.data();
    int EdgeWeight = 0;          //weight of edge will be the distance btw points



    //--------------------  END Declarations --------------------------------------------//



    // Generate N random, unique points

//Random int generator
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, N-1);
    std::uniform_int_distribution<> disr(0, M-1);

    std::cout << "The 50 random and Unique Nodes are: " << std::endl;
// Generate Node 0
    x = dis(gen); //
    y = dis(gen); // generate a random px
    pt.Set(x, y); //
    *p = pt;  //put point 0 in the Nodelist
    grph.addNode(pt);         // add node to Graph

// ostream overload can't handle the point pair reference
// a temp value ptj for the point is assigned for display purposes
    pti = NodeList[NodeCnt];
    Ui = pti.getX();
    Vi = pti.getY();
    std::cout << "Node[" << NodeCnt << "] =(" << Ui << ",";
    std::cout << Vi << ")   ";
    ++p;           // advance pxr to next NodeList location
    NodeCnt = 1;   //Node is added to vector, so advance the coun

// point 0 is assigned, now generate the next N-1 values checking for duplicates

    while (NodeCnt < N) {
        x = dis(gen);   //
        y = dis(gen);   // generate a new random point
        pt.Set(x, y); //   //

        // Check to see if pt is already on the Node List
        auto NL_iterator = find(begin(NodeList), end(NodeList), pt);
        if (NL_iterator != std::end(NodeList)) {   // This Node Already exists, Do not advance Node Cntr
            //std::cout << "Nodelist Already Contains: " << pt << std::endl;  // uncomment to disp duplicate event
            ++DupliCount;  // monitor the number of times a duplicate point is generated for stats
        }
        else {
            // Node pt is unique, add to pointlist and add to Graph
            *p = pt;       // put pt in NodeList
            ptj = NodeList[NodeCnt];
            grph.addNode(ptj);
            Uj = ptj.getX();
            Vj = ptj.getY();
            cout << "Node[" << NodeCnt << "] =(" << Uj << ",";
            cout << Vj << ")   ";
            if (NodeCnt % 5 == 0)  // for disp formating purposes
                cout << std::endl;
            ++p;           // advance ptr to next NodeList location
            ++NodeCnt;        // advance Node counter

        }
    }
    cout << std::endl;
    cout << "---------------------------------------------  " << endl;
    cout << "   Local unconnected graph has been created    " << endl;
    cout << "---------------------------------------------  " << endl;

// Generate the boolean connected graph and populate the adjacency matrix set.

    for (int i = 0; i < N; i++) {
        pti = NodeList[i];         // read node from Node list
        Uj = pti.getX();
        Vj = pti.getY();
        cout << " " << std::endl;
        EdgeCnt = 0;
        cout << "Node[" << i << "] (" << Ui << "," << Vi << ") has been added to Graph" << std::endl;
        cout << "Node[" << i << "] (" << Ui << "," << Vi << ") is connected to: " << std::endl;

        for (int j = 0; j < N; ++j) {     // assign edges based on probability

            ptj = NodeList[j];
            Uj = ptj.getX();
            Vj = ptj.getY();

            RandInt = disr(gen);
            if ((Ui == Uj) && (Vi == Vj)) {        //The self referenced point has a weight of 0
                EdgeWeight = 0;
                *Edge = EdgeWeight;
                cout <<" Itself: -->Node[" << j << "] "<<" @ ("<< Uj<< ","<<Vj<<")";
                cout <<" Edge = "<< EdgeWeight<<std::endl;
                cout <<std::endl;
                ++Edge;
                grph.addEdge(i, j, EdgeWeight);
            } else if ((RandInt < lowr) || (RandInt >= uppr)) { // 80% of the time
                EdgeWeight = VIRT_INF;  //  virt inf (edge doesn't exist)
                *Edge = EdgeWeight;
                ++Edge;

            }
            else     // 20% of the time
            {

                Uj = ptj.getX();
                Vj = ptj.getY();
                cout <<"  -->Node[" << j << "] "<<" @ ("<< Uj<< ","<<Vj<<")";
                Uj = Uj - pti.getX();   // Uj = Uj-Ui
                Vj = Vj - pti.getY();   // Vj = Vj-Vi
                EdgeWeight = (int) sqrt((Uj * Uj + Vj * Vj));  // edge weight is the distance btw points
                grph.addEdge(i, j, EdgeWeight);
                *Edge = EdgeWeight;
                ++EdgeCnt;
                std::cout <<" Edge = "<< EdgeWeight<<std::endl;
                if (EdgeCnt % 5 == 0)  // for disp formating purposes
                    cout << std::endl;
            }
            ++Edge;

        }

        for (int k = 0; k < N; ++k)  //  back the pointer up for mem mgt otherwise it will keep
            --Edge;                  // advancing.  Assigning the vect in the manner
        // above doesn't take advantage of the STL mem mgt
    }

    cout << "------------------------------ Graph is populated ----------------------------" << endl;
//
//--------------------------------------- Graph is populated ------------------------------  //
//


   //auto ShortestPath =
           grph.Dijkstra(StartNode);

};


