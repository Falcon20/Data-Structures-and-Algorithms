// Problem link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
// video tutorial - https://www.youtube.com/watch?v=G5CVOjWDAmY
// create a min heap of size k, insert only if the current element is greater than the root, root will always
// be the kth largest element
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,k,n;
	cin>>t;
	while(t--)
	{
	    cin>>k>>n;
	    int a[n];
	    // min_heap
	    priority_queue <int, vector<int>, greater<int>> pq;
	    for(int i = 0;i<n;i++)
	    {
	        cin>>a[i];
	        if(pq.size() < k-1)
	        {
	            pq.push(a[i]);
	            cout<<-1<<" ";
	        }
	        else if(pq.size() == k-1)
	        {
	            pq.push(a[i]);
	            cout<<pq.top()<<" ";
	        }
	        else
	        {
	            if(pq.top() < a[i])
	            {
	                pq.pop();
	                pq.push(a[i]);
	            }
	            cout<<pq.top()<<" ";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}