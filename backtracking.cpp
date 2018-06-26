//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/prison-break-5/
// find the no of possible paths from [0][0] to [n-1][n-1];
// can traverse only cells with values 0 not 1
#include<bits/stdc++.h>
using namespace std;
int ans,n;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};// direction array to traverse in all possible direction
int a[21][21],v[21][21];// input array and visited array
void solve(int x,int y)
{
	if(x==n-1&&y==n-1)// base case 
	{
		ans++;
		return ;
	}
	v[x][y]=1;// visit the cell
	for(int i=0;i<4;++i)// to try out in all possible direction
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx>=n||xx<0||yy>=n||yy<0)// out of grid
		continue;
		if(v[xx][yy]||a[xx][yy]==1)// if already visited or can not traverse
		continue;
		solve(xx,yy);
		v[xx][yy]=false;// unmarked the cell for further possible paths
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{ 
		memset(v , false, sizeof v); 
		memset(a, false, sizeof a); 
		ans=0;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin>>a[i][j];
				v[i][j]=0;
			}
		}
		solve(0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
