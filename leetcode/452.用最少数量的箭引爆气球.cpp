/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int pre = points[0][1], count = 1;
        for (int i = 1; i < points.size(); i++)
        {
            // 无重叠则开启下一轮
            if (points[i][0] > pre)
            {
                pre = points[i][1];
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
