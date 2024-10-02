#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int x){
            data=x;
            next=NULL;
    }
};
class Queue{
    private:
    Node *front;
    Node *rear;
    public:
    Queue(){
        front=rear=NULL;
    }
    void enqueue(int x){
        Node *temp=new Node(x);
        if(rear==NULL){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue is empty\n";
            return -1;
        }
        int x=front->data;
        Node *temp=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
        return x;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        return front==NULL;
    }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<"\n";
    cout<<q.peek()<<"\n";
    cout<<q.isEmpty()<<"\n";
    return 0;
}
