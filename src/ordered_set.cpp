
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(x) : gives the x-th element in sorted order, if x = 2, gives the third smallest value;
// order_of_key(x) : return the count of element < x

