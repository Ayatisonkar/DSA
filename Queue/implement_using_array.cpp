#include <bits/stdc++.h>
using namespace std;
class Queue{
    private:
    int *arr;
    int front;
    int rear;
    int capacity;
    public:
    Queue(int size){
        arr=new int[size];
        capacity=size;
        front=rear=-1;
    }
    void enqueue(int x){
        if(rear==capacity-1){
            cout<<"Queue is full\n";
            return;
        }
        if(front==-1){
            front++;
        }
        arr[++rear]=x;
    }
    int dequeue(){
        if(front==-1){
            cout<<"Queue is empty\n";
            return -1;
        }
        int x=arr[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
        return x;
    }
    int peek(){
        if(front==-1){
            cout<<"Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return rear==capacity-1;
    }
};
int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<"\n";
    cout<<q.peek()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cin.get();
    return 0;
}
