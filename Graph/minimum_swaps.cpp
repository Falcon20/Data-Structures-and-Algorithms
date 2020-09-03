// return the minimum number of swaps required to sort the array
// Problem link - https://practice.geeksforgeeks.org/problems/minimum-swaps/1
int minSwaps(int arr[], int N){
    vector<pair<int,int> >v;
    for(int i = 0;i<N;i++)
    {
        v.push_back({arr[i], i});
    }
    sort(v.begin(),v.end());
    int res = 0;
    bool vis[N];
    memset(vis,false, sizeof(vis));
    for(int i = 0;i<N;i++)
    {
        if(vis[i] || v[i].second == i)
        continue;
        int j = i;
        int k = 0;
        while(!vis[j])
        {
            vis[j] = true;
            k++;
            j = v[j].second;
        }
        if(k>0)
        res += k-1;
    }
    return res;
}
