#include<bits/stdc++.h>
#define f1(i, n) for(int i = 1; i <=(n); ++i)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define el cout<<'\n'

using namespace std;

int n, m, r, c;
int dx[5] = {0, 1, -1, 0 , 0};
int dy[5] = {0, 0, 0, 1, -1};
int visited[1005][1005];
int a[1005][1005];
queue<pii> q;

main(){
	cin >> n>> m>> r >> c;
	f1(i, n){
		f1(j, m){
			cin>>a[i][j];
		}
	}
	q.push(mp(r, c));
	visited[r][c] = 1;
	while(!q.empty()){
		int cur_x = q.front().fi;
		int cur_y = q.front().se;
		q.pop();
		f1(i, 4){
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];
			if(new_x == 0 || new_y == 0 || new_x == n+1 || new_y == m+1){
				cout<<visited[cur_x][cur_y], el;
				return 0;
			}
			if(a[new_x][new_y] == 1)
				continue;
			if(visited[new_x][new_y])
				continue;
			q.push(mp(new_x, new_y));
			visited[new_x][new_y] = visited[cur_x][cur_y] + 1;
		}
	}
	cout<< -1, el;
	return 0;
}
