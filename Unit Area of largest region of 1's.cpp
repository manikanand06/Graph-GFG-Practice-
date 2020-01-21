#include<bits/stdc++.h>
using namespace std;
int countCells(vector<vector<int> >&v, int i, int j) {
	
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size()||v[i][j]==0)
	    return 0;
	    
       
		
        int count = v[i][j]--;   //so that you dont need visited array
        
        count += countCells(v, i + 1, j);
        count += countCells(v, i - 1, j);
        count += countCells(v, i, j + 1);
        count += countCells(v, i, j - 1);
        count += countCells(v, i + 1, j + 1);
        count += countCells(v, i - 1, j - 1);
        count += countCells(v, i - 1, j + 1);
        count += countCells(v, i + 1, j - 1);
        return count;
    }




int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		vector<vector<int> >v(m,vector<int>(n));
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>v[i][j];
		
		int maximum = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                maximum = max(maximum, countCells(v, i, j));
            }
        }
        cout<<maximum<<endl;
	}
}
