static bool comp(string &s1, string &s2){
    if(s1.size() != s2.size()) return s1.size() > s2.size();
    if(s1.size() == s2.size() ) if(s1 < s2) return 1; else return 0;
    return 1;
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string>v;
        for(int i = 0; i<dictionary.size(); i++){
            int j = 0, k = 0;
            while(j < s.size() && k < dictionary[i].size()){
                if(s[j] == dictionary[i][k]){
                    j++;
                    k++;
                }
                else j++;
            }
            if(j <= s.size() && k == dictionary[i].size()){
                v.push_back(dictionary[i]);
            }
        }
        sort(v.begin(), v.end(), comp);
        for(auto val : v) cout<<val<<" ";
        if(v.size() == 0) return "";
        return v[0];
    }
};