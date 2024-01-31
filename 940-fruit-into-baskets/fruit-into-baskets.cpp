class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>mp;
        int maxi = 0;
        int i = 0, j = 0;
        int n = arr.size();
        while(j < n){
            mp[arr[j]]++;
            while(mp.size() > 2){
              mp[arr[i]]--;
              if(mp[arr[i]] == 0) mp.erase(arr[i]);
              i++;
            } 
            maxi =  max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};