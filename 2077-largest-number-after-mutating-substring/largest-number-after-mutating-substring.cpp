class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        int c = 0;
        for(int i = 0; i<n; i++){
            if(num[i]-'0' < change[num[i]-'0']) {num[i] = char((change[num[i] - '0']) + '0');c++;}
            else if(num[i]-'0' == change[num[i]-'0'] && c){num[i] = char((change[num[i] - '0']) + '0');c++;}
            else if(c) break;
        }
        return num;
    }
};