// SEGMENT TREES :- vector<int> seg(1000), vector<int>arr(1000), i = 0, l = 0, h = n-1, x = idx, v = val, (x,y) = (l,r).
void buildSeg1(vector<int>& seg, const vector<int>& arr, int i, int l, int h) {
    if (l == h) {
        seg[i] = arr[l];
        return;
    }
    int m = (l + h) / 2;
    buildSeg1(seg, arr, 2*i + 1, l, m);
    buildSeg1(seg, arr, 2*i + 2, m + 1, h);
    seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
}
void updateSeg1(vector<int>& seg, vector<int>& arr, int i, int l, int h, int x, int v) {
    if (l == h) {
        arr[x] = v;
        seg[i] = v;
        return;
    }
    int m = (l + h) / 2;
    (x <= m) ? updateSeg1(seg, arr, 2*i + 1, l, m, x, v) : updateSeg1(seg, arr, 2*i + 2, m + 1, h, x, v);
    seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
}
int querySeg1(const vector<int>& seg, int i, int l, int h, int x, int y) {
    if (l > y || h < x) return INT_MIN;
    if (l >= x && h <= y) return seg[i];
    int m = (l + h) / 2;
    int leftMin = querySeg1(seg, 2*i + 1, l, m, x, y);
    int rightMin = querySeg1(seg, 2*i + 2, m + 1, h, x, y);
    return max(leftMin, rightMin);
}

void buildSeg2(vector<int>& seg, const vector<int>& arr, int i, int l, int h) {
    if (l == h) {
        seg[i] = arr[l];
        return;
    }
    int m = (l + h) / 2;
    buildSeg2(seg, arr, 2*i + 1, l, m);
    buildSeg2(seg, arr, 2*i + 2, m + 1, h);
    seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
}
void updateSeg2(vector<int>& seg, vector<int>& arr, int i, int l, int h, int x, int v) {
    if (l == h) {
        arr[x] = v;
        seg[i] = v;
        return;
    }
    int m = (l + h) / 2;
    (x <= m) ? updateSeg2(seg, arr, 2*i + 1, l, m, x, v) : updateSeg2(seg, arr, 2*i + 2, m + 1, h, x, v);
    seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
}
int querySeg2(const vector<int>& seg, int i, int l, int h, int x, int y) {
    if (l > y || h < x) return INT_MAX;
    if (l >= x && h <= y) return seg[i];
    int m = (l + h) / 2;
    int leftMin = querySeg2(seg, 2*i + 1, l, m, x, y);
    int rightMin = querySeg2(seg, 2*i + 2, m + 1, h, x, y);
    return min(leftMin, rightMin);
}

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> seg1(4*n+1), seg2(4*n+1);
        buildSeg1(seg1, nums, 0, 0, n-1);
        buildSeg2(seg2, nums, 0, 0, n-1);
        int i = 0, j = 0;
        int maxi = INT_MIN;
        while(j < nums.size()) {
            while(j < n && (querySeg1(seg1, 0, 0, n-1, i, j) - querySeg2(seg2, 0, 0, n-1, i, j)) > limit) {
                i++;
            }
            maxi = max(maxi, (int)j-i+1);
            j++;
        }
        return maxi;
    }
};