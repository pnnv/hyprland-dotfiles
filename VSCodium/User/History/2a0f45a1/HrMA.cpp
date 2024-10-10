#include <iostream>
#include <vector>
#include <cmath>

class SegmentTree {
private:
    std::vector<int> tree;
    int n;

    void buildTree(const std::vector<int>& arr, int treeIndex, int lo, int hi) {
        if (lo == hi) {  // leaf node
            tree[treeIndex] = arr[lo];
            return;
        }

        int mid = lo + (hi - lo) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        buildTree(arr, leftChild, lo, mid);
        buildTree(arr, rightChild, mid + 1, hi);

        tree[treeIndex] = std::min(tree[leftChild], tree[rightChild]);
    }

    void updateTree(int treeIndex, int lo, int hi, int arrIndex, int value) {
        if (lo == hi) {  // leaf node
            tree[treeIndex] = value;
            return;
        }

        int mid = lo + (hi - lo) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        if (arrIndex > mid) {
            updateTree(rightChild, mid + 1, hi, arrIndex, value);
        } else {
            updateTree(leftChild, lo, mid, arrIndex, value);
        }

        tree[treeIndex] = std::min(tree[leftChild], tree[rightChild]);
    }

    int queryTree(int treeIndex, int lo, int hi, int i, int j) {
        if (lo > j || hi < i) {  // range represented by a node is completely outside the given range
            return INT_MAX;
        }

        if (i <= lo && hi <= j) {  // range represented by a node is completely inside the given range
            return tree[treeIndex];
        }

        int mid = lo + (hi - lo) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        int leftQuery = queryTree(leftChild, lo, mid, i, j);
        int rightQuery = queryTree(rightChild, mid + 1, hi, i, j);

        return std::min(leftQuery, rightQuery);
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        int height = static_cast<int>(std::ceil(std::log2(n)));
        int maxSize = 2 * (1 << height) - 1;
        tree.resize(maxSize);
        buildTree(arr, 0, 0, n - 1);
    }

    void update(int arrIndex, int value) {
        updateTree(0, 0, n - 1, arrIndex, value);
    }

    int query(int i, int j) {
        return queryTree(0, 0, n - 1, i, j);
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    std::cout << "Minimum value in range [1, 5]: " << segTree.query(1, 5) << std::endl;
    segTree.update(1, 0);
    std::cout << "Minimum value in range [1, 5] after update: " << segTree.query(1, 5) << std::endl;

    return 0;
}
