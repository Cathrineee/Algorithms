/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 */

vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dic;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            auto find = dic.find(target - nums[i]);
            if (find != dic.end()) {
                vector<int> ans = {i, dic[target - nums[i]]};
                return ans;
            } else {
                dic.insert({nums[i], i});
            }
        }
        return nums;
    }
