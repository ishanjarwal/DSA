#include <iostream>
using namespace std;

class Heap{
    public: 

    int arr[100];
    int size = 0;

    void insert(){

        int data;

        cout << "Enter value : ";
        cin >> data;
            
        size++;
        int index = size;
        arr[index] = data;

        while(index > 0){
                int parentIndex = index/2;
                if(parentIndex == 0) break;
                if(arr[parentIndex] < arr[index]){
                    swap(arr[parentIndex], arr[index]);
                    index = parentIndex;
                }else{
                    break;
                }
            }
    }

    void print(){
        cout << endl;
        for(int i = 1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap(){

        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }
        
        arr[1] = arr[size];
        size--;

        int i = 1;

        while(i < size){
            int leftChildIndex = 2*i;
            int rightChildIndex = 2*i + 1;

            if(leftChildIndex < size && arr[i] < arr[leftChildIndex]){
                swap(arr[i], arr[leftChildIndex]);
                i = leftChildIndex;
            }else if(rightChildIndex < size && arr[i] < arr[leftChildIndex]){
                swap(arr[i], arr[rightChildIndex]);
                i = rightChildIndex;
            }else{
                return;
            }
        }
    }
};

int main() {

    Heap h;
    
    for(int i = 0; i<=5; i++){
        h.insert();
        h.print();
    }
    h.deleteFromHeap();
    h.print();


    return 0;
}