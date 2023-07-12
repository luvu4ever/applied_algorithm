#include<bits/stdc++.h>
#define el cout<<'\n'

using namespace std;

map<string, int> cnt;
map<string, long long> call_time;
int total_call = 0;

main(){
	string order;
	int num_check = 1;
	cin>>order;
	while(order[0] != '#'){
		string from_num, to_num, date, from_time, to_time;
		cin>> from_num >> to_num >> date >> from_time >> to_time >>order;
		int valid = 1;
		for(int j = 0; j<=9; j++){
			if(!isdigit(from_num[j])){
				num_check = 0;
				valid = 0;
			}
		}
		for(int j = 0; j<=9; j++){
			if(!isdigit(to_num[j])){
				num_check = 0;
				valid = 0;
			}
		}
		long long time_diff = (long long) (to_time[0] - from_time[0]) * 10 + (to_time[1] - from_time[1]);
		time_diff = time_diff * 60 + (to_time[3] - from_time[3]) * 10 + (to_time[4] - from_time[4]);
		time_diff = time_diff * 60 + (to_time[6] - from_time[6]) * 10 + (to_time[7] - from_time[7]);
		if(!valid)
			continue;
		total_call++;
		cnt[from_num]++;
		call_time[from_num] += time_diff;
	}
	cin>>order;
	while(order[0] != '#'){
		//check_phone_number
		if(order[1] == 'c' && order[2] == 'h'){
			cout<<num_check, el;
			cin>>order;
			continue;
		}
		//count time call from
		if(order[1] == 'c'){
			string q_num;
			cin >> q_num;
			cout<<call_time[q_num], el;
			cin>>order;
			continue;
		}
		//number_total_calls
		if(order[8] == 't'){
			cout<<total_call, el;
			cin>>order;
			continue;
		}
		//number_calls_from
		string q_num;
		cin >> q_num;
		cout<<cnt[q_num], el;
		cin>>order;
	}
}