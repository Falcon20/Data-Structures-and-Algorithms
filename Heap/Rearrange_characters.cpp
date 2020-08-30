// Problem link -https://practice.geeksforgeeks.org/problems/rearrange-characters/0
// use priority queue to keep elements of most frequencies to be used first
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int a[26];
        memset(a,0,sizeof(a));
        for(int i = 0;str[i];i++)
        {
            a[str[i] - 97]++;
        }
        vector<pair<int,char> >v;
        for(int i =0;i<26;i++)
        {
            if(a[i])
            {
                v.push_back({a[i], char(i+97)});
            }
        }
        priority_queue<pair<int,char> >pq;
        for(int i = 0;i<v.size();i++)
        {
            pq.push(v[i]);
        }
        pair<int,char>prev={0,'$'};
        string s = "";
        while(!pq.empty())
        {
            pair<int, char>u = pq.top();
            pq.pop();
            s.push_back(u.second);
            u.first--;
            if(prev.first > 0)
            pq.push(prev);
            prev = u;
        }
        cout<<(s.length()==str.length())<<"\n";
    }
    return 0;
}