//#include <iostream>
//using namespace std;
//int BribedQueue(int arr[], int n) {
  //  int bribes = 0;

    //for (int i = 1; i < n; i++) {
      //  int current = arr[i];
        //int j = i - 1;

        // Insertion sort to sort the array and count the bribes
        //while (j >= 0 && arr[j] > current) {
          //  arr[j + 1] = arr[j];
            //j--;
           // bribes++;
        //}

        //arr[j + 1] = current;
    //}

    //return bribes; // Return the total number of bribes
//}

//int main() {
  //  int n;
    //cout << "Enter the length of the array: ";
    //cin >> n; // Get the length of the array from the user

    //int arr[n]; // Declare an array to store the elements of the queue
    //cout << "Enter the elements of the array : ";

    // Get the elements of the array from the user
    //for (int i = 0; i < n; i++) {
      //  cin >> arr[i];
    //}

    // Call the BribedQueue function to count the bribes
    //int bribes = BribedQueue(arr, n);
    
    //if (bribes>=0){
       // cout<< "Total bribes taken in the queue:" << bribes<< endl;
     //} else{
      //  cout << "queue is not given!" << endl;
    // }


  //  return 0; // End of the program
//}
//ses\\C:\\Users\\c m\\Desktop\\Assignment01\\TestCases\\TestCases\\BribedQueue\\TestCases\\TestCase_04.txt
#include <iostream>
#include <fstream>
using namespace std;

int BribedQueue(int arr[], int n) {
    int bribes = 0;

    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        // Insertion sort to sort the array and count the bribes
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
            bribes++;
        }

        arr[j + 1] = current;
    }

    return bribes; // Return the total number of bribes
}

int main() {
    int n;
    string filePath;
    cout << "Input the filepath: ";
    getline(cin, filePath);

    ifstream inputFile(filePath.c_str());
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file!" << endl;
        return 1;
    }

    // Read the size of array
    inputFile >> n;
    cout << "The size of the array is: " << n << endl;

    // Read the array
    int arr[n];
    for (int i = 0; i < n; i++) {
        char comma; // To read the comma separator
        if (!(inputFile >> arr[i])) {
            cout << "Error: Unable to read array element!" << endl;
            return 1;
        }
        if (i < n - 1) {
            inputFile >> comma; // Read the comma separator
            if (comma != ',') {
                cout << "Error: Invalid comma separator!" << endl;
                return 1;
            }
        }
    }

    // print the array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << endl;

    inputFile.close();

    // Call the BribedQueue function to count the bribes
    int bribes = BribedQueue(arr, n);
    
    if (bribes >= 0) {
        cout << "Total bribes taken in the queue: " << bribes << endl;
    } else {
        cout << "Queue is not given in the input file!" << endl;
    }

    return 0; // End of the program
}
