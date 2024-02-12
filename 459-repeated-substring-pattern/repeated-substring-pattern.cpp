class Solution {
public:
    // KMP ALGORITHM :- vector<int> V = KMP (string s1, string s2).
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int>lps(m, 0);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(const string& text, const string& pattern) {
    vector<int>lps = buildLPS(pattern);
    int n = text.size();
    int m = pattern.size();
    vector<int> matches;
    int i = 0, j = 0;
    while (i < n) {
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            matches.push_back(i - j);
            j = lps[j - 1];
        }
        else if(i < n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return matches;
}

    bool repeatedSubstringPattern(string s) {
        vector<int>lps = buildLPS(s);
        int count = 0;
        for(auto val : lps) cout<<val<<" ";
        int n = lps.size();
        if(lps[n-1] > 0 && (lps[n-1] % (n - lps[n-1])) == 0) return true;
        return false;
    }
};