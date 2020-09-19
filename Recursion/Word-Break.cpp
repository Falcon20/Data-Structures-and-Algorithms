// Problem link - https://practice.geeksforgeeks.org/problems/word-break-part-2/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_set<string>s;
vector<string>v;
void solve(string str, int n , string res)
{
    string ss;
    for(int i = 0;i<n;i++)
    {
        ss += str[i]; 
        if(s.find(ss) != s.end())
        {
            if(i == n-1)
            {
                v.push_back(res+ ss);
                return;
            }
            solve(str.substr(i+1,n-i+1), n-i-1, res + ss + " ");
        }
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        s.clear();
        v.clear();
        cin>>n;
        string str;
        for(int i = 0;i<n;i++)
        {
            cin>>str;
            s.insert(str);
        }
        cin>>str;
        solve(str, str.length(), "");
        sort(v.begin(),v.end());
        for(auto s: v)
        cout<<"("<<s<<")";
        cout<<"\n";
    }
	
	return 0;
}