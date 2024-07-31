class Solution {
public:
    int solve(string &s, vector<int>&mapping) {
        int a = 0;
        for(auto val : s) {
            a = a*10 + mapping[val-'0'];
        }
        return a;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        multiset<pair<pair<int, int>, int>>st;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            string temp = to_string(nums[i]);
            st.insert({{solve(temp, mapping), i}, nums[i]});
        }
        for(auto val : st) {
            ans.push_back(val.second);
            // cout << val.first.first << "," << val.second << " ";
        }
        // cout << endl;
        return ans;
    }
};