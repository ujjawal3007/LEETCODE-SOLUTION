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
    ListNode* middleNode(ListNode* head) {
        ListNode* Slow = head;
        ListNode* Fast = head;
        while(Fast != NULL && Fast ->next != NULL) {
            Slow = Slow -> next;
            Fast = Fast -> next -> next;
        }
        return Slow;
    }
};