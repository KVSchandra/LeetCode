class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int a = asteroids.back();
        for(auto val : asteroids) {
            if(mass >= a) return true;
            if(val <= mass) {
                mass += val;
            }
            else {
                return false;
            }
        }
        return true;
    }
};