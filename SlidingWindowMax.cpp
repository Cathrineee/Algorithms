/*
 * You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.
 */
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int len = nums.size();
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < len; i += k)
    {
        for (int j = i; j < min(i + k, len); ++j)
        {
            if (j == i)
                left.emplace_back(nums[j]);
            else
                left.emplace_back(max(nums[j], left.back()));
            right.emplace_back(0);
        }
        for (int j = min(i + k - 1, len - 1); j >= i; --j)
        {
            if (j == i + k - 1 || j == len - 1)
                right[j] = nums[j];
            else
                right[j] = max(nums[j], right[j + 1]);
        }
    }
    vector<int> ret;
    for (int i = k - 1; i < len; ++i)
    {
        int start = i - k + 1;
        ret.emplace_back(max(right[start], left[i]));
    }
    return ret;
}
