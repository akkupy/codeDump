
// This is the solution for Merge Two Sorted LinkedList question from Leetcode
// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    void change(ListNode* &prev, ListNode* &curr, ListNode* &newHead){
        if(prev==NULL){
            newHead= curr;
            prev= curr;
            curr= curr->next;
        }
        else{
            prev->next= curr;
            prev= curr;
            curr= curr->next;
        }
        prev->next= NULL;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* prev= NULL;
        ListNode* newHead= NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                change(prev, list1, newHead);
            }else{
                change(prev, list2, newHead);
            }
        }
        while(list1!=NULL){
            change(prev, list1, newHead);
        }
        while(list2!=NULL){
            change(prev, list2, newHead);
        }
        return newHead;
    }
};
