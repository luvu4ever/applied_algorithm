#include<bits/stdc++.h>

#define oo (1e9+7)
#define EPS (1e-5)
#define MOD
#define MAX_N 100005
#define forr(i, a, b) for(int i = (a); i <= (b) ; ++i)
#define ford(i, a, b) for(int i = (a); i >= (b) ; ++i)
#define f1(i, n) for(int i = 1; i <= (n); ++i)
#define f0(i, n) for(int i = 0; i< (n); ++i)
#define first fi
#define second se
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define el cout<<'\n'

typedef long long ll;
//typedef pair<int,int> pii;

using namespace std;

int a[MAX_N];
double f[MAX_N];
int n, k;

int Check(double mid){
    double minn = 0;
    for(int i = k; i<=n; i++){
        if(f[i] - mid * i > minn)
            return 1;
        minn = min(minn, f[i-k] - mid * (i-k));
    }
    return 0;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    f[0] = 0;
    f1(i, n){
        cin>> a[i];
        f[i] = f[i-1] + a[i];
    }
    double low = -100000;
    double high = 100000;
    double ans;
    while(high - low > EPS){
        double mid = (high + low) / 2;
        if(Check(mid)){
            low = mid;
        }
        else
            high = mid; 
    }
    cout << high;
    return 0;
}