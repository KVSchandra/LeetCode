class Solution {
public:
    bool isThree(int n) {
        int c = 0;
        for(int i = 2; i<n; i++){
            if(n%i == 0) c++;
            if(c == 2) return false;
        }
        return c == 1;
    }
};