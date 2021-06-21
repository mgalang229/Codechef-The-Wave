#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// sort the sequence in non-decreasing order
	sort(a.begin(), a.end());
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		int low = 0;
		int high = n - 1;
		bool zero = false;
		int pos = -1;
		// find the correct position of 'x' in the sequence using binary search
		while (low <= high) {
			int mid = (low + high) / 2;
			if (a[mid] == x) {
				// if 'x' is equal to a number in the sequence, break the loop
				// and set 'zero' to true (polynomial expression will be equal to 0)
				zero = true;
				break;
			} else if (a[mid] > x) {
				// if the current number is greater than 'x', then check if the previous number is less than 'x'
				if (a[mid - 1] < x) {
					// if yes, then store the value of 'mid' in 'pos' and break the loop
					pos = mid;
					break;
				}
				// otherwise, continue the binary search
				high = mid - 1;
			} else {
				// if the current number is less than 'x', then check if the next number is less than 'x'
				if (a[mid + 1] > x) {
					// if yes, then store the value of 'mid' + 1 to 'pos' and break the loop
					pos = mid + 1;
					break;
				}
				// otherwise, continue the binary search
				low = mid + 1;
			}
		}
		if (zero) {
			// if 'zero' is true, then output 0
			cout << 0;
		} else if (pos == -1) {
			// if 'pos' is equal to -1, then check if 'x' is the smallest or largest number
			// if it's the largest, then output POSITIVE
			// otherwise, if it's the smallest, then check if the number of elements in the
			// sequence is even, and if it's even then output POSITIVE, otherwise NEGATIVE
			cout << (x > a.back() ? "POSITIVE" : (int) a.size() % 2 == 0 ? "POSITIVE" : "NEGATIVE");
		} else {
			// if the difference of 'n' and 'pos' (numbers greater than 'x') is even then
			// output POSITIVE, otherwise, NEGATIVE
			cout << ((n - pos) % 2 == 0 ? "POSITIVE" : "NEGATIVE");
		}
		cout << '\n';
	}
	return 0;
}
