#include <vector>
#include "heap/min_heap_api.hpp"

//constructor
MinHeap::MinHeap(std::vector<int> data) :m_heap(std::move(data)){_heapify();}

int MinHeap::peek() const {
    if(m_heap.empty()){
        throw std::out_of_range("Peek on empty heap.");
    } 
    return m_heap.front();
}


void MinHeap::_heapify() { //build heap
    //need to run siftDown
    int n=(int)m_heap.size();
    for (int i=(n-2)/2;i>=0;--i){
        // (n-2)/2 indeks ostatniego wezla ktory jest nie lisciem 
        _siftDown(i,n-1);
    }
}

void MinHeap::_siftDown(int currentIdx,int endIdx) {
    
    // check what is inside heap until we have left child, we don't care about right child -> heap definition
    while (2*currentIdx+1<=endIdx){
        int leftChildIdx=2*currentIdx+1;
        int rightChildIdx=2*currentIdx+2;

        int swapWith=currentIdx;
        if(m_heap[leftChildIdx]<m_heap[swapWith]){
            swapWith=leftChildIdx;
        }

        if(rightChildIdx<=endIdx&& m_heap[rightChildIdx]<m_heap[swapWith]){//right might not exist left is guaranteed 
            swapWith=rightChildIdx;
        }

        if (swapWith==currentIdx)
             break;
        std::swap(m_heap[currentIdx],m_heap[swapWith]);
        currentIdx=swapWith;
    }
}

void MinHeap::_siftUp(int idx){
    while (idx>0){
        int parent=(idx-1)/2;
        if(m_heap[idx]>=m_heap[parent]){ //parent is in right place with respect to idx
            break;
        }
        std::swap(m_heap[idx],m_heap[parent]);
        idx=parent; //go up
    }

}

int MinHeap::extractMin() {
    if (m_heap.empty())
         throw std::out_of_range("You cannot extract min from empty heap");
        // we want to remove first element in O(log n) but we may only remove in vector last element
    int v=m_heap.front();
    m_heap.front()=m_heap.back();
    m_heap.pop_back();
    int n=(int)m_heap.size();
    if(!m_heap.empty()){
        _siftDown(0,n-1);
    }
    return v;
}

void MinHeap::insert(int val){
    //append na sermater a potem odpal siftup
    m_heap.push_back(val);
    int n =(int)m_heap.size();
    _siftUp(n-1);
}

