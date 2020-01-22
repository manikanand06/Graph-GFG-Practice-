#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int>adj[],int u,int v) 
{
    adj[u].push_back(v); 
    adj[v].push_back(u);
}

bool isSafe(int i, int j, vector<vector<int> >vect) 
{ 
	if (i<0 || j<0 || i>=vect.size() || j>=vect.size() || vect[i][j]==0)
		return false; 
	return true;
} 

bool BFS(int V,int s,int d,vector <int> adj[])
{
	if (s == d) 
	return true; 
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
		for(i=adj[s].begin();i!=adj[s].end();i++){
			if (*i == d) 
				return true; 
			if(!visited[*i])
			q.push(*i);
		}
		
	}
	return false;
}

int main()
{	
/*
test case:
    0 , 3 , 1 , 0           \     1     2 -- 3     4
    3 , 0 , 3 , 3         ---|               |
    2 , 3 , 0 , 3         ---|    5     6    7 --  8
    0 , 3 , 3 , 3           /     |                |
                                  9 -- 10    11    12
                                       |           |
                                  13   14 -- 15 -- 16

source = 2 , Destination = 9
*/

	int t;
	cin>>t;
	while(t--)
	{
	int N;
	cin>>N;
	vector<vector<int> >vect(N,vector<int>(N));
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	cin>>vect[i][j];		
	
	int s , d ; // source and destination 
	int V = N*N+2; //we are starting from 1 and need last as well so added 2 here
	vector<int>adj[V]; //Adjacency list
	int k = 1 ; 
	for (int i =0 ; i < N ; i++) 
	{ 
		for (int j = 0 ; j < N; j++) 
		{ 
			if (vect[i][j] != 0) 
			{ 
				if ( isSafe ( i , j+1 , vect ) ) 
					addEdge (adj, k , k+1 ); 
				if ( isSafe ( i , j-1 , vect ) ) 
					addEdge (adj, k , k-1 ); 
				if (isSafe ( i+1 , j , vect ) ) 
					addEdge (adj, k , k+N ); 
				if (isSafe ( i-1 , j , vect ) ) 
					addEdge (adj, k , k-N ); 
			} 

			// source index 
			if( vect[i][j] == 1 ) 
				s = k ; 

			// destination index 
			if (vect[i][j] == 2) 
				d = k; 
			k++; 
		} 
	} 
	cout<<BFS(V,s,d,adj)<<endl; 
	}	
	return 0;
}
