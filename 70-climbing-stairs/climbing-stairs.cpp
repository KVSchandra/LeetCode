class Solution {
public:
    //TC : O(N) SC : O(N)
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int prev2 = 1;
        int prev1 = 1;
        int curri;
        for(int i = 2;i <= n; i++){
            curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri; 
        }
        return prev1;
    }
};