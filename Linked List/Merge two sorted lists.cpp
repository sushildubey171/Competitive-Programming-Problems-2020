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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-1);
        ListNode *trace = ans;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                trace->next = l1;
                trace = l1;
                l1 = l1->next;
            }
            else {
                trace->next = l2;
                trace = l2;
                l2 = l2->next;
            }
        }
        if(l1)
            trace->next = l1;
        if(l2)
            trace->next = l2;
        return ans->next;
    }
};

/*
ANOTHER WAY 
*/
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    Node *head;
    Node **ref=&head;
    while(head_A && head_B)
    {   if(head_A->data < head_B->data)
        {   *ref=head_A;
            head_A=head_A->next;
        }
        else
        {   *ref=head_B;
            head_B=head_B->next;
        }
        ref=&((*ref))->next;
    }
    *ref=(head_A)?head_A:head_B;
    return head;
}  
