class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>mp;
        int maxi = INT_MIN;
        for(auto val : matches){
            maxi = max(maxi, max(val[0], val[1]));
        }
        for(int i = 1; i<=maxi; i++){
            mp[i] = 0;
        }
        for(auto val : matches){
            mp[val[0]] = -100000;
        }
        for(auto val : matches){
            mp[val[1]]++;
        }
        vector<int> v1, v2;
        for(auto val : mp){
            if(val.second == -100000){
                v1.push_back(val.first);
            }
            else if(val.second == -99999  || val.second == 1){
                v2.push_back(val.first);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return {v1, v2};
    }
};