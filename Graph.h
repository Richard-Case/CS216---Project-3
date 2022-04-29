/*
 * File: Graph.h
 * Course: CS216-00x
 * Project: Lab 11
 * Purpose: Declaration of Graph class
 *          This class represents an undirected Graph (no weight on each edge)
 *          using adjacent map representation
 *          It contains one private data memeber: adjMap
 *          which represents the mapping from a Vertex, say u (key) to a set of vertices (value) which directly connect to u
 *
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <set>
#include <queue>
#include <iostream>

const int NO_PATH = -1;
const int INVALID_VERTEX = -2;

template <typename T>
class Graph
{
public:

	// Check to see if an edge exists between two points.
    bool HasEdge(T T1, T T2) const;

    // Add an edge between two points.
    void AddEdge(T T1, T T2);

    // Apply BFS to find the shortest path from the starting point to the destination.
    // Return the distnace from the start to the finish.
    // If either doesn't exist, return INVALID_VERTEX (-2)
    // If noth path exists, return NO_PATH (-1)
    // store the shortest path distance from the given source s  to vertex w in distance map<w, distance>
    // store which next vertex to go through on the shortest path to the given source s in go_through map<w, v>.
    // Here a pair <w, v> in go_through map represents on the shortest path from w to the given source s, it needs to take the path: w-->v...-->s
    int BFS(T& T1, T& T2, std::map<T, int>& T3, std::map<T, T>& T4);

private:
    //represent the mapping from a Vertex, say u (key) to a set of vertices (value) which directly connect to u
    std::map<T, std::set<T> > mapAdjacentPoints;
};

#endif   /* GRAPH_H */
#include "Graph.cpp"
