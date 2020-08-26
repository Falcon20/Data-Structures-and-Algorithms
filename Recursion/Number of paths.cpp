// Problem link - https://practice.geeksforgeeks.org/problems/number-of-paths/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int n, int m, int x, int y)
{
    if(x >=n || y >=m )
    return 0;
    if((x+1) == n && (y+1)== m)
    return 1;
    return solve(n,m,x+1,y) + solve(n,m,x,y+1);
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<solve(n,m,0,0)<<"\n";
    }
	
	return 0;
}