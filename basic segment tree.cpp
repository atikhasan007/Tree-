#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int a[N];
int t[N*4];//sum 



void build(int node , int b , int e ) {
   if(b == e){
    t[node] = a[b];
    return;
   }
    int l = 2*node, r = 2*node + 1;
    int mid = (b+e)/2;
    build(l, b, mid);
    build(r, mid+1, e);
    t[node] = t[l] + t[r];




}

// log2(n)
int query(int node, int b , int e , int i , int j) {
    //out of the query
  if(e<i || j<b) {
    return 0;
  }
  //inside of query
  if(b >= i && e <= j) {
    return t[node];
  }
  //interset of query

  int l = 2 * node, r = 2 * node + 1;
  int mid = (b + e) / 2;
  return query(l, b , mid, i , j) + query(r , mid+1 , e, i, j);

}
//update i to x 
void upd(int node, int b, int e, int i, int x){
 
 

 if(i<b or e<i)return ;
 if(b==e and b == i){
    t[node] = x;
    return;
 }
int l = 2 * node, r = 2 * node + 1;
 int mid = (b + e) / 2;
 upd(l, b , mid, i, x);
 upd(r, mid+1, e, i, x);
 t[node] = t[l] + t[r];

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

int n; cin >> n;

for(int i = 1; i <= n; i++){
    cin >> a[i];
}

build(1,1,n);
cout << t[1] << '\n';
cout << query(1, 1, n, 2, 4) << '\n';
upd(1, 1, n, 3 , 10);
cout << query(1, 1, n, 2, 4) << '\n';




    return 0;
}
