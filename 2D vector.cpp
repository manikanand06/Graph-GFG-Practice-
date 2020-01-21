#include<bits/stdc++.h>
using namespace std;
//void print(vector< vector<int> > a)   //call by value
void print(vector< vector<int> > &a)   //call by reference
{	
	for (int i = 0; i < a.size(); i++) { 
        for (int j = 0; j < a[i].size(); j++) 
            a[i][j] = 6;  
    } 
	
	
	for (int i = 0; i < a.size(); i++) { 
        for (int j = 0; j < a[i].size(); j++) 
            cout << a[i][j] << " "; 
        cout << endl; 
    } 
}
int main()
{
	int M=5,N=5;
	vector< vector<int> > a(M, vector<int>(N));
	for (int i = 0; i < a.size(); i++) { 
        for (int j = 0; j < a[i].size(); j++) 
            a[i][j] = 5;  
    } 
	print(a);	
	
	
	for (int i = 0; i < a.size(); i++) { 
        for (int j = 0; j < a[i].size(); j++) 
            cout << a[i][j] << " "; 
        cout << endl; 
    } 
}
