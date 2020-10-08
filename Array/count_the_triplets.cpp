//User function template for C++
// Problem link - https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1
class Solution{
public: 
    
    int countTriplet(int arr[], int n)
    {
        sort(arr,arr+n);
        int res = 0;
        for(int k = n-1;k>=2;k--)
        {
           int i = 0, j = k-1;
           while(i<j)
           {
               int temp = arr[i]+ arr[j];
               if(temp == arr[k])
               {
                   res++;
                   i++;
                   j--;
               }
               else if(temp < arr[k])
               {
                   i++;
               }
               else
               j--;
           }
        }
        return res;
    }
};