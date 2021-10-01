//User function template for C++
// Problem link - https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
	    bool flag = true;
	    for(int i = 0;i<n-1;i++)
	    {
	        if(flag) // for < relation
	        {
	            if(arr[i] > arr[i+1])
	            swap(arr[i], arr[i+1]);
	        }
	        else // for > relation
	        {
	            if(arr[i] < arr[i+1])
	            swap(arr[i], arr[i+1]);
	        }
	        flag = !flag;
	    }
	}
};