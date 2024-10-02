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
class Stack{
    private:
    Node *top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int x){
        Node *temp=new Node(x);
        temp->next=top;
        top=temp;
    }
    int pop(){
        if(top==NULL){
            cout<<"Stack is empty\n";
            return -1;
        }
        int x=top->data;
        Node *temp=top;
        top=top->next;
        delete temp;
        return x;
    }
    int peek(){
        if(top==NULL){
            cout<<"Stack is empty\n";
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        return top==NULL;
    }
};
