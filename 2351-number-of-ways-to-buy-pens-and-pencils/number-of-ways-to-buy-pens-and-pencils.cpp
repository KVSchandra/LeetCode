class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        long long a = total / cost1;
        long long t = total;
        while(a>=0){
            t -= (a*cost1);
            ans += ((int)(t/cost2)+1);
            // ans++;
            t = total;
            a--;
        }
        // if(total < cost1 && total < cost2) return 1;
        return ans ;
    }
};