class Solution {
public:
    bool check(string &word, string &temp){
        for(int i = 0; i<word.size(); i++){
            if(temp[i] != '#' && word[i] != temp[i]) return false;
        }
        return true;
    }

    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        string temp = word;
        int count = 1;
        for(int i = 0; i<n; i++) temp += '#';
        temp = temp.substr(k) + string(k, '#');
        while(!check(word, temp)){
            count++;
            int b = k;
            temp = temp.substr(k) + string(k, '#');
            // cout<<a<<endl;
            // temp = a;
            // cout<<word<<endl;
        }
        return count;
    }
};