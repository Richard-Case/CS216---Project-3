#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.h"

// Check to see if an edge exists between two points.
template <typename T>
bool Graph<T>::HasEdge(T T1, T T2) const
{
	bool hasEdge = false;
	std::set<T> TSet = mapAdjacentPoints.at(T1);
	for(auto index = TSet.begin(); index != TSet.end(); index++)
	{
		if (T2 == *index)
		{
			hasEdge = true;
		}
	}

	return hasEdge;
}

// Add an edge between two points.
template <typename T>
void Graph<T>::AddEdge(T T1, T T2)
{
	mapAdjacentPoints[T1].insert(T2);
	mapAdjacentPoints[T2].insert(T1);
}


template <typename T>
int Graph<T>::BFS(T& T1, T& T2, std::map<T, int>& T3, std::map<T, T>& T4)
{
	// For each vertex in the graph...
	for (auto index = mapAdjacentPoints.begin(); index != mapAdjacentPoints.end(); index++)
	{
		T3[index->first] = -1;
	}

	if(T3.find(T1) == T3.end())
	{
		return INVALID_VERTEX;
	}

	// Create an empty QUEUE.
	std::queue<T> pointQueue;

	// Set the T3 at 'T1' equal to 0.
	T3.at(T1) = 0;

	// Set "T4" at 'T1' equal to 'T1'.
	T4[T1] = T1;

	// Insert T1 into the QUEUE.
	pointQueue.push(T1);

	// Set "current" equal to 'T1'.
	T current = T1;

	// While QUEUE is not empty AND "current" is not equal to 'T2'...
	while (!pointQueue.empty() && current != T2)
	{
		current = pointQueue.front();
		pointQueue.pop();

		// For each vertex that is adjacent to "current"...
		for (auto index : mapAdjacentPoints.at(current))
		{
			// If T3 at given index is equal to -1...
			if (T3.at(index) == -1)
			{
				// Set T3 at given index equal to T3 at "current" plus 1.
				T3.at(index) = (T3.at(current) + 1);

				// Set "T4" at given index equal to current.
				T4[index] = current;

				// Add given index to QUEUE.
				pointQueue.push(index);
			}
		}
	}

	if (T3.find(T2) != T3.end())
	{
		return T3[T2];
	}
	else if(!HasEdge(T1,T2))
	{
		return NO_PATH;
	}
	else
	{
		return INVALID_VERTEX;
	}
}

#endif
