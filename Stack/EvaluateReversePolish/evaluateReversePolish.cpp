#include<iostream>
using namespace std;

int reversePolishNotation(vector<string>&tokens)
{
    int size = tokens.size();
    stack<int>st;
    for(int index=0;index<size;++index)
    {
        string currentChar = tokens[index];
        if(currentChar == "+" || currentChar == "-" || currentChar == "*" || currentChar == "/")
        {
            int firstNum = st.top();st.pop();
            int secondNum = st.top();st.pop();
            if(currentChar=="+") st.push(secondNum+firstNum);
            if(currentChar=="*") st.push(secondNum*firstNum);
            if(currentChar=="-") st.push(secondNum-firstNum);
            if(currentChar=="/") st.push(secondNum/firstNum);
        }
        else
            st.push(stoi(currentChar));
    }
    return st.top();
}



int main()
{
    vector<string>tokens = {"2","1","+","3","*"};
    cout<<reversePolishNotation(tokens);

    return 0;


}