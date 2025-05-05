#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    
    int parentIndex(int i) {
        return (i-1)/2;
    }
    
    int leftChild(int i) {
        return 2*i + 1;
    }
    
    int rightChild(int i) {
        return 2*i + 2;
    }
    
    public:
    void insert(int element) {
        heap.push_back(element);
        
        int i = heap.size() - 1;
        int parent = parentIndex(i);
        
        while(i > 0 && heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = parentIndex(i);
        }
    }
    
    int removeItem() {
        if(heap.size() == 0) {
            // throw exception
            return -1;
        }
        
        int ans = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        
        int i = 0;
        
        // if there's no leftChild then there's no right child because of Complete Binary tree property
        while(leftChild(i) < heap.size()) {
            // downheapify
            int min = i;
            int left = leftChild(i);
            int right = rightChild(i);
            
            if(heap[left] < heap[min]) {
                min = left;
            }
            
            if(right < heap.size() && heap[right] < heap[min]) {
                min = right;
            }
            
            if(min == i) break;
            swap(heap[i], heap[min]);
            i = min;
        }
        return ans;
    }
    
    void print() {
        for(int i : heap) {
            cout << i << " ";
        }
    }
    
};

int main() {
    vector<int> data { 5, 6, 8, 10, 12 };
    
	PriorityQueue p;
	for(int i : data) {
	    p.insert(i);
	}
	
	p.insert(7);
	p.insert(1);
	p.removeItem();
	p.print();

}
