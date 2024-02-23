static bool comp(pair<string, int>&s1, pair<string, int>&s2){
    if(s1.first.size() == s2.first.size()){
        return s1.second < s2.second;
    }
    return s1.first.size() < s2.first.size();
}


class Solution {
public:
    string arrangeWords(string text) {
        text[0] |= ' ';
        vector<pair<string, int>>v;
        string s = "";
        int count = 0;
        for(int i = 0; i<text.size(); i++){
            if(text[i] == ' ' || i == text.size()-1){
                if(i == text.size()-1) s += text[i];
                v.push_back({s, count});
                count++;
                s.clear();
            }
            else {
                s += text[i];
            }
        }
        s.clear();
        sort(v.begin(), v.end(), comp);
        for(auto val : v){
            s += (val.first + ' ');
        }
        s.pop_back();
        s[0] &= '_';
        // for(auto val : v) cout<<val.first<<" ";
        return s;
    }
};