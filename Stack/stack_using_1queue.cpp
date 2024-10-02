#include <bits/stdc++.h>
using namespace std;
class Stack{
    private:
    queue<int> q1;
    
    public:
    void push(int x){
        if(q1.empty()){
            q1.push(x);
            return;
        }
        int size=q1.size();
        q1.push(x);
        int i=0;
        while(i<size){
            int temp = q1.front();
            q1.push(temp);
            q1.pop();
            i++;
        }
    }
    int pop(){
        if(q1.empty()){
            cout<<"Stack is empty\n";
            return -1;
        }
        int x=q1.front();
        q1.pop();
        return x;
    }
    int peek(){
        if(q1.empty()){
            cout<<"Stack is empty\n";
            return -1;
        }
        return q1.front();
    }
    bool isEmpty(){
        return q1.empty();
    }

};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<"\n";
    cout<<s.peek()<<"\n";
    cout<<s.isEmpty()<<"\n";
    cin.get();
    return 0;
}
