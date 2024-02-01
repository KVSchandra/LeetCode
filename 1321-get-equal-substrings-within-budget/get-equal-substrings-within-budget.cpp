class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i = 0;
        int j = 0;
        long long sum = 0;
        int count = 0;
        int maxi = INT_MIN;
        while(j < n){
            sum += (abs(s[j] - t[j]));
            while(sum > maxCost && i <= j){
                sum -= (abs(s[i] - t[i]));
                i++;
            }
            // if(sum == maxCost){
            //     count++;
            // }
            maxi = max(j-i+1, maxi);
            j++;
        }
        return maxi;
    }
};