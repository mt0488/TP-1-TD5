#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Graph{

public:
    Graph(); //Constructor default
    Graph(int n); //Constructor con parametros

    void addNode(int n);
    void delNode(int n);
    void addEdge(int n1, int n2);
    void delEdge(int n1, int n2);
    set<int> getNeighbors(int n);
    set<pair<int,int>> edges();
    int qNeighbors(int n); //Cantidad de vecinos de un nodo
    bool conflicto(int n1, int n2); //verificar la existencia de una arista
    set<int> nodes(); int qNodes();

private:
    set<int> nodos_;
    set<pair<int, int>> aristas_;
    map<int, set<int>> vecinos_;
    map<int, int> cant_vecinos_;
    int cant_nodos;

};  

#endif