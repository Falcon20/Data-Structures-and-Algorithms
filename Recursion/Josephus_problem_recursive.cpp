// problem link - https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
// video tutorial - https://www.youtube.com/watch?v=n2IQ8mZtk3E
// Recursive solution
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int n , int k)
{
    if(n == 0)
    return 0;
    return (solve(n-1,k)+k)%n;
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<solve(n,k)+1<<"\n";
    }
	
	return 0;
}