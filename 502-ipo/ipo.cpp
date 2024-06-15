class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        priority_queue<int>pq1;
        for(int i = 0; i<profits.size(); i++) {
            pq.push({capital[i], profits[i]});
        }
        while(k--) {
            while(!pq.empty() && pq.top().first <= w) {
                pq1.push(pq.top().second);
                pq.pop();
            }
            if(pq1.empty()) break;
            w += pq1.top();
            pq1.pop();
        }
        // while(!pq.empty()) {
        //     cout << pq.top().first << " " << pq.top().second << endl;
        //     pq.pop();
        // }
        return w;
    }
};