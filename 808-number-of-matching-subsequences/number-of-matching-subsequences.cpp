bool solve(string &s, string words){
    long long j = 0, k = 0;
    while(j < s.size() && k < words.size()){
        if(s[j] == words[k]){
            j++;
            k++;
        }
        else j++;
    }
    if(j <= s.size() && k == words.size()){
       return true;
    }
    return false;
}

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string, long long>mp;
        for(auto val : words){
            mp[val]++;
        }
        for(auto val : mp){
            if(solve(s, val.first)){
                count += val.second;
            }
        }
        return count;
    }
};