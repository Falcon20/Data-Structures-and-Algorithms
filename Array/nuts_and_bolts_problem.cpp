// Problem link - https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
class Solution{
public: 

    void matchPairs(char nuts[], char bolts[], int n) {
        map<char, bool>m;
        for(int i = 0;i<n;i++)
        {
            m[nuts[i]] = true;
        }
        for(int i = 0;i<n;i++)
        {
           if(m.find(bolts[i]) == m.end())
           m.erase(bolts[i]);
        }
        int i = 0;
        for(auto s: m)
        {
           nuts[i] = s.first;
           bolts[i] = s.first;
           i++;
           
        }

    }

};
