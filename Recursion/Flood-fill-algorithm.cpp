// Flood-fill-algorithm
// Problem link - https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[104][104];
void solve(int prev_color, int x, int y, int new_color, int n, int m)
{
    if(x>=n || y>=m || x<0 || y<0)
    return ;
    if(a[x][y] == new_color || a[x][y] != prev_color)
    return;
    a[x][y] = new_color;
    solve(prev_color, x, y+1, new_color,n,m);
    solve(prev_color, x, y-1, new_color,n,m);
    solve(prev_color, x+1,y, new_color,n,m);
    solve(prev_color, x-1,y, new_color,n,m);
}
int main()
{
	int t,n,m,x,y,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        cin>>a[i][j];
	    }
	    cin>>x>>y>>k;
	    solve(a[x][y],x,y,k,n,m);
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        cout<<a[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}