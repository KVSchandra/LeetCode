class Solution {
public:
    vector<int> generateRows(int n){
        vector<int>ansRow;
        long long ans = 1;
        ansRow.push_back(1);
        for(int i = 1;i<n;i++){
            ans = ans*(n-i);
            ans = ans/i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i = 1;i<=numRows;i++){
            res.push_back(generateRows(i));
        }
        return res;
    }
};