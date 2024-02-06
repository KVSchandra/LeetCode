class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        vector<int>ans;
        if(t < c || t&1 || t > 4*c || t < 2*c) return ans;
        ans.push_back(t/2 - c);
        ans.push_back(2*c - (t/2));
        return ans;
    }
};