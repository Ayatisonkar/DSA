#include <bits/stdc++.h>
class Stack{
    private:
    int *arr;
    int top;
    int capacity;
    public:
    Stack(int size){
        arr=new int[size];
        capacity=size;
        top=-1;
    }
    void push(int x){
        if(top==capacity-1){
            std::cout<<"Stack is full\n";
            return;
        }
        arr[++top]=x;
    }
    int pop(){
        if(top==-1){
            std::cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top==-1){
            std::cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==capacity-1;
    }
};
int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout<<s.pop()<<"\n";
    std::cout<<s.peek()<<"\n";
    std::cout<<s.isEmpty()<<"\n";
    std::cout<<s.isFull()<<"\n";
    std::cin.get();
    return 0;
}
