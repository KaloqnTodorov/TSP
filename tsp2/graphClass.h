#pragma once

#define V 15
class graphClass
{	
private:
	int  size;
	int graph[V][V];
	void copy(const graphClass& other);
public:
	graphClass();
	graphClass(int newSize,int newGraph[V][V]);
	graphClass(const graphClass& other);
	graphClass& operator = (const graphClass& other);

	int getSize() const;
	int** getGraph() const;
	void createGraph();
};