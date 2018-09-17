//https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
//Fenwick tree implementation
// space complexity to create O(n)
// time complexity to create  tree O(nlogn)
// to update O(logn)
// to find sum O(logn)
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;// elements and queries
		cin>>n>>q;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		int bitree[n+1]={0};// no of nodes in fenwick tree will be one more than array
		for(int i=0;i<n;i++)
		{
			int idx=i+1;
			while(idx<=n)
			{
				bitree[idx]+=a[i];
				idx+=idx & (-idx);// get the next node
			}
		}
		/* to print the fenwick tree
		for(int i=0;i<=n;i++)
		cout<<bitree[i]<<" ";
		*/
		while(q--)
		{
			int x,y,z;
			cin>>x;
			if(x==0)//  if x==0; update value of index y as z
			{
				cin>>y>>z;
				a[y]+=z;
				int idx=y+1;
				while(idx<=n)
				{
					bitree[idx]+=z;
					idx+=idx&(-idx);// update the next node
				}
			}
			else//find the sum of first x elements of array 
			{
				int sum=0;
				int idx=x;
				while(idx>0)
				{
					sum+=bitree[idx];
					idx-=idx&(-idx);// to get the parent
				}
				cout<<sum<<"\n";
			}
		}
	return 0;
}

