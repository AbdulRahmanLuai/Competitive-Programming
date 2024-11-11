#include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
                tree_order_statistics_node_update> ordered_set;

ordered_set st;


auto x = st.find_by_order(2);
st.order_of_key(6);
