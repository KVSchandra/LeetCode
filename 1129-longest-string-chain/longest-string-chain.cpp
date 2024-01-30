class Solution {
public:
    bool isSimilar(string &s1, string &s2){
        if(s1.size() - s2.size() != -1) return false;
        int i = 0;
        int j = 0;
        int count = 2;
        while(i < s1.size() && j < s2.size() && count > 0){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            if(s1[i] != s2[j]){
                j++;
                count--;
            }
        }
        if((i != s1.size()-1 && j != s2.size()) || count <= 0) return false;
        return true;
    }

    int solve(int i, int prevInd, int n, vector<string>&words, vector<vector<int>>&dp){
        if(i == n) return 0;
        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];
        int pick = INT_MIN;
        if(prevInd == -1 || (isSimilar(words[prevInd], words[i]))) {
            pick = 1 + solve(i+1, i, n, words, dp);
        }
        int notPick = 0 + solve(i+1, prevInd, n, words, dp);
        return dp[i][prevInd + 1] = max(pick, notPick);
    }

    // bool compaa(string &s1, string &s2){
    //     return s1.size() < s2.size();
    // }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        });
        for(auto val : words) cout<<val<<" ";
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, -1, n, words, dp);
    }
};