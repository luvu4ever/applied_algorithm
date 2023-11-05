#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 1005
#define MAX_T 105

using namespace std;

int n, T, d;
int a[MAX_N], t[MAX_N], f[MAX_N][MAX_T];

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> T >> d;
    int ans = 0;
    f1(i, n)
        cin>>a[i];
    f1(i, n)
        cin>>t[i];
    a[0] = 0;
    f1(i, n){
        for(int j = max(i-d, 0); j<i; j++){
            for(int time = 0; time + t[i]<= T; time++){
                f[i][time + t[i]] = max(f[i][time+t[i]], f[j][time] + a[i]);
                ans = max(ans, f[i][time+t[i]]);
            }
        }
    }
    cout<<ans;
    return 0;
}