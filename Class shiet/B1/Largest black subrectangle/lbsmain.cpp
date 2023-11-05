#include<bits/stdc++.h>
#define f0(i,a) for(int i=0; i<a; ++i)
#define f1(i,a) for(int i = 1; i<=(a); ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int m, n;
vector<vector<int>> matrix;

int largestRectangleArea(vector<int> &a)
{
    int n = a.size();
    int ans = 0;
    stack<int> index, heights;
    int last_index;
    f0(i, n)
    {
        if (index.empty() || heights.top() < a[i])
        {
            index.push(i);
            heights.push(a[i]);
            continue;
        }
        while (!index.empty() && a[i] <= heights.top())
        {
            ans = max(ans, (i - index.top()) * heights.top());
            last_index = index.top();
            index.pop();
            heights.pop();
        }
        heights.push(a[i]);
        index.push(last_index);
    }
    while (!index.empty())
    {
        ans = max(ans, (n - index.top()) * heights.top());
        index.pop();
        heights.pop();
    }
    return ans;
}
int maximalRectangle()
{
    vector<int> basic;
    basic.clear();
    int res = 0;
    f0(i, n)
        basic.pb(0);
    f0(i, m){
        f0(j, n){
            if (matrix[i][j] == 0)
                basic[j] = 0;
            else
                basic[j] += 1;
        }
        res = max(res, largestRectangleArea(basic));
    }
    return res;
}

main()
{
    cin>> m>> n;
    f0(i, m){
        vector<int> row;
        f0(j, n){
            int x;
            cin>> x;
            row.pb(x);
        }
        matrix.pb(row);
        row.clear();
    }
    cout<<maximalRectangle();
    return 0;
}