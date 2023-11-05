#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define el cout<<"\n"
#define EPS 1
#define MAX_N 100005

using namespace std;

int n, c;
int a[MAX_N];

int Check(int mid){
    int need = 0;
    int cnt = 0;
    f1(i, n){
        if(a[i] >= need){
            cnt++;
            need = a[i] + mid;
        }
        if(cnt >= c)
            return 1;
    }
    return 0;
}

void Solve(){
    cin >> n >> c;
    f1(i, n){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int low = 0;
    int high = a[n] - a[1];

    while(low <= high){
        int mid = (high + low) / 2;
        if(Check(mid)) low = mid+1;
        else high = mid-1;
    }
    cout<< high, el;
    return;
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin>> test;
    while(test--){
        Solve();
    }
    return 0;
}