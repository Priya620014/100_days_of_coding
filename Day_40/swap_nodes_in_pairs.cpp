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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;

        head = head->next;

        while (current && current->next) {
            ListNode* first = current;
            ListNode* second = current->next;

            first->next = second->next;
            second->next = first;

            if (prev) {
                prev->next = second;
            }

            prev = first;
            current = first->next;
        }

        return head;
    }
};