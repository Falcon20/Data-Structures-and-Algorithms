// Max flow problem using Ford Fulkerson and Edmond Karp algorithm
// problem link : https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/find-the-flow/
// video tutorial : https://www.youtube.com/watch?v=GiN3jRdgxU4&index=10&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j
 
#include<bits/stdc++.h>
using namespace std;
int main()
{
		int e,w;
		char ch1,ch2;
		cin>>e;// total edges
		int a[26][26]={{0}};// represent the graph using adjacency matrix
		for(int i=0;i<e;i++)
		{
			cin>>ch1>>ch2>>w;// char S is source and T is sink
			a[ch1-65][ch2-65]=w;
		}
		int res=0;// max flow
		while(1)
		{
		bool chk=false;
			bool vis[26]={0};
			vis[18]=1;// source is S
			int parent[26];
			for(int i=0;i<26;i++)
			parent[i]=-1;
			queue<int>q;
			q.push(18);
			while(!q.empty())// do a bfs traversal until source is able to reach sink
			{
				int u=q.front();
				q.pop();
				for(int i=0;i<26;i++)
				{
					if(!vis[i]&&a[u][i]>0)
					{
						vis[i]=1;
						parent[i]=u;
						if(i==19)// if sink is found then break
						{
							chk=true;
							break;
						}
						q.push(i);
					}
				}
				if(chk)
				break;
			}
			if(!chk)
			break;
			int k=19,mx=INT_MAX;// mx is the wt of bottleneck edge in the path S->T
			while(k!=18)
			{
				if(a[parent[k]][k]<mx)
				mx=a[parent[k]][k];
				k=parent[k];
			}
			k=19;
			while(k!=18)
			{
				
				a[parent[k]][k]-=mx;// reduce the capacity of initial edge by mx
				a[k][parent[k]]+=mx;// increase the capacity of the back edge by mx
				k=parent[k];
			}
			res+=mx;
		}
		cout<<res<<"\n";
	return 0;
}
