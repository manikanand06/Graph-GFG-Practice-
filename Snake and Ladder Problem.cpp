#include<bits/stdc++.h> 
using namespace std; 
int getMinDiceThrows(int *move, int N) 
{ 
	bool *visited = new bool[N+1]; 
	memset(visited,false,sizeof(visited));

	queue<pair<int,int> > q; //vertex no and distance 

	visited[1] = true; 
	
	q.push(make_pair(1,0)); // distance of 1'st vertex is also 0

	// Do a BFS starting from vertex at index 1
	pair<int,int> qe;
	while (!q.empty()) 
	{ 
		qe = q.front(); 
		int v = qe.first; // vertex no. of queue entry 
		
		if (v == N) //if vertex no. reach to the last
			break; 
			
		q.pop(); 
		
		for (int j=v+1; j<=(v+6) && j<=N; ++j) 
		{ 
			if (!visited[j]) 
			{ 
				pair<int,int> a; 
				a.second = (qe.second + 1); 
				visited[j] = true; 

				// Check if there a snake or ladder at 'j' 
				// then tail of snake or top of ladder 
				// become the adjacent of 'i' 
				if (move[j] != -1) 
					a.first = move[j]; 
				else
					a.first = j; 
				q.push(a); 
			} 
		} 
	} 

	return qe.second; 
} 


int main() 
{ 
//	// Let us construct the board given in above diagram 
//	int N = 30; 
//	int moves[N+1]; 
//	for (int i = 1; i<=N; i++) 
//		moves[i] = -1; 
//
//	// Ladders 
//	moves[3] = 22; 
//	moves[5] = 8; 
//	moves[11] = 26; 
//	moves[20] = 29; 
//
//	// Snakes 
//	moves[28] = 1; 
//	moves[21] = 9; 
//	moves[17] = 4; 
//	moves[19] = 7; 
//  cout << "Min Dice throws required is " << getMinDiceThrows(moves, N); 

    
	
    int t;
    cin>>t;
    while(t--)
    {
    	int N=30;
    	int moves[N+1]; 
	    for (int i = 1; i<=N; i++) 
		moves[i] = -1; 
    	int x;
    	cin>>x;
    	int a,b;
    	while(x--)
    	{
    		cin>>a>>b;
    		moves[a]=b;
		}
		cout<<getMinDiceThrows(moves, N)<<endl;
	}

	return 0; 
} 

