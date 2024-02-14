// SEGMENTED TREES :- vector<int> seg(1000), vector<int>arr(1000), i = 0, l = 0, h = n-1, x = idx, v = val, (x,y) = (l,r).
void buildSeg(vector<int>& seg, const vector<int>& heights, int i, int l, int h) {
    if (l == h) {
        seg[i] = heights[l];
        return;
    }
    int m = (l + h) / 2;
    buildSeg(seg, heights, 2*i + 1, l, m);
    buildSeg(seg, heights, 2*i + 2, m + 1, h);
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
    seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
}
int querySeg(const vector<int>& seg, int i, int l, int h, int x, int y) {
    if (l > y || h < x) return INT_MIN;
    if (l >= x && h <= y) return seg[i];
    int m = (l + h) / 2;
    int leftMin = querySeg(seg, 2*i + 1, l, m, x, y);
    int rightMin = querySeg(seg, 2*i + 2, m + 1, h, x, y);
    return max(leftMin, rightMin);
}

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = heights.size();
        int q = queries.size();
        vector<int>seg(4*n+100);
        buildSeg(seg, heights, 0, 0, n-1);
        for(int i = 0; i<q; i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(x == y || heights[max(x, y)] > heights[min(x, y)]) ans.push_back(max(x, y));
            else {
                int l = max(x, y) + 1;
                int h = n-1;
                int res = -1;
                while(l <= h){
                    int mid = l + (h-l)/2;
                    if(querySeg(seg, 0, 0, n-1, l, mid) > max(heights[x], heights[y])){
                        res = mid;
                        h = mid-1;
                    }
                    else l = mid + 1;
                }

                ans.push_back(res);
            }
        }
        return ans;
    }
};