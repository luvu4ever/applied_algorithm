#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 1000005

using namespace std;

int f[MAX_N], a[MAX_N];
int ans = 0;
deque<int> dq;

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    f1(i, n){
        cin>>a[i];
        f[i] = a[i];
    }
    f[0] = 0;
    dq.push_back(1);
    for(int i = l1+1; i<=n; i++){
        // for(int j = max(i-l2, 0); j<=i-l1; j++){
        //     f[i] = max(f[i], f[j] + a[i]);
        // }
        f[i] = max(f[dq.front()] + a[i], f[i]);
        ans= max(ans, f[i]);
        while((!dq.empty()) && dq.front() < i - l2)
            dq.pop_front();
        while((!dq.empty()) && f[i-l1+1] >= f[dq.back()])
            dq.pop_back();
        dq.push_back(i-l1+1);
    }
    // f1(i, n){
    //     cout<<f[i]<<endl;
    // }
    cout<< ans;

    return 0;
}