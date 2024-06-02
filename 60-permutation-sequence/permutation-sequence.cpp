class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        for(int i = 1; i<=n; i++) {
            ans += (i + '0');
        }
        if(k == 1) return ans;
        k--;
        while(next_permutation(ans.begin(), ans.end())) {
            k--;
            if(k == 0) return ans;
        }
        return ans;
    }
};