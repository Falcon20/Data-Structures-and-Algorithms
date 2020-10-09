//User function template for C++
// O(max(a[i])^2
//Problem link - https://practice.geeksforgeeks.org/problems/pythagorean-triplet3018/1
class Solution{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n) {
     int mx = *max_element(arr,arr+n);
     int hash[mx+1];
     memset(hash, 0, sizeof(hash));
     for(int i = 0;i<n;i++)
     {
         hash[arr[i]]++;
     }
     for(int i= 1;i<=mx;i++)
     {
         if(!hash[i])
         continue;
         for(int j = i;j<=mx;j++)
         {
             if(hash[j] == 0 || (i == j && hash[j] == 1))
             continue;
             
             int k = sqrt(i*i + j*j);
             if((i*i + j*j) != k*k)
             continue;
             
             if(k>mx)
             continue;
             
             if(hash[k])
             {
                return true;
             }
         }
     }
     
     return false;
     
    }