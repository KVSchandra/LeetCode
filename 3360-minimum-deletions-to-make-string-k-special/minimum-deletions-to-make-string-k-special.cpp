class Solution {
public:
    int solve(int k, int c, unordered_map<char, int>&mp){
        int sum = 0;
        for(auto val : mp){
            if(val.second == c) continue;
            else if(val.second - c >= k){
                sum += val.second - c - k;
            }
            else if(val.second < c) sum += val.second;
        }
        return sum;
    }

    int minimumDeletions(string word, int k) {
        unordered_map<char, int>mp;
        for(auto val : word){
            mp[val]++;
        }
        int mini = INT_MAX;
        for(auto val : mp){
            mini = min(mini, solve(k, val.second, mp));
        }
        return mini;
    }
};