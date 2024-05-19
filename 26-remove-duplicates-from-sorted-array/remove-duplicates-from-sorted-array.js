/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let count = 0;
    let n = nums.length;
    for(let i = 0; i<nums.length; i++) {
        if(nums[i] === nums[i+1]) {
            nums.splice(i, 1);
            i--;
        }
        else count++;
    }
    return count;
};