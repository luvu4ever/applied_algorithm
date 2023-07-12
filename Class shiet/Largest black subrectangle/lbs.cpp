#include<bits/stdc++.h>
#define f0(i,a) for(int i=0; i<a; ++i)
#define f1(i,a) for(int i = 1; i<=(a); ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int largestRectangleArea(vector<int>& a) {
    int n = a.size();
    int ans = 0;
    stack<int> index, heights;
    int last_index;
    f0(i, n){
        if(index.empty() || heights.top() < a[i]){
            index.push(i);
            heights.push(a[i]);
            continue;
        }
        while(!index.empty() && a[i] <= heights.top()){
            ans = max(ans, (i - index.top()) * heights.top());
            last_index = index.top();
            index.pop();
            heights.pop();
        }
        heights.push(a[i]);
        index.push(last_index);
    }
    while(!index.empty()){
        ans=max(ans, (n-index.top()) * heights.top());
        index.pop();
        heights.pop();
    }
    return ans;
}

main()
{
    int n;
    cin>> n;
    vector<int> heights;
    f1(i, n){
        int x;
        cin>> x;
        heights.pb(x);
    }
    cout << largestRectangleArea(heights);
    return 0;
}