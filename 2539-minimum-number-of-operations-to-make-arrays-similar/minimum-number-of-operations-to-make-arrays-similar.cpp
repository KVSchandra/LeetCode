#define ll long long
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> v1, v2, v3, v4;
        for(auto val : nums) {
            if(val&1) {
                v1.push_back(val);
            }
            else {
                v3.push_back(val);
            }
        }
        for(auto val : target) {
            if(val & 1) {
                v2.push_back(val);
            }
            else {
                v4.push_back(val);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());
        ll count = 0;
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] > v2[i]) {
                count += (v1[i] - v2[i]);
            }
        }
        for(int i = 0; i < v3.size(); i++) {
            if(v3[i] > v4[i]) {
                count += (v3[i] - v4[i]);
            }
        }
        return count/2;
    }
};