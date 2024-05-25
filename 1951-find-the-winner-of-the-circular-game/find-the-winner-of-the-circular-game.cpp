class Solution {
public:
    int findTheWinner(int n, int k) {
        k = (k-1)%n;
        deque<int>dq;
        for(int i = 1; i<=n; i++) {
            dq.push_back(i);
        }
        int count = k;
        while(dq.size() != 1) {
            if(count) {
                int a = dq.front();
                dq.pop_front();
                dq.push_back(a);
                count--;
            }
            else {
                dq.pop_front();
                count = k;
            }
        }
        return dq.front();
    }
};