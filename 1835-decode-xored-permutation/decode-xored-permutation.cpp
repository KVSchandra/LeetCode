class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int>ans;
        int x = 1;
        int X = encoded[0];
        for(int i = 1; i<encoded.size()+1; i++) {
            x ^= (i+1);
            if(i < encoded.size()-1 && i%2 == 0) {
                X ^= encoded[i];
            }
        }
        int last = (x ^ X);
        cout<<last<<endl;
        ans.push_back(last);
        for(int i = encoded.size()-1; i>=0; i--) {
            int a = (last ^ encoded[i]);
            ans.push_back(a);
            last = a;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};