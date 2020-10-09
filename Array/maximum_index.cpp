/ Problem link - https://practice.geeksforgeeks.org/problems/maximum-index3307/1
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int l[n], r[n];
        l[0] = arr[0];
        r[n-1] = arr[n-1];
        for(int i =1;i<n;i++)
        {
            l[i] = min(l[i-1], arr[i]);
        }
        for(int i = n-2;i>=0;i--)
        {
            r[i] = max(r[i+1], arr[i]);
        }
        int max_diff = 0;
        int i = 0,j=0;
        while(i<n && j<n)
        {
            if(l[i]<=r[j])
            {
                max_diff = max(max_diff, j-i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return max_diff;
    }

};