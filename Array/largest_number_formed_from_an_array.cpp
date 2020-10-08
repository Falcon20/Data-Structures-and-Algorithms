// Problem link - https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
//User function template for C++
bool compare(string x, string y)
{
    string s1 = x.append(y);
    string s2 = y.append(x);
    return s1 > s2;
}
class Solution{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings

    string printLargest(vector<string> &arr) {
        sort(arr.begin(), arr.end(), compare);
        string res = "";
        int n = arr.size();
        for(int i = 0;i<n;i++)
        {
            res.append(arr[i]);
        }
        return res;
    }
};