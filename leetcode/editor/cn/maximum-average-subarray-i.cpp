/**
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。 

 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。 

 任何误差小于 10⁻⁵ 的答案都将被视为正确答案。 

 

 示例 1： 

 
输入：nums = [1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

 示例 2： 

 
输入：nums = [5], k = 1
输出：5.00000
 

 

 提示： 

 
 n == nums.length 
 1 <= k <= n <= 10⁵ 
 -10⁴ <= nums[i] <= 10⁴ 
 

 Related Topics 数组 滑动窗口 👍 278 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int start = 0;
        int end = start + k - 1;
        double maxAverage = (double)-99999999;
        double sum = 0;
        for (int i = 0; i <= end; i++) // 先把前k个加起来
        {
            sum += (double)nums[i];
        }
        maxAverage = sum / (double)k;

        end++;

        while (end < nums.size())
        {
            sum = sum - (double)nums[start] + (double)nums[end];
            maxAverage = sum / (double)k > maxAverage ? sum / (double)k : maxAverage;
            start++;
            end++;
        }
        return maxAverage;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,12,-5,-6,50,3};
    s.findMaxAverage(data, 4);
    
    cout<<"Hello LeetCode"<<endl;
}
