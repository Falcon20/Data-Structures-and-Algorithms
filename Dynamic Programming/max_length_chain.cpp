/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

// Problem link - https://practice.geeksforgeeks.org/problems/max-length-chain/1
// Solution is similar to activity solution problem
// video tutorial - https://www.youtube.com/watch?v=dgNdDMMb8Rk&t=386s
bool compare(val v1, val v2)
{
    return v1.second < v2.second;
}
int maxChainLen(struct val p[],int n)
{
    vector<val>v(n);
    for(int i =0;i<n;i++)
    v[i] = p[i];
    sort(v.begin(),v.end(), compare);
    int res = 0;
    int mx = v[0].second;
    for(int i = 1;i<n;i++)
    {
        if(v[i].first >mx)
        {
            res++;
            mx = v[i].second;
        }
    }
    return res +1;
    
}