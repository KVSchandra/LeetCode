class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int a = (1 << k);
        if(s.size() < k) return false;
        unordered_set<string>st;
        for(int i = 0; i<s.size()-k+1; i++) {
            st.insert(s.substr(i, k));
            if(st.size() == a) return true;
        }
        return false;
    }
};