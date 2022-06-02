#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, x;
	stack<int> st;
	cin >> n;

	if (n > 0) {
		cin >> x;
		st.push(x);

		bool imparell = n%2;
		int meitat = n/2;
		for (int i = 1; i < n; ++i) {
			cin >> x;
			if (!imparell or i != meitat) {
				if (i >= meitat) {
					if (st.top() == x) st.pop();
					else i = n-1;
				} else st.push(x);
			}
		}
	}

	if (st.empty() or n == 1) cout << "SI" << endl;
	else cout << "NO" << endl;
}
