// Read the method from editorial
// Problem link - https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++)
	cin>>a[i];
	double median = a[0]*1.0;
	cout<<a[0]<<"\n";
    priority_queue<int> s; // max_heap 
    priority_queue<int,vector<int>,greater<int> > g; // min_heap
	s.push(a[0]);
    for(int i =1;i<n;i++)
    {
        if(s.size() > g.size())
        {
            if(a[i] < median)
            {
                g.push(s.top());
                s.pop();
                s.push(a[i]);
            }
            else
            g.push(a[i]);
            median = ((s.top() + g.top())*1.0)/2;
        }
        else if(s.size() < g.size())
        {
            if(a[i] > median)
            {
                s.push(g.top());
                g.pop();
                g.push(a[i]);
            }
            else
            s.push(a[i]);
        median = ((s.top() + g.top())*1.0)/2;
        }
        else
        {
            if(a[i]< median)
            {
                s.push(a[i]);
                median = s.top();
            }
            else
            {
                g.push(a[i]);
                median = g.top();
            }
        }
        cout<<int(median)<<"\n";
    }
    

	return 0;
}