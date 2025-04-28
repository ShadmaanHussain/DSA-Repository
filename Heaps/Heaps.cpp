#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> heap;
    
    int parent(int index) {
        return (index - 1) / 2;
    }
    
    int leftChild(int index) {
        return 2*index + 1;
    }
    
    int rightChild(int index) {
        return 2*index + 2;
    }
    
    void downHeap(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;
        
        if(left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        
        if(right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if(smallest != index) {
            swap(heap[smallest], heap[index]);
            downHeap(smallest);
        }
    }
    
    void upHeap(int index) {
        if(index == 0) return;
        
        int parent = this->parent(index);
        if(heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            upHeap(parent);
        }
    }
    
    public:
    void insertIteratively(int item) {
        heap.push_back(item);
        int n = heap.size();
        
        int i = n-1;
        while(heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    
    void insert(int item) {
        heap.push_back(item);
        upHeap(heap.size() - 1);
    }
    
    int retreive() {
        int ans = heap[0];
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        downHeap(0);
        return ans;
    }
    
    void print() {
        for(int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> list {10, 2, 5, 8, 12, 1};
	Heap* h = new Heap();
	for(int i : list) {
	    h->insert(i);
	}
	
	h->print();
	cout << endl;
	cout << h->retreive() << endl;
	h->print();
}
