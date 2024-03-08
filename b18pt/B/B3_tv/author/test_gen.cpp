#include <bits/stdc++.h>
#define f(i, a, n) for(int i = a; i < n; i++)
#define D(x) cerr << "at " << __LINE__ << #x << " = " << (x) << endl;
using namespace std;

const string PROBLEM_NAME = "remote";
const int NUM_TESTS = 20;

enum TestSize {
    BIG,
    SQRT,
    SMALL
};

int getRandom(int minV, int maxV) {
    return rand() %(maxV - minV) + minV;
}

template<typename T>
T getRandom(vector<T> options) {
    return options[getRandom(0, options.size())];
}

template<typename T>
T getRandom(initializer_list<T> options) {
    return getRandom(vector<T>(options));
}

bool getChance(double p) {
    return (rand()%1000 / 1000.0) < p;
}

string getRandomString(int minLength, int maxLength) {
    int length = getRandom(minLength, maxLength);
    string res = "";
    for(int i = 0; i < length; i++) {
        res += char('a' + getRandom(0, 26));
    }
    return res;
}

const int MAXLEN = 1<<20;
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



void generateTest(fstream& input, fstream& output, TestSize bigness, bool hasBack, bool singleElementIntervals) {

    n = getRandom(500000, 1000000);
    if(bigness == BIG) {
        len = getRandom(900000, 1000000);
        q = getRandom(90000, 100000);
    } else if(bigness == SQRT) {
        len = getRandom(90000, 100000);
        q = getRandom(90000, 100000);
    } else if(bigness == SMALL) {
        len = getRandom(500, 1000);
        q = getRandom(500, 1000);
    }

    input << n << " " << q << endl;

    memset(plusPref, 0, sizeof(int)*MAXLEN);
    memset(nexxt, 0, sizeof(int)*MAXLEN);
    memset(tree, 0, sizeof(int)*2*MAXLEN);
    memset(lazy, 0, sizeof(int)*2*MAXLEN);

    s = "";
    for(int i = 0; i < len; i++) {
        if(hasBack) {
            s += getRandom({'+', '-'});
        } else {
            if(i==0) s += getRandom({'+', '-'});
            else s += getRandom({'+', '-', 'o'});
        }
    }
    input << s << endl;

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

    for (int i = 0; i < q; i++) {
        int left, right;

        if (singleElementIntervals) {
            left = right = getRandom(0, len);
        } else {
            if(bigness == BIG) {
                int range = sqrt(len)/2;
                left = getRandom(0, range);
                right = getRandom(len-range, len);
            } else {
                left = getRandom(0, len/2);
                right = getRandom(len/2+1, len);
            }
        }
        input << left << " " << right << endl;
        left--;right--;
        left = nexxt[left];

        if(s[right]=='o') right = nexxt[right]-1;
        if(right < len && s[right+1]=='o') right = nexxt[right+1]-1;
        updateMult(left, right, 1);

        int res = query(0, MAXLEN-1);

        while(res < 0) res += n;
        res %= n;
        res++;

        output << res << endl;
    }
}

void generateTest(int testIndex) {
    fstream input(PROBLEM_NAME + "." + to_string(testIndex) + ".in", ios::out);
    fstream output(PROBLEM_NAME + "." + to_string(testIndex) + ".out", ios::out);

    bool SINGLE_ELEMENT_UPDATE = true;
    bool HAS_BACK = true;

    if (1 <= testIndex && testIndex <= 2)
        generateTest(input, output, SMALL, !HAS_BACK, !SINGLE_ELEMENT_UPDATE);
    if (3 <= testIndex && testIndex <= 4)
        generateTest(input, output, SMALL, HAS_BACK, !SINGLE_ELEMENT_UPDATE);

    if (5 <= testIndex && testIndex <= 6)
        generateTest(input, output, SQRT, !HAS_BACK, SINGLE_ELEMENT_UPDATE);
    if (7 <= testIndex && testIndex <= 8)
        generateTest(input, output, SQRT, HAS_BACK, SINGLE_ELEMENT_UPDATE);

    if (9 <= testIndex && testIndex <= 10)
        generateTest(input, output, SQRT, !HAS_BACK, !SINGLE_ELEMENT_UPDATE);
    if (11 <= testIndex && testIndex <= 14)
        generateTest(input, output, SQRT, HAS_BACK, !SINGLE_ELEMENT_UPDATE);

    if (15 <= testIndex && testIndex <= 16)
        generateTest(input, output, BIG, !HAS_BACK, !SINGLE_ELEMENT_UPDATE);
    if (17 <= testIndex && testIndex <= 20)
        generateTest(input, output, BIG, HAS_BACK, !SINGLE_ELEMENT_UPDATE);

    input.close();
    output.close();
}

void generateAll() {
    for(int i = 1; i <= NUM_TESTS; i++) {
        cout << "Generating test #" << i << endl;
        generateTest(i);
    }
}

int main() {
    srand(time(NULL));
    generateAll();
}

