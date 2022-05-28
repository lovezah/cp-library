#include<iostream>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(x) : gives the x-th element in sorted order, if x = 2, gives the third smallest value;
// order_of_key(x) : return the count of element < x

int main () {
	int Q;
	cin >> Q;

	ordered_set<int> st;
	for(int q = 0; q < Q; q++) {
		string op;
		int x;
		cin >> x;
		if(op == "I") {
			st.insert(x);
		} else if(op == "D") {
			st.erase(x);
		} else if(op == "K") {
			x--;
			if(x >= int(st.size())) {
				cout << "invalid" << "\n";
			} else {
				cout << *st.find_by_order(x) << "\n";
			}
		} else {
			cout << int(st.order_of_key(x)) << "\n";
		}
	}
}