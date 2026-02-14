#include <cstring>
#include <iostream>
using namespace std;
int main() {
    freopen("foto2.in", "r", stdin);
	int n;
	cin >> n;
	int moved[n] = {0};
	int a[n], b[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}

	int res = 0;
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j < n && moved[a[j]]) { j++; }

		if (a[j] == b[i]) {
			j++;
		} else {
			res++;
			moved[b[i]] = 1;
		}
	}

	cout << res << '\n';
}