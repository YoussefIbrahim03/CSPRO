#include "DirectedUnweightedGraph.h"

DirectedUnweightedGraph::DirectedUnweightedGraph(int count)
{
	numberOfVertices = count;
	adjacencyList.resize(numberOfVertices);
}
void DirectedUnweightedGraph::addEdge(Edge edge)
{
	if (edge.source >= 0 && edge.source < numberOfVertices && edge.destination >= 0 && edge.destination < numberOfVertices)
		adjacencyList[edge.source].push_back(edge.destination);
}
void DirectedUnweightedGraph::BFS() // Breadth First Search
{
	if (numberOfVertices == 0)
		return;

	vector<bool> visited(numberOfVertices, false);

	queue<int> q;
	q.push(0); // Assume that 0 is the start vertex.
	visited[0] = true;
	int j = 0;
	do
	{
		while (q.empty() == false)
		{
			int vertex = q.front();
			q.pop();
			cout << vertex << " ";

			for (int i = 0; i < adjacencyList[vertex].size(); i++)
			{
				int dest = adjacencyList[vertex][i];
				if (visited[dest] == false)
				{
					q.push(dest);
					visited[dest] = true;
				}
			}
		}
		if (j < numberOfVertices && visited[j] == false)
		{
			q.push(j);
			visited[j] = true;
		}
		j++;
	} while (j <= numberOfVertices);
}
void DirectedUnweightedGraph::DFS()
{
	if (numberOfVertices == 0)
		return;
	vector<bool> visited(numberOfVertices, false);
	for (int i = 0; i < numberOfVertices; i++)
		if (visited[i] == false)
			DFSRec(i, visited);
}
void DirectedUnweightedGraph::DFSRec
(int vertex, vector<bool>& visited)
{
	if (visited[vertex] == true)
		return;
	cout << vertex << " ";
	visited[vertex] = true;
	for (int i = 0; i < adjacencyList[vertex].size(); i++)
	{
		int dest = adjacencyList[vertex][i];
		if (visited[dest] == false)
			DFSRec(dest, visited);
	}
}
