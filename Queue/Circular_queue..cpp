#include <bits/stdc++.h>
using namespace std;
class CircularQueue{
    private:
    int *arr;
    int front;
    int rear;
    int capacity;
    public:
    CircularQueue(int size){
        arr=new int[size];
        capacity=size;
        front=rear=-1;
    }
    void enqueue(int x){
        if((rear+1)%capacity==front){
            cout<<"Queue is full\n";
            return;
        }
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%capacity;
        arr[rear]=x;
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
            front=(front+1)%capacity;
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
        return (rear+1)%capacity==front;
    }
};
int main(){
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(3);
    cout<<q.dequeue()<<"\n";
    q.enqueue(4);
     q.enqueue(4);
    cout<<q.peek()<<"\n";
    cout<<q.dequeue()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cout<<q.isFull()<<"\n";
    cin.get();
    return 0;
}
