class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int a = 0;
        while(left != right){
            left = left>>1;
            right = right>>1;
            a++;
        }
        return left<<a;
    }
};