/**
 * @param {number[]} nums
 * @return {number}
 */
function solve(i, x, nums) {
    if(i == nums.length) return x;
    let pick = solve(i+1, x^nums[i], nums);
    let notPick = solve(i+1, x, nums);
    return pick + notPick;
}

var subsetXORSum = function(nums) {
    return solve(0, 0, nums);
};