#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000009

using namespace std;

stack<long long> number;
stack<char> op;

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

long long Calculate(){
    long long x = number.top();
    number.pop();
    long long y = number.top();
    number.pop();
    char ope = op.top();
    op.pop();
    if(ope == '+')
        return x+y% MOD;
    if(ope == '-')
        return (x - y + MOD) % MOD;
    if(ope == '*')
        return x*y% MOD;
    return 0;
}

main()
{
    long long cur_num = 0;
    string s;
    getline(cin, s);
    int n = s.length();
    f0(i,n){
        char c = s[i];
        if(c == ' ')
            continue;
        if(c >= '0' && c <= '9'){
            int cur_num = 0;
            while(i<n && c>='0' && c<='9'){
                cur_num = cur_num*10 + c-'0';
                i++;
                c = s[i];
            }
            i--;
            number.push(cur_num%MOD);
            continue;
        }
        if(c == '('){
            op.push(c);
            continue;
        }
        if(c == ')'){
            while(!op.empty() && op.top() != '(' ){
                number.push(Calculate());
            }
            if(!op.empty())
                op.pop();
            continue;
        }
        while(!op.empty() && priority(c) <= priority(op.top())){
            number.push(Calculate());
        }
        op.push(c);
    }
    while(!op.empty()){
        number.push(Calculate());
    }
    cout<< number.top();
    return 0;
}

