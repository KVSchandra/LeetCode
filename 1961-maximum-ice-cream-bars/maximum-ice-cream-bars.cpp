class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto val : costs) pq.push(val);
        int count = 0;
        while(!pq.empty()) {
            coins -= pq.top();
            if(coins < 0) break;
            count++;
            pq.pop();
        } 
        return count;
    }
};