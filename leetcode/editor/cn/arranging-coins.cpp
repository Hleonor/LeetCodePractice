/**
你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。 

 给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。 

 

 示例 1： 
 
 
输入：n = 5
输出：2
解释：因为第三行不完整，所以返回 2 。
 

 示例 2： 
 
 
输入：n = 8
输出：3
解释：因为第四行不完整，所以返回 3 。
 

 

 提示： 

 
 1 <= n <= 2³¹ - 1 
 

 Related Topics 数学 二分查找 👍 250 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arrangeCoins(int n)
    {
        long low = 0, high = n;
        while (low <= high)
        {
            long mid = (high - low) / 2 + low;
            long cost = (mid * mid + mid) / 2;
            if (cost == n)
            {
                return mid;
            }
            else if (cost > n)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    // vector<int> data{7, 1, 5, 3, 6, 4};
    
    cout<<"Hello LeetCode"<<endl;
}
