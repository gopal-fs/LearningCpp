#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode *prev=nullptr;
    int val;
    ListNode *next=nullptr;
};



class DoublyLinkedList{
    
    public:
    ListNode *head;
    int length;
    DoublyLinkedList(){
        head=nullptr;
        length=0;
    }
    void show(){
        cout<<head->val<<" "<<length;
    }
    
    void addAtHead(int val){
        
        ListNode *newNode = new ListNode();
        newNode->val=val;
        if(head==nullptr){
            head=newNode;
            
        }else{
            
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
            
        }
        length++;
    }
    
    void addAtTail(int val){
        ListNode *newNode=new ListNode();
        newNode->val=val;
        
        if(head==nullptr) return addAtHead(val);
        
        ListNode *curr=head;
        while(curr->next){
            curr=curr->next;
        }
        
        newNode->prev=curr;
        curr->next=newNode;
        length++;
    }
    
};



int main() {
	
	DoublyLinkedList doub;
	doub.addAtTail(5);
	doub.show();
	cout<<endl;
	doub.addAtTail(10);
	doub.show();
	
	
    doub.show();
}
