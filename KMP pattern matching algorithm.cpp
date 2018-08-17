// time complexity of this algorithm is O(n+m)
// time complexity to make lps array is O(m) , m is the length of pattern
// time complexity to search pattern is O(n), n is the length of string
#include<iostream>
using namespace std;
int main()
{
	int t;
	string ptrn,str;// str is the string in which pattern ptrn is to be searched
	cin>>t;
	while(t--)
	{
		cin>>str>>ptrn;
		int a[ptrn.length()]={0};// longest prefix suffix array. 
		int idx=0,i=1;
		while(ptrn[i])
		{
			if(ptrn[i]==ptrn[idx])
			{
				a[i]=idx+1;
				idx++;
				i++;
			}
			else 
			{
				if(idx!=0)
				{
					idx=a[idx-1];
				}
				else
				{
					i++;
					a[i]=0;
				}
			}
		}
		i=0;
		int j=0;
		while(str[i]&&ptrn[j])// kmp searching 
		{
			if(str[i]==ptrn[j])
			{
				i++;
				j++;
			}
			else
			{
				if(j==0)
				i++;
				else
				{
					j=a[j-1];
				}
			}
		}
		if(j==ptrn.length())
		cout<<"YES\n";
		else
		cout<<"NO\n";
		}
	return 0;
}
