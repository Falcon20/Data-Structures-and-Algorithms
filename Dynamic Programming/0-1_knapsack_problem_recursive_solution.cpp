// Problem link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
//Video Tutorial - https://www.youtube.com/watch?v=kvyShbFVaY8
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Recursive solution
int knapsack(vector<int>wt, vector<int>val, int n, int W)
{
    if(W == 0 || n == 0) // if no capacity is 0 or we have iterated all items
    return 0;
    if(wt[n-1] <= W) // choice to take the item or not
    return max(val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]), knapsack(wt, val, n-1, W));
    else  // don't take the item if weight is greater than the current capacity of the knapsack.
    return knapsack(wt, val, n-1, W);
    
}
int main()
{
	int t,n,W;
	cin>>t;
	while(t--)
	{
	    cin>>n>>W;
	    vector<int>wt(n);
	    vector<int>val(n);
	    for(int i = 0;i<n;i++)
	    cin>>val[i];
	    for(int j = 0;j<n;j++)
	    cin>>wt[j];
	    cout<<knapsack(wt, val, n, W)<<"\n";
	}
	return 0;
}