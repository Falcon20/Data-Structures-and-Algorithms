// Problem link - https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
// Keep a stack to store current maximum increasing sequence
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)
        cin>>a[i];
        stack<int>s;
        bool profit_present = false;
        for(int i = 0;i<n;i++)
        {
            if(s.empty() || a[s.top()] <= a[i])
            s.push(i);
            else
            {
                int y = s.top(), x;
                while(!s.empty())
                {
                    x = s.top();
                    s.pop();
                }
                if(x!=y)
                {
                    profit_present = true;
                    cout<<"("<<x<<" "<<y<<") ";
                }
                s.push(i);
            }
        }
        if(!s.empty())
        {
            int y = s.top(), x;
                while(!s.empty())
                {
                    x = s.top();
                    s.pop();
                }
                if(x!=y)
                {
                    profit_present = true;
                    cout<<"("<<x<<" "<<y<<") ";
                }
        }
        if(!profit_present)
        cout<<"No Profit";
        cout<<"\n";
    }
    return 0;
}