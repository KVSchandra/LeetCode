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

    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        string c = a;
        bool flag = true;
        if(n > m){
            vector<int>v = KMP(a, b);
            if(v.size() == 0) flag = false;
            else return 1;
            if(flag == false){
                a += c;
                vector<int>v2 = KMP(a, b);
                if(v2.size() != 0) return 2;
                else return -1;
            }
        }
        else {
            int i = 1;
            while(a.size() < m){
               a += c;
               i++;
            }
            vector<int>v = KMP(a,b);
            if(v.size()) return i;
            a += c;
            vector<int>v1 = KMP(a, b);
            if(v1.size()) return i+1;
            return -1;
        }
        return -1;
    }
};