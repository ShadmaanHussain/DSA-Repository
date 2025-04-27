#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> heap;
    
    public:
    void insert(int item) {
        heap.push_back(item);
        int n = heap.size();
        
        if(n == 1) return;
        
        int i = n-1;
        while(heap[(i-1)/2] > heap[i]) {
            swap(heap[(i-1)/2],heap[i]);
            i = (i-1)/2;
        }
    }
    
    int retreive() {
        int n = heap.size();
        if(n == 0) return -1;
        
        int ans = heap[0];
        
        swap(heap[0], heap[n-1]);
        heap.pop_back();
        
        int i = 0;
        
        while(heap.size() > 0 &&  )
        
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
}
