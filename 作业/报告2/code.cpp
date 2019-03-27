//1148
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;

int  rocks[20000];

int F[20000];

int min(int a, int b) {
	return (a < b ? a : b);
}

int stone_pos[200];

int L, min_step, max_step, n;

int main() {
	memset(rocks, 0, sizeof(rocks));
	cin >> L >> min_step >> max_step >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stone_pos[i];
	}
	stone_pos[0] = 0;
	sort(stone_pos, stone_pos + n + 1);
	// 特殊情况判断
	if (min_step == max_step) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (stone_pos[i] % min_step == 0)
				ans++;
		cout << ans << endl;
		return 0;
	}
	// 压缩到rocks里
	int index;
	stone_pos[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (stone_pos[i] - stone_pos[i - 1] > 100) {
			index = stone_pos[i - 1] + 100;
			int pos = stone_pos[i] - (stone_pos[i - 1] + 100);
			for (int j = i; j <= n; j++) {
				stone_pos[j] -= pos;
			}
		}
		else {
			index = stone_pos[i];
		}
		rocks[index] = 1;
	}
	if (L - index > 100) {
		L = index + 100;
	}

	for (int i = 0; i <= L; i++) {
		F[i] = 999;
	}

	for (int i = min_step; i <= max_step; i++) {
		if (rocks[i] == 0) {
			F[i] = 0;
		}
		else {
			F[i] = 1;
		}
	}

	for (int i = max_step+1; i <= L; i++) {
		for (int k = min_step; k <= max_step && i-k >= 1; k++) {
			F[i] = min(F[i], F[i - k]);
		}
		if (rocks[i]) {
			F[i]++;
		}
	}
	cout << F[L] << endl;
	system("pause");
}


/*
//1163
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

double cal[100][100];

struct point {
	double x, y;
	point() {

	}
	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

point p[100];

double dist(point a, point b) {
	return sqrt(double((a.x - b.x)*(a.x - b.x)) + double((a.y - b.y)*(a.y - b.y)));
}

double min(double a, double b) {
	return (a < b ? a : b);
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			double x, y;
			cin >> x >> y;
			p[i].x = x;
			p[i].y = y;
		}
		cal[1][1] = 0;
		cal[2][1] = dist(p[2], p[1]);
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (j < i - 1) {
					cal[i][j] = cal[i - 1][j] + dist(p[i], p[i - 1]);
				}
				else {
					cal[i][j] = cal[i - 1][1] + dist(p[i], p[1]);
					for (int k = 2; k < i-1; k++) {
						cal[i][j] = min(cal[i - 1][k] + dist(p[i], p[k]), cal[i][j]);
					}
				}
			}
		}
		cout << fixed << setprecision(2) << cal[n][n - 1] + dist(p[n], p[n - 1]) << endl;
	}
}
*/
/*
//1264
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int a[110];
double t[110];
double b, r, v, e, f;

double min(double a, double b) {
	return (a < b ? a : b);
}

int distance(int k, int i) {
	return abs(a[i] - a[k]);
}


double G[10010];

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			return  0;
		}
		a[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cin >> b >> r >> v >> e >> f;
		t[0] = 0;
		G[0] = 0;
		for (int i = 0; i <= a[n]; i++) {
			double temp = (i >= r) ? 1 / (v - e * (i - r)) : 1 / (v - f * (r - i));
			G[i + 1] = G[i] + temp;
		}
		t[1] = G[a[1]];
		for (int i = 2; i <= n; i++) {
			t[i] = G[a[i]];
			for (int k = i - 1; k >= 1; k--) {
				t[i] = min(t[i], t[k] + b + G[distance(k, i)]);
			}
		}
		cout << fixed << setprecision(4) << t[n] << endl;
	}
}
*/

/*
//1345
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;

long long energy[210][210];

int m[210];

long  long max(long long  a, long long b) {
	return (a > b ? a : b);
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> m[i];
			m[i + n] = m[i];
		}
		m[2*n + 1] = m[1];
		for (int j = 3; j <= 2*n; j++) {
			for (int i = j-2; i >= 1; i--) {
				energy[i][j] = 0;
				for (int k = i + 1; k < j; k++) {
					energy[i][j] = max(energy[i][k] + energy[k][j] + m[i] * m[j] * m[k], energy[i][j]);
				}
			}
		}
		int max_num = 0;
		for (int i = 1; i <= n; i++) {
			max_num = max(max_num, energy[i][i + n]);
		}
		cout << max_num << endl;
	}

}
*/

/*
//13062 
// 实际就是进栈出栈问题
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;


int main() {
	long long f[32];
	f[0] = 1;
	f[1] = 1;
	f[2] = 2;
	f[3] = 5;
	for (int i = 4; i <= 31; i++) {
		f[i] = 0;
		for (int j = 0; j < i; j++) {
			f[i] += f[i - j - 1] * f[j];
		}
	}
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		cout << f[n] << endl;
	}
}
*/


/*
//1527
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;

int m[1010][16];
int main() {
	int T;
	cin >> T;
	int count = 0;

	m[1][0] = m[1][3] = m[1][6] = m[1][12] = m[1][15] = 1;
	for (int i = 2; i <= 1000; i++) {
		m[i][0] = m[i - 1][15];
		m[i][3] = m[i - 1][15] + m[i - 1][12];
		m[i][6] = m[i - 1][15] + m[i - 1][9];
		m[i][9] = m[i - 1][6];
		m[i][12] = m[i - 1][15] + m[i - 1][3];
		m[i][15] = m[i - 1][15] + m[i - 1][12] + m[i - 1][6] + m[i - 1][3] + m[i - 1][0];
	}

	while (T--) {
		count++;
		cout << count << " ";
		int n;
		cin >> n;
		cout << m[n][15] << endl;
	}

}
*/
/*
//1828
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;

int min(int a, int b) {
	return (a < b ? a : b);
}

int p[510][510];
int s_arr1[510];
int s_arr2[510];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1; i++) {
			cin >> s_arr1[i];
		}
		for (int i = 0; i < s2; i++) {
			cin >> s_arr2[i];
		}
		sort(s_arr1, s_arr1 + s1);
		sort(s_arr2, s_arr2 + s2);
		memset(p, 9999999, sizeof(p));
		int min_num = 9999999;
		for (int i = 1; i <= s2; i++) {
			if (abs(s_arr1[0] - s_arr2[i - 1]) < min_num) {
				min_num = abs(s_arr1[0] - s_arr2[i - 1]);
			}
			p[1][i] = min_num;
		}
		for (int i = 2; i <= s1; i++) {
			for (int j = i; j <= s2; j++) {
				p[i][j] = min(p[i][j - 1], p[i - 1][j - 1] + abs(s_arr1[i - 1] - s_arr2[j - 1]));
			}
		}
		cout << p[s1][s2] << endl;
	}
}
*/




/*
//1121
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int cal[40];

int main() {
	memset(cal, 0, sizeof(cal));
	cal[0] = 1;
	cal[2] = 3;
	for (int i = 4; i <= 31; i += 2) {
		cal[i] = cal[i - 2] * 4 - cal[i - 4];
	}
	int n;
	while (true) {
		cin >> n;
		if (n == -1) {
			return 0;
		}
		cout << cal[n] << endl;
	}
}
*/
/*
// 1011
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int max(int a, int b) {
	return (a > b ? a : b);
}

long long list[20][2020];

long long cal_n_m(int n, int m) {
	for (int i = 1; i <= m; i++) {
		list[1][i] = i;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			// 选择j或者不选j的和
			list[i][j] = list[i - 1][j / 2]  + list[i][j - 1];
		}
	}
	return list[n][m];
}

int main() {
	int T;
	cin >> T;
	int count = 0;
	while (T--) {
		count++;
		int n, m;
		cin >> n >> m;
		memset(list, 0, sizeof(list));
		long long ans = cal_n_m(n, m);
		cout << "Case "<< count << ": n = " << n << ", m = " << m << ", # lists = " << ans << endl;
	}
}
*/
/*
// 1176
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;
int arr[1010];
int cal[1010][1010];

int max(int a, int b) {
	return (a > b ? a : b);
}

int cal_a_b(int a, int b) {
	int leftsum;
	int rightsum;
	if (a > b) return 0;
	if (cal[a][b] != -1) {
		return cal[a][b];
	}
	if (arr[a + 1] >= arr[b]) {
		leftsum = cal_a_b(a + 2, b) + arr[a];
	}
	else {
		leftsum = cal_a_b(a + 1, b - 1) + arr[a];
	}
	if (arr[a] >= arr[b - 1]) {
		rightsum = cal_a_b(a + 1, b - 1) + arr[b];
	}
	else {
		rightsum = cal_a_b(a, b - 2) + arr[b];
	}
	cal[a][b] =  max(leftsum, rightsum);
	return cal[a][b];
}

int main() {
	int n;
	int count = 0;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		memset(cal, -1, sizeof(cal));
		count++;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		int win_sum = cal_a_b(0, n - 1);
		int lose_sum = sum - win_sum;
		cout << "In game " << count << ", the greedy strategy might lose by as many as " << win_sum - lose_sum << " points." << endl;
	}
}
*/