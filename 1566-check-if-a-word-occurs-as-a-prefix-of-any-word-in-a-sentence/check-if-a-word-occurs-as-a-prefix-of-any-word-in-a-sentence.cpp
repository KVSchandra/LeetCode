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

class Solution {
public:
    int isPrefixOfWord(string st, string word) {
        vector<string>v;
        int i = 0; 
        int j = 0;
        string a = "";
        while(j <= st.size()){
            if(st[j] == ' ' || j == st.size()){
                v.push_back(a);
                i = j+1;
                a = "";
                // j++;
            }
            if(st[j] != ' ')a += st[j];
            j++;
            
        }
        for(auto val : v) cout<<val<<" ";
        for(int i = 0; i<v.size(); i++){
            vector<int>ans = KMP(v[i], word);
            if(ans.size() == 0) continue;
            // for(auto val : ans) cout<<val<<" ";
            // cout<<endl;
            if(ans[0] == 0) return i+1;
        }
        // vector<int>as = KMP("burger", "burg");
        // cout<<as[0]<<endl;
        return -1;
    }
};