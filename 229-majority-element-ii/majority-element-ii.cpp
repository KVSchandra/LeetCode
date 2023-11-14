class Solution {
public:
    //BOYER - MOORE VOTING ALGORITHM TC: O(N) SC : O(1)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count1 = 0, count2 = 0;
        int ele1 = 0, ele2 = 0;

        //1) FIND POTENTIAL MAJORITY ELEMENTS
        for(int i = 0;i<nums.size();i++){
            if(count1 == 0 && nums[i] != ele2){
                count1 = 1;
                ele1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != ele1){
                count2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        //2) COUNT OCCURRENCES OF THESE POTENTIAL MAJOR ELEMENTS IN THE ARRAY
        count1 = 0, count2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
        }

        //3) CHECK IF THE OCCURRENCES ARE GREATER THAN N/3
        if(count1 > nums.size()/3) ans.push_back(ele1);
        if(count2 > nums.size()/3) ans.push_back(ele2);

        return ans;
    }
};