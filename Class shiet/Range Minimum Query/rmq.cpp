#include<bits/stdc++.h>
#define f0(i,a) for(int i=0; i<a; ++i)
#define f1(i,a) for(int i=1; i<=(a); ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 1000005
#define el cout<<'\n'

using namespace std;

int n, q;
int st[23][MAX_N];

main()
{
    cin >> n;
    f0(i, n){
        cin>> st[0][i];
    }
    f1(j, __lg(n)){
        for(int i = 0; i + (1<< (j-1)) - 1 < n; ++i){
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]); 
        }
    }
    long long ans = 0;
    cin >> q;
    f1(i, q){
        int l, r;
        cin >> l >> r;
        int k = __lg(r - l + 1);
        ans += 1ll * min(st[k][l], st[k][r - (1<<k) +1]);
    }
    cout << ans;
    return 0;
}