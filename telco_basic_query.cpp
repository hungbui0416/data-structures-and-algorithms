#include <bits/stdc++.h>
using namespace std;

int validPhoneNb = 1;
map<string, int> nbCallsFrom;
int nbTotalCalls = 0;
map<string, int> timeCallsFrom;

void checkPhoneNb(string pnb) {
	if (pnb.length() != 10) {
		validPhoneNb = 0;
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (pnb[i] < '0' || pnb[i] > '9') {
			validPhoneNb = 0;
			return;
		}
	}
}

int convertTime(string time) {
	int h = (time[0] - '0') * 10 + time[1] - '0';
	int m = (time[3] - '0') * 10 + time[4] - '0';
	int s = (time[6] - '0') * 10 + time[7] - '0';

	return 3600*h + 60*m + s;
}

int main() {
	//data
	while (true) {
		string s;
		cin >> s;

		if (s == "#") break;
		else if (s == "call") {
			string fnb, tnb, date, ftime, ttime;
			cin >> fnb >> tnb >> date >> ftime >> ttime;

			if (validPhoneNb) {
				checkPhoneNb(fnb); checkPhoneNb(tnb);
			}

			nbCallsFrom[fnb]++;

			nbTotalCalls++;

			timeCallsFrom[fnb] += convertTime(ttime) - convertTime(ftime);
		}
	}

	//query
	while (true) {
		string s;
		cin >> s;

		if (s == "#") break;
		else if (s == "?check_phone_number")
			cout << validPhoneNb << endl;
		else if (s == "?number_calls_from") {
			string pnb;
			cin >> pnb;
			cout << nbCallsFrom[pnb] << endl;
		}
		else if (s == "?number_total_calls")
			cout << nbTotalCalls << endl;
		else if (s == "?count_time_calls_from") {
			string pnb;
			cin >> pnb;
			cout << timeCallsFrom[pnb] << endl;
		}
	}
}
