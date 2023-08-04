//#include <iostream>
//using namespace std;

//int GoingOffTheCharts(int arr[], int n) {
    //int consDays = 0; // Initialize consDays 
   // int maxConsDays = 0; // Initialize maxConsDays 

    //for (int i = 0; i < n; i++) {
        //if (arr[i] > 6) {
          //  consDays++;
      //  } else {
        //    if (consDays > maxConsDays) {
         //       maxConsDays = consDays;
           // }
           // consDays = 0; // Reset it to 0
        //}
    //}

    //if (consDays > maxConsDays) {
      //  maxConsDays = consDays;
    //}

  //  return maxConsDays;
//}

//int main() {
    //int n;
    //cout << "Enter the length of the array: ";
    //cin >> n; // Get  length of array from  user

    //int arr[n]; // Declare an array to store  working hours
    //cout << "Enter the working hours : ";

    
    //for (int i = 0; i < n; i++) {
      //  cin >> arr[i];
    //}

    // Call  function to calculate the highest cons days
    //int highestConsDays = GoingOffTheCharts(arr, n);

    //cout << "Highest  consecutive  working hours above 6: "
    //     << highestConsDays << endl;

  //  return 0; // End  program
//}


#include <iostream>     // for input/output operation
#include <fstream>      // fstream used to read from file
#include <string>       //  for string variable type
using namespace std;    // Use the standard library  to use name for object and variable

// Function to calculate the max cons working hours above 6
int GoingOffTheCharts(int arr[], int n) {
    int consDays = 0;   // Initialize consDays
    int maxConsDays = 0;    // Initialize maxConsDays

    for (int i = 0; i < n; i++) {   //  array loop
        if (arr[i] > 6) {   // Checking if the element is above 6
            consDays++;     // Increment consecutive days 
        } else {
            if (consDays > maxConsDays) {   // Checking if current cons days  is higher than the max cons days
                maxConsDays = consDays;     // Upgrade the max cons days
            }
            consDays = 0;   // Reset the cons days to 0
        }
    }

    if (consDays > maxConsDays) {   // Check again after the loop ends
        maxConsDays = consDays;     // Upgrade the maxcons days if needed
    }

    return maxConsDays;     // Return the max cons working hours above 6
}

int main() {
    int n;
    string filePath;
    cout << "Input the filepath: ";
    getline(cin, filePath);     // Read the file path from  user

    ifstream inputFile(filePath.c_str());   // Open the file
    if (!inputFile.is_open()) {     // Check if the file is  opened
        cout << "Error: Unable to open input file!" << endl;   // Print  error message if file doesn't open
        return 1;   // Return 1 to show error
    }

    // Read the size of array from  file
    inputFile >> n;
    cout << "The size of  array is: " << n << endl;  //print the size of array

    // Read the array elements from  file
    int arr[n];
    for (int i = 0; i < n; i++) {
        char comma; // To read the comma separator
        if (!(inputFile >> arr[i])) {   // Read each element from  file
            cout << "Error: Unable to read array element!" << endl;   // Print error message if it fail to read
            return 1;  // Return 1 to show error
        }
           if (i < n - 1) {
            inputFile >> comma; // Read the comma separator
            if (comma != ',') {
                cout << "Error: Invalid comma separator!" << endl;  //print error 
                return 1; 
          }
         }
        }

    // Print the array elements
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];     // Print every element of the array
        if (i < n - 1)
            cout << ",";    // Adding the comma separator for all elements except the last one
    }
    cout << endl;     // print

    inputFile.close();  // Close the file after reading


    int maxConsDays = GoingOffTheCharts(arr, n);   //  Calling the function to calculate the max cons working hours above 6

    // Printing the maxConsDays
    cout << "max cons working hours above 6: " << maxConsDays << endl;
    return 0;   // program end 
    }
