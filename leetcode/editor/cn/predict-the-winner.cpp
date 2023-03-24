/**
给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏。 

 玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手。开始时，两个玩家的初始分值都是 0 。每一回合，玩家从数组的任意一端取一个数字（即，nums[0] 
或 nums[nums.length - 1]），取到的数字将会从数组中移除（数组长度减 1 ）。玩家选中的数字将会加到他的得分上。当数组中没有剩余数字可取时，
游戏结束。 

 如果玩家 1 能成为赢家，返回 true 。如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true 。你可以假设每个玩家的玩法都会使他的分数最
大化。 

 

 示例 1： 

 
输入：nums = [1,5,2]
输出：false
解释：一开始，玩家 1 可以从 1 和 2 中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选
。 
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 false 。 

 示例 2： 

 
输入：nums = [1,5,233,7]
输出：true
解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 true，表示玩家 1 可以成为赢家。 

 

 提示： 

 
 1 <= nums.length <= 20 
 0 <= nums[i] <= 10⁷ 
 

 Related Topics 递归 数组 数学 动态规划 博弈 👍 612 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int sum = 0;
        for (auto &num : nums)
        {
            sum += num;
        }
        int res = my_dp(nums, 0, nums.size() - 1);
        if (res >= sum - res)
        {
            return true;
        }
        return false;
    }

    int my_dp(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return nums[l];
        }
        int former = 0;
        int latter = 0;
        if (r - l == 1)
        {
            former = nums[l];
            latter = nums[r];
        }
        if (r - l >= 2)
        {
            former = nums[l] + min(my_dp(nums, l + 2, r), my_dp(nums, l + 1, r - 1));
            latter = nums[r] + min(my_dp(nums, l + 1, r - 1), my_dp(nums, l, r - 2));
        }
        return max(former, latter);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/*
int main()
{
    Solution s;
    vector<int> data{7, 100, 5, 1};
    Solution solution = *new Solution();
    cout << solution.PredictTheWinner(data) << endl;
}*/
