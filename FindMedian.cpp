//#include <iostream>
//using namespace std;

//int findMedian(int arr[], int n) {
  //  for (int i = 0; i < n - 1; i++) {
    //    for (int j = 0; j < n - i - 1; j++) {
      //      if (arr[j] > arr[j + 1]) {
        //        int temp = arr[j];
          //      arr[j] = arr[j + 1];
            //    arr[j + 1] = temp;
            //}
        //}
    //}

    // Find the median value
  //  return arr[n / 2];
//}

//int main() {
   // int n;
   // cout << "Enter the length of the array: ";
    //cin >> n;

    //int arr[n];
    //cout << "Enter the elements of the array (comma-separated): ";
    //for (int i = 0; i < n; i++) {
      //  cin >> arr[i];
    //}

    //int median = findMedian(arr, n);

    //cout << "Median value: " << median << endl;

    //return 0;
//}
 //"C:\\Users\\c m\\Desktop\\Assignment01\\TestCases\\TestCases\\FindMedian\\TestCases\\TestCase_03.txt"; 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int SelectingTheMedian(int arr[], int n) {
    bubbleSort(arr, n);
    return arr[n / 2];
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

    int median = SelectingTheMedian(arr, n);

    cout << "Median value: " << median << endl;

    return 0;
}
