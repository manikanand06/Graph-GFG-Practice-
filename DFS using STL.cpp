#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[], int u,int v) 
{ 
    adj[u].push_back(v); 
} 
void DFSUtil(int v,bool visited[],vector <int> adj[])
{
	visited[v]=true;
	cout<<v<<" ";	
	vector<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	if(!visited[*i])
	DFSUtil(*i,visited,adj);
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
	
	cout<<"DFS Traversal is:";
	for(int i=0;i<V;i++)
	if(!visited[i])
	DFSUtil(i,visited,adj);	
	
	return 0;
}

