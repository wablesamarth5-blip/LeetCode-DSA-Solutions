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

    ListNode* reverseS(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;

        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        

       ListNode* slow=head;
       ListNode* fast=head;

       while(fast!=NULL && fast->next!=NULL)
       {
          slow=slow->next;
          fast=fast->next->next;
       }

       ListNode* headF=head;

       ListNode* headS=reverseS(slow);

       while(headF && headS)
       {
          if(headF->val!=headS->val)
          {
             return false;
          }

          headF=headF->next;
          headS=headS->next;
       }

       return true;
    }
};