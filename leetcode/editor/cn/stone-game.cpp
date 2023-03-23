/**
Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，排成一行；每堆都有 正 整数颗石子，数目为 piles[i] 。 

 游戏以谁手中的石子最多来决出胜负。石子的 总数 是 奇数 ，所以没有平局。 

 Alice 和 Bob 轮流进行，Alice 先开始 。 每回合，玩家从行的 开始 或 结束 处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手
中 石子最多 的玩家 获胜 。 

 假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回 true ，当 Bob 赢得比赛时返回 false 。 

 

 示例 1： 

 
输入：piles = [5,3,4,5]
输出：true
解释：
Alice 先开始，只能拿前 5 颗或后 5 颗石子 。
假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果 Bob 拿走前 3 颗，那么剩下的是 [4,5]，Alice 拿走后 5 颗赢得 10 分。
如果 Bob 拿走后 5 颗，那么剩下的是 [3,4]，Alice 拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对 Alice 来说是一个胜利的举动，所以返回 true 。
 

 示例 2： 

 
输入：piles = [3,7,2,3]
输出：true
 

 

 提示： 

 
 2 <= piles.length <= 500 
 piles.length 是 偶数 
 1 <= piles[i] <= 500 
 sum(piles[i]) 是 奇数 
 

 Related Topics 数组 数学 动态规划 博弈 👍 485 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        // 动态规划的做法
        int n = piles.size();
        /**
         * 注意这种写法不推荐，因为会有内存泄漏的问题，可以使用vector<vector<int>> dp(n, vector<int>(n, 0));
         * 但是这里为了方便，就直接使用了二维数组，不出错的原因是因为n的值是固定的
         * 如果直接写int n;
         * cin >> n;
         * int dp[n][n];
         * 这样的话，就会出现内存泄漏的问题
         * 原因是因为n的值是不确定的，所以在编译的时候，就会出现内存泄漏的问题
         * 这里传入的向量piles必然有一个固定的长度，所以这里就不会出现内存泄漏的问题
         */
        int dp[n][n];
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                /**
                 * max的内容含义是，我拿了piles[i]或者piles[j]以后，我还比对方多拿多少？
                 * 所以要减去对方比我多拿的
                 * 先手如果拿了piles[i]，那么dp[i + 1][j]就表示后手比我多拿多少
                 * 先手如果拿了piles[j]，那么dp[i][j - 1]就表示后手比我多拿多少
                 */
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        if (dp[0][n - 1] > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    // vector<int> data{7, 1, 5, 3, 6, 4};

    cout << "Hello LeetCode" << endl;
}
