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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp = head;
        int n = 0;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        if(n == 1)return nullptr;
        if(n == 2)
        {
            head->next = nullptr;
            return head;
        }
        int i = 0;
        temp = head;
        while(i < n/2-1)
        {
           temp = temp->next;
           i++;
        }
        temp->next = temp->next->next;
        return head;
    }
};