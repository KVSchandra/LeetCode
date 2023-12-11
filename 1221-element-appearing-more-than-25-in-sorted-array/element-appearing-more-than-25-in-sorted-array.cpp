class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        int a,maxi = INT_MIN;
        for(int i = 0;i<arr.size();i++) mp[arr[i]]++;
        for(auto val : mp){
            if(maxi < val.second){
                maxi = val.second;
                a = val.first;
            }
        }
        return a;
    }
};