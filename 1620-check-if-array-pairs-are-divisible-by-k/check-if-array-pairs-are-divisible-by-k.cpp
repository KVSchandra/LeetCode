class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto val : arr) {
            mp[(k - (val % k)) % k]++;
        }
        for(auto val : arr) {
            int temp = (k - (val % k)) % k;
            if(temp == 0) {
                if(mp[0] & 1) {
                    return false;
                }
            }
            else if(mp.find(k - temp) != mp.end()) {
                if(mp[k - temp] != mp[temp]) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};