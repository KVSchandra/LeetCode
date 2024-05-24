class Solution {
public:
    // SEGMENT TREES :- vector<int> seg(1000), vector<int>arr(1000), i = 0, l = 0, h = n-1, x = idx, v = val, (x,y) = (l,r).
    void buildSeg(vector<int>& seg, const vector<int>& arr, int i, int l, int h) {
        if (l == h) {
            seg[i] = arr[l];
            return;
        }
        int m = (l + h) / 2;
        buildSeg(seg, arr, 2*i + 1, l, m);
        buildSeg(seg, arr, 2*i + 2, m + 1, h);
        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }
    void updateSeg(vector<int>& seg, vector<int>& arr, int i, int l, int h, int x, int v) {
        if (l == h) {
            arr[x] = v;
            seg[i] = v;
            return;
        }
        int m = (l + h) / 2;
        (x <= m) ? updateSeg(seg, arr, 2*i + 1, l, m, x, v) : updateSeg(seg, arr, 2*i + 2, m + 1, h, x, v);
        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }
    int querySeg(const vector<int>& seg, int i, int l, int h, int x, int y) {
        if (l > y || h < x) return INT_MIN;
        if (l >= x && h <= y) return seg[i];
        int m = (l + h) / 2;
        int leftMin = querySeg(seg, 2*i + 1, l, m, x, y);
        int rightMin = querySeg(seg, 2*i + 2, m + 1, h, x, y);
        return max(leftMin, rightMin);
    }

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans;
        set<int>st;
        for(auto val : obstacles) st.insert(val);
        vector<int>v;
        unordered_map<int, int>mp;
        for(auto val : st) {
            v.push_back(val);
            mp[val] = v.size()-1;
        }
        vector<int>vis(v.size(), 0);
        vector<int>seg(v.size()*4 + 1);
        int n = v.size();
        buildSeg(seg, vis, 0, 0, n-1);
        for(auto val : obstacles) {
            int a = querySeg(seg, 0, 0, n-1, 0, mp[val]);
            vis[mp[val]] = a+1;
            ans.push_back(vis[mp[val]]);
            updateSeg(seg, vis, 0, 0, n-1, mp[val], vis[mp[val]]);
        }
        return ans;
    }
};