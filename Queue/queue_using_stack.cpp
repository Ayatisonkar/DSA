#include <bits/stdc++.h>
using namespace std;
class Queue{
    private:
    stack<int> s1;
    stack<int> s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }
    int dequeue(){
        if(s1.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
         while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        return x;
    }
    int peek(){
        if(s1.empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
         while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        return x;
    }
    bool isEmpty(){
        return s1.empty() && s2.empty();
    }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<"\n";
    q.enqueue(4);
    cout<<q.dequeue()<<"\n";
    cout<<q.peek()<<"\n";
    cout<<q.isEmpty()<<"\n";
    cin.get();
    return 0;
}
