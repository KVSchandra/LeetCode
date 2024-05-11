class Solution {
public:
    double mincostToHireWorkers(vector<int>quality, vector<int>wage, int k) {
        vector<vector<double>> v;
        for(int i = 0; i < quality.size(); ++i) {
            v.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
        }
        sort(v.begin(), v.end());
        double mini = INT_MAX*(1.0);
        double a = 0;
        priority_queue<int> pq;

        for(auto val: v) {
            a += val[1]; 
            pq.push(val[1]);
            if(pq.size() > k) a -= pq.top(), pq.pop();
            if(pq.size() == k) mini = min(mini, a * val[0]);
        }
        return mini;
    }
};