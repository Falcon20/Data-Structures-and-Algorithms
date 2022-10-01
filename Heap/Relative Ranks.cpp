class Solution {
public:
    string int_to_string(int num)
    {
        string temp = "";
        while(num)
        {
            temp.push_back(char(num%10 + 48));
            num /= 10;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    string get_rank(int num)
    {
        if(num == 1)
            return "Gold Medal";
        else if(num == 2)
            return "Silver Medal";
        else if(num == 3)
            return "Bronze Medal";
        else return int_to_string(num);
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,string>rank;
        priority_queue<int>q;
        for(auto s: score)
            q.push(s);
        int curr = 1;
        while(!q.empty())
        {
            rank[q.top()] = get_rank(curr);
            q.pop();
            curr++;
        }
        vector<string>result;
        for(auto s: score)
            result.push_back(rank[s]);
        return result;

    }
};