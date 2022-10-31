class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }

    bool check(ListNode*& head, ListNode* p) {
        if(!p) { return true; }
        bool isPal = check(head, p->next);
        if(head->val != p->val) {
            return false;
        }
        head = head->next;
        return isPal;
    }
};