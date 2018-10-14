#include<iostream>

struct Node;

struct uNode{
    uNode* next;
    uNode* prev;
    Node* down;
    int data;
};

struct Node{
    Node* next;
    Node* prev;
    uNode* up;
    int data;
};

class linkedList{
public:
    Node* head;
    Node* tail;
    uNode* u_head;
    uNode* u_tail;
    int gap;
    linkedList();
    void insertElement(int data);
    void print();
    void printBack();
    void printUpperList();
    void search(int val);
};

linkedList::linkedList(){
    std::cout<<"Linked List initialized"<<std::endl;
    this->head=nullptr;
    this->tail=nullptr;
    this->gap=0;
    this->u_head=nullptr;
    this->u_tail=nullptr;
}

void linkedList::insertElement(int data){
    Node* node=new Node();
    
    if(this->head==nullptr){
        this->head=node;
        this->tail=node;
        uNode* unode=new uNode();
        this->u_head=unode;
        this->u_tail=unode;
        unode->data=data;
        unode->down=node;
        node->up=unode;
        node->data=data;
        ++(this->gap);
    }
    
    else{
        if(this->gap==3){
            uNode* unode=new uNode();
            unode->down=node;
            node->up=unode;
            unode->data=data;
            unode->prev=this->u_tail;
            this->u_tail->next=unode;
            this->u_tail=unode;
            this->gap=0;
        }
        node->data=data;
        node->prev=this->tail;
        this->tail->next=node;
        ++(this->gap);
    }
    this->tail=node;
}

void linkedList::print(){
    std::cout<<this->head->data<<std::endl;
    do{
        this->head=this->head->next;
        std::cout<<this->head->data<<std::endl;
    }while(this->head!=this->tail);
}

void linkedList::printBack(){
    std::cout<<this->tail->data<<std::endl;
    do{
        this->tail=this->tail->prev;
        std::cout<<this->tail->data<<std::endl;
    }while(this->tail!=this->head);
}

void linkedList::printUpperList(){
    std::cout<<this->u_head->data<<std::endl;
    do{
        this->u_head=this->u_head->next;
        std::cout<<this->u_head->data<<std::endl;
    }while(this->u_head!=this->u_tail);
}

void linkedList::search(int val){
    Node* temp=this->head;
    uNode* utemp=this->u_head;
    while(utemp->data<=val){
        if(utemp->data==val){
            std::cout<<utemp->data<<std::endl;
            return;
        }
        utemp=utemp->next;
    }
    utemp=utemp->prev;
    temp=utemp->down;
    while(temp->data<=val){
        if(temp->data==val){
            std::cout<<temp->data<<std::endl;
            return;
        }
        temp=temp->next;
    }
    std::cout<<"Element Not Found"<<std::endl;
}

int main(){
    linkedList* list=new linkedList();
    list->insertElement(3);
    list->insertElement(5);
    list->insertElement(7);
    list->insertElement(11);
    list->insertElement(13);
    list->insertElement(17);
    list->insertElement(19);
//    list->print();
//    list->printBack();
//    list->printUpperList();
    list->search(17);
    return 0;
}
