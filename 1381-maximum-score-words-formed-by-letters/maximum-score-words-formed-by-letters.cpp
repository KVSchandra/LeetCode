class Solution {
public:
    int getScore(vector<string>&temp, unordered_map<char, int>mp, vector<int>&score) {
        int sum = 0;
        for(auto val : temp) {
            for(auto val1 : val) {
                if(mp[val1]) { 
                    sum += score[val1 - 'a'];
                    mp[val1]--;
                }
                else return 0;
            }
        }
        return sum;
    }

    bool check(string &s, unordered_map<char, int>&mp) {
        unordered_map<char, int>mp1;
        for(auto val : s) mp1[val]++;
        for(auto val : s) {
            if(mp.find(val) != mp.end()) {
                if(mp[val] < mp1[val]) return false;
            }
            else return false;
        }
        return true;
    }

    void solve(int i, vector<string>&words, vector<string>&temp, int &maxi, unordered_map<char, int>&mp, vector<int>&score) {
        if(i == words.size()) {
            if(temp.size()) {
                maxi = max(maxi, getScore(temp, mp, score));
            }
            return;
        }
        if(check(words[i], mp)) {
            temp.push_back(words[i]);
            solve(i+1, words, temp, maxi, mp, score);
            temp.pop_back();
        }
        solve(i+1, words, temp, maxi, mp, score);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int maxi = INT_MIN;
        vector<string>temp;
        unordered_map<char, int>mp;
        for(auto val : letters) mp[val]++;
        solve(0, words, temp, maxi, mp, score);
        if(maxi < 0) maxi = 0;
        return maxi;
    }
};