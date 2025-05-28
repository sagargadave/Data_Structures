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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == NULL|| head->next == NULL)
        {
            return head;
        }

        struct ListNode* newN = new ListNode;
        newN->val = 0;
        newN->next = head;

        struct ListNode* pointer = head;
        
        head = head->next;

        while (true)
        {
            if ((newN->next->val == newN->next->next->val) ||(head->next != NULL && head->val == head->next->val))
            {                            
                if(newN->next->val == newN->next->next->val)
                { 
                    pointer = newN;
                    head = newN->next;
                }

                while ((head->next != NULL && head->val == head->next->val))
                {
                    head = head->next;
                }

                head = head->next;
                pointer->next = head;
            } 
            else
            {
                pointer = pointer->next;
                head = head->next;
            }

            if( head == NULL || head->next == NULL)
            {
                return newN->next;
            }
        }

        return newN->next;
    }
};