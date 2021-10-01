// Problem link - https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0
// O(1) extra space
// take first row and first column as the array to check if a cell is to be made 1 or not
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    int a[n][m];
	    bool r_flag = false, c_flag = false;
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        {
	            cin>>a[i][j];
	            if(a[i][j])
	            {
	                if(j == 0)
	                c_flag = true;
	                if(i == 0)
	                r_flag = true;
	                a[0][j] = 1;
	                a[i][0] = 1;
	            }
	        }
	    }
	    for(int i =1;i<n;i++)
	    {
	        for(int j = 1;j<m;j++)
	        {
	            if(a[0][j] || a[i][0])
	            a[i][j] = 1;
	        }
	    }
	    if(r_flag)
	    {
	        for(int i = 0;i<m;i++)
	        a[0][i] = 1;
	    }
	    if(c_flag)
	    {
	        for(int i = 0;i<n;i++)
	        a[i][0] = 1;
	    }
	    for(int i= 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        cout<<a[i][j]<<" ";
	        cout<<"\n";
	    }
	}
	return 0;
}