// Problem link - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
#include<bits/stdc++.h>
#define ll long long
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
        {
            cin>>a[i];
        }
        int low = 0; // to store the value of next 0
        int mid = 0; // to iterate
        int high = n-1; // to store the value of next 2
        while(mid <= high)
        {
            switch(a[mid])
            {
                case 0:
                    swap(a[low], a[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(a[mid], a[high]);
                    high--;
                    break;
            }
        }
        for(int i =0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<"\n";
    }
	return 0;
}