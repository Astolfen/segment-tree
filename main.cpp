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

    long long sum(int l, int r, int w) {
        long long res = 0;
        if (l == r)
            return tree[w + r];
        while (l < r) {
            if (l % 2 == 1) {
                res += tree[w + l];
                l++;
            }
            if (r % 2 == 0) {
                res += tree[w + r];
                r--;
            }
            w /= 2;
            l /= 2;
            r /= 2;
        }
        if (l == r) {
            res += tree[w + r];
        }
        return res;
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
    void change(int index, int x) {  //alternative name: set
        int w = size / 2;
        tree[w + index] = x;
        while (w > 1) {
            w /= 2;
            tree[w] = tree[w * 2] + tree[w * 2 + 1];
        }
    }

    long long sum(int l, int r) {
        int w = size / 2;
        return sum(l, r, w);
    }
};

int main() {
    segment_tree st;
    vector<long long> a = {1, 2, 3, 4, 5, 6, 7, 8};

    st.build_tree(a);

    for (int i = 0; i < st.size; i++)
        cout << st.tree[i] << ' ';

//    st.change(0, 2);

    cout << endl;

//    for (int i = 0; i < st.size; i++)
//        cout << st.tree[i] << ' ';

    int l = 2;//проюлемы с нулем бесконечный цикл //1-2,1-4
    int r = 3;
    long long sum = st.sum(l, r);
    cout << sum;

    return 0;
}
