class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<unordered_map<char, int>>v(words2.size());
        unordered_map<char, int>max_freq;
        for(int i = 0; i<words2.size(); i++) {
            unordered_map<char, int>mp;
            for(auto val : words2[i]) mp[val]++;
            v[i] = mp;
            for(auto val : mp) {
                if(max_freq.find(val.first) != max_freq.end()) {
                    if(max_freq[val.first] < val.second) max_freq[val.first] = val.second;
                }
                else max_freq[val.first] += val.second;
            }
        }
        vector<string>ans;
        for(int i = 0; i<words1.size(); i++) {
            unordered_map<char, int>mp;
            for(auto val : words1[i]) mp[val]++;
            bool flag = false;
            for(auto val : max_freq) {
                if(mp.find(val.first) == mp.end()) {
                    flag = true; 
                    break;
                }
                else if(mp[val.first] < val.second) {
                    flag = true;
                    break;
                }
            }
            if(flag == false) ans.push_back(words1[i]); 
        }
        return ans;
    }
};