/**
给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。 

 

 示例 1： 

 
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 

 示例 2： 

 
输入：n = 0
输出：0
 

 示例 3： 

 
输入：n = 1
输出：0
 

 

 提示： 

 
 0 <= n <= 5 * 10⁶ 
 

 Related Topics 数组 数学 枚举 数论 👍 972 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        long long count = 0;
        for (long long i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;
                for (long long j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    // vector<int> data{7, 1, 5, 3, 6, 4};
    
    cout<<"Hello LeetCode"<<endl;
}
