class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int a;
        for(int i = num.size()-1;i>=0;i--){
          if((num[i] - '0') & 1) {
            a = i;
            break;
          }
        }
        return num.substr(0,a+1);
    }
};