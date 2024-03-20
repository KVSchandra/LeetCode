class Solution {
public:
    long long solve(int idx, vector<int>maxHeights){
        for(long long i = idx+1; i<maxHeights.size(); i++){
            if(maxHeights[i-1] < maxHeights[i]) maxHeights[i] = maxHeights[i-1];
        }
        for(long long i = idx-1; i>=0; i--){
            if(maxHeights[i+1] < maxHeights[i]) maxHeights[i] = maxHeights[i+1];
        }
        // for(auto val : maxHeights) cout<<val<<" ";
        // cout<<endl;
        return accumulate(maxHeights.begin(), maxHeights.end(), 0ll);
    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long maxi = INT_MIN;
        for(int i = 0; i<maxHeights.size(); i++){
            maxi = max(maxi, solve(i, maxHeights));
        }
        return maxi;
    }
};