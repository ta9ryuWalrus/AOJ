#include<iostream>
#include<string>
using namespace std;
#define MAX 100000
#define SENTINEL 2000000000

//安定かどうか判定するのにmerge sortの結果と比較する

struct Card{
    char suit;
    int value;
};

Card L[MAX/2 + 2], R[MAX/2 + 2];

void merge(Card A[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for(i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for(k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card A[], int p, int r){
    int i, j;
    Card t, x;
    x = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if(A[j].value <= x.value){
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i + 1;
}

void quickSort(Card A[], int p, int r){
    int q;
    if(p < r){
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int n, i, v;
    Card A[MAX], B[MAX];
    string S;
    int stable = 1;
    
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> S >> v;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    for(i = 0; i < n; i++){
        if(A[i].suit != B[i].suit){
            stable = 0;
        }
    }

    if(stable == 1){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(i = 0; i < n; i++){
        cout << B[i].suit << " " << B[i].value << endl;
    }
}