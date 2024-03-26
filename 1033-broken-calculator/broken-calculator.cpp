class Solution {
public:
    int solve(int x, int y) {
        if(x >= y) {
            return abs(x-y);
        }
        if(y%2 == 0) return 1 + solve(x, y/2);
        return 1 + solve(x, y+1);
    }

    int brokenCalc(int startValue, int target) {
        return solve(startValue, target);
    }
};