#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int val){
            data =val;
            next=NULL; 
        }
};
class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head=NULL;
            tail=NULL;
        }
        void push_front(int val){
            Node* newNode=new Node(val);
            if (head==NULL){
                head=tail=newNode;
            }
            else{
                newNode->next=head;
                head=newNode;
            }
        }
        void push_back(int val){
        Node* newNode=new Node(val);
        if (head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
        void printlist(){
            Node* temp=head;
            while (temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
                cout<<"NULL"<<endl;
        }
        void popfront(){
            if (head==NULL){
                cout<<"List is empty"<<endl;
            }
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        void popback(){
             Node* temp=head;
             while(temp->next->next !=NULL){
                temp=temp->next;
             }
             temp->next=NULL;
             delete tail;
             tail=temp;
        }
};
int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlist();
    ll.popfront();
    ll.popback();
    ll.printlist();

return 0;
}