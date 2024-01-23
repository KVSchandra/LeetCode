bool isUnique(string &s){
    if(s.size() == 0) return true; 
    unordered_map<char, int>mp;
    for(auto val : s) mp[val]++;
    for(auto val : mp){
        if(val.second > 1) return false;
    }
    return true;
}

int solve(vector<string>&arr, string ans, int i){
    // if(i == n) return 0;
    if(!isUnique(ans)) return 0;
    int maxi = ans.size();
    for(int j = i; j<arr.size(); j++){
        maxi = max(maxi, solve(arr, ans + arr[j], j+1));
    }
    return maxi;
}

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        if(n == 1){
            if(isUnique(arr[0])){
                return arr[0].size();
            }
            return 0;
        }
        int ans = solve(arr, "", 0);
        return ans;
    }
};