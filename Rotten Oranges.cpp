#include<bits/stdc++.h> 
using namespace std; 

int rotOranges(vector<vector<int> >grid)
{
	//for dirrection like up,down,left,right
	int dr[] = {-1, 0, 1, 0};  
    int dc[] = {0, -1, 0, 1};
    
     int R = grid.size(), C = grid[0].size();
     
     queue<pair<int,int> >q;
     
     for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                if (grid[r][c] == 2) {
                    int code = r * C + c;  //storing index i&j
                    q.push(make_pair(code,0)); 
                }
 
    int ans = 0;
        while (!q.empty()) {
            pair<int,int> code = q.front();
            q.pop();
            int r = code.first / C, c = code.first % C;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    int ncode = nr * C + nc;
                    q.push(make_pair(ncode,code.second+1));
                    ans = code.second+1;
                }
            }
        }
        
        for (int i=0;i<R;i++)
            for (int j=0;j<C;j++)
                if (grid[i][j] == 1)
                    return -1;
        
		return ans;
    
	
}


 
int main() 
{ 
//	vector<vector<int> > v= { {2, 1, 0, 2, 1}, 
//					{1, 0, 1, 2, 1}, 
//					{1, 0, 0, 2, 1}}; 
//	int ans = rotOranges(v); 
//	if (ans == -1) 
//		cout << "All oranges cannot rotn"; 
//	else
//		cout << "Time required for all oranges to rot => " << ans << endl; 


int t;
cin>>t;
while(t--)
{
	int r,c;
	cin>>r>>c;
	vector<vector<int> >v(r,vector<int>(c));
	for(int i=0;i<r;i++)
	for(int j=0;j<c;j++)
	cin>>v[i][j];
	int ans = rotOranges(v); 
	cout<<ans<<endl;
}

	return 0; 
} 

