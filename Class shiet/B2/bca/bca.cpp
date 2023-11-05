#include<bits/stdc++.h>
#define f1(i,b) for(int i=1; i<=b; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_M 35

using namespace std;

int m, n;
int teach[MAX_M], ab_teach[MAX_M][MAX_M], conflict[MAX_M][MAX_M];
int teach_by[MAX_M][MAX_M], cnt[MAX_M];
int ans = MAX_M;

int TakeAnswer(){
    int max_load = 0;
    f1(i, m){
        max_load = max(max_load, cnt[i]);
    }
    //cout<<endl;
    return max_load;
}   

void Recursion(int cur_sub, int n, int teach[]){
    if(cur_sub == n+1){
        ans = min(ans, TakeAnswer());
        return;
    }
    f1(i, m){
        if(!ab_teach[i][cur_sub])
            continue;
        if(cnt[i] > ans)
            continue;
        int flag = 0;
        int cnt_job = 0;
        f1(j, n){
            if(teach[j] == i && conflict[cur_sub][j] == 1)
                flag = 1;
        }
        if(flag == 1)
            continue;
        teach[cur_sub] = i;
        cnt[i]+=1;
        Recursion(cur_sub + 1, n, teach);
        teach[cur_sub] = -1;
        cnt[i] -=1;
    }
}

main()
{
    cin >> m >> n;
    f1(i,m){
        f1(j, n){
            ab_teach[i][j] = 0;
        }
    }
    f1(i, m){
        int x;
        cin >> x;
        f1(j, x){
            int s;
            cin >> s;
            ab_teach[i][s] = 1;
        }
    }
    int q;
    cin>> q;
    f1(i,m){
        f1(j,m){
            conflict[i][j] = 0;
        }
    }
    f1(i, q){
        int s, t;
        cin>> s >> t;
        conflict[s][t] = 1;
        conflict[t][s] = 1;
    }
    f1(i, n){
        teach[i] = -1;
    }
    Recursion(1, n, teach);
    cout << ans;
    return 0;
}