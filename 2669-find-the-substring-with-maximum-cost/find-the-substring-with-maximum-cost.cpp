class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<long long>v(26, 0);
        for(long long i = 1; i<=26; i++){
            v[i-1] = i;
        }
        for(long long i = 0; i<chars.size(); i++){
            v[chars[i]-'a'] = vals[i];
        }
        long long maxi = INT_MIN;
        long long sum = 0;
        for(long long i = 0; i<s.size(); i++){
           sum += v[s[i] - 'a'];
           if(sum < 0) sum = 0;
           maxi = max(maxi, sum); 
        }
        if(maxi < 0) return 0;
        return maxi;
    }
};