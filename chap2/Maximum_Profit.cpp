#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long max_profit = - 1000000000;
    long long min_val = 10000000000;

    for(int i = 0; i < n; i++){
        long long r;
        cin >> r;
        if(i > 0){
            if((r-min_val) > max_profit){
                max_profit = (r - min_val);
            }
        }
        if(r < min_val){
            min_val = r;
        }
    }
    cout << max_profit << endl;
    return 0;
}