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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Find node before left position
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Current points to left position
        ListNode* curr = prev->next;

        // Reverse the required portion
        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;

            temp->next = prev->next;

            prev->next = temp;
        }

        return dummy->next;
    }
};
