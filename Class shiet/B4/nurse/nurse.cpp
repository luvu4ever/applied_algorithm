#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 10005

using namespace std;

int n, s, t;
int f[MAX_N];
int f1[MAX_N], f0[MAX_N];

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> t;
    f1(i, n){
        f1[i] = 0;
        f0[i] = 0;
    }

    f0[1] = 1;
    f1[s] = 1;
    f0[0] = 1; 
    for(int i = s+1; i<=n; i++){
        f0[i] = f1[i-1];
        for(int j = s; j<=t; j++){
                f1[i] += f0[i-j]; 
        }
    }
    cout<< f0[n] + f1[n];
    return 0;
}