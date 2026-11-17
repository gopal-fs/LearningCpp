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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head || !head->next || k==1) return head;

        int links=0;
        int length=0;
        ListNode *curr=head;
        while(curr){
            curr=curr->next;
            length++;
        }

        ListNode *prev=nullptr;
        ListNode *first=head;
        ListNode *ans=nullptr;
        ListNode *link1=head;
        bool isTrue=false;
        int count=0;
        while(head){
            ListNode *temp=head->next;
            head->next=prev;
            prev=head;
            count++;
            head=temp;
            if(count==k){
                if(!ans) ans=prev;
                count=0;
                links++;
                if(links>1){
                    first->next=prev;
                    first=link1;
                }
                link1=head;
                prev=nullptr;
            }
            if((length-links*k)<k){
                isTrue=true;
                break;
            }
        }
        if(isTrue) first->next=link1;
        return ans;


    }
};