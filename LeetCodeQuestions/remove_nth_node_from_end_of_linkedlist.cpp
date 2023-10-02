#include <iostream>

using namespace std; // Using namespace std to avoid explicit std:: prefix

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move the fast pointer n nodes ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If the fast pointer reaches the end (null), remove the first node (nth from the end)
        if (!fast) {
            return head->next;
        }

        // Move the fast pointer to the end while maintaining a gap of n nodes with the slow pointer
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end by updating the 'next' pointer of the node before it
        slow->next = slow->next->next;

        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end

    Solution solution;
    ListNode* result = solution.removeNthFromEnd(head, n);

    cout << "Linked list after removing the " << n << "th node from the end:" << endl;
    printList(result);

    return 0;
}
