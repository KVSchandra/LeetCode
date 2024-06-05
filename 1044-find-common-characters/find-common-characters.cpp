class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>count(26, INT_MAX);
        vector<string>ans;
        for(auto val : words) {
            vector<int>temp(26, 0);
            for(auto val1 : val) {
                temp[val1 - 'a']++;
            }
            for(int i = 0; i<26; i++) {
                count[i] = min(count[i], temp[i]);
            }
        }
        for(int i = 0; i<26; i++) {
            while(count[i]--) {
                string a = "";
                a.push_back(i + 'a');
                ans.push_back(a);
            }
        }
        return ans;
    }
};