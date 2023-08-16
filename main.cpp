
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

void printArray(const vector<int>& array) {
    
        for (int i = 0; i < array.size(); ++i) {
            cout << array[i]<<"<->";
        }
        cout << endl;

    cout << "---------------------" << endl;
}

void insertionSort(vector<int>& array) {
    for (int i = 1; i < array.size(); ++i) {
        for (int j = i; j > 0 && array[j] < array[j - 1]; --j) {
            
            swap(array[j], array[j - 1]);
            cout<<endl;
            cout<<array[j]<<"<->"<<array[j-1];
            cout<<endl;
            printArray(array);
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
}

void bubbleSort(vector<int>& array) {
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < array.size() - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                cout<<endl;
                cout<<array[j]<<"<->"<<array[j+1];
                cout<<endl;
                printArray(array);
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
     
        }
    }

}

void insertionsort(vector<int>&array){
    for(int i=1;i<array.size();i++){
        for(int j=i;j<0.;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                cout<<endl;
                cout<<array[j]<<"<->"<<array[j-1];
                cout<<endl;
                printarray(array);
                this_thread::sleep_for(chrono::milliseconds(200));
            }
        }
    }
}

void merge(vector<int>& arr, int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            printArray(arr);
            this_thread::sleep_for(chrono::milliseconds(1000));
            i++;
        } else {
            temp.push_back(arr[j]);
            printArray(arr);
            this_thread::sleep_for(chrono::milliseconds(1000));
            j++;
        }
    }

    while (j <= r) {
        temp.push_back(arr[j]);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(1000));
        j++;
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(1000));
        i++;
    }

    for (int s = 0; s < temp.size(); s++) {
        arr[l + s] = temp[s];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(1000));
        mergeSort(arr, mid + 1, r);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(1000));
        merge(arr, l, mid, r);
        printArray(arr);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
            printArray(arr);
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
    swap(arr[i], arr[low]);
    printArray(arr);
    this_thread::sleep_for(chrono::milliseconds(1000));
    return i;
    
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSortHelper(arr, low, pivotIndex - 1);
        quickSortHelper(arr, pivotIndex + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}



int main() {
    vector<int> arr = {4, 8, 1, 3, 2, 9, 5, 7, 6};

    vector<string>availablealgorithms={"selection sort","insertion sort","bubble sort","merge sort","quick sort"};
    
    

    

    cout << "Original Array:" << endl;
    printArray(arr);
    
    cout<<"During sorting :"<<endl;

    quickSort(arr);

    cout << "Sorted Array:" << endl;
    printArray(arr);

    return 0;
}
