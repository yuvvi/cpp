/*
238. Product of Array Except Self
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left(nums.size()), right(nums.size());

        left[0] = 1;
        right[nums.size()-1] = 1;

        //calculate all left sides
        for ( int i=1; i < nums.size(); i++ ) {
            left[i] = left[i-1] * nums[i - 1];
        }

        //calculate all right sides
        for (int j=nums.size()-2; j > -1; j--) {
            right[j] = right[j+1] * nums[j+1];
        }

        vector<int> res(nums.size());
        //multiply left and right on same indexes
        for (int i=0; i < nums.size(); i++) {
            res[i] = left[i] * right[i];
        }
        return res;

    }
};
