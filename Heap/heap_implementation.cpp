#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int i, int heapsize) {
    int largest = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    
    // Compare parent with left child
    if (L < heapsize && arr[L] > arr[largest]) 
        largest = L;
    
    // Compare largest with right child
    if (R < heapsize && arr[R] > arr[largest])
        largest = R;
    
    // If the largest is not the parent, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, heapsize);
    }
}

void insert(vector<int>& arr, int& heapsize, int val) {
    // Insert at the end of the heap
    arr.push_back(val);
    heapsize++;
    
    // Bubble up to restore heap property
    int i = heapsize - 1;
    while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int find_max(const vector<int>& arr) {
    return arr[0];  // The max element is at the root of the heap
}

void delete_max(vector<int>& arr, int& heapsize) {
    if (heapsize < 1) return;
    
    // Move the last element to the root
    arr[0] = arr[heapsize - 1];
    heapsize--;
    arr.pop_back();  // Remove the last element
    
    // Restore the heap property
    heapify(arr, 0, heapsize);
}

void heapsort(vector<int>& arr) {
    int heapsize = arr.size();
    
    // Build the heap
    for (int i = heapsize / 2 - 1; i >= 0; i--) {
        heapify(arr, i, heapsize);
    }
    
    // One by one extract elements from heap
    for (int i = heapsize - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // Call heapify on the reduced heap
        heapify(arr, 0, i);
    }
}

int main() {
    vector<int> heap;
    int heapsize = 0;
    
    insert(heap, heapsize, 10);
    insert(heap, heapsize, 20);
    insert(heap, heapsize, 5);
    
    cout << "Max element: " << find_max(heap) << endl;  // Should output 20
    
    delete_max(heap, heapsize);
    cout << "Max element after delete: " << find_max(heap) << endl;  // Should output 10
    
    vector<int> arr = {4, 10, 3, 5, 1};
    heapsort(arr);
    
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
