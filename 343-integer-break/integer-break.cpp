class Solution {
public:
    int solve(int i, int sum, int prod, vector<int>&v){
        if(i == v.size()) return 0;
        if(sum == 0) return prod;
        int pick = INT_MIN;
        if(sum - v[i] >= 0) pick = v[i] * solve(i, sum-v[i], prod, v);
        int notPick = solve(i+1, sum, prod, v);
        return max(pick, notPick);
    }

    int integerBreak(int n) {
        vector<int>v;
        for(int i = 1;i<n;i++) v.push_back(i);
        int sum = n;
        int prod = 1;
        return solve(0, sum, prod, v);
    }
};