class Solution {
public:
    int solve(int i, int prev, bool b, vector<int>&arr) {
        if(i == arr.size()) return 0;
        int pick = INT_MIN;
        if(b == 1 && prev > arr[i]) pick = 1 + solve(i+1, arr[i], !b, arr);
        else if(b == 0 && prev < arr[i]) pick = 1 + solve(i+1, arr[i], !b, arr);
        if(pick != INT_MIN) return pick;
        return 0;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int maxi = INT_MIN;
        for(int i = 0; i<arr.size(); i++) {
            maxi = max(max(solve(i+1, arr[i], 1, arr)+1, solve(i+1, arr[i], 0, arr)+1), maxi);
        }
        return maxi;
    }
};