class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(), potions.end());
        for(long long i = 0; i<spells.size(); i++) {
            long long a = ceil(double(success)/double(spells[i]));
            long long idx = lower_bound(potions.begin(), potions.end(), a) - potions.begin();
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
};