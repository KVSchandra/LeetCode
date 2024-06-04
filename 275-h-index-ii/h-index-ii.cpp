class Solution {
public:
    int hIndex(vector<int>& citations) {
        int maxi = INT_MIN;
        // sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i = 0; i<n; i++) {
            maxi = max(maxi, min(citations[i], n-i));
        }
        return maxi;
    }
};