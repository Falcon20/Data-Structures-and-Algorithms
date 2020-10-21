//User function template for C++
// Problem link - https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
// Solution is to print (n+2)th fibonacci number
class Solution{
public:
	ll countStrings(int n) {
	    ll a=1,b=1,c;
	    for(ll i = 0;i<n;i++)
	    {
	        c = (a+b)%1000000007;
	        a = b;
	        b = c;
	    }
        return b;
	}
};