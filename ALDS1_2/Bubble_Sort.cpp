#include <iostream>
using namespace std;

int bubbleSort(int A[], int n){
    int flag = 1;
    int counter = 0;
    while(flag){
        flag = 0;
        for(int j = n-1; j > 0; j--){
            if(A[j] < A[j-1]){
                int a = A[j];
                A[j] = A[j-1];
                A[j-1] = a;
                flag = 1;
                counter++;
            }
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
    int ans = bubbleSort(A, n);
    for(int i = 0; i < n; i++){
        if(i>0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl << ans << endl;

    return 0;

}