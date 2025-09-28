#pragma
#include <vector>

class MinHeap {


public:
    MinHeap()=default;
    explicit MinHeap(std::vector <int> data);
    int peek() const;
    int extractMin(); //cannot be const because it will modify the object's state
    int getSize() const;
    void insert(int n);
private:
    std::vector<int> m_heap;
    void heapify();
    void siftDown(int i);
    void siftUp(int i);

};