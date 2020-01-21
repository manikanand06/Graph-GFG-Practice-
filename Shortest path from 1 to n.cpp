#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int x,count=0;
	    cin>>x;
	    while(x!=1)
	    {
	        if(x%3==0)
	        x/=3;
	        else
	        x--;
	        count++;
	    }
	cout<<count<<endl;
	}
	return 0;
}
