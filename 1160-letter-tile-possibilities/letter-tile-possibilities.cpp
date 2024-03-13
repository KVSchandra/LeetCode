void solve(int i, string &tiles, string temp, vector<string>&v){
    if(i == tiles.size()) {v.push_back(temp); return;}
    temp += tiles[i];
    solve(i+1, tiles, temp, v);
    temp.pop_back();
    solve(i+1, tiles, temp, v);
    return;
}

void solve2(int i, string s,vector<string>&a){
	    if(i == s.size()){
	        a.push_back(s);
            return;
	    }
	    for(int j = i; j<s.size(); j++){
            swap(s[i], s[j]);
            solve2(i+1, s, a);
            swap(s[i], s[j]);       
	    }
}

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<string>v;
        solve(0, tiles, "", v);
        // for(auto val : v) cout<<val<<" ";
        unordered_set<string>st;
        // cout<<endl;
        for(auto val : v){
            vector<string>a;
            solve2(0, val, a);
            for(auto val1 : a) st.insert(val1);
        }
        // for(auto val : v) st.insert(val);
        // for(auto val : st) cout<<val<<" ";
        return st.size() - 1;
    }
};