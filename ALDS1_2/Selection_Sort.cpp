#include <iostream>
using namespace std;

int selectionSort(int A[], int n){
    int counter = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int j = i; j < n; j++){
            if(A[minj] > A[j]){
                minj = j;
            }
        }
        if(minj != i){
            counter++;
            int a = A[minj];
            A[minj] = A[i];
            A[i] = a;
        }
    }
    return counter;
}

int main(){
    int n;
    cin >> n;
    int A[100];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int ans = selectionSort(A, n);

    for(int i = 0; i < n; i++){
        if(i){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl << ans << endl;
    return 0;
}