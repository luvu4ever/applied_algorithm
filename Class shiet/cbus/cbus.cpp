#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<=a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define oo 1000000009
#define MAX_N 55

using namespace std;

int ans = oo;
int status[MAX_N];
int dis[MAX_N][MAX_N];
int cur_picked = 0, cur_dropped = 0;
int min_road = 1000000009;
int n, k;
deque<int> drop;
// status= 0 stand for didnt pick
// = 1 stand for picked up
// = 2 stand for droped

void Recursion(int cur_index, int last_pos, int cost){
    if(cost + min_road * (2*n - cur_index) > ans)
        return;
    if(cur_index == 2*n){
        ans = min(ans, cost + dis[last_pos][0]);
        return;
    }
    if(cur_picked - cur_dropped < k && cur_picked < n){
        f1(i, n){
            if(status[i])
                continue;
            status[i] = 1;
            cur_picked += 1;
            drop.push_back(i);
            Recursion(cur_index + 1, i, cost + dis[last_pos][i]);
            drop.pop_back();
            status[i] = 0;
            cur_picked -=1;
        }
    }
    if(cur_picked - cur_dropped > 0){
        f1(i,n){
            if(status[i] != 1)
                continue;
            status[i] = 2;
            cur_dropped +=1;
            Recursion(cur_index +1, i+n, cost + dis[last_pos][i+n]);
            status[i] = 1;
            cur_dropped -=1;
        }
    }
    return;
}

main(){
    cin >> n >> k;
    f0(i, 2*n){
        f0(j, 2*n){
            cin >> dis[i][j];
            if(i!=j) 
                min_road = min(min_road, dis[i][j]);
        }
    }
    Recursion(0, 0, 0);
    cout << ans;
    return 0;
}




