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
    
    void printList(ListNode* head){
        ListNode* curr = head;
        while(curr!=NULL){
            cout<<curr->val<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
    
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp= NULL, *prev = NULL;
        
        if(curr == NULL || curr->next ==NULL)
            return curr;
      
        
        while (curr && curr->next){
            
                temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                
                if(!prev)
                     head = temp;
                else
                    prev->next=temp;
            
                prev = curr;
                curr=curr->next;
            
        }
        
        return head;
        
        
    }
};