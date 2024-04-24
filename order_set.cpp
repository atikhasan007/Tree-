#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  o_set<int> se;
  se.insert(4);
  se.insert(2);
  se.insert(5);
  se.insert(6);
  se.insert(9);
  se.insert(2);
  for(auto x : se)cout<<x<<" ";cout<<endl;
  	auto it = se.find_by_order(0);//log(n)
    cout<<*it<<endl;
    cout<< se.order_of_key(5)<<endl;//exectly 5 er nite koyta ase
    
 
  return 0;
}
