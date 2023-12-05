class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while(n){
            if(n&1 != 0){
                n = (n-1)/2;
                sum += n + 1;
            }
            else {
                n = n/2;
                sum += n;
            }
        }
        return sum - 1;
    }
};