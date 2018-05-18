//
// Created by pj on 5/13/18.
//

#include "Graph.h"


using namespace std;


// Allocates memory for adjacency list
Graph::Graph(int n) {

    // Graph member graph is STL container, list
    this->n = n;
    graph = new list<node>[n];

    ConnMtx = new bool*[n];
    for (int i = 0; i<n; ++i){
        ConnMtx[i] = new bool[n];
    }

    //initalize Conn Matrix
    for (int i = 0; i<n; ++i)
        for (int j = 0; j<n; ++j)
            ConnMtx[i][j] = false;

}


void Graph::addEdge(int srcNode, int targNode, int weight) {
    bool E;
    E = Graph::EdgeCheck(srcNode, targNode);
    if (!E)
    {
        graph[srcNode].emplace_back(make_pair(targNode, weight));
        ConnMtx[srcNode][targNode] = true;

        list<node>::iterator i;
        for (i = graph[srcNode].begin(); i != graph[srcNode].end(); ++i) {
            // Get point label and weight of current child of Node U.
            int U = (*i).getX();  // child node Vi
            int V = (*i).getY();  // Edge weight node U <-> Vi

            cout << "Source Node " << U << " --> Child Node " << V << endl;
        }

    }
    else
        cout << "Edge from " << srcNode << " to " << targNode << " already exists! " << endl;
    cout << endl;

}


void Graph::addNode(node newNode) {

    int NodeY = newNode.getY();
    int NodeX = newNode.getX();

    Graph::ConnMtx[NodeX][NodeY] = true;

}


//void Graph::delNode(node newNode) {
//    int NodeY = (newNode).getY();
//    int NodeX = (newNode).getX();
//
//    Graph::ConnMtx[NodeX][NodeY] = false;
//}

//void Graph::delEdge(int srcNode, int targNode) {
//    node tmpPair_targ(srcNode, VIRT_INF);
//    node tmpPair_src(targNode, VIRT_INF);
//
//    graph[targNode].push_back(tmpPair_src);
//    graph[srcNode].push_back(tmpPair_targ);
//
//
//}


bool Graph::EdgeCheck(int srcNode, int targNode) const {
    return ConnMtx[srcNode][targNode];
}

//int Graph::getEdge(int srcNode, int targNode) const {
//
//    node newNode(0,0);
//    int edgeWeight = VIRT_INF;
//
//    // Get  child nodes of srcNode  <childNode,weight> pair
//    //list<node>::iterator i;
//    for (auto i = graph[srcNode].begin(); i != graph[srcNode].end(); ++i) {
//        int Y = newNode.getY(); // weight of edge
//        int X = newNode.getX(); //child Node
//
//        if (X == targNode) {
//            edgeWeight = Y;
//            return edgeWeight;
//        } else
//            edgeWeight = VIRT_INF;  // Edge Does Not Exist
//    }
//
//    return edgeWeight;
//}

// Return pair
//node getNode(int srcNode) const;

//int Graph::getClosestNode(int srcNode) const {
    // Declare a set of pair pairs to store and pre-sort node list
   // set<node> pointSet;

  //  int closestNode = -1;  //Return -1 if there is no closest point

    // declare a temporary pair variable with our
    // user defined type "point"initialize to (0,0)
 //   node tmpPair(0, 0);

    //
    // the neighbors list
  //  vector<int> neigh = Graph::neighbors(srcNode);
  //  if (!neigh.empty()) {
        // put all child points of srcNode ( <childNode,weight> pair ) into the a set. .
        //list<node>::iterator i;
  //      for (auto i = graph[srcNode].begin(); i != graph[srcNode].end(); ++i) {

            //pointSet.insert(*i);
        // }

        // The first node in Set presorted  container is the minimum distance
        //tmpPair = *(pointSet.begin());

   //     int X = (tmpPair).getX();  // child node Vi is 1st of pair

   //     closestNode = X;
   // }
    //return closestNode;

// };


//vector<int> Graph::neighbors(int srcNode) const {
//    vector<int> adjacent;     // list of adjacent edges -1=NC 0=self  Edge=distance
//    bool neigh;
//
//    for (int i = 0; i < n; i++) {
//        neigh = Graph::ConnMtx[srcNode][i];
//        if (neigh) {
//            adjacent.push_back(i);
//        }
//    }
//
//    return adjacent;
//
//}

// Dijkstra Function
// Returns shortest paths from srcNode to all other vertices
//priority_queue< pair<int, int> >
   void     Graph::Dijkstra(int srcNode) {


    node tmpPair;
    // Create a priority queue to store nodes to be sorted in place

    priority_queue<node, vector<node>, greater<node>> PriorityQueue;

    //   {(node_i,weight_i)}

    // Create a vector for distances and initialize to INT16MAX)
    vector<int> dist(n, VIRT_INF);


    // declare a temporary pair variable and initialize to (0,0)
    //node c = (0, 0);



    // Insert source itself in priority queue and initialize
    // its distance as 0.
    tmpPair.Set(0,srcNode);
    PriorityQueue.push(tmpPair);
    dist[srcNode] = 0;

/* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!PriorityQueue.empty())
    {
        // The first node in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        tmpPair = PriorityQueue.top();
        int u = tmpPair.getY();
        PriorityQueue.pop();



        // 'i' is used to get all adjacent vertices of a vertex
        //list< pair<int, int> >::iterator i;
        for (auto i = graph[u].begin(); i != graph[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).getX();
            int weight = (*i).getY();

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                tmpPair.Set(dist[v], v);
                PriorityQueue.push(tmpPair);
            }
        }


    }

    cout << "Vertex   Distance from Source " << endl;
    for (int i = 0; i < n; ++i)
        cout << " \t" << i << "\t " << dist[i] << endl;

   // return pointSet;


}

Graph::~Graph() {

    for (int i = 0; i < n; ++i) {
        delete[] ConnMtx[i];
    }

    delete[] ConnMtx;
}