class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int count = 0;
        while(pq.top() != 0) {
            count++;
            int A = pq.top();
            pq.pop();
            int B = pq.top();
            if(B == 0) {
                count--;
                break;
            }   
            pq.pop();
            pq.push(A-1);
            pq.push(B-1);
        }
        return count;
    }
};