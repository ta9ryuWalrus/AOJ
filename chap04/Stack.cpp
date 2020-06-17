#include<iostream>
#include<string>
using namespace std;

int top, S[1000];

void push(int x){
    S[++top] = x;
}

int pop(){
    top--;
    return S[top+1];
}

int main(){
    int a, b;
    top=0;
    string s;

    while(cin >> s){
        if(s[0] == '+'){
            a = pop();
            b = pop();
            push(a+b);
        }else if(s[0] == '-'){
            b = pop();
            a = pop();
            push(a-b);
        }else if(s[0]=='*'){
            a = pop();
            b = pop();
            push(a*b);
        }else{
            push(stoi(s));
        }
    }
    cout << pop() << endl;
    return 0;
}