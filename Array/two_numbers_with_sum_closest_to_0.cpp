// Problem link - https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1
class Solution
{
    public:
        int closestToZero (int arr[], int n)
        {
            sort(arr, arr+n);
           int l = 0, r = n-1;
           int res = INT_MAX;
           while(l<r)
           {
               int sm = arr[l] + arr[r];
               if(sm >0)
               r--;
               else
               l++;
               if(abs(sm) < abs(res))
               res = sm;
           }
           return res;
        }
};