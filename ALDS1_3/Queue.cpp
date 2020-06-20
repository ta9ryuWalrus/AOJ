#include<iostream>
#include<string>
#define LEN 100005
using namespace std;
#include<algorithm>

//Cで構造体を定義するときはこうする
/*typedef struct pp{
    string name;
    int t;
} P;*/

//C++で構造体を定義するときはこれで良い
struct P{
    string name;
    int t;
};

P Q[LEN];
int head, tail, n;

void enqueue(P x){
    Q[tail] = x;
    tail = (tail+1) % LEN;
}

P dequeue(){
    P x = Q[head];
    head = (head+1) % LEN;
    return x;
}

int main(){
    int elaps = 0, c;
    int i, q;
    P u;
    cin >> n >> q;

    for(i = 1; i <= n; i++){
        cin >> Q[i].name >> Q[i].t;
    }
    head = 1;
    tail = n + 1;

    while(head != tail){
        u = dequeue();
        c = min(q, u.t);
        u.t -= c;
        elaps += c;
        if(u.t) enqueue(u);
        else{
            cout << u.name << " " << elaps << endl;
        }
    }
    return 0;
}