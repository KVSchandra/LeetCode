class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        int s = n*(n+1)/2;
        for(int i = 1;i<=n;i++){
            sum += i;
            if(sum == s-sum+i) return i;
        }
        return -1;
    }
};