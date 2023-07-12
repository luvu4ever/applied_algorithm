#include<bits/stdc++.h>

#define f1(i, a) for(int i = 1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 100005

using namespace std;

bool cmp(int A, int B)
{
    return A > B;
}

int cnt = 0;
int a[MAX_N], f[MAX_N];

void Recursion(int cur, int n, int sum){
    if(cur == n && sum != 0 && sum % a[n] == 0){
        cnt++;
        return;
    }
    if(sum < f[cur+1]){
        return;
    }

    f1(i, sum/a[cur]){
        Recursion(cur+1, n, sum - i * a[cur]);
    }
    return;
}

main()
{
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, M;
    cin >> n >> M;
    f1(i, n)
        cin>>a[i];
    f[n+1] = 0;
    for(int i = n; i>0; --i){
        f[i] = f[i+1] + a[i];
    }
    sort(a+1 ,a+n+1, cmp);
    Recursion(1, n, M);
    cout << cnt;
    return 0;
}