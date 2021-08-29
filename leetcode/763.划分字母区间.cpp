/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int start = 0, end = 0;
        int last[26];
        vector<int> res;
        // 寻找每个字母最后出现的位置
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }
        // 使用贪心的方法将字符串划分为尽可能多的片段
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (end == i)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
// @lc code=end
