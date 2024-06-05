class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s1 = s;
        int i = 0;
        while(s[i] == '9') {
            i++;
        }
        char ch = s[i];
        while(i < s.size()) {
            if(s[i] == ch) {
                s[i] = '9';
            }
            i++;
        }
        i = 0;
        if(s1[i] == '1') {
            while(s1[i] == '1' || s1[i] == '0') {
                i++;
            }
            char c = s1[i];
            while(i < s1.size()) {
                if(s1[i] == c) {
                    s1[i] = '0';
                }
                i++;
            }
        }
        else {
            char c = s1[0];
            for(int j = 0; j<s.size(); j++) {
                if(s1[j] == c) {
                    s1[j] = '1';
                }
            }
        }
        cout << s << " " << s1 << endl;
        return stoi(s) - stoi(s1);
    }
};