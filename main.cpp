#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<long long> LongLongVector;

struct segment_tree {
    vector<long long> tree;
    int size = 1;
    int arraySize = 0;//размер массива по которому строили дерево
    //пусть дерево начинаеться с 1 для простоты обращения

private:
    void build_tree(LongLongVector &a, int n) {
        int w = n / 2;
        for (int i = 0; i < arraySize; i++) tree[w + i] = a[i];
        while (w > 1) {
            w--;
            tree[w] = tree[w * 2] + tree[w * 2 + 1];
        }
    }

public:
    /// Builds a tree based on the array
    /// \param a vector by which the tree is built
    void build_tree(LongLongVector &a) {
        arraySize = a.size();
        while (size < arraySize) size *= 2;
        size *= 2;
        tree.assign(size, 0);
        build_tree(a, size);
    }

    /// Changes the value of the variable located at the index index to x
    /// \param index index of the variable to be replaced
    /// \param x the value to change to array
    void change(int index, int x) {
        int w = size / 2;
        tree[w + index] = x;
        while (w > 1) {
            w /= 2;
            tree[w] = tree[w * 2] + tree[w * 2 + 1];
        }
    }
};

int main() {
    segment_tree st;
    vector<long long> a = {1, 2, 4, 3, 5, 6, 7, 8};

    st.build_tree(a);

    for (int i = 0; i < st.size; i++)
        cout << st.tree[i] << ' ';

    st.change(0, 2);

    for (int i = 0; i < st.size; i++)
        cout << st.tree[i] << ' ';

    return 0;
}
