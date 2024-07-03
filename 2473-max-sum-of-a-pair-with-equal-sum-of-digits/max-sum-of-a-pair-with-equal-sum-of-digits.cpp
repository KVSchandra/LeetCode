class Solution {
public:
    int solve(int n) {
        int s = 0;
        while(n) {
            s += (n%10);
            n /= 10;
        }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, vector<int>> mp;
        for(auto val : nums) {
            mp[solve(val)].push_back(val);
        }
        int maxi = -1;
        for(auto val : mp) {
            int s = 0;
            if(val.second.size() > 1) {
                s += val.second.back();
                val.second.pop_back();
                s += val.second.back();
                maxi = max(maxi, s);
            }
        }
        return maxi;
    }
};