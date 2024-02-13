class Solution {
public:
    // SEGMENTED TREES :- vector<int> seg(1000), vector<int>arr(1000), i = 0, l = 0, h = n-1, x = idx, v = val, (x,y) = (l,r).
    void buildSeg1(vector<int>& seg1, const vector<int>& nums, int i, int l, int h) {
        if (l == h) {
            seg1[i] = nums[l];
            return;
        }
        int m = (l + h) / 2;
        buildSeg1(seg1, nums, 2*i + 1, l, m);
        buildSeg1(seg1, nums, 2*i + 2, m + 1, h);
        seg1[i] = min(seg1[2*i + 1], seg1[2*i + 2]);
    }
    void buildSeg2(vector<int>& seg2, const vector<int>& nums, int i, int l, int h) {
        if (l == h) {
            seg2[i] = nums[l];
            return;
        }
        int m = (l + h) / 2;
        buildSeg2(seg2, nums, 2*i + 1, l, m);
        buildSeg2(seg2, nums, 2*i + 2, m + 1, h);
        seg2[i] = max(seg2[2*i + 1], seg2[2*i + 2]);
    }
    void updateSeg(vector<int>& seg, vector<int>& nums, int i, int l, int h, int x, int v) {
        if (l == h) {
            nums[x] = v;
            seg[i] = v;
            return;
        }
        int m = (l + h) / 2;
        (x <= m) ? updateSeg(seg, nums, 2*i + 1, l, m, x, v) : updateSeg(seg, nums, 2*i + 2, m + 1, h, x, v);
        seg[i] = min(seg[2*i + 1], seg[2*i + 2]);
    }
    int querySeg1(const vector<int>& seg, int i, int l, int h, int x, int y) {
        if (l > y || h < x) return INT_MAX;
        if (l >= x && h <= y) return seg[i];
        int m = (l + h) / 2;
        int leftMin = querySeg1(seg, 2*i + 1, l, m, x, y);
        int rightMin = querySeg1(seg, 2*i + 2, m + 1, h, x, y);
        return min(leftMin, rightMin);
    }

    int querySeg2(const vector<int>& seg, int i, int l, int h, int x, int y) {
        if (l > y || h < x) return INT_MIN;
        if (l >= x && h <= y) return seg[i];
        int m = (l + h) / 2;
        int leftMin = querySeg2(seg, 2*i + 1, l, m, x, y);
        int rightMin = querySeg2(seg, 2*i + 2, m + 1, h, x, y);
        return max(leftMin, rightMin);
    }
    

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> seg1(4*n + 1000), seg2(4*n + 1000);
        buildSeg1(seg1, nums, 0, 0, n-1);
        buildSeg2(seg2, nums, 0, 0, n-1);
        long long sum = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int a = querySeg1(seg1, 0, 0, n-1, i, j);
                int b = querySeg2(seg2, 0, 0, n-1, i, j);
                sum += abs(a-b);
            }
        }
        return sum;
    }
};