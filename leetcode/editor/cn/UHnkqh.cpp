/**
给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。 

 
 
 
 
 

 示例 1： 
 
 
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
 

 示例 2： 
 
 
输入：head = [1,2]
输出：[2,1]
 

 示例 3： 

 
输入：head = []
输出：[]
 

 

 提示： 

 
 链表中节点的数目范围是 [0, 5000] 
 -5000 <= Node.val <= 5000 
 

 

 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 

 

 
 注意：本题与主站 206 题相同： https://leetcode-cn.com/problems/reverse-linked-list/ 

 Related Topics 递归 链表 👍 100 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current)
        {
            ListNode* next = current->next;
            current->next = prev;
            // 注意下面两行的顺序不能颠倒
            prev = current;
            current = next;
        }
        return prev;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    //vector<int> ans = s.twoSum(data,11);
    //cout << ans[0]<<ans[1]<<endl;
    cout<<"Hello LeetCode"<<endl;
}
