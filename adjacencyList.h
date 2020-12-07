#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map> 
#include <unordered_map>
using namespace std;

class AdjacencyList{ 
public:
    struct Node{
        string name;
        double rank = 0.00; // starts off as 1/numVertices, but changes as p iterations continue 
        Node(string name){ this->name = name; }
    };

    AdjacencyList(int toPrint){
        numToPrint = toPrint;
    }

    void addEdge(string from, string to);
    void print();

private:
    unordered_map<string, vector<string>> outDegree; // returns vec of who they are pointing to 
    map<string, Node*> nodes; // keep track of pages + their ranks 
    static int numToPrint;
};

void AdjacencyList::addEdge(string from, string to){
    outDegree[from].push_back(to); // vec of who they are pointing to 

    Node* newFrom = new Node(from);
    nodes.emplace(from, newFrom); // will not replace if already created 
}