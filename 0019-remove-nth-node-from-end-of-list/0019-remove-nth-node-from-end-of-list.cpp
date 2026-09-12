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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int size=0;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        
        if(size==1 && n==1)
        {
            ListNode* todelete=head;
            head=NULL;
            delete todelete;
            return head;
        }
        temp=head;

        for(int i=1;i<size-n;i++)
        {
           temp=temp->next;
        }

        if(temp==head && n==size)
        {
            head=temp->next;
            temp=NULL;
            delete temp;
            return head;
        }
       
        ListNode* todelete=temp->next;
        if(temp->next->next!=NULL)
        {
            temp->next=temp->next->next;
        }

        else
        {
            temp->next=NULL;
        }
       

        delete todelete;

        return head;
        
       
      
    }
};