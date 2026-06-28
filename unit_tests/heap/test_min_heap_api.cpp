#include "heap/min_heap_api.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using std::vector;

// --------------------
// Helpers
// --------------------
static bool SatisfiesMinHeapProperty(const vector<int>& heap) {
    const int n = static_cast<int>(heap.size());
    for (int i = 0; i < n; ++i) {
        const int left = 2 * i + 1;
        const int right = 2 * i + 2;
        if (left < n && heap[i] > heap[left]) return false;
        if (right < n && heap[i] > heap[right]) return false;
    }
    return true;
}

static bool SameMultiset(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    vector<int> sa = a;
    vector<int> sb = b;
    std::sort(sa.begin(), sa.end());
    std::sort(sb.begin(), sb.end());
    return sa == sb;
}

static vector<int> DrainInSortedOrder(MinHeap& heap, int count) {
    vector<int> out;
    out.reserve(static_cast<size_t>(count));
    for (int i = 0; i < count; ++i) {
        out.push_back(heap.extractMin());
    }
    return out;
}

// --------------------
// Empty heap
// --------------------
TEST(MinHeap, DefaultConstructor_IsEmpty) {
    MinHeap heap;
    EXPECT_THROW(heap.peek(), std::out_of_range);
    EXPECT_THROW(heap.extractMin(), std::out_of_range);
}

// --------------------
// Constructor + heapify
// --------------------
TEST(MinHeap, Constructor_HeapifiesUnsortedInput) {
    MinHeap heap({9, 4, 7, 1, 3});
    EXPECT_EQ(heap.peek(), 1);
}

TEST(MinHeap, Heapify_SatisfiesMinHeapProperty) {
    const vector<int> input = {9, 4, 7, 1, 3};
    MinHeap heap(input);

    EXPECT_TRUE(SatisfiesMinHeapProperty(heap.asArray()));
    EXPECT_TRUE(SameMultiset(heap.asArray(), input));
    EXPECT_EQ(heap.asArray().front(), 1);
}

TEST(MinHeap, Heapify_ProducesExpectedArray) {
    // deterministic outcome for bottom-up siftDown heapify
    MinHeap heap({9, 4, 7, 1, 3});
    EXPECT_EQ(heap.asArray(), (vector<int>{1, 3, 7, 4, 9}));
}

TEST(MinHeap, Heapify_SmallCases) {
    MinHeap single({42});
    EXPECT_EQ(single.asArray(), (vector<int>{42}));
    EXPECT_TRUE(SatisfiesMinHeapProperty(single.asArray()));

    MinHeap three({3, 1, 2});
    EXPECT_EQ(three.asArray(), (vector<int>{1, 3, 2}));
    EXPECT_TRUE(SatisfiesMinHeapProperty(three.asArray()));

    MinHeap sorted({1, 2, 3, 4, 5});
    EXPECT_EQ(sorted.asArray(), (vector<int>{1, 2, 3, 4, 5}));
    EXPECT_TRUE(SatisfiesMinHeapProperty(sorted.asArray()));
}

TEST(MinHeap, Constructor_AlreadySorted) {
    MinHeap heap({1, 2, 3, 4, 5});
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_EQ(DrainInSortedOrder(heap, 5), (vector<int>{1, 2, 3, 4, 5}));
}

TEST(MinHeap, Constructor_ReverseSorted) {
    MinHeap heap({5, 4, 3, 2, 1});
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_EQ(DrainInSortedOrder(heap, 5), (vector<int>{1, 2, 3, 4, 5}));
}

// --------------------
// Single element
// --------------------
TEST(MinHeap, SingleElement_PeekAndExtract) {
    MinHeap heap({42});
    EXPECT_EQ(heap.peek(), 42);
    EXPECT_EQ(heap.extractMin(), 42);
    EXPECT_THROW(heap.peek(), std::out_of_range);
}

// --------------------
// extractMin ordering
// --------------------
TEST(MinHeap, ExtractMin_ReturnsAscendingOrder) {
    vector<int> data = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    MinHeap heap(data);

    vector<int> expected = data;
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(DrainInSortedOrder(heap, static_cast<int>(data.size())), expected);
    EXPECT_THROW(heap.extractMin(), std::out_of_range);
}

TEST(MinHeap, ExtractMin_WithDuplicates) {
    MinHeap heap({2, 2, 1, 1, 3});
    EXPECT_EQ(heap.extractMin(), 1);
    EXPECT_EQ(heap.extractMin(), 1);
    EXPECT_EQ(heap.peek(), 2);
    EXPECT_EQ(heap.extractMin(), 2);
    EXPECT_EQ(heap.extractMin(), 2);
    EXPECT_EQ(heap.extractMin(), 3);
    EXPECT_THROW(heap.extractMin(), std::out_of_range);
}

TEST(MinHeap, ExtractMin_WithNegatives) {
    MinHeap heap({0, -3, 5, -1, 2});
    EXPECT_EQ(DrainInSortedOrder(heap, 5), (vector<int>{-3, -1, 0, 2, 5}));
}

// --------------------
// peek semantics
// --------------------
TEST(MinHeap, Peek_DoesNotRemoveMinimum) {
    MinHeap heap({3, 1, 2});
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_EQ(heap.extractMin(), 1);
    EXPECT_EQ(heap.peek(), 2);
}

// --------------------
// insert + siftUp
// --------------------
TEST(MinHeap, Insert_EmptyHeap) {
    MinHeap heap;
    heap.insert(5);
    EXPECT_EQ(heap.peek(), 5);
    EXPECT_EQ(heap.asArray().size(), 1u);
    EXPECT_TRUE(SatisfiesMinHeapProperty(heap.asArray()));
}

TEST(MinHeap, Insert_MaintainsMinHeapProperty) {
    MinHeap heap;
    for (int v : {5, 3, 8, 1, 9, 2}) {
        heap.insert(v);
        EXPECT_TRUE(SatisfiesMinHeapProperty(heap.asArray()));
    }
    EXPECT_EQ(heap.peek(), 1);
}

TEST(MinHeap, Insert_ThenDrainSorted) {
    MinHeap heap;
    const vector<int> values = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    for (int v : values) {
        heap.insert(v);
    }

    vector<int> expected = values;
    std::sort(expected.begin(), expected.end());
    EXPECT_EQ(DrainInSortedOrder(heap, static_cast<int>(values.size())), expected);
}

TEST(MinHeap, Insert_SmallerThanRoot) {
    MinHeap heap({5, 3, 7});
    EXPECT_EQ(heap.peek(), 3);
    heap.insert(1);
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_TRUE(SatisfiesMinHeapProperty(heap.asArray()));
}

TEST(MinHeap, Insert_WithDuplicates) {
    MinHeap heap;
    for (int v : {2, 2, 1, 1, 3}) {
        heap.insert(v);
    }
    EXPECT_EQ(heap.extractMin(), 1);
    EXPECT_EQ(heap.extractMin(), 1);
    EXPECT_EQ(heap.extractMin(), 2);
    EXPECT_EQ(heap.extractMin(), 2);
    EXPECT_EQ(heap.extractMin(), 3);
    EXPECT_THROW(heap.extractMin(), std::out_of_range);
}

TEST(MinHeap, Insert_AfterExtractMin) {
    MinHeap heap({4, 2, 3});
    EXPECT_EQ(heap.extractMin(), 2);
    heap.insert(1);
    EXPECT_EQ(heap.peek(), 1);
    EXPECT_TRUE(SatisfiesMinHeapProperty(heap.asArray()));
    EXPECT_EQ(DrainInSortedOrder(heap, 3), (vector<int>{1, 3, 4}));
}

TEST(MinHeap, BuildViaInsert_MatchesConstructorHeapify) {
    const vector<int> data = {9, 4, 7, 1, 3};
    MinHeap fromConstructor(data);

    MinHeap fromInserts;
    for (int v : data) {
        fromInserts.insert(v);
    }

    EXPECT_TRUE(SatisfiesMinHeapProperty(fromInserts.asArray()));
    EXPECT_TRUE(SameMultiset(fromInserts.asArray(), data));
    EXPECT_EQ(fromInserts.peek(), fromConstructor.peek());
    EXPECT_EQ(
        DrainInSortedOrder(fromInserts, static_cast<int>(data.size())),
        DrainInSortedOrder(fromConstructor, static_cast<int>(data.size())));
}
