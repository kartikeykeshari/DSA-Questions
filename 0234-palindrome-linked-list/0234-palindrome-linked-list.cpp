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
    bool isPalindrome(ListNode* head) {

        //1.find middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }   

        //now slow is pointing to middle element.
        //2.Break the LL in the middle.
        ListNode* curr = slow->next;
        ListNode* prev = slow;
        slow->next = NULL;

        //3.Reverse the second half of the LL.
        while(curr){
            ListNode* nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        //4.Check if the two LL are equal.
        ListNode* head1 = head;
        ListNode* head2 = prev;
        while(head2){
            if(head1->val != head2->val) return false;
            head1 = head1->next; 
            head2 = head2->next;
        }
        return true;
    }
};