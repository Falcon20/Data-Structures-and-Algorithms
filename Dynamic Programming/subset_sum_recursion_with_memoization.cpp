//Problem link - https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
// Check if a subset of sum(arr) / 2 is present in the array or not
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<int,int>,bool>m; // Memoization
bool res; // return value for each function
bool solve(vector<int>v, int n, int sum)
{
    if(sum == 0)
    {
        m.insert({{n,sum}, true});
        return true;
    }
    if(n == 0)
    {
        m.insert({{n,sum}, false});
        return false;
    }
    
    auto it = m.find({n,sum}); // check if subproblem is already solved
    if(it!=m.end())
    return it->second;
    
    if(v[n-1] <= sum) // take the element
    res = (solve(v,n-1,sum-v[n-1]) || solve(v,n-1,sum));
    else
    res = solve(v,n-1,sum); // do not take the element
    m.insert({{n,sum}, res}); 
    return res;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    m.clear();
	    cin>>n;
	    vector<int>v(n);
	    int s = 0;
	    for(int i =0;i<n;i++)
	    {
	        cin>>v[i];
	        s+=v[i];
	    }
	    if(s%2)
	    {
	        cout<<"NO\n";
	        continue;
	    }
	    cout<<(solve(v,n,s/2) ? "YES\n" : "NO\n");
	}
	return 0;
}