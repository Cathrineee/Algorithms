/*
 * Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n 
 * that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 */

#include <algorithm>
#include <vector>
using namespace std;

// return the largest index that the element < target
// assume nums is ascending
int binary_search(vector<int>& nums, int target, int begin, int end) {
    while (begin <= end) {
        int mid = begin + (end-begin)/2;
        int x = nums[mid];
        if (x >= target) {
            end = mid-1;
        } else {
            begin = mid+1;
        }
    }
    return end;
}
// assume nums is ascending
int twoSumSmaller(vector<int>& nums, int target, int begin){
    int i = 0;
    int len = nums.size();
    if (begin >= len) return 0;
    int count = 0;
    for (int n : nums) {
        if (i < begin) {
            ++i;
        } else {
            int largest = binary_search(nums, target-n, i+1, len-1);
            // std::cout << i << " " << largest << std::endl;
            if (largest < i+1) return count;
            count += (largest - i);
            ++i;
        }
    }
    return count;
}
int threeSumSmaller(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int k = 0;
    int count = 0;
    for (int n : nums) {
        int ret = twoSumSmaller(nums, target-n, k+1);
        // std::cout << ret << std::endl;
        if (ret == 0) return count;
        else count += ret;
        ++k;
    }
    return count;
}
