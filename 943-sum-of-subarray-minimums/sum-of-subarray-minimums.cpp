class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        vector<int>ple(n), nle(n);
        for(int i = 0; i<n; i++) {
            while(!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if(st.empty()) ple[i] = i;
            else ple[i] = i-st.top()-1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if(st.empty()) nle[i] = n-i-1;
            else nle[i] = st.top()-i-1;
            st.push(i);
        }
        // for(auto val : ple) cout << val << " ";
        // cout << endl;
        // for(auto val : nle) cout << val << " ";
        // cout << endl;
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            long long prod = ((ple[i]+1)*(nle[i]+1))%mod;
            prod = (prod*arr[i])%mod;
            ans = (ans + prod)%mod;
        }
        return ans;
    }
};