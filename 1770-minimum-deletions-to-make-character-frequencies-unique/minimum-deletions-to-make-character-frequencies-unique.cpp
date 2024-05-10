class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int>mp;
        for(auto val : s) mp[val]++;
        unordered_set<int>st;
        int count = 0;
        for(auto val : mp) {
            while(val.second && st.find(val.second) != st.end()) {
                val.second--;
                count++;
            }
            st.insert(val.second);
        }
        return count;
    }
};