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
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int i : nums)
        {
            if (i < min1)
            {
                min2 = min1;
                min1 = i;
            }
            else if (i < min2)
            {
                min2 = i;
            }

            if (i > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if (i > max2)
            {
                max3 = max2;
                max2 = i;
            }
            else if (i > max3)
            {
                max3 = i;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    // vector<int> data{7, 1, 5, 3, 6, 4};
    
    cout<<"Hello LeetCode"<<endl;
}
