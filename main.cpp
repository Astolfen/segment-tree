#include <iostream>
#include <vector>

#define MAX_SIZE_SEGMENT 8

typedef std::vector<int> IntVector;


void build_segment_tree_(IntVector &segment, IntVector &segment_tree, int w, int sl, int sr) {
    if (sl == sr)
        segment_tree[w] = segment[sl];
    else {
        int sm = sl + (sr - sl) / 2;
        build_segment_tree_(segment, segment_tree, w * 2, sl, sm);
        build_segment_tree_(segment, segment_tree, w * 2 + 1, sm + 1, sr);
        segment_tree[w] = segment_tree[w * 2] + segment_tree[w * 2 + 1];
    }
}

void build_segment_tree(IntVector &segment, IntVector &segment_tree) {
    build_segment_tree_(segment, segment_tree, 1, 0, MAX_SIZE_SEGMENT - 1);
}

//void sum_segment_tree(){
//
//}

void set_segment_tree_(IntVector &segment_tree, int w, int sl, int sr, int index, int x) {
    if (sl == sr)
        segment_tree[w] = x;
    else {
        int sm = sl + (sr - sl) / 2;
        if (index <= sm)
            set_segment_tree_(segment_tree, w * 2, sl, sm, index, x);
        else
            set_segment_tree_(segment_tree, w * 2 + 1, sm + 1, sr, index, x);
        segment_tree[w] = segment_tree[w * 2] + segment_tree[w * 2 + 1];
    }
}

void set_segment_tree(IntVector &segment_tree, int index, int x) {
    set_segment_tree_(segment_tree, 1, 0, MAX_SIZE_SEGMENT - 1, index, x);
}

int main() {
    std::vector<int> segment(MAX_SIZE_SEGMENT);
    std::vector<int> segment_tree(4 * MAX_SIZE_SEGMENT);

    //ввод вектора по которому строим дерево
    for (auto &x: segment)
        std::cin >> x;

    build_segment_tree(segment, segment_tree);

    for (auto &x: segment_tree)
        std::cout << x << ' ';

    set_segment_tree(segment_tree, 1, 2);

    std::cout << std::endl;

    for (auto &x: segment_tree)
        std::cout << x << ' ';
}
