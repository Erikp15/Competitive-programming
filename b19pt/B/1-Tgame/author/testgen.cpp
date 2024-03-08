#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <random>
using namespace std;

struct node{
    int l, r;
};

int root;
vector<node> tree;

default_random_engine generator;

void print(string filename, int m){
    ofstream out(filename);
    vector<int> ind, rev;
    for (int i=0; i<tree.size(); ++i){
        ind.push_back(i+1);
    }
    random_shuffle(ind.begin(), ind.end());
    for (int i=0; i<ind.size(); ++i){
        if (ind[i] == 1){
            swap(ind[i], ind[root]);
            break;
        }
    }
    rev.resize(ind.size());
    for (int i=0; i<ind.size(); ++i){
        rev[ind[i]-1] = i;
    }
    out<<ind.size()<<" "<<m<<"\n";
    for (int i: rev){
        if (tree[i].l == -1) out<<"-1\n";
        else out<<ind[tree[i].l]<<" "<<ind[tree[i].r]<<"\n";
    }
}

void gen_balanced(int ind, int d){
    if (d == 0) return;
    tree[ind].l = tree.size();
    tree[ind].r = tree.size()+1;
    tree.push_back({-1, -1});
    tree.push_back({-1, -1});
    gen_balanced(tree[ind].l, d-1);
    gen_balanced(tree[ind].r, d-1);
}

void gen_deep(int ind, int l){
    if (l==1) return;
    tree[ind].l = tree.size();
    tree[ind].r = tree.size()+1;
    tree.push_back({-1, -1});
    tree.push_back({-1, -1});
    if (rand()%2){
        gen_deep(tree[ind].l, 1);
        gen_deep(tree[ind].r, l-1);
    }else{
        gen_deep(tree[ind].l, l-1);
        gen_deep(tree[ind].r, 1);
    }
}

void gen_random(int ind, int l, double div){
    if (l==1) return;
    tree[ind].l = tree.size();
    tree[ind].r = tree.size()+1;
    tree.push_back({-1, -1});
    tree.push_back({-1, -1});
    normal_distribution<double> distribution(l/2.0, l/div+1);
    int split;
    do{
        split = distribution(generator);
    }while(split < 1 || split > l-1);

    gen_random(tree[ind].l, split, div);
    gen_random(tree[ind].r, l-split, div);
}

void balanced(string filename, int depth, int m){
    tree.clear();
    root = 0;
    tree.push_back({-1, -1});
    gen_balanced(0, depth);
    print(filename, m);
}

void deep(string filename, int leafs, int m){
    tree.clear();
    root = 0;
    tree.push_back({-1, -1});
    gen_deep(0, leafs);
    print(filename, m);
}

void randomt(string filename, int leafs, double div, int m){
    tree.clear();
    root = 0;
    tree.push_back({-1, -1});
    gen_random(0, leafs, div);
    print(filename, m);
}

void deep_rand(string filename, int leafs, double div, int m){
    tree.clear();
    root = 0;
    tree.push_back({1, 2});
    tree.push_back({-1, -1});
    tree.push_back({-1, -1});
    int sm_random = leafs/20+1, bg_random = leafs/3+1, dp = leafs - sm_random - bg_random;
    gen_random(1, sm_random, div);
    int cand = 1;
    if (sm_random > 1){
        for (int i=3; i<tree.size(); ++i){
            if (tree[i].l==-1){
                cand = i;
                break;
            }
        }
    }
    gen_deep(cand, dp);
    gen_random(2, bg_random, div);
    print(filename, m);
}

int main(){
    srand(42);
    balanced("tests/test00.in", 10, 500);
    balanced("tests/test01.in", 10, 700);
    balanced("tests/test02.in", 11, 1200);
    balanced("tests/test03.in", 11, 900);
    balanced("tests/test04.in", 11, 1027);
    balanced("tests/test05.in", 11, 700);

    randomt("tests/test06.in", 50, 2.0, 15);
    deep_rand("tests/test07.in", 50, 2.0, 15);
    randomt("tests/test08.in", 50, 5.0, 20);
    randomt("tests/test09.in", 50, 0.2, 10);
    randomt("tests/test10.in", 50, 0.2, 10);
    randomt("tests/test11.in", 50, 0.1, 15);

    randomt("tests/test12.in", 2500, 2.0, 1000);
    randomt("tests/test13.in", 2500, 1.0, 700);
    randomt("tests/test14.in", 2500, 1.0, 600);
    randomt("tests/test15.in", 2500, 0.1, 500);
    randomt("tests/test16.in", 2500, 0.5, 700);
    randomt("tests/test17.in", 2500, 5.0, 1000);
    deep_rand("tests/test18.in", 2500, 2.0, 500);
    deep_rand("tests/test19.in", 2500, 5.0, 600);
    return 0;
}
