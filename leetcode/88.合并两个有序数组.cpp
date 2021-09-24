/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 后续m和n作为下标使用，所以要自减
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0)
        {
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0)
        {
            nums1[pos--] = nums2[n--];
        }
    }
};
// @lc code=end
