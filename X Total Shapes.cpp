#include<bits/stdc++.h>
using namespace std;

void totalshapes(vector<vector<char> >&v,vector<vector<bool> >&visited,int x,int y)
{
	if(x<0||y<0||x>=v.size()||y>=v[0].size())
	return;
	
	if(v[x][y]=='O'||visited[x][y])
	return;
	
	visited[x][y]=true;   
	totalshapes(v,visited,x+1,y);
    totalshapes(v,visited,x-1,y);
    totalshapes(v,visited,x,y+1);
    totalshapes(v,visited,x,y-1);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		vector<vector<char> >v(m,vector<char>(n));
		string s;
		for(int i=0;i<m;i++)
		{
			cin>>s;
			for(int j=0;j<s.length();j++)
			v[i][j]=s[j];
			
			
		}
		vector<vector<bool> >visited(m,vector<bool>(n,false));
		int count=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((!visited[i][j])&&v[i][j]=='X')
				{
				totalshapes(v,visited,i,j);
				count++;	
				}
			}
		}
	cout<<count<<endl;
    } 	
	}
