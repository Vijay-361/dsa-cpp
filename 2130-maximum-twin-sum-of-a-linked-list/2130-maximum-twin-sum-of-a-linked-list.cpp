class Solution {
public:
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode * temp = head;
        while(temp)
        {
            n++;
            temp = temp-> next;
        }
        temp = head;
        int i = 0;
        while(i < n / 2 - 1)
        {
            temp = temp -> next;
            i++;
        }
        ListNode*rev = temp->next;
        ListNode*prev = nullptr;
        ListNode*next = nullptr;
        while(rev)
        {
            next = rev->next;
            rev->next = prev;
            prev = rev;
            rev = next;
        }
        temp->next = prev;
        temp = temp->next;
        int ans = INT_MIN;
        while(temp)
        {
            ans = max(ans, head->val+temp->val);
            temp= temp->next;
            head= head->next;
        }
        return ans;
    }
};