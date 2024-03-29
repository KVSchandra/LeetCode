// SEGMENT TREES :- vector<int> seg(1000), vector<int>arr(1000), i = 0, l = 0, h = n-1, x = idx, v = val, (x,y) = (l,r).
void buildSeg(vector<int>& seg, const vector<int>& arr, int i, int l, int h) {
    if (l == h) {
        seg[i] = arr[l];
        return;
    }
    int m = (l + h) / 2;
    buildSeg(seg, arr, 2*i + 1, l, m);
    buildSeg(seg, arr, 2*i + 2, m + 1, h);
    seg[i] = (seg[2*i + 1] ^ seg[2*i + 2]);
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
    if (l > y || h < x) return 0;
    if (l >= x && h <= y) return seg[i];
    int m = (l + h) / 2;
    int leftXor = querySeg(seg, 2*i + 1, l, m, x, y);
    int rightXor = querySeg(seg, 2*i + 2, m + 1, h, x, y);
    return leftXor ^ rightXor;
}

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = arr.size();
        vector<int>seg(4*n);
        buildSeg(seg, arr, 0, 0, n-1);
        for(auto val : queries) {
            int a = querySeg(seg, 0, 0, n-1, val[0], val[1]);
            ans.push_back(a);
        }
        return ans;
    }
};