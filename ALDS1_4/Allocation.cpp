#include<iostream>
using namespace std;
#define MAX 100000
typedef long long ll;
int n, k;
ll T[MAX];

// 最大積載量Pでk台のトラックに何個荷物を積めるか
int check(ll P){
    int i = 0; // 積める荷物の個数i
    for(int j = 0; j < k; j++){ // トラックの台数j
        ll s = 0;
        while(s + T[i] <= P){
            s += T[i];
            i++;
            if(i == n) return n;
        }
    }
    return i;
}

int solve(){
    ll left = 0;
    ll right = 100000 * 10000; // 荷物の個数 * 1個あたりの最大重量
    ll mid;
    while(right - left > 1){
        mid = (left + right) / 2;
        int v = check(mid);
        if(v >= n){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> T[i];
    }
    ll ans = solve();
    cout << ans << endl;
}