#include<bits/stdc++.h> 
using namespace std; 

struct Graph 
{ 
	int V, E; 
	vector< pair<int, pair<int, int>> > edges;
	Graph(int V, int E) 
	{ 
		this->V = V; 
		this->E = E; 
	} 
	
	void addEdge(int x, int y, int z) 
	{ 
		edges.push_back({y, {x, z}}); 
	} 
	int kMST(); 
}; 
 
struct DisjointSets 
{ 
	int *parent, *rnk; 
	int n; 
 
	DisjointSets(int n) 
	{ 
	    this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 
		for (int i = 0; i <= n; i++) 
		{ 
			rnk[i] = 0; 
			parent[i] = i; 
		} 
	} 
	int find(int x) 
	{ 
		if (x != parent[x]) 
			parent[x] = find(parent[x]); 
		return parent[x]; 
	} 
 
	void merge(int a, int b) 
	{ 
		a = find(a), b = find(b); 

		if (rnk[a] > rnk[b]) 
			parent[b] = a; 
		else 
			parent[b] = a; 

		if (rnk[a] == rnk[b]) 
			rnk[b]++; 
	} 
}; 

int Graph::kMST() 
{ 
	int mst_wt = 0;  
	sort(edges.begin(), edges.end()); 

	DisjointSets ds(V); 

	vector< pair<int, pair<int, int>> >::iterator it; 
	for (it=edges.begin(); it!=edges.end(); it++) 
	{ 
		int x = it->second.first; 
		int z = it->second.second; 

		int set_x = ds.find(x); 
		int set_z = ds.find(z); 

		if (set_x != set_z) 
		{ 
			cout << x << " - " << z << endl; 
			mst_wt += it->first; 
			ds.merge(set_x, set_z); 
		} 
	} 

	return mst_wt; 
} 
 
int main() 
{ 
	int V = 8, E = 12; 
	Graph g(V, E); 
	g.addEdge(0, 4, 2); 
	g.addEdge(0, 9, 4); 
	g.addEdge(1, 3, 5); 
	g.addEdge(1, 9, 9); 
	g.addEdge(2, 6, 4); 
	g.addEdge(2, 0, 3); 
	g.addEdge(2, 7, 5); 
	g.addEdge(3, 5, 1); 
	g.addEdge(4, 7, 5);  

	cout << "Edges of MST graph are \n"; 
	int mst_wt = g.kMST(); 

	cout << "\nWeight of MST graph is " << mst_wt; 

	return 0; 
} 