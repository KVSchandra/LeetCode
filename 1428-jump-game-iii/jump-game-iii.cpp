class Solution {
public:
    bool solve(int i, vector<int>&arr, vector<int>&vis){
        if(arr[i] == 0) return true;
        bool left = false, right = false;
        vis[i] = 1;
        if(i - arr[i] >= 0 && !vis[i-arr[i]]) left =  solve(i-arr[i], arr, vis);
        if(i + arr[i] < arr.size() && !vis[i+arr[i]]) right =  solve(i+arr[i], arr, vis);
        return left | right;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(), 0);
        // vis[start] = 1;
        return solve(start, arr, vis);
    }
};