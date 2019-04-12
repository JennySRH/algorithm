// 1214
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <memory.h>
#include <sstream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// 700000
// 1, 2, 3,4,



int main() {

		long long num;
		cin >> num;
		if (num == 1) {
			cout << 1 << endl;
			return 0;
		}
		string num_str = "";
		long long num_cal = num;
		while (num_cal > 0) {
			int a = num_cal % 2;
			num_cal /= 2;
			num_str += a + '0';
		}
		int half = num_str.length() / 2;
		long long temp = num >> half;
		long long temp_left = num - (temp << half);
		if (half * 2 == num_str.length()) {	//  偶
			int count = temp;
			count += pow(2, half) - 1;
			string reverse_left = num_str.substr(half, half);
			long long right_sum = 0;
			for (int k = 0; k < reverse_left.size(); k++) {
				right_sum = right_sum * 2 + reverse_left[k] - '0';
			}
			if (right_sum > temp_left) {
				count--;
			}
			cout << count << endl;
		}
		else {
			temp_left = num - ((temp>>1) << (half+1));
			int count = (pow(2, half)-1) + temp;
			string reverse_left = num_str.substr(half, half + 1);
			long long right_sum = 0;
			for (int k = 0; k < reverse_left.size(); k++) {
				right_sum = right_sum * 2 + reverse_left[k] - '0';
			}
			if (right_sum > temp_left) {
				count--;
			}
			cout << count << endl;
		}
//	system("pause");
}


/*
// 1231
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <memory.h>
#include <sstream>
using namespace std;

int num[2000000];

bool mod(string k, int l) {
	long long m = 0;
	for (int i = 0; i < k.length(); i++) {
		m = (m * 10 + (k[i] - '0')) % l;
	}
	if (m == 0) {
		return true;
	}
	else return false;
}

int main() {
	memset(num, 1, sizeof(num));
	for (int i = 2; i <= 1000000; i++) {
		if (num[i]) {
			for (int j = 2 * i; j <= 1000000; j += i) {
				num[j] = 0;
			}
		}
	}
	while (true) {
		string k;
		int l;
		cin >> k >> l;
		if (l == 0) {
			return 0;
		}
		bool flag = true;
		int index;
		for (int i = 2; i < l; i++) {
			if (num[i] && mod(k, i)) {
				flag = false;
				index = i;
				break;
			}
		}
		if (flag) {
			cout << "GOOD" << endl;
		}
		else {
			cout << "BAD " << index << endl;
		}
	}
}
*/

/*
// 1240
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <memory.h>
#include <sstream>
using namespace std;


int main() {
	while (true) {
		long long n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		string temp;
		stringstream ss;
		ss << n;
		ss >> temp;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] - '0' > 4) {
				temp[i]--;
			}
		}
		long long sum = 0;
		int base = 9;
		for (int i = 0; i < temp.length(); i++) {
			sum = sum * base + (temp[i] - '0');
		}
		cout << n << ": " << sum << endl;
	}
}
*/

/*
// 1259
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <memory.h>
#include <sstream>
using namespace std;

int num[20010];
int main() {
	memset(num, 1, sizeof(num));
	for (int i = 2; i <= 20000; i++) {
		if (num[i]) {
			for (int j = 2 * i; j <= 20000; j += i) {
				num[j] = 0;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		int count = 0;
		int start = 0;
		for (int i = 2; i <= n; i++) {
			int sum = 0;
			for (int k = i; k <= n; k++) {
				if (num[k]) {
					if (sum == 0) {
						start = k;
					}
					sum += k;
				}
				if (sum == n) {
					count++;
					i = start;
					break;
				}
				if (sum > n) {
					break;
				}
			}
		}
		cout << count << endl;
	}
}
*/
/*
// 1500
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <memory.h>
#include <sstream>
using namespace std;

int num[2000000];
int main() {
	memset(num, 1, sizeof(num));
	for (int i = 2; i <= 1299709; i++) {
		if (num[i]) {
			for (int j = 2 * i; j <= 1299709; j+=i) {
				num[j] = 0;
			}
		}
	}
//	for (int i = 2; i <= 1000; i++) {
//		if (num[i]) cout << i << " ";
//	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		if (num[n]) {
			cout << 0 << endl;
			continue;
		}
		int count = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (!num[i]) count++;
			else break;
		}
		for (int i = n+1; i <= 1299709; i++) {
			if (!num[i]) count++;
			else break;
		}
		cout << count+1 << endl;
	}
}
*/

/*
// 1203
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


int a[10] = { 0,1,0,7,0,0,0,3,0,9 };

// a^3%1000 = (a*a*a)%1000 = ((a*a)%1000)*a%1000


//c = a*b%mod = (bn*2^n+...+b1*2^1+...+b0)*a%mod  
long long mul(long long a, long long b, long long mod) {
	long long c = 0;
	const int base = 2;
	for (; b != 0; b /= base) {
		c += (b % base) * a;
		c %= mod;
		a = (a * base) % mod;
	}
	return c;
}

long long cube(long long num, long long mod) {
	return mul(mul(num, num,mod), num, mod);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string num;
		cin >> num;
		long long result = a[num[num.size() - 1] - '0'];
		long long remain = num[num.size()-1]-'0';
		long long power = 10;
		for (int i = num.size() - 2; i >= 0; i--) {
			remain += power * (num[i] - '0');
			long long step = power;
			power *= 10;
			while (cube(result, power) != remain) {
				result += step;
			}
		}
		cout << result << endl;
	}
//	system("pause");
}
*/

/*
// 1119
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
int main() {
	while (true) {
		int year;
		cin >> year;
		if (year == 0) {
			return 0;
		}
		// get the max n that satisfies n! < 2^k -> n! < 2^{2^(2+(n-1960)/10)} -> logn + logn-1+...+0 < log(2)*(2+(year-1960)/10)
		double right = pow(2.0, (year - 1960) / 10 + 2);
		double sum = 0;
		int n = 1;
		do{
			sum += log(double(n))/log(double(2.0));
			n++;
		} while (sum < right);
		cout << n - 2 << endl;
	}
}
*/

/*
// 1099
#include <iostream>
#include <string>
using namespace std;

int main() {
	int count = 0;
	while (true) {
		count++;
		long long n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		long long costA, passengerA;
		long long costB, passengerB;
		cin >> costA >> passengerA >> costB >> passengerB;
		cout << "Data set " << count << ": ";
		if (passengerA == 0 ) {
			if (passengerB == 0 || n%passengerB != 0 ) {
				cout << "cannot be flown" << endl;
			}
			else {
				cout << "0 aircraft A, " << n / passengerB << " aircraft B" << endl;
			}
			continue;
		}
		if (passengerB == 0) {
			if (passengerA == 0 || n%passengerA != 0 ) {
				cout << "cannot be flown" << endl;
			}
			else {
				cout <<  n/passengerA  << " aircraft A, 0 aircraft B" << endl;
			}
			continue;
		}
		double valueA = double(costA) / passengerA;
		double valueB = double(costB) / passengerB;
		if (valueA <= valueB) {
			bool flag = false;
			long long countA = n / passengerA;
			long long countB;
			for (countA; countA >= 0; countA--) {
				if ((n-countA*passengerA) >= 0 && (n - countA * passengerA) % passengerB == 0) {
					countB = (n - countA * passengerA) / passengerB;
					cout << countA << " aircraft A, " <<  countB << " aircraft B" << endl;
					flag = true;
					break;
				}
			}
			if (flag == false) {
				cout << "cannot be flown" << endl;
			}
		}
		else {
			bool flag = false;
			long countB = n / passengerB;
			long countA;
			for (countB; countB >= 0; countB--) {
				if ((n - countB * passengerB) >= 0 && (n - countB * passengerB) % passengerA == 0) {
					countA = (n - countB * passengerB) / passengerA;
					cout << countA << " aircraft A, " << countB << " aircraft B" << endl;
					flag = true;
					break;
				}
			}
			if (flag == false) {
				cout << "cannot be flown" << endl;
			}
		}
	}
}
*/

/*

// 1014
#include <iostream>
#include <string>
using namespace std;

int get_dec(int n) {
	return n % 10 + n / 10 % 10 + n / 100 % 10 + n / 1000 % 10;
}

int get_hex(int n) {
	return n % 16 + n / 16 % 16 + n / (16 * 16) % 16 + n / (16 * 16 * 16) % 16;
}

int get_duo(int n) {
	return n % 12 + n / 12 % 12 + n / (12 * 12) % 12 + n / (12 * 12 * 12) % 12;
}

int main() {
	for (int i = 2992; i <= 9999; i++) {
		int a = get_dec(i);
		int b = get_hex(i);
		int c = get_duo(i);
		if (a == b && b == c) {
			cout << i << endl;
		}
	}
	system("pause");
}
*/