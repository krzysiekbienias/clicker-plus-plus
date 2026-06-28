#pragma
#include <vector>

class MinHeap {


public:
    MinHeap()=default;
    explicit MinHeap(std::vector <int> data);
    int peek() const;
    int extractMin(); //cannot be const because it will modify the object's state
    int getSize() const;
    void insert(int val);

    // read-only view of backing array (useful for tests / debugging heapify)
    const std::vector<int>& asArray() const { return m_heap; }
private:
    std::vector<int> m_heap;
    void _heapify();
    void _siftDown(int currentIdx,int endIdx);
    void _siftUp(int i);

};