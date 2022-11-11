/**
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 

 

 示例: 

 输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL 

 

 限制： 

 0 <= 节点个数 <= 5000 

 

 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/ 

 Related Topics 递归 链表 👍 504 👎 0

*/

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
