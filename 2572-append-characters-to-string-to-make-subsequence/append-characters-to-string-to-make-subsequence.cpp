class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int count = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {count++; i++; j++;}
            else i++;
        }
        return t.size() - count;
    }
};