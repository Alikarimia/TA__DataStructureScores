#include <iostream>
#include <string>
//siza stack
#define maxSize 20

using namespace std;
template <class KeyType> class Stack {
private:
    KeyType* item;
    int top;
public:
    Stack();
    ~Stack();
    bool IsFull();
    bool IsEmpty();
    void Push(KeyType& x);
    KeyType Pop();
    KeyType TopElement();
};

//sazande
template <class KeyType>  Stack<KeyType>::Stack() {
    item = new KeyType[maxSize];
    top = -1;
}
//mokhareb
template <class KeyType>  Stack<KeyType>::~Stack() {
    delete[] item;
    top = -1;
    cout << endl;
}
//ezafe kardan meghdar be stack
template <class KeyType> void Stack<KeyType>::Push(KeyType& x) {
    if (IsFull()) {
        cout << "Stack is full" << endl;
    }
    item[++top] = x;
}
//khali boodan?
template <class KeyType> bool Stack<KeyType>::IsEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
//por boodan
template <class KeyType> bool Stack<KeyType>::IsFull()
{
    if (top == (maxSize - 1))
        return true;
    else
        return false;
}
//delete 
template <class KeyType> KeyType Stack<KeyType>::Pop()
{
    if (IsEmpty()) {
        cout << "Stack is epmty";
    }
    else {
        KeyType PoppedElement = item[top];
        top--;
        return PoppedElement;
    }

}
//namayesh top element
template <class KeyType> KeyType Stack<KeyType>::TopElement()
{
    KeyType top_element = item[top];
    return top_element;
}

string getInfix();

void ConvertInfixToPostfix(string infix);

void postfixToInfix(string postfix);
//main
int main()
{
    ConvertInfixToPostfix(getInfix());

}
//get infix
string getInfix()
{
    string infix;
    cout << "Please enter infix phrase : ";
    cin >> infix;
    return infix;
}
//tabdil infix To Postfix
void ConvertInfixToPostfix(string infix) {

    string postfix = "";
    Stack<char> s;
    //if infix [i]was an oprand put it in the postfix string
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9') {
            postfix += infix[i];
        }
        //age parantez baz bood push kon to stack 
        else if (infix[i] == '(') {
            s.Push(infix[i]);
        }
        //age parantez baste bood pop kon az stack 
        else if (infix[i] == ')') {
            while (s.TopElement() != '(') {
                postfix += s.TopElement();
                s.Pop();
            }
            //parantez baz akhar ro delete mikone 
            s.Pop();
        }
        //ag oprator bood push mikonim to stack ^_^
        else {
            s.Push(infix[i]);
        }
    }


    cout << "\nThe Postfix is : " << postfix << "\n";
    postfixToInfix(postfix);
}

bool isOperator(char operatorr)
{
    if (operatorr == '-' || operatorr == '+' || operatorr == '*' || operatorr == '/')
    {
        return true;
    }
    else
        return false;
}

bool isOperand(char operand)
{
    if (operand >= 'a' && operand <= 'z' || operand >= 'A' && operand <= 'Z' || operand >= '0' && operand <= '9')
        return true;
    else
        return false;
}



//convert postfix To Infix
void postfixToInfix(string postfix)
{
    Stack<string> s;
    for (int i = 0; i < postfix.size(); i++)
    {
        //age oprand bood push mikoni to stack
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.Push(op);
        }
        //age oprator bood 2ta data balaee stack ro barmidarim va amaliat ro roosh eemal mikonim va push mikonim to stack 
        else {
            string op1 = s.TopElement();
            s.Pop();
            string op2 = s.TopElement();
            s.Pop();
            string t = "(" + op2 + postfix[i] + op1 + ")";
            s.Push(t);
        }
    }
    cout << s.TopElement();
}
