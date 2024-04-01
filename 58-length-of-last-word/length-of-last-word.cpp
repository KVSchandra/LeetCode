class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0,a;
        for(int i = s.size()-1;i >= 0;i--){
            if(s[i] != ' ') {a = i;break;}
        }
        for(int i = a;i>=0;i--){
            if(s[i] == ' ') break;
            count++;
        }
        return count;
    }
};