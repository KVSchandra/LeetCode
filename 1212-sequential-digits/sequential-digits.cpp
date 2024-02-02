class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i = 1; i<=8; i++){
            int n = i;
            for(int j = i+1; j<=9; j++){
                n = n*10 + j;
                if(n >= low && n <= high) ans.push_back(n);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};