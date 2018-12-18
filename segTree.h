/***************************************************
 * Title :
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class SegTree {
	vector<int> tree;
	vector<int> lazy;
	int n;
public:
	SegTree(int n) {
		int N = 1 << ( (int)ceil(log(n) / log(2)) + 1 );
		this->n = n;
		for (int i = 0; i < N; i++) {
			tree.push_back(0);
			lazy.push_back(0);
		}
	}

	void insert(int a, int b, int h) {
		insert(1, 0, n-1, a, b, h);
	}
	void insert(int index, int li, int hi, int a, int b, int h) {
		if (lazy[index] != 0) {
			int update = lazy[index];
			lazy[index] = 0;
			tree[index] = max(tree[index], update);
			if (li != hi) {
				lazy[2 * index] = max(lazy[2 * index], update);
				lazy[2 * index + 1] = max(lazy[2 * index + 1], update);
			}
		}		
		if (li>hi || li > b || a > hi ) {
			return;
		}
		if (li>=a && hi<=b) {
			tree[index] = max(tree[index], h);
			if (li != hi) {
				lazy[2 * index] = max(lazy[2 * index], h);
				lazy[2 * index + 1] = max(lazy[2 * index + 1], h);
			}
			return;
		}
		int mid = li + (hi - li) / 2;
		insert(2 * index, li, mid, a, b, h);
		insert(2 * index + 1, mid + 1, hi, a, b, h);
		tree[index] = max(tree[index * 2], tree[2 * index + 1]);
	}
	int query(int pos) {
		return query(1, 0, n - 1, pos);
	}
	int query(int index, int li, int hi, int pos) {
		if (lazy[index] != 0) {
			int update = lazy[index];
			lazy[index] = 0;
			tree[index] = max(tree[index], update);
			if (li!=hi) {
				lazy[2 * index] = max(lazy[2 * index], update);
				lazy[2 * index + 1] = max(lazy[2 * index + 1], update);
			}
		}
		if (li > hi || li > pos || hi < pos)return 0;
		if (pos == li && pos == hi) {
			return tree[index];
		}
		int mid = li + (hi - li) / 2;
		return max(query(2 * index, li, mid, pos), query(2 * index + 1, mid + 1, hi, pos));
	}
};