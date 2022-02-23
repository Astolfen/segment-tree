#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<long long> LongLongVector;

struct segment_tree {
    vector<long long> tree;
    int size = 1;
    //пусть дерео начинаеться с 1 для простоты обращения

    void build_tree(LongLongVector &a, int n) {
        int w = n / 2 + n % 2;
        for (int i = 0; i < a.size(); i++) tree[w + i] = a[i];
        while (w > 1) {
            w--;
            tree[w] = tree[w * 2] + tree[w * 2 + 1];
        }
    }

    void build_tree(LongLongVector &a) {
        while (size < a.size()) size *= 2;
        size *= 2;
        tree.assign(size, 0);
        build_tree(a, size);
    }

};

int main() {
    segment_tree st;
    vector<long long> a = {1, 2, 4, 3, 5, 6};

    st.build_tree(a);

    for (int i = 0; i < st.size; i++)
        cout << st.tree[i] << ' ';

    return 0;
}
