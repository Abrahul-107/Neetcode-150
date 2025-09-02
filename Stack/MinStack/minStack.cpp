#include<iostream>
using namespace std;

class MinStack
{
    stack<int>st;
    stack<int>minStack;
public:

    //Push the element to stack and also maintaining monotonic min stack 
    void push(int val)
    {
        st.push(val);
        if(minStack.empty() || minStack.top()>=val)
            minStack.push(val);

    }
    
    //Pop the element from the stack and also maintaining the minstack for pop() operations
    void pop()
    {
        if(st.empty())
            return;
        if(st.top()==minStack.top())
        minStack.pop();
        st.pop();
    }

    //Get the top element 
    int top()
    {
        if(st.empty())
            return -1;
        return st.top();

    }

    //Get the min in o(1)
    int getMin()
    {
        if(minStack.empty())
            return -1;
        return minStack.top();

    }

};


int main()
{
    MinStack ms;

    ms.push(5);
    cout << "Pushed 5, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.push(3);
    cout << "Pushed 3, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.push(7);
    cout << "Pushed 7, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.pop();
    cout << "Popped, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.pop();
    cout << "Popped, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.push(2);
    cout << "Pushed 2, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.push(1);
    cout << "Pushed 1, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    ms.pop();
    cout << "Popped, Min: " << ms.getMin() << ", Top: " << ms.top() << endl;

    return 0;

    return 0;
}