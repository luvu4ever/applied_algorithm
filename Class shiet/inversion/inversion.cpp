#include <bits/stdc++.h>
#define f1(i, a) for (int i = 1; i <= a; ++i)
#define f0(i, a) for (int i = 0; i < a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAX_N 1000005

using namespace std;

int ans = 0;
int a[MAX_N];
int temp[MAX_N];

int Recursion(int left, int right)
{
    if (left >= right)
        return 0;
    int mid = (left + right) / 2;
    int cnt = Recursion(left, mid) + Recursion(mid + 1, right);
    int i = left, j = mid + 1;
    int cur = 0;
    while (i <= mid || j <= right){
        if (i > mid){
            temp[cur++] = a[j++];
        }
        else if (j > right){
            temp[cur++] = a[i++];
        }
        else if (a[i] <= a[j]){
            temp[cur++] = a[i++];
        }
        else{
            temp[cur++] = a[j++];
            cnt+= mid - i+1;
            cnt%= MOD;
        }
    }
    for (int i = 0; i < cur; i++)
        a[left + i] = temp[i];
    return cnt;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    f1(i, n){
        cin >> a[i];
        temp[i] = 0;
    }
    cout<< Recursion(1, n);
    return 0;
}