#include<bits/stdc++.h>
// #define for(i,a,b) for(int i=a; i<=b; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define f1(i, a) for(int i =1; i<=a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 100005
#define pii pair<int,int>

using namespace std;

int n;
pair<int,int> a[MAX_N];

bool cmp(pii a, pii b){
    // if(a.se < b.se)
    //     return true;
    // return (a.fi < b.fi);
    return (a.se < b.se);
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int cnt = 0;
    f1(i, n){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1, a+n+1, cmp);
    int curLast = 0;
    f1(i, n){
        if(curLast < a[i].fi){
            cnt++;
            curLast = a[i].se;
        }
    }
    cout << cnt;
    return 0;
}
