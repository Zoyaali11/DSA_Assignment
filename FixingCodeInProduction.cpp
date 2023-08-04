//#include <iostream>
//using namespace std;

// Function to find the index of an element in a sorted array using binary search
//int FixingCodeInProduction(int arr[], int n, int numToFind) {
    //int s = 0; //start initialization
    //int e = n - 1; // end initialization

    //while (s <= e) {
        //int mid = s + (e - s) / 2;

        //if (arr[mid] == numToFind) {
          //  return mid; // Element found, return the index
        //} else if (arr[mid] < numToFind) {
          //  s = mid + 1; // Discard left half, search in right half
        //} else {
       //     e = mid - 1; // Discard right half, search in left half
     //   }
   // }

  //  return -1; // Element not found, return -1
//}

//int main() {
    //int numToFind, n;
   // cin >> numToFind; // Read the number to find
    //cin >> n; // Read the length of the array

    //int arr[n];
    //for (int i = 0; i < n; i++) {
      //  cin >> arr[i]; // Read the elements of the array
    //}

    // Call the FixingCodeInProduction function to find the index of the element
    //int index = FixingCodeInProduction(arr, n, numToFind);

    //cout << index << endl; // Print the index of the number to find in the array

  //  return 0; // End of the program
//}C:\\Users\\c m\\Desktop\\Assignment01\\TestCases\\TestCases\\FixingCodeInProduction\\TestCases\\TestCase_01.txt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to find the index of an element in a sorted array using binary search
int FixingCodeInProduction(int arr[], int n, int numToFind) {
    int s = 0; //start initialization
    int e = n - 1; // end initialization

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == numToFind) {
            return mid; // Element found, return the index
        } else if (arr[mid] < numToFind) {
            s = mid + 1; // Discard left half, search in right half
        } else {
            e = mid - 1; // Discard right half, search in left half
        }
    }

    return -1; // Element not found, return -1
}

int main() {
    int numToFind, n;
    string filePath;
    cout << "Input the filepath: ";
    getline(cin, filePath);

    ifstream inputFile(filePath.c_str());
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file!" << endl;
        return 1;
    }

    // Read the number to find
    inputFile >> numToFind;
    cout << "Number to find: " << numToFind << endl;

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

    // Print the array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << endl;

    inputFile.close();

    // Call the FixingCodeInProduction function to find the index of the element
    int index = FixingCodeInProduction(arr, n, numToFind);

    cout << "Index of the number: " << index << endl;

    return 0; // End of the program
}
