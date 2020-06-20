#include<iostream>
#include<string>
using namespace std;

struct Node{
    int key;
    Node *next, *prev;
};

Node *nil;

Node* listSearch(int key){
    Node *cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void init(){//最初のinsertの時に末尾に先頭と同じnilが来て循環するようになっている
    nil = new Node;
    nil->next = nil;
    nil->prev = nil;
}

void printList(){
    Node *cur = nil->next;
    int isf = 0;
    while(1){
        if(cur == nil)break;
        if(isf++>0)cout << " ";
        cout << cur->key;
        cur = cur->next;
    }
    cout << endl;
}

void deleteNode(Node *t){
    if (t == nil)return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

void insert(int key){
    Node *x = new Node;
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main(){
    int key, n;
    string com;
    cin >> n;
    init();
    for(int i = 0; i < n; i++){
        cin >> com;
        if(com[0] == 'i'){
            cin >> key;
            insert(key);
        }else if(com[0] == 'd'){
            if(com.length() > 6){
                if(com[6] == 'F'){
                    deleteFirst();
                }else if(com[6] == 'L'){
                    deleteLast();
                }
            }else{
                cin >> key;
                deleteKey(key);
            }
        }
    }
    printList();
    return 0;
}