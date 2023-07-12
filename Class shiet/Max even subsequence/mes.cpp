#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N (1000005)

using namespace std;

int n;
long long a[MAX_N];
long long sum = 0;
long long ans = -1000000000000009;
long long even_min = -ans, odd_min = -ans;

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    f1(i, n){
        cin>>a[i];
    }
    even_min = 0;
    f1(i, n){
        sum += a[i];
        if(sum % 2){
            ans= max(ans, sum - odd_min);
            odd_min = min(odd_min, sum);
            continue;
        }
        ans = max(ans, sum - even_min);
        even_min = min(even_min, sum);
    }
    cout<< ans;
    return 0;
}