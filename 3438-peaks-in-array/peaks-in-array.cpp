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
        seg[i] = (seg[2*i + 1] + seg[2*i + 2]);
    }
    void updateSeg(vector<int>& seg, vector<int>& arr, int i, int l, int h, int x, int v) {
        if (l == h) {
            arr[x] = v;
            seg[i] = v;
            return;
        }
        int m = (l + h) / 2;
        (x <= m) ? updateSeg(seg, arr, 2*i + 1, l, m, x, v) : updateSeg(seg, arr, 2*i + 2, m + 1, h, x, v);
        seg[i] = (seg[2*i + 1] + seg[2*i + 2]);
    }
    int querySeg(const vector<int>& seg, int i, int l, int h, int x, int y) {
        if (l > y || h < x) return 0;
        if (l >= x && h <= y) return seg[i];
        int m = (l + h) / 2;
        int leftMin = querySeg(seg, 2*i + 1, l, m, x, y);
        int rightMin = querySeg(seg, 2*i + 2, m + 1, h, x, y);
        return (leftMin + rightMin);
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>v(n, 0);
        for(int i = 1; i < n-1; i++) {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                v[i]++;
            }
        }
        vector<int>seg(4*n+1);
        buildSeg(seg, v, 0, 0, n-1);
        vector<int>ans;
        for(auto val : queries) {
            if(val[0] == 1) {
                if(abs(val[1] - val[2]) < 2) {
                    ans.push_back(0);
                    continue;
                }
                int a = querySeg(seg, 0, 0, n-1, val[1]+1, val[2]-1);
                ans.push_back(a);
            }
            else {
                int i = val[1];
                nums[i] = val[2];
                int newVal1 = 0, newVal2 = 0, newVal3 = 0;
                if(i > 0 && i < n-1) {
                    if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                        newVal1 = 1;
                    }
                }
                if(i-1 > 0) {
                    if(nums[i-2] < nums[i-1] && nums[i-1] > nums[i]) {
                        newVal2 = 1;
                    }
                }
                if(i+1 < n-1) {
                    if(nums[i] < nums[i+1] && nums[i+1] > nums[i+2]) {
                        newVal3 = 1;
                    }
                }
                if(i > 0 && i < n-1) updateSeg(seg, v, 0, 0, n-1, i, newVal1);
                if(i-1 > 0) updateSeg(seg, v, 0, 0, n-1, i-1, newVal2);
                if(i+1 < n-1) updateSeg(seg, v, 0, 0, n-1, i+1, newVal3);
            }
            // for(auto val : v) cout << val << " ";
        }
        return ans;
    }
};