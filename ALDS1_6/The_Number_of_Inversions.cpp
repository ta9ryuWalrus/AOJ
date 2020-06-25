#include<iostream>
using namespace std;
#define MAX 200000
#define SENTINEL 2000000000
typedef long long ll;

int L[MAX/2+2], R[MAX/2+2];

ll merge(int A[], int left, int mid, int right){
    int i, j, k;
    ll cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    for(i = 0; i < n1; i++){
        L[i] = A[left+i];
    }
    for(i = 0; i < n2; i++){
        R[i] = A[mid+i];
    }
    L[n1] = R[n2] = SENTINEL;
    i = j = 0;
    for(k = left; k < right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            cnt += n1 - i;

        }
    }
    return cnt;
}

ll mergeSort(int A[], int left, int right){
    int mid;
    ll v1, v2, v3;
    if(left + 1 < right){
        mid = (left + right) / 2;
        v1 = mergeSort(A, left, mid);
        v2 = mergeSort(A, mid, right);
        v3 = merge(A, left, mid, right);
        return v1 + v2 + v3;
    }else{
        return 0;
    }
}

int main(){
    int A[MAX], n, i;
    cin >> n;

    for(i = 0; i < n; i++){
        cin >> A[i];
    }

    ll ans = mergeSort(A, 0, n);
    cout << ans << endl;
}