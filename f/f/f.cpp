#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
void write(vector<int> v) {
	cout << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << " - " << v[i];
	}
}

vector<int> pr(int x) {
	vector<char> prime(x + 1, true);
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= x; ++i) {
		if (prime[i] && i * 1ll * i <= x) {
			for (int j = i * i; j <= x; j += i) {
				prime[j] = 0;
			}
		}
	}
	vector<int> del;
	for (int z = 0; z <= x; ++z) {
		if (prime[z] && x % z == 0) del.push_back(z);
	}
	vector<int> res;
	int l = 0;
	while (x > 1) {
		if (x % del[l] == 0) {
			res.push_back(del[l]);
			x /= del[l];
		}
		else ++l;
	}
	return res;
}
int c(vector<int> s, vector<int> b) {
	int iter = 0;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			if (s[i] == b[j]) {
				s[i] = b[j] = 0;
				break;
			}
		}
	}
	for (int j = 0; j < s.size(); ++j) {
		if (s[j] != 0) {
			++iter;
		}
	}
	for (int j = 0; j < b.size(); ++j) {
		if (b[j] != 0) {
			++iter;
		}
	}
	return iter;
}

int main() {

	int n, m; cin >> n >> m;
	vector<int> nv, mv;
	nv = pr(n); mv = pr(m);
	if (nv.size() > mv.size()) cout << c(mv, nv);
	else cout << c(nv, mv);

}//hiiiiiiii 3242