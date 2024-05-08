class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while(target && maxDoubles) {
            if((target&1) == 0) {target /= 2; maxDoubles--;}
            else target--;
            count++;
        }
        return count + target - 1;
    }
};