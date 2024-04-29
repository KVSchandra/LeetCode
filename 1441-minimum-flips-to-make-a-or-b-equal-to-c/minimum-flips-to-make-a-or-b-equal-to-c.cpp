class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        int C = a | b; 
        for(int i = 0; i < 31; i++) {
            bool bitC = C & (1 << i);
            bool bitc = c & (1 << i);
            if(!bitc && bitC) {  
                if(a & (1 << i)) count++;
                if(b & (1 << i)) count++;
            } 
            else if(bitc && !bitC) {  
                if(!(a & (1 << i)) && !(b & (1 << i))) { 
                    count++;
                }
            }
        }
        return count;
    }
};
