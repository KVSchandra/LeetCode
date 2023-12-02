class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26,0);
        int count = 0;
        for(auto ch : chars){
            v[ch-'a']++;
        }
        for(auto str : words){
            bool flag = true;
            vector<int>cc(26,0);
            for(auto ch : str){
                if(++cc[ch-'a'] > v[ch-'a']){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count += str.size();
            }
        }
        return count;
    }
};