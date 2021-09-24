/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> a;
        int n = numbers.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                a.push_back(left + 1);
                a.push_back(right + 1);
                break;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return a;
    }
};
// @lc code=end
