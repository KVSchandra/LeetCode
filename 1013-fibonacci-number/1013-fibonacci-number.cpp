class Solution {
public:
    int f(int n){
        int prev = 1;
        int prev2 = 0;
        int curr;
        for(int i = 2;i<=n;i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int fib(int n) {
        if(n<=1) return n;
        return f(n);
    }
};