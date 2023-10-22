class Solution {
public:
    void comb(int ind,vector<int>&candidates,int target,vector<vector<int>>&v,vector<int>&output,int n){
        if(ind == n){
            if(target == 0){
                v.push_back(output);
            }
            return;
        }
        if(candidates[ind] <= target){
            output.push_back(candidates[ind]);
            comb(ind,candidates,target-candidates[ind],v,output,n);
            output.pop_back();
        }
        comb(ind+1,candidates,target,v,output,n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>output;
        
        comb(0,candidates,target,v,output,candidates.size());
        return v;
    }
};