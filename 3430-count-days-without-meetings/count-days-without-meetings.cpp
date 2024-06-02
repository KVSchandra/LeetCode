class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int i = 0, j = 1;
        int count = 0;
        while(j < meetings.size()) {
            if(meetings[i][1] < meetings[j][0]) {
                count += abs(meetings[i][1] - meetings[j][0])-1;
                i = j;
                j++;
            }
            else {
                meetings[i][1] = max(meetings[i][1], meetings[j][1]);
                j++;
            }
        }
        // for(auto val : meetings) {
        //     cout << val[0] << " " << val[1] << endl;
        // }
        count += abs(meetings[0][0] - 1);
        count += abs(meetings[i][1] - days);
        return count;
    }
};