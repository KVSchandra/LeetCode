class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int>mp;
        int mini = INT_MAX;
        while(j < n){
            mp[cards[j]]++;
            while(mp[cards[j]] >= 2 && i < j){
                mp[cards[i]]--;
                i++;
                mini = min(mini, j-i+1);
            }
            // if(mp[cards[j]] == 2){
            //     mini = min(mini, j-i+1);
            // }
            j++;
        }
        if(mini == INT_MAX) return -1;
        return mini+1;
    }
};