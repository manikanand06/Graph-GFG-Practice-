#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[], int u,int v) 
{ 
    adj[u].push_back(v); 
} 
int findSum(vector<int> adj[], int V)     //For sum of Dependency
{ 
    int sum = 0; 
  
    // just find the size at each vector's index 
    for (int u = 0; u < V; u++) 
        sum += adj[u].size(); 
  
    return sum; 
}

int main()
{
	int V = 6; 
    vector<int >adj[V];   //static array of N vectors
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);
	
	bool *visited=new bool[V];
	memset(visited,false,sizeof(visited));
	
	cout << "\nSum of dependencies is "
         << findSum(adj, V);
	
	return 0;
}

