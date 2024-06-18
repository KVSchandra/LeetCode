class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int>mp;
        int n = arr.size();
        for(int i = 0; i < target.size(); i++) {
            mp[target[i]] = i;
        }
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(mp.find(arr[i]) != mp.end()) {
                auto it = lower_bound(temp.begin(), temp.end(), mp[arr[i]]);
                if(it != temp.end()) temp[it-temp.begin()] = mp[arr[i]];
                else temp.push_back(mp[arr[i]]);
            }
        }
        return target.size() - temp.size();
    }
};