class Solution {
public:
    void bfs(int i, vector<int>&vis, vector<vector<int>>&rooms){
        vis[i] = 1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto val : rooms[node]){
                if(!vis[val]){
                    vis[val] = 1;
                    q.push(val);
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n, 0);
        bfs(0, vis, rooms);
        for(auto val : vis){
            if(val == 0) return false;
        }
        return true;
    }
};