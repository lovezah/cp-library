#include<bits/stdc++.h>

using namespace std;

template<typename T, typename T_compare>
vector<int> closest_left(const vector<T> &values, T_compare &&compare) {
	int n = int(values.size());
	vector<int> closest(n);
	vector<int> stack;

	for(int i = 0; i < n; i++) {
		while(!stack.empty() && !compare(values[stack.back()], values[i]))
			stack.pop_back();

		closest[i] = stack.empty() ? -1 : stack.back();
		stack.push_back(i);
	}

	return closest;
}

template<typename T, typename T_compare>
vector<int> closest_right(vector<T> values, T_compare &&compare) {
	int n = int(values.size());
	reverse(values.begin(), values.end());
	vector<int> closest = closest_left(values, compare);
	reverse(closest.begin(), closest.end());

	for(auto &c : closest)
		c = n - 1 - c;

	return closest;
}

int main () {
	int N;
	cin >> N;

	vector<int> values(N);
	for(auto &value : values)
		cin >> value;

	auto output_closest = [&](auto compare) -> void {
		vector<int> left = closest_left(values, compare);
		vector<int> right = closest_left(values, compare);

		for(int i = 0; i < N; i++)
			cout << left[i] << " " << right[i] << " \n"[i == N - 1];
	};

	output_closest(less<int>());
	output_closest(greater<int>());
	output_closest(less_equal<int>());
	output_closest(greater_equal<int>());

}