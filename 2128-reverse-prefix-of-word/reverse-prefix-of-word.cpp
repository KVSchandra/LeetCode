class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx;
        if(find(word.begin(), word.end(), ch) != word.end())
        idx = find(word.begin(), word.end(), ch) - word.begin();
        else return word;
        reverse(word.begin(), word.begin()+idx+1);
        return word;
    }
};