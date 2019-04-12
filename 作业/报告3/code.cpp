// 1153
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <math.h>
#include <iomanip>
using namespace std;


int map[8][8];

int offset_x[] = { -1, -2,-2,-1,1, 2, 2, 1 };
int offset_y[] = { -2, -1, 1, 2,2, 1,-1,-2 };

bool visited[65];

int visit_order[65];
int count_order = 1;

int get_n(int n, int i) {
	int x = (n - 1) / 8;
	int y = (n - 1) % 8;
	x = x + offset_x[i];
	y = y + offset_y[i];
	return map[x][y];
}


bool isValid(int n, int i) {
	int x = (n-1) / 8;
	int y = (n-1) % 8;
	x = x + offset_x[i];
	y = y + offset_y[i];
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7 ) {
		int n_next = get_n(n, i);
		if (visited[n_next] == false) {
			return true;
		}
	}
	return false;
}


int get_c(int n) {
	int  count = 0;
	for (int i = 0; i < 8; i++) {
		if (isValid(n, i)) {
			count++;
		}
	}
	return count;
}


struct  next_node {
	int index;
	int count;
};

void swap(next_node & a, next_node & b) {
	next_node temp = a;
	a = b;
	b = temp;
}


void dfs(int n) {
	if (count_order > 64) {
		return;
	}
	visited[n] = true;
	visit_order[n] = count_order++;
	if (count_order > 64) {
		return;
	}
	vector<next_node> order;
	for (int i = 0; i < 8; i++) {
		if (isValid(n, i)) {
			next_node next;
			next.index = get_n(n, i);
			next.count = get_c(next.index);
			if (next.count != 0) {
				order.push_back(next);
			}
		}
	}
	for (int i = 0; i < order.size(); i++) {
		for (int j = 0; j < order.size()-1; j++) {
			if (order[j].count > order[j + 1].count) {
				swap(order[j], order[j + 1]);
			}
		}
	}
	for (int i = 0; i < order.size(); i++) {
		dfs(order[i].index);
		if (count_order >= 64) {
			return;
		}
		visited[order[i].index] = false;
		count_order--;
	}

}

int main() {
	int count = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = count++;
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == -1) {
			return 0;
		}
		count_order = 1;
		memset(visited, false, sizeof(visited));
		memset(visit_order, 0, sizeof(visit_order));
		dfs(n);
		int  c = 1;
		while(true) {
			if (c == 64) {
				break;
			}
			for (int i = 1; i < 65; i++) {
				if (visit_order[i] == c) {
					c++;
					cout << i << " ";
					break;
				}
			}
		}
		for (int i = 1; i < 65; i++) {
			if (visit_order[i] == 0 || visit_order[i] == 64) {
				cout << i << endl;
				break;
			}
		}
	}
}


/*
// 1012
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <math.h>
#include <iomanip>
using namespace std;
#define PI 3.14159265358979323846
struct cycle {
	double x, y;
	cycle() {

	}
	cycle(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	double temp_arr[1010];
	int count = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		vector<cycle> arr;
		for (int i = 0; i < n; i++) {
			cin >> temp_arr[i];
		}
		sort(temp_arr, temp_arr + n);
		for (int i = 0; i < n; i++) {
			arr.push_back(cycle(temp_arr[i], 1));
		}
		for (int i = n - 1; i > 0; i--) {
			vector<cycle> arr_temp;
			for (int k = 0; k < i; k++) {
				cycle node1, node2, node;
				node1 = arr[k];
				node2 = arr[k + 1];
				double a = atan(abs(node1.y - node2.y) / abs(node1.x - node2.x));
				double b = acos(sqrt((node2.y - node1.y)*(node2.y - node1.y) + (node2.x - node1.x)*(node2.x - node1.x)) / 4);
				a = a + b;
				if (node2.y > node1.y) {
					node.x = node1.x + 2 * cos(a);
					node.y = node1.y + 2 * sin(a);
				}
				else if (node2.y < node1.y) {
					node.x = node2.x - 2 * cos(a);
					node.y = node2.y + 2 * sin(a);
				}
				else {
					node.x = node1.x + 2 * cos(b);
					node.y = node1.y + 2 * sin(b);
				}
				arr_temp.push_back(node);
			}
			arr.clear();
			arr = arr_temp;
		}
		cout.precision(4);
		cout <<  fixed << arr[0].x << " " << arr[0].y << endl;
		count++;
	}
	//system("pause");
}
*/

/*
// 1206
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <math.h>
#include <iomanip>
using namespace std;
#define PI 3.14159265358979323846
struct cycle {
	double x, y;
	cycle() {

	}
	cycle(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

int main() {
	int T;
	cin >> T;
	double temp_arr[1010];
	int count = 1;
	while (T--) {
		int n;
		cin >> n;
		vector<cycle> arr;
		for (int i = 0; i < n; i++) {
			cin >> temp_arr[i];
		}
		sort(temp_arr, temp_arr + n);
		for (int i = 0; i < n; i++) {
			arr.push_back(cycle(temp_arr[i], 1));
		}
		for (int i = n-1; i > 0; i--) {
			vector<cycle> arr_temp;
			for (int k = 0; k < i; k++) {
				cycle node1, node2, node;
				node1 = arr[k];
				node2 = arr[k + 1];
				double a = atan(abs(node1.y - node2.y) / abs(node1.x - node2.x));
				double b = acos(sqrt((node2.y - node1.y)*(node2.y - node1.y) + (node2.x - node1.x)*(node2.x - node1.x)) / 4);
				a = a + b;
				if (node2.y > node1.y) {
					node.x = node1.x + 2 * cos(a);
					node.y = node1.y + 2 * sin(a);
				}
				else if (node2.y < node1.y) {
					node.x = node2.x - 2 * cos(a);
					node.y = node2.y + 2 * sin(a);
				}
				else {
					node.x = node1.x + 2 * cos(b);
					node.y = node1.y + 2 * sin(b);
				}
				arr_temp.push_back(node);
			}
			arr.clear();
			arr = arr_temp;
		}
		cout.precision(4);
		cout << count << ": "  << fixed <<  arr[0].x << " " << arr[0].y << endl;
		count++;
	}
	//system("pause");
}
*/
/*
// 1140
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

struct node {
	int in;
	vector<int> out;
	int root_count;		//以该节点为根的子树的节点数目
	bool exist;			// 该节点是否存在
	int min_index;	// 以该节点为根的子树的最小节点
	node() {
		in = -1;
		root_count = -1;
		exist = false;
		min_index = -1;
	}
};

node tree_node[30050];


void build_tree(int n) {
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tree_node[a].exist = true;
		tree_node[b].exist = true;
		if (tree_node[a].in == -1) {
			tree_node[a].in = b;
			tree_node[b].out.push_back(a);
		}
		else {
			tree_node[b].in = a;
			tree_node[a].out.push_back(b);
		}
	}
}

int set_subtree_count(int root) {
	if (tree_node[root].exist == false) {
		return 0;
	}
	if (tree_node[root].out.size() == 0) {
		tree_node[root].root_count = 1;
		return 1;
	}
	if (tree_node[root].root_count != -1) {
		return tree_node[root].root_count;
	}
	tree_node[root].root_count = 1;
	for (int i = 0; i < tree_node[root].out.size(); i++) {
		tree_node[root].root_count += set_subtree_count(tree_node[root].out[i]);
	}
	return tree_node[root].root_count;
}

int set_min_index(int root) {
	if (tree_node[root].exist == false) {
		return 99999;
	}
	if (tree_node[root].out.size() == 0) {
		tree_node[root].min_index = root;
	}
	if (tree_node[root].min_index != -1) {
		return tree_node[root].min_index;
	}
	tree_node[root].min_index = root;
	for (int i = 0; i < tree_node[root].out.size(); i++) {
		tree_node[root].min_index = min(tree_node[root].min_index, set_min_index(tree_node[root].out[i]));
	}
	return tree_node[root].min_index;
}

void remove_edge(int index) { // 去掉一条边
	int edge_from = tree_node[index].in;
	int edge_to = index;
	tree_node[edge_to].in = -1;
	for (int k = 0; k < tree_node[edge_from].out.size(); k++) {
		if (tree_node[edge_from].out[k] == edge_to) {
			for (int j = k; j < tree_node[edge_from].out.size() - 1; j++) {
				tree_node[edge_from].out[j] = tree_node[edge_from].out[j + 1];
			}
			tree_node[edge_from].out.pop_back();
			break;
		}
	}
}

void add_edge(int edge_from, int edge_to) {
	tree_node[edge_from].out.push_back(edge_to);
	tree_node[edge_to].in = edge_from;
}

int get_min_index_sub(int root) {
	if (tree_node[root].exist == false) {
		return 999999;
	}
	if (tree_node[root].out.size() == 0) {
		return root;
	}
	int min_index = root;
	for (int i = 0; i < tree_node[root].out.size(); i++) {
		min_index = min(min_index, get_min_index_sub(tree_node[root].out[i]));
	}
	return min_index;
}

int get_min_index(int root, int k) {
	int edge_from = tree_node[k].in;
	int edge_to = k;
	remove_edge(k);
	int min_index = get_min_index_sub(root);
	add_edge(edge_from, edge_to);
	return min_index;
}

void init_false(int n) {
	for (int i = 1; i <= n; i++) {
		tree_node[i].exist = false;
	}
}

void init(int root) {
	tree_node[root].exist = true;
	tree_node[root].min_index = -1;
	tree_node[root].root_count = -1;
	for (int i = 0; i < tree_node[root].out.size(); i++) {
		init(tree_node[root].out[i]);
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	build_tree(n);
	int root;
	for (int i = 1; i <= n; i++) {
		if (tree_node[i].in == -1) { // 找到根
			root = i;
			break;
		}
	}
	int sum_count = n;
	for (int i = 0; i < k - 1; i++) {
		set_subtree_count(root);	// O(n)
		set_min_index(root);	// O(n)

		int delete_root;
		int save_root;
		int delete_root_min_index = 9999999;
		int delete_count = -1;
		for (int k = 1; k <= n; k++) {
			if (k == root) {
				continue;
			}
			if (tree_node[k].exist) {
				int delete_left_count = sum_count - tree_node[k].root_count;
				if (delete_left_count < tree_node[k].root_count) {
					if (delete_left_count > delete_count) {
						int delete_left_min_index = get_min_index(root, k);
						delete_count = delete_left_count;
						delete_root = k;
						save_root = k;
						delete_root_min_index = delete_left_min_index;
					}
					else if (delete_left_count == delete_count) {
						int delete_left_min_index = get_min_index(root, k);
						if (delete_left_min_index < delete_root_min_index) {
							delete_root = k;
							save_root = k;
							delete_count = delete_left_count;
							delete_root_min_index = delete_left_min_index;
						}
					}
				}
				else if (delete_left_count > tree_node[k].root_count) {
					if (tree_node[k].root_count > delete_count || (tree_node[k].root_count == delete_count && tree_node[k].min_index < delete_root_min_index)) {
						delete_count = tree_node[k].root_count;
						delete_root = k;
						save_root = root;
						delete_root_min_index = tree_node[k].min_index;
					}
				}
				else {
					if (tree_node[k].root_count > delete_count ) {
						int delete_left_min_index = get_min_index(root, k);
						if (tree_node[k].min_index < delete_left_min_index) {
								delete_count = tree_node[k].root_count;
								delete_root = k;
								save_root = root;
								delete_root_min_index = tree_node[k].min_index;
						}
						else {
								delete_count = tree_node[k].root_count;
								delete_root = k;
								save_root = k;
								delete_root_min_index = delete_left_min_index;
						}
					}
					else if (tree_node[k].root_count == delete_count) {
						int delete_left_min_index = get_min_index(root, k);
						if (delete_count < delete_left_min_index && delete_count < tree_node[k].min_index) {
							if (tree_node[k].min_index < delete_left_min_index) {
								if (tree_node[k].min_index < delete_root_min_index) {
									delete_count = tree_node[k].root_count;
									delete_root = k;
									save_root = root;
									delete_root_min_index = tree_node[k].min_index;
								}
							}
							else {
								if (delete_left_min_index < delete_root_min_index) {
									delete_count = tree_node[k].root_count;
									delete_root = k;
									save_root = k;
									delete_root_min_index = delete_left_min_index;
								}
							}
						}
					}
				}
			}
		}
		remove_edge(delete_root);
		root = save_root;
		init_false(n);
		init(root);
		cout << delete_count << " ";
		sum_count = sum_count - delete_count;
//		for (int i = 1; i <= n; i++) {
//			cout << "index " << i << " count: " << tree_node[i].root_count << " min_index: " << tree_node[i].min_index << endl;
//		}
	}
	cout << sum_count << endl;
	system("pause");
}
*/




/*

// 1034
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

int max(int a, int b) {
	return (a > b ? a : b);
}

struct node {
	int in;
	int depth;
	vector<int> out;
	node() {
		in = -1;
		depth = -1;
	}
};

node tree_node[200];

bool valid_flag;

bool visited[200];

int dfs_depth(int index) {
	if (valid_flag == false) {
		return -1;
	}
	if (visited[index]) {
		valid_flag = false;
		return -1;
	}
	visited[index] = true;
	if (tree_node[index].out.size() == 0) {
		return 0;
	}
	int max_depth = dfs_depth(tree_node[index].out[0]) + 1;
	int visit_node = tree_node[index].out[0];
	for (int i = 1; i < tree_node[index].out.size(); i++) {
		max_depth = max(max_depth, dfs_depth(tree_node[index].out[i]) + 1);
	}
	return max_depth;
}

void get_depth(int index) {
	if (tree_node[index].in == -1) {
		tree_node[index].depth = 0;
		return;
	}
	if (tree_node[index].depth != -1) {
		return;
	}
	if (tree_node[tree_node[index].in].depth == -1) {
		get_depth(tree_node[index].in);
	}
	tree_node[index].depth = tree_node[tree_node[index].in].depth + 1;

	
}

int main() {
	int n, m;
	while (true) {
		cin >> n >> m;
		valid_flag = true;
		if (n == 0) {
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			visited[i] = false;
			tree_node[i].depth = -1;
			tree_node[i].in = -1;
			tree_node[i].out.clear();
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (a == b) {
				valid_flag = false;
			}
			tree_node[a].out.push_back(b);
			tree_node[b].in = a;
		}
		int max_depth = 0;
		bool has_root_flag = false;
		for (int i = 1; i <= n; i++) {
			if (tree_node[i].in == -1) {
				int temp = dfs_depth(i);
				visited[i] = true;
				max_depth = max(max_depth, temp);
			}
		}
		for (int i = 1; i < n; i++) {
			if (visited[i] == false) {
				valid_flag = false;
				break;
			}
		}
		
		if (valid_flag) {
			int width[200];
			for (int i = 0; i <= max_depth; i++) {
				width[i] = 0;
			}
			for (int i = 1; i <= n; i++) {
				get_depth(i);
			}
			for (int i = 1; i <= n; i++) {
				width[tree_node[i].depth]++;
			}
			int max_width = 0;
			for (int i = 0; i <= max_depth; i++) {
				max_width = max(max_width, width[i]);
			}
			cout << max_depth << " " << max_width << endl;
		}
		else {
			cout << "INVALID" << endl;
		}
	}
}
*/

/*
// 1381
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;


string get_sum(string adult, string children) {
	reverse(adult.begin(), adult.end());
	reverse(children.begin(), children.end());
	string temp = (adult.length() > children.length() ? adult : children);
	if (children.length() < adult.length()) {
		int c_l = children.length();
		for (int i = c_l; i < adult.length(); i++) {
			children += '0';
		}
	}
	else if (children.length() > adult.length()) {
		int a_l = adult.length();
		for (int i = a_l; i < children.length(); i++) {
			adult += '0';
		}
	}
	children += '0';
	adult += '0';
	temp += '0';
	int c = 0;
	for (int i = 0; i < temp.length(); i++) {
		int cur_sum = children[i] + adult[i] - '0' - '0' + c;
		c = (cur_sum - 9 > 0 ? 1 : 0);
		if (cur_sum > 9) {
			cur_sum -= 10;
		}
		temp[i] = cur_sum + '0';
	}
	int count = temp.length();
	while (count > 0 && temp[count - 1] == '0') {
		count--;
	}
	string sum = temp.substr(0, count);
	reverse(sum.begin(), sum.end());
	return sum;
}

string get_single_mul(string a, char b) {
	string sum = "0";
	int n = b - '0';
	for (int i = 0; i < n; i++) {
		sum = get_sum(sum, a);
	}
	return sum;
}

string get_mul(string a, string b) {
	string sum = "0";
	string mul = "0";
	reverse(b.begin(), b.end());
	for (int i = 0; i < b.length(); i++) {
		mul = get_single_mul(a, b[i]);
		for (int j = 0; j < i; j++) {
			mul += "0";
		}
		sum = get_sum(sum, mul);
	}
	return sum;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		string ans = get_mul(a, b);
		if (ans.length() == 0) {
			cout << 0 << endl;
		}
		else {
			cout << get_mul(a, b) << endl;
		}
	}
}
*/

/*
// 1029
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

string adult;

string get_sum(string adult, string children) {
	reverse(adult.begin(), adult.end());
	reverse(children.begin(), children.end());
	string temp = (adult.length() > children.length() ? adult : children);
	if (children.length() < adult.length()) {
		int c_l = children.length();
		for (int i = c_l; i < adult.length(); i++) {
			children += '0';
		}
	}
	else if (children.length() > adult.length()) {
		int a_l = adult.length();
		for (int i = a_l; i < children.length(); i++) {
			adult += '0';
		}
	}
	children += '0';
	adult += '0';
	temp += '0';
	int c = 0;
	for (int i = 0; i < temp.length(); i++) {
		int cur_sum = children[i] + adult[i] - '0' - '0' + c;
		c = (cur_sum - 9 > 0 ? 1 : 0);
		if (cur_sum > 9) {
			cur_sum -= 10;
		}
		temp[i] = cur_sum + '0';
	}
	int count = temp.length();
	while ( count > 0 && temp[count-1] == '0') {
		count--;
	}
	string sum = temp.substr(0, count);
	reverse(sum.begin(), sum.end());
	return sum;
}

string children[20];

int main() {
	int m, d;
	while (true) {
		cin >> m >> d;
		if (m == 0) {
			return 0;
		}
		int temp_count = m;
		for (int i = 0; i < 20; i++) {
			children[i] = "0";	// 还有i个月长大的孩子的个数
		}
		children[m] = "1";
		adult = "1";
		for (int i = 1; i < d; i++) {
			adult = get_sum(children[1], adult);
			for (int k = 1; k < m; k++) {
				children[k] = children[k + 1];
			}
			children[m] = adult;
		}
		string sum = "0";
		for (int i = 1; i <= m; i++) {
			sum = get_sum(sum, children[i]);
		}
		cout << get_sum(sum, adult) << endl;
	}
}
*/
/*
// 1028
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;

int a[110];

int main() {
	int T;
	cin >> T;
	int C = 0;
	while (T--) {
		C++;
		string str;
		cin >> str;
		int k = 2;
		int count = 1;
		//str是大数，求str%k,ans即为结果
		int ans = 0;
		for (int i = str.length()-1; i >= 0; i--) {
			a[i] = int(str[str.length()-i-1] - '0');
		}
		int l = str.length()-1;
		while (a[0] % 2 == 0) {
			int rem = 0;
			while (a[l] == 0) l--;
			for (int i = l; i >= 0; i--) {
				a[i] = a[i] + rem * 10;
				rem = a[i] % 2;
				a[i] /= 2;
			}
			count++;
		}
		cout << "Case " << C << ": " << count << endl;
		if (T > 0) {
			cout << endl;
		}
	}
}
*/
/*
// 1438
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
		sort(v, v + n, cmp);
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
*/

/*
// 1134
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;



struct puzzle {
	long long has_get;
	long long to_get;
};

puzzle puz[10050];

struct Cmp {
	bool operator ()(puzzle a, puzzle b) {
		return a.to_get < b.to_get;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		long long s;
		cin >> s;
		for (int i = 0; i < n; i++) {
			cin >> puz[i].has_get >> puz[i].to_get;
		}
		bool flag = true;
		sort(puz, puz + n,Cmp());
		for (int i = 0; i < n; i++) {
			if (s < puz[i].to_get) {
				cout << "NO" << endl;
				flag = false;
				break;
			}
			s += puz[i].has_get;
		}
		if (flag) {
			cout << "YES" << endl;
		}
	}
}
*/

/*
// 1093
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



void print(int w, int p, int add) {
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
					temp_cost[i] = cost[i] * (weight[i - 1] + 1);
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
			else {
				print(n, cost[3] * n, 0);
			}
		}
		cout << endl;
	}
}
*/


/*
// 1152
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

const int N = 5;//棋盘的边长
const int M = 6;
int chess[N][M];//标记
vector<int> order;
void showTrail() {
	int count = 1;
	while (count <= 30) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (count == chess[i][j]) {
					cout << i * 6 + j + 1;
					if (count < 30) {
						cout << " ";
					}
					count++;
				}
			}
		}
	}
	cout << endl;

}

bool flag = false;

void dfs(int x, int y, int cnt) {
	if (cnt == N * M) {
		showTrail();
		flag = true;
		return;
	}
	if (flag) {
		return;
	}
	for (int i = 0; i<8; ++i) {
		int move[8][2] = { { 1,-2 },{ 2,-1 },{ 2,1 },{ 1,2 },{ -1,2 },{ -2,1 },{ -2,-1 },{ -1,-2 } };
		int x1 = x + move[i][0];
		int y1 = y + move[i][1];
		if (0 == chess[x1][y1] && x1 >= 0 && x1<N&&y1 >= 0 && y1<M) {
			chess[x1][y1] = cnt + 1;
			dfs(x1, y1, cnt + 1);
			chess[x1][y1] = 0;
		}
	}
	return;
}


int main()
{
	int start;
	while (true) {
		cin >> start;
		if (start <= -1 || start > 30) {
			return 0;
		}
		flag = false;
		int x = (start - 1) / 6;
		int y = (start - 1) % 6;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				chess[i][j] = 0;
			}
		}
		chess[x][y] = 1;
		order.push_back(start);
		dfs(x, y, 1);
	}
}
*/