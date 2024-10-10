#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct Node {
 ll count = 0; // may change
    unordered_map<ll,ll> freq;
 Node() { // Identity element
  count = 0; // may change
        // freq.resize(20);
 }
 Node(ll p1) {  // Actual Node
  freq[p1-1]++; // may change
        count++;
 }
 void merge(Node &l, Node &r) { // Merge two child nodes
  unordered_map<ll,ll> combFreq;
        for(auto it: l.freq) combFreq[it.first]+=it.second;
        for(auto it: r.freq) combFreq[it.first]+=it.second;
        for(auto it: combFreq) if(it.second>0) count++;
        freq = combFreq;
 }
};

struct Update {
 ll val; // may change
 Update(ll p1) { // Actual Update
  val = p1; // may change
 }
 void apply(Node &a) { // apply update to given node
        for(auto &it: a.freq) it.second=0;
  a.freq[val-1]++; // may change
 }
};

struct SegTree {
 vector<Node> tree;
 vector<ll> arr; // type may change
 int n;
 int s;
 SegTree(int a_len, vector<ll> &a) { // change if type updated
  arr = a;
  n = a_len;
  s = 1;
  while(s < 2 * n){
   s = s << 1;
  }
  tree.resize(s); fill(tree.begin(), tree.end(), Node());
  build(0, n - 1, 1);
 }
 void build(int start, int end, int index)  // Never change this
 {
  if (start == end) {
   tree[index] = Node(arr[start]);
   return;
  }
  int mid = (start + end) / 2;
  build(start, mid, 2 * index);
  build(mid + 1, end, 2 * index + 1);
  tree[index].merge(tree[2 * index], tree[2 * index + 1]);
 }
 void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
 {
  if (start == end) {
   u.apply(tree[index]);
   return;
  }
  int mid = (start + end) / 2;
  if (mid >= query_index)
   update(start, mid, 2 * index, query_index, u);
  else
   update(mid + 1, end, 2 * index + 1, query_index, u);
  tree[index].merge(tree[2 * index], tree[2 * index + 1]);
 }
 Node query(int start, int end, int index, int left, int right) { // Never change this
  if (start > right || end < left)
   return Node();
  if (start >= left && end <= right)
   return tree[index];
  int mid = (start + end) / 2;
  Node l, r, ans;
  l = query(start, mid, 2 * index, left, right);
  r = query(mid + 1, end, 2 * index + 1, left, right);
  ans.merge(l, r);
  return ans;
 }
 void make_update(int index, ll val) {  // pass in as many parameters as required
  Update new_update = Update(val); // may change
  update(0, n - 1, 1, index, new_update);
 }
 Node make_query(int left, int right) {
  return query(0, n - 1, 1, left, right);
 }
};



int GetAnswer(int N, int Q, int C, vector <int> A, vector <vector <int>> P) {
	set <int> st;
	vector <int> pre(N + 2), suf(N + 2);
	for(int i = 0; i < N; i++) {
		st.insert(A[i]);
		pre[i + 1] = st.size();
	}
	st.clear();
	for(int i = N - 1; i >= 0; i--) {
		st.insert(A[i]);
		suf[i + 1] = st.size();
	}
	for(int i = 1; i < pre.size(); i++) pre[i] += pre[i - 1];
	for(int i = suf.size() - 2; i >= 0; i--) suf[i] += suf[i + 1];

	long long ans = 0;
	for(int i  = 0; i < Q; i++) {
		ans += (pre[P[i][0] - 1] + suf[P[i][1] + 1]);
	}

	return ans;
}

void solve()
{
    ll n,q,c;
    cin>>n>>q>>c;
    vector <int>  a(n);
    for(auto &i: a) cin >> i;
    // SegTree tree = SegTree(n,a);
	vector <vector <int>> P(q);

    ll ans = 0;
    for(int i = 0; i < q; i++)
    {
        ll l,r;
        cin>>l>>r;
		P[i].push_back(l);
		P[i].push_back(r);
        
    }

	cout << GetAnswer(n, q, c, a, P) << endl;

}

int main() {
	solve();
}