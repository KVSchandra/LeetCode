class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        s.push_back(' ');
        reverse(s.begin(), s.end());
        while(s[i] != ' ') i++;
        string temp = "";
        int a = s.size();
        while(i < a) {
            if(s[i] != ' ') {
                temp += s[i];
            }
            else if(temp != ""){
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans.push_back(' ');
                temp = "";
            }
            i++;
        }
        if(temp != "") reverse(temp.begin(), temp.end());
        if(temp != "") ans += temp;
        if(ans[ans.size()-1] == ' ') ans.pop_back();
        return ans;
    }
};
