class MyLinkedList {
    struct ListNode{
        int val;
        ListNode *next=nullptr;

        ListNode(int data){
            this->val=data;
        };
    };
public:
    int length;
    ListNode *head;
    MyLinkedList() {
        this->length=0;
        this->head=nullptr;
    }
    
    int get(int index) {
        if(index<0 || index>=length || !head) return -1;

        ListNode *curr=head;
        for(int i=0;i<index;i++){
            curr=curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode *newNode=new ListNode(val);
        if(!head){
            head=newNode; 
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        ++length;
    }
    
    void addAtTail(int val) {
        if(!head) return addAtHead(val);

        ListNode *curr=head;

        while(curr->next){
            curr=curr->next;
        }

        ListNode *newNode=new ListNode(val);
        curr->next=newNode;
        ++length;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>length) return;
        if(index==0 || !head) return addAtHead(val);
        else if(index==length) return addAtTail(val);

        ListNode *curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
        }
        ListNode *newNode=new ListNode(val);
        newNode->next=curr->next;
        curr->next=newNode;
        ++length;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=length || !head) return;

        ListNode *curr=head;
        if(index==0){
            head=head->next;
            delete curr;
            --length;
            return;
        }

    
        for(int i=0;i<index-1;i++){
            curr=curr->next;
        }

        ListNode *nodeToDelete=curr->next;
        curr->next=nodeToDelete->next;
        delete nodeToDelete;
        --length;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */