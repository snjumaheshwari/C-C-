#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
#define MOD 1000000007
#define INF 1000000000


// calculate sum of all distinct prime factors in a given range
bool P[1000001];
int sumofprimes[1000001];
LL primesum[1000001];

void getprimes() {
	memset(sumofprimes, 0, sizeof sumofprimes);
	for (int i = 0; i <= 1000000; ++i) {
		P[i] = true;
	}
	P[0] = 0;
	P[1] = 0;
	sumofprimes[0] = 0;
	sumofprimes[1] = 0;
	for (int i = 2; i <= 1000000; ++i) {
		if (!P[i]) {
			continue;
		}
		sumofprimes[i] = i;
		for (int j = i + i; j <= 1000000; j += i) {
			P[j] = false;
			sumofprimes[j] += i;
		}
	}
}

void precompute() {
	getprimes();
	primesum[0] = 0;
	primesum[1] = 0;
	for (int i = 2; i <= 1000000; ++i) {
		primesum[i] = (primesum[i - 1] + sumofprimes[i]) % MOD;
	}
}

int main() {
	precompute();
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int x, y;
		cin >> x >> y;
		cout << (primesum[y] + MOD - primesum[x - 1]) % MOD << "\n";
	}
	return 0;
}