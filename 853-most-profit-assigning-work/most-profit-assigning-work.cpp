class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        unordered_map<int, int>mp;
        for(int i = 0; i<profit.size(); i++) {
            if(mp[difficulty[i]]) {
                if(mp[difficulty[i]] < profit[i]) {
                    mp[difficulty[i]] = profit[i];
                }
            }
            else {
                mp[difficulty[i]] = profit[i];
            }
        }
        sort(difficulty.begin(), difficulty.end());
        vector<int>prefix(difficulty.size(), 0);
        int maxi = INT_MIN;
        for(int i = 0; i<difficulty.size(); i++) {
            maxi = max(maxi, mp[difficulty[i]]);
            prefix[i] = maxi;
        }
        int sum = 0;
        // for(int i = 0; i<difficulty.size(); i++) {
        //     cout << '{' << difficulty[i] << ',' << prefix[i] << '}' << " ";
        // }
        for(int i = 0; i<worker.size(); i++) {
            auto it = upper_bound(difficulty.begin(), difficulty.end(), worker[i]);
            if(it != difficulty.end()) {
                int idx = it - difficulty.begin();
                idx--;
                if(idx < 0) {
                    continue;
                }
                sum += prefix[idx];
            }
            else {
                sum += prefix.back();
            }
        }
        return sum;
    }
};