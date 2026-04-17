/*
 Sliding Window Maximum
Hard
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 
Example 3:

Input: nums = [2,7,3,1,6,2,5,8,1,4], k = 4
Output: [7,7,6,6,8,8,8]

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(k);
        deque<int> dq; // deque will store only indexes , front of the queue is always maximum element.

        for (int i=0; i < nums.size(); i++) {

            //Remove 1st element if it gets out of the window
            if (!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }
            //if incoming element is smaller, keep it in queue.
            //if incoming element is larger, remove all smaller.
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            //update result
            if (i > k-1) {
                res.append(nums[dq.front()])
            }
        }
        return res;
    }
};
