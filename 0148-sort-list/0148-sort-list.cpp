class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        
        ListNode* mid = getMid(head);
        ListNode* leftHalf = head;       
        ListNode* rightHalf = mid->next; 
        mid->next = nullptr;             

        
        leftHalf = sortList(leftHalf);
        rightHalf = sortList(rightHalf);

        
        return merge(leftHalf, rightHalf);
    }

private:
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; 

        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; 
    }

    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;

        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next; 
            } else {
                tail->next = l2;
                l2 = l2->next; 
            }
            tail = tail->next; 
        }
        tail->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next; 
    }
};
