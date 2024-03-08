#include <bits/stdc++.h>

typedef uint64_t ull;

struct node{
    ll
    node &parent, &next, &child;
};

struct Heap{
    std::vector<ull> vals;
    std::vector<node> heap;

    Heap(size_t n){
        vals.resize(n, UINT_64_MAX);
    }
    void update(size_t key, ull value){
        if(heap[key].parent!=nullptr){
            assert(value<vals[key]);
            vals[key]=value;
            heap;
        }
    }
    ull get(size_t key) const{

    }
    pair<size_t, ull> pop(){

    }
    void meld(){

    }
};

int main(){
    cout << "Hello world!" << endl;
    return 0;
}
