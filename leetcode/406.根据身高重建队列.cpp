/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &u, const vector<int> &v)
             { return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]); });
        int n = people.size();
        vector<vector<int>> res;
        for (auto i : people)
        {
            res.insert(res.begin() + i[1], i);
        }
        return res;
    }
};
// @lc code=end
