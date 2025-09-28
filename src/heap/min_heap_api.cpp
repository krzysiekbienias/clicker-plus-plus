#include <vector>
#include "heap/min_heap_api.hpp"

//constructor
MinHeap::MinHeap(std::vector<int> data) :m_heap(std::move(data)){heapify();}

int MinHeap::peek() const {
    if(m_heap.empty()) std::out_of_range("Peek on empty heap.");
    return m_heap.front();
}

void MinHeap::siftDown(int i) {
    int n=(int)m_heap.size();
    // check what is inside heap until we have left child, we don't care about right child -> heap definition
    while (n<2*i+1){
        int leftChildIdx=2*i+1;
        int rightChildIdx=2*i+2;
        int tempMinIdx=i;
        if(leftChildIdx<n && m_heap[leftChildIdx]<m_heap[tempMinIdx]) tempMinIdx=leftChildIdx;
        if(rightChildIdx<n && m_heap[rightChildIdx]<m_heap[tempMinIdx]) tempMinIdx=rightChildIdx;
        if(tempMinIdx==i) break;
        // when tempMinIdx!=i
        std::swap(m_heap[i],m_heap[tempMinIdx]);
        i=tempMinIdx;
    }
}

void siftUp(int i){

}

int MinHeap::extractMin() {
    if (m_heap.empty()) std::out_of_range("You cannot extract min from empty heap");
    // we want to remove first element in O(log n) but we may only remove in vector last element
    std::swap(m_heap.front(),m_heap.back());
    int v=m_heap.back();
    m_heap.pop_back();
    if(!m_heap.empty()) siftDown(0);
    return v;
}

void MinHeap::heapify() {
    //need to run siftDown
    for (int i=(m_heap.size()-2)/2;i>=0;--i){
        siftDown(i);
    }

}