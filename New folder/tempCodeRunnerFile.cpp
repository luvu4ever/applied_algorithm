#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000009

using namespace std;

stack<int> number;
stack<int> equation;

main()
{
    long long cur_num = 0;
    string s;
    getline(cin, s);
    s = '(' + s;
    s = s + ')';
    int n = s.size();
    int check = 0;
    f0(i, n){
        char c = s[i];
        if(c == ' ')
            continue;
        if(c >= '0' && c <= '9'){
            cur_num = cur_num * 10 + c - '0';
            continue;
        }
        if(c == '+'){
            if(cur_num != 0){
                equation.push(1);
                number.push(cur_num);
                cur_num = 0;
            }
            continue;
        }
        if(cur_num != 0){
            number.push(cur_num);
            cur_num = 0;
        }
        if(c == '('){
            check++;
            equation.push(0);
            continue;
        }
        if(!equation.empty() && equation.top() == 2){
            long long num1 = number.top();
            number.pop();
            long long num2 = number.top();
            number.pop();
            equation.pop();
            number.push(num1 * num2 % MOD);
        }
        if(c == '*'){
            equation.push(2);
            continue;
        }
        if(c == ')'){
            check--;
            if(check < 0){
                cout<<"NOT_CORRECT";
                return 0;
            }
            long long ans = number.top();
            number.pop();
            while(!equation.empty() && equation.top() != 0){
                ans+= number.top();
                ans%= MOD;
                number.pop();
                equation.pop();
            }
            equation.pop();
            number.push(ans);
        }
    }
    if(check != 0){
        cout<<"NOT_CORRECT";
        return 0;
    }
    cout<<number.top();
    return 0;
}