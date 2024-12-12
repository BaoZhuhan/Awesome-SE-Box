#include <bits/stdc++.h>
using namespace std ;

class MyQueue {
private:
    stack<int> instack , outstack;
    
    void in2out() {
        while(!instack.empty()) {
            outstack.push(instack.top());
            instack.pop();
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        instack.push(x);
    }
    
    int pop() {
        if(outstack.empty()){ in2out(); }
        int x = outstack.top();
        outstack.pop();
        return x;
    }
    
    int peek() {
        if(outstack.empty()){ in2out(); }
        return outstack.top();
    }
    
    bool empty() {
        if(outstack.empty() and instack.empty()) return true;
        return false;
    }
};



int main(){
    MyQueue mq;
    

}