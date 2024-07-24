class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>ans;
        map<int,int>mp;
        int maxi=0;
        set<int>st;
        for(int i=0;i<k;i++)
        {
            st.insert(arr[i]);
            mp[arr[i]]++;
        }
        /*for(auto it:st)
        {
            cout<<it<<endl;
        }*/
        //cout<<*(st.rbegin())<<endl;
        ans.push_back(*(st.rbegin()));
        int j=k;
        int i=0;
        while(j<n){
            mp[arr[j]]++;
            st.insert(arr[j]);
            mp[arr[i]]--;
            if(mp[arr[i]]==0)
            {
               mp.erase(arr[i]);
               st.erase(arr[i]);
               ans.push_back(*(st.rbegin()));
            }
            else
            {
                ans.push_back(*(st.rbegin()));
            }
           i++;j++;
        }
        return ans;
    }
};