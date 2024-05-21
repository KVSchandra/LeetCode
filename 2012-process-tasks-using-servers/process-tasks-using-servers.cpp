class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>busy;
        vector<int>ans(tasks.size());

        for(int i = 0; i<servers.size(); i++) {
            free.push({servers[i], i});
        }

        int time = 0;
        for(int i = 0; i<tasks.size(); i++) {
            time = max(time, i);
            if(free.empty()) {
                time = busy.top().first;
            }

            while(!busy.empty() && busy.top().first <= time) {
                auto val = busy.top();
                free.push({servers[val.second], val.second});
                busy.pop();
            }

            auto val = free.top();
            busy.push({time + tasks[i], val.second});
            ans[i] = val.second;
            free.pop();
        }
        return ans;
    }
};