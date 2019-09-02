//C++ program to find the no of divisors of a number in O(N^(1/3)) time complexity
//Read this blog https://codeforces.com/blog/entry/22317
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	//sieve of eratostheses
	bool isPrime[1000006];
	for(int i=2;i<=1000000;i++)
	isPrime[i]=true;
	isPrime[0]= false;
	isPrime[1]= false;
	for(int i=2;i*i<=1000000;i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i ;j<= 1000000;j+=i)
			isPrime[j]= false;
		}
	}
	vector<int>v;// this vector will contain all the prime numbers till 10^6
	for(int i= 2;i<=1000000;i++)
	{
		if(isPrime[i])
		{	
			v.push_back(i);
		}
	}
	int k ;
	cin>>k;// Number for which no of divisors are to be found
	ll ans =1 ;
	for(int i=0;i<v.size();i++)
	{
		ll res = v[i]*v[i]*v[i];
		if(res>k)
		break;	
		ll count = 1;
		while(k%v[i]==0)
		{
			k/=v[i];
			count++;
		}
		ans*= count;	
	}
	ll d= sqrt(k);
	if (isPrime[k])
	ans*=2;
	else if((d*d)==k&& isPrime[d])
	{
		ans*=3;
	}
	else if (k!=1)
	ans*=4;
	cout<<ans<<"\n";
	return 0;
}
