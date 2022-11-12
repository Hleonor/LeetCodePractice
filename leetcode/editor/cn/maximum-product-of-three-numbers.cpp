/**
给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。 

 

 示例 1： 

 
输入：nums = [1,2,3]
输出：6
 

 示例 2： 

 
输入：nums = [1,2,3,4]
输出：24
 

 示例 3： 

 
输入：nums = [-1,-2,-3]
输出：-6
 

 

 提示： 

 
 3 <= nums.length <= 10⁴ 
 -1000 <= nums[i] <= 1000 
 

 Related Topics 数组 数学 排序 👍 413 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[nums.size() - 1],
                   nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    // vector<int> data{7, 1, 5, 3, 6, 4};
    
    cout<<"Hello LeetCode"<<endl;
}
