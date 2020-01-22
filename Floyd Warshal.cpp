#include <bits/stdc++.h> 
using namespace std;  
#define INF 10000000
void printSolution(vector<vector<int> >dist) 
{ 
int V=dist.size();
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<" "; 
			else
				cout<<dist[i][j]<<" "; 
		} 
		cout<<endl; 
	} 
} 

void floydWarshall (vector<vector<int> >graph) 
{
	int V=graph.size();
	vector<vector<int> >dist(V,vector<int>(V));
	int i, j, k; 
	
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	for (k = 0; k < V; k++) //via k
	{ 
	
		for (i = 0; i < V; i++) 
		{ 
			for (j = 0; j < V; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	printSolution(dist); 
} 



int main() 
{ 

//	int V=4;
//	
//   input:
//	 vector<vector<int> > graph{ {0, 5, INF, 10}, 
//						       {INF, 0, 3, INF}, 
//						       {INF, INF, 0, 1}, 
//						       {INF, INF, INF, 0} };
//   output: 
//            0      5      8      9
//          INF      0      3      4
//          INF    INF      0      1
//          INF    INF    INF      0
						

					
	int t;
	cin>>t;
	while(t--)
	{
	int V;
	cin>>V;			
	vector<vector<int > >graph(V,vector<int>(V));
	string s;
	for(int i=0;i<V;i++)
	for(int j=0;j<V;j++)
	{
		cin>>s;
		if(s=="INF")
		graph[i][j]=INF;
		else
		graph[i][j]=stoi(s);
	}
	floydWarshall(graph); 
    }
	return 0; 
} 

