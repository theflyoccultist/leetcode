// Design a number container system that can do the following:

//     Insert or Replace a number at the given index in the system.
//     Return the smallest index for the given number in the system.

// Implement the NumberContainers class:

//     NumberContainers() Initializes the number container system.
//     void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
//     int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.

// Test case format:
// ["NumberContainers","find","change","change","change","change","find","change","find"]
// [[],[10],[2,10],[1,10],[3,10],[5,10],[10],[1,20],[10]]

// Output:
// [null, -1, null, null, null, null, 1, null, 2]

package main

import (
	"container/heap"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type NumberContainers struct {
	indexToNumber map[int]int
	numberToHeap  map[int]*IntHeap
}

func Constructor() NumberContainers {
	return NumberContainers{
		indexToNumber: make(map[int]int),
		numberToHeap:  make(map[int]*IntHeap),
	}
}

func (this *NumberContainers) Change(index int, number int) {
	if oldNumber, found := this.indexToNumber[index]; found {
		if oldNumber == number {
			return
		}
		heap := this.numberToHeap[oldNumber]
		heap.Push(index)
	}

	this.indexToNumber[index] = number

	if _, found := this.numberToHeap[number]; !found {
		this.numberToHeap[number] = &IntHeap{}
		heap.Init(this.numberToHeap[number])
	}
	heap.Push(this.numberToHeap[number], index)
}

func (this *NumberContainers) Find(number int) int {
	heap := this.numberToHeap[number]
	for heap.Len() > 0 {
		smallest := (*heap)[0]
		if this.indexToNumber[smallest] == number {
			return smallest
		}
		heap.Pop()
	}

	if _, found := this.numberToHeap[number]; !found {
		return -1
	}

	return -1
}
