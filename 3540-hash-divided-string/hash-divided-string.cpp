class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        int count = 0;
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            if(count && count % k == (0)) {
                sum = sum % 26;
                ans.push_back('a' + sum);
                sum = 0;
            }
            sum += s[i] - 'a';
            count++;
        }
        ans.push_back('a' + (sum % 26));
        return ans;
    }
};