#include<bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int> > &v,int x,int y,int newval,int oldval)
{
	
	if(x<0||y<0||x>=v.size()||y>=v[0].size())
	return;
	
	if(v[x][y]!=oldval)
	return;
	
	v[x][y]=newval;
    floodfill(v,x+1,y,newval,oldval);
	floodfill(v,x-1,y,newval,oldval);
	floodfill(v,x,y-1,newval,oldval);
	floodfill(v,x,y+1,newval,oldval);
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
		{
			for(int j=0;j<n;j++)
			{
				cin>>v[i][j];
			}
		}
		int x,y,newval;
		cin>>x>>y>>newval;
		int oldval=v[x][y];
		floodfill(v,x,y,newval,oldval);	
		for (int i = 0; i < v.size(); i++) { 
        for (int j = 0; j < v[i].size(); j++) 
            cout << v[i][j]<<" ";
            cout<<endl;
    }
		
	}
}
