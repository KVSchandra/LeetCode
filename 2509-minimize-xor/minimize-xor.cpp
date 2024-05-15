class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        int a = __builtin_popcount(num2);
        for(int i = 31; i>=0; i--) {
            if((1 << i) & num1) {
                x |= (1 << i);
                a--;
            }
            if(a == 0) break;
        }
        
        if(a > 0) {
            for(int i = 0; i<32; i++) {
                if((num1 & (1 << i)) == 0) {
                    x |= (1 << i);
                    a--;
                }
                if(a == 0) break;
            }
        }
        return x;
    }
};