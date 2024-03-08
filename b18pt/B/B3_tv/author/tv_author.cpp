#include <bits/stdc++.h>
#define f(i, a, n) for(int i = a; i < n; i++)
using namespace std;

const int MAXLEN = 1<<19;
int n, q, len;
string s, s2;

int plusPref[MAXLEN];
int nexxt[MAXLEN];


inline char inv(char c) {
    return (c=='+')?'-':'+';
}

int tree[2*MAXLEN];
int lazy[2*MAXLEN]; // if lazy = x the node should be multiplied by (-1)^x

void update(int idx, int by) {
    idx += MAXLEN;
    while(idx > 0) {
        tree[idx] += by;
        idx /= 2;
    }
}

int getNode(int idx) {
    int res = tree[idx];
    if(lazy[idx] % 2 == 1) res *= -1;
    return res;
}

void _update(int idx, int leftRange, int rightRange, int left, int right, int by) {
    if (idx < MAXLEN && lazy[idx] %2 == 1) {
        tree[idx] *= -1;

        lazy[idx*2] += lazy[idx];
        lazy[idx*2+1] += lazy[idx];
        lazy[idx] = 0;
    }

    if (left <= leftRange && rightRange-1 <= right) {
        tree[idx] *= -1;
        if(idx < MAXLEN) {
            lazy[idx*2]++;
            lazy[idx*2+1]++;
        }
        return;
    }

    if (right < leftRange || rightRange-1 < left) return;

    _update(2*idx,     leftRange, (leftRange + rightRange)/2, left, right, by);
    _update(2*idx + 1, (leftRange + rightRange)/2, rightRange, left, right, by);

    tree[idx] = getNode(2*idx) + getNode(2*idx+1);
}


void updateMult(int left, int right, int by) {
    _update(1, 0, MAXLEN, left, right, by);
}



int _query(int idx, int leftRange, int rightRange, int left, int right) {
    if (idx < MAXLEN && lazy[idx] % 2 == 1) {
        tree[idx] *= -1;
        lazy[idx*2] += lazy[idx];
        lazy[idx*2+1] += lazy[idx];
        lazy[idx] = 0;
    }

    if (left <= leftRange && rightRange-1 <= right) {
        return getNode(idx);
    }

    if (right < leftRange || rightRange-1 < left) return 0;

    return _query(2*idx,     leftRange, (leftRange + rightRange)/2, left, right) +
        _query(2*idx + 1, (leftRange + rightRange)/2, rightRange, left, right);
}

int query(int left, int right) {
    return _query(1, 0, MAXLEN, left, right);
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> q;
    cin >> s;

    len = s.size();

    int nextCurr = len;
    f(i, 0, len) {
        if(s[len-1-i] != 'o') nextCurr = len-1-i;
        nexxt[len-1-i] = nextCurr;
    }

    s2 = s;
    f(i, 0, len) {
        if(s[i] == 'o') {
            s2[i] = inv(s2[i-1]);
        }
    }

    f(i, 0, len) {
        if(s2[i] == '+') {
            update(i, 1);
        } else {
            update(i, -1);
        }
    }

    f(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        l = nexxt[l];

        if(s[r]=='o') r = nexxt[r]-1;
        if(r < len && s[r+1]=='o') r = nexxt[r+1]-1;
        updateMult(l, r, 1);

        int res = query(0, MAXLEN-1);
        //cout << "res is " << res << endl;
        //cout << endl;
        //f(k, 0, len)
        //    cout << (query(k, k)==1?'+':'-');
        //cout << endl;

        while(res < 0) res += n;
        res %= n;
        res++;

        cout << res << endl;
    }

    return 0;
}
/**
100 3
+++++-
1 1
2 2
6 6

*/
