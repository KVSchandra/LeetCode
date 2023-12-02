class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;
        for(int i = 0;i<words.size();i++){
            string s;
            for(int j = 0;j<words[i].size();j++){
                if(words[i][j] == separator) {if(!s.empty()) ans.push_back(s);s.clear();}
                else s+=words[i][j];
            }
            ans.push_back(s);
        }
        vector<string>res;
        for(auto val : ans){
            if(val == "") continue;
            else res.push_back(val);
        }
        return res;
    }
};