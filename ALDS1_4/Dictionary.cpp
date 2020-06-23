#include<iostream>
#include<string>
using namespace std;

#define M 1046527
string H[M];

int getChar(char ch){
    if(ch == 'A')return 1;
    else if(ch == 'C')return 2;
    else if(ch == 'G')return 3;
    else if(ch == 'T')return 4;
    else return 0;
}

long long getKey(string str){
    long long sum = 0, p = 1;
    int i;
    for(i = 0; i < str.length(); i++){
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}
int h1(int key){
    return key % M;
}

int h2(int key){
    return 1 + (key % (M-1));
}

int find(string str){
    long long key, i, h;
    key = getKey(str);
    for(i = 0;; i++){
        h = (h1(key) + i * h2(key)) % M;
        if(H[h] == str){
            return 1;
        }else if(H[h].length() == 0){
            return 0;
        }
    }
    return 0;
}

int insert(string str){
    long long key, i, h;
    key = getKey(str);
    for(i = 0;; i++){
        h = (h1(key) + i * h2(key)) % M;
        if(H[h] == str){
            return 1;
        }else if(H[h].length() == 0){
            H[h] = str;
            return 0;
        }
    }
    return 0;
}

int main(){
    int i, n, h;
    string str, com;
    for(i = 0; i < M; i++){
        H[i][0] = '\0';
    }
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> com >> str;

        if(com[0] == 'i'){
            insert(str);
        }else{
            if(find(str)){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
}