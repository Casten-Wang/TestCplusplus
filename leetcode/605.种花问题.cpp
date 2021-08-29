/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (!flowerbed[i] && (i == flowerbed.size() - 1 || !flowerbed[i + 1]) && (i == 0 || !flowerbed[i - 1]))
            {
                count++;
                flowerbed[i] = 1;
            }
        }

        return count >= n ? true : false;
    }
};
// @lc code=end
