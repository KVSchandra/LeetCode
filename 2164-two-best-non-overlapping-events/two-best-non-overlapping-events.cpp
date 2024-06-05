class Solution {
public:
    int solve(int i, int count, vector<vector<int>>&events, vector<vector<int>>&dp) {
        if(count == 2) return 0;
        if(i == events.size()) return 0;
        if(dp[i][count] != -1) return dp[i][count];
        int pick = 0;
        int low = i+1, high = events.size()-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(events[i][1] < events[mid][0]) high = mid-1;
            else low = mid+1;
        }
        pick += events[i][2] + solve(low, count+1, events, dp);
        int notPick = 0 + solve(i+1, count, events, dp);
        return dp[i][count] = max(pick, notPick);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int maxi = INT_MIN;
        // for(int i = 0; i<events.size(); i++) {
        //     int low = i+1, high = events.size()-1;
        //     maxi = max(maxi, events[i][2]);
        //     while(low <= high) {
        //         int mid = low + (high - low)/2;
        //         if(events[i][1] < events[mid][0]) high = mid-1;
        //         else low = mid+1;
        //     }
        //     for(int j = low; j<events.size(); j++) {
        //         maxi = max(maxi, events[i][2] + events[j][2]);
        //     }
        // }
        vector<vector<int>>dp(events.size(), vector<int>(3, -1));
        return solve(0, 0, events, dp);
    }
};