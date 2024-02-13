class Solution {
public:
    int numSplits(string s) {
        int j = 1;
        int n = s.size();
        unordered_map<char, int>mp1, mp2;
        mp1[s[0]]++;
        int count = 0;
        for(int i = 1; i<n; i++) mp2[s[i]]++;
        while(j < n){
            if(mp1.size() == mp2.size()){
                count++;
            }
            
            mp1[s[j]]++;
            mp2[s[j]]--;
            if(mp2[s[j]] == 0) mp2.erase(s[j]);
            
            j++;
        }
        return count;
        
    }
};