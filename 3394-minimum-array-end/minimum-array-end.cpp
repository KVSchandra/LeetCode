class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long j = 0;
        long long nn = (long long)n;

        for(long long i = 0; i<63; i++) {
            if((ans & (1LL << i)) == 0) {
                long long b = ((nn-1) & (1LL << j));
                if(b) {
                    ans |= (1LL << i);
                }
                j++;
            }
        }
        return ans;
    }
};
