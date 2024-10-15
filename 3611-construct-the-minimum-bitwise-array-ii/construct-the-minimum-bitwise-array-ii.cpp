#define ll long long
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& v) {
        vector<int> ans;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 2) {
                ans.push_back(-1);
            }
            else if(((v[i] + 1) & (v[i])) == 0) {
                ans.push_back(v[i] / 2);
            
            }
            else if(v[i] & (1 << 1)) {
                for(ll j = 1; j < 32; j++) {
                    if((v[i] & (1 << j)) == 0) {
                        v[i] ^= (1 << (j-1));
                        break;
                    }
                }
                ans.push_back(v[i]);
            }
            else {
                ans.push_back(v[i] - 1);
            }
        }
        return ans;
    }
};