#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i){
    int curr = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[curr] < arr[left]){
        curr = left;
    }
     if(right < n && arr[curr] < arr[right]){
        curr = right;
    }

    // if curr changed, its not equal to i now
    if(curr != i){
        swap(arr[curr], arr[i]);
        heapify(arr, n, curr);
    }

}

int main() {

    int n = 6;
    int arr[n] = {-1, 54, 55, 53, 52, 50};

    for(int i = (n-1)/2; i > 0; i--){
        heapify(arr, n-1, i);
    }

    cout << "After Heapify : " << endl;
    for(auto i: arr){
        cout << i << " ";
    }

    return 0;
}