
// sicily 1438
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

int v[20010];

bool cmp(int a, int b)
{
	return a>b;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v, v + n ,cmp);
		int sum = 0;
		if (n < 3) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 2; i < n; i += 3) {
			sum += v[i];
		}
		cout << sum << endl;
	}
}

/*
// sicily 1093
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

int weight[3];
int cost[4];

int get_min_w(int n) {
	if (n <= weight[0]) {
		return 0;
	}
	else if (n > weight[0] && n <= weight[1]) {
		return 1;
	}
	else if (n <= weight[2]) {
		return 2;
	}
	else {
		return 3;
	}
}



void print(int w,int p,int add) {
//	cout << "Weight(" << w << ") has best price $" << p << "(add " << add << " pounds)" << endl;
	cout << "Weight (" << w << ") has best price $"
		<< p << " (add " << add << " pounds)\n";
}

int temp_cost[4];
int add_pounds[4];

int main() {
	int count = 0;
	while (cin >> weight[0]) {
		count++;
		cin >> cost[0];
		cin >> weight[1] >> cost[1] >> weight[2] >> cost[2] >> cost[3];
		cout << "Set number " << count << ":" << endl;
		int n;
		while (true) {
			cin >> n;
			if (n == 0) {
				break;
			}
			int f = get_min_w(n);
			for (int i = 0; i < 4; i++) {
				add_pounds[i] = 0;
			}
			if (f == 0) {
				temp_cost[0] = cost[0] * n;
				for (int i = 1; i < 4; i++) {
					add_pounds[i] = weight[i - 1] + 1 - n;
					temp_cost[i] = cost[i] * (weight[i-1] + 1);
				}
				int min = temp_cost[0];
				int index = 0;
				for (int i = 1; i < 4; i++) {
					if (min > temp_cost[i]) {
						min = temp_cost[i];
						index = i;
					}
				}
				print(n, min, add_pounds[index]);
			}
			else if (f == 1) {
				temp_cost[1] = cost[1] * n;
				for (int i = 2; i < 4; i++) {
					add_pounds[i] = weight[i - 1] + 1 - n;
					temp_cost[i] = cost[i] * (weight[i - 1] + 1);
				}
				int min = temp_cost[1];
				int index = 1;
				for (int i = 2; i < 4; i++) {
					if (min > temp_cost[i]) {
						min = temp_cost[i];
						index = i;
					}
				}
				print(n, min, add_pounds[index]);
			}
			else if (f == 2) {
				temp_cost[2] = cost[2] * n;
				for (int i = 3; i < 4; i++) {
					add_pounds[i] = weight[i - 1] + 1 - n;
					temp_cost[i] = cost[i] * (weight[i - 1] + 1);
				}
				int min = temp_cost[2];
				int index = 2;
				for (int i = 3; i < 4; i++) {
					if (min > temp_cost[i]) {
						min = temp_cost[i];
						index = i;
					}
				}
				print(n, min, add_pounds[index]);
			}
			else{
				print(n, cost[3] * n, 0);
			}
		}
		cout << endl;
	}
}
*/
/*
// sicily 1783
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

void swap(char & a, char & b) {
	char c = a;
	a = b;
	b = c;
}

void sort(string & a) {
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < a.length() - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string num_arr;
		cin >> num_arr;
		vector<string> num;
		int count = 0;
		for (int i = 0; i < num_arr.length(); i++) {
			if (num_arr[i] == '0') {
				if (count != 0) {
					num.push_back(num_arr.substr(i - count, count));
					num.push_back(num_arr.substr(i, 1));
				}
				else {
					num.push_back("0");
				}
				count = 0;
			}
			else {
				count++;
			}
		}
		num.push_back(num_arr.substr(num_arr.length() - count, count));

		for (int i = 0; i < num.size(); i++) {
			sort(num[i]);
		}
		for (int i = 0; i < num.size(); i++) {
			cout << num[i];
		}
		cout << endl;
	}
	system("pause");
}
*/

/*
// sicily 1198
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

struct Cmp {
	bool operator()(string a, string b) {
		return (a + b > b + a);
	}
}; 

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		priority_queue<string, vector<string>, Cmp> q;
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			q.push(temp);
		}
		while (!q.empty()) {
			cout << q.top();
			q.pop();
		}
		cout <<  endl;
	}
}
*/


/*
// sicily 1051
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>

using namespace std;

void print_in_2_45(double ans) {
	cout << fixed << setprecision(2) << ans;
}

int main() {
	double d, n, t;
	int count = 0;
	while (true) {
		cin >> d >> n >> t;
		if (n == 0) {
			return 0;
		}
		count++;
		double l = d * 3.1415927 / 12 / 5280*n;
		double v = l / t * 3600;
		cout << "Trip #"<<count<<": ";
		print_in_2_45(l);
		cout << " ";
		print_in_2_45(v);
		cout << endl;
		
	}
}
*/

/*
// sicily 1046
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int arr[1000];

int cal_sum(int * arr, int from, int end) {
	int sum = 0;
	for (int i = from; i < end; i++) {
		sum += arr[i];
	}
	return sum;
}

struct node {
	int from;
	int end;
	double average;
	node(int from, int end, double average) {
		this->from = from;
		this->end = end;
		this->average = average;
	}
};

struct Cmp {
	bool operator()(node a, node b) {
		if (a.average < b.average) {
			return true;
		}
		else if (a.average > b.average) {
			return false;
		}
		else {
			if ((a.end - a.from) < (b.end - b.from)) {
				return true;
			}
			else if ((a.end - a.from) > (b.end - b.from)) {
				return false;
			}
			else {
				if (a.end > b.end) {
					return true;
				}
				else{
					return false;
				}
			}
		}
	}
};

int main() {
	int T;
	cin >> T;
	int N = T;
	while (T--) {
		int n;
		int q_num;
		int mini_quar;
		cin >> n >> q_num >> mini_quar;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		priority_queue<node, vector<node>, Cmp> q;
		for (int i = 0; i < n - mini_quar+1; i++) {
			int this_sum = cal_sum(arr, i, i + mini_quar);
			node temp(i + 1, i + mini_quar, double(this_sum) / double(mini_quar));
			q.push(temp);
			for (int j = i+mini_quar; j < n; j++) {
				this_sum += arr[j];
				node temp2(i + 1, j+1, double(this_sum) / double(j-i+1));
				q.push(temp2);
			}
		}
		cout << "Result for run " << N - T << ":" << endl;
		for (int i = 0; i < q_num && !q.empty(); i++) {
			node temp = q.top();
			q.pop();
			cout << temp.from << "-" << temp.end << endl;
		}
	}
}
*/

/*
// sicily 1035
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

bool complement(string a, string b) {
	if (a.length() != b.length()) {
		return false;
	}
	for (int i = 0; i < a.length(); i++) {
		if ((a[i] == 'A' && b[i] == 'T') || (a[i] == 'T' && b[i] == 'A') ||
			(a[i] == 'G' && b[i] == 'C') || (a[i] == 'C' && b[i] == 'G')) {

		}
		else {
			return false;
		}
	}
	return true;
}

bool visit[1000];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			v.push_back(temp);
			visit[i] = false;
		}
		int count = 0;
		for (int i = 0; i < v.size(); i++) {
			bool flag = true;
			for (int j = i + 1; j < v.size(); j++) {
				if (visit[i] == false && visit[j] == false && complement(v[i], v[j])) {
					count++;
					visit[i] = true;
					visit[j] = true;
				}
			}
		}
		cout << count << endl;
	}
}
*/

/*

// sicily 1027 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
bool flag[1000000];

void swap(pair<string, string> &a, pair<string, string> &b) {
	pair<string, string> c;
	c = a;
	a = b;
	b = c;
}

void compare_sort(vector<pair<string, string> > &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j].second > v[j + 1].second) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		vector<pair<string, string> > v;
		for (int i = 0; i < n; i++) {
			string temp1, temp2;
			cin >> temp1 >> temp2;
			flag[i] = false;
			v.push_back(pair<string, string>(temp1, temp2));
		}
		vector<pair<string, string> > ans;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (v[i].second == v[j].second && flag[i] == false && flag[j] == false) {
					flag[i] = flag[j] = true;
					string temp = v[j].first + " is the MaJia of ";
					ans.push_back(pair<string, string>(temp, v[i].first));
					break;
				}
			}
		}
		compare_sort(ans);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << ans[i].second << endl;
		}
		cout << endl;

	}
}
*/

/*
// sicily 1021 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


int r[200010];

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			r[a] = b;
			r[b] = a;
		}
		stack<int> s;
		for (int i = 1; i <= 2*n; i++) {
			if (s.empty()) {
				s.push(i);
			}
			else if(s.top() == r[i]) {
				s.pop();
			}
			else {
				s.push(i);
			}
		}
		if (s.empty()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		
	}
}
*/

/*
// sicily 1020 big integer
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//(a + b) % p = (a % p + b % p) % p （1）
//(a - b) % p = (a % p - b % p) % p （2）
//(a * b) % p = (a % p * b % p) % p （3）
//a ^ b % p = ((a % p)^b) % p （4）
int base[1001];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> base[i];
		}
		string str;
		cin >> str;
		cout << "(";
		for (int k = 0; k < n; k++) {
			int ans = 0;
			for (int i = 0; i < str.length(); i++) {
				ans = ((ans * 10)%base[k]  + (str[i]-'0')%base[k] ) % base[k];
			}
			if (k < n - 1)
				cout << ans << ",";
			else
				cout << ans << ")" << endl;
		}

	}
}
*/