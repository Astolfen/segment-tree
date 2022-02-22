#include <iostream>
#include <vector>

#define MAX_SIZE_SEGMENT 8

typedef std::vector<int> IntVector;


void build_segment_tree_(IntVector &segment, IntVector &segment_tree, int iWrite, int sl, int sr) {
    if (sl == sr)
        segment_tree[iWrite] = segment[sl];
    else {
        int sm = sl + (sr - sl) / 2;
        build_segment_tree_(segment, segment_tree, iWrite * 2, sl, sm);
        build_segment_tree_(segment, segment_tree, iWrite * 2 + 1, sm + 1, sr);
        segment_tree[iWrite] = segment_tree[iWrite * 2] + segment_tree[iWrite * 2 + 1];
    }
}

void build_segment_tree(IntVector &segment, IntVector &segment_tree) {
    build_segment_tree_(segment, segment_tree, 1, 0, MAX_SIZE_SEGMENT - 1);
}

//void sum_segment_tree(){
//
//}
//
//void set_segment_tree(){
//
//}

int main() {
    std::vector<int> segment(MAX_SIZE_SEGMENT);
    std::vector<int> segment_tree(4 * MAX_SIZE_SEGMENT);

    //ввод вектора по которому строим дерево
    for (auto &x: segment)
        std::cin >> x;

    build_segment_tree(segment, segment_tree);

    for (auto &x: segment_tree)
        std::cout << x << ' ';
}
