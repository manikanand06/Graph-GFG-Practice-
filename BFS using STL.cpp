#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[], int u,int v) 
{ 
    adj[u].push_back(v); 
} 
void BFS(int V,int s,vector <int> adj[])
{
	bool *visited=new bool[V];
	memset(visited,false,sizeof(visited));
	queue<int>q;
	q.push(s);
	vector<int>::iterator i;
		
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		visited[s]=true;
		cout<<s<<" ";	
		for(i=adj[s].begin();i!=adj[s].end();i++)
			if(!visited[*i])
			q.push(*i);
		
	}
}

int main()
{	
	int V = 6; 
    vector<int >adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 3, 4);
	addEdge(adj, 4, 5);	
	BFS(V,0,adj);
	return 0;
}
