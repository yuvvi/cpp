//Two sum
//Time complexity O(n)

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map <int, int> hash;

        for (int i=0; i < nums.size(); ++i) {
            int currentVal = target - nums[i];
            std::cout<<"index :"<< i << " currentVal:"<<currentVal<<std::endl;

            auto it = hash.find(currentVal);
            std::cout <<""<<std::endl;
            if (it != hash.end()) {
            std::cout<<"found currentVal  "<<std::endl;
                std::vector<int> vec = {hash[currentVal], i};
                return vec;
            } else {
            std::cout<<"NOT found currentVal : "<<currentVal<<std::endl;
                
            }
            hash[nums[i]] = i;
            for (auto x : hash) {
                std::cout <<x.first<<" : "<<x.second<<std::endl;
            }
        }
        return std::vector<int>();
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {2,7,11,15};
    std::vector<int> res = s.twoSum(nums, 9);
    for (int i : res) {
        std::cout << i <<" ";
    }
    return 0;
}
