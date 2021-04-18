// Week05Quiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// This is the DrawTitle function that takes the string input and prints out the header that we've created in many of our assignments
void DrawTitle(string sTitle) {
    // I declared the titleWidth and titleLength as a constant integer
    const int titleWidth = 60;
    const int titleLength = sTitle.length();
    // This code will output the title using format manipulators
    cout << setfill('*') << setw(titleWidth) << "*" << endl;
    cout << setfill('*') << setw((titleWidth - titleLength) / 2) << "*" << sTitle << right << setw((titleWidth - titleLength) / 2) << "*" << endl;
    cout << setfill('*') << setw(titleWidth) << "*" << endl;
    // Print an empty line after the header
    cout << endl;
}

// This is the ReadFile function that opens the file, reads the coordinates, closes the file and returns them
bool ReadFile(string sFileName, int& ix, int& iy, int& iWidth, int& iHeight) {
    // Open up the file
    ifstream fileInput;
    fileInput.open(sFileName);
    // Read the coordinates of the file
    string line;
    string xy;
    string wh;
    int index = 0;
    // The if else is going to test to see if the file opened successfully or not
    if (!fileInput) {
        cout << endl;
        cout << "Can't open file: " << sFileName << endl;
        return false;
    }
    else {
        while (!fileInput.eof() && fileInput >> line) {
            // So what I did here was make an if statement to say that if the index is at 0, we take the x and y coordinates as a string.
            // If the index is at 1, we take the height and width as a string. I will convert these into integers later in the program.
            if (index == 0) {
                xy = line;
            }
            if (index == 1) {
                wh = line;
            }
            index++;
        }
        // Convert the strings we got into integers that will be returned by reference
        // I decided to use stringstream instead of stoi because I couldn't figure out how to get stoi to work (it was only returning the first numerical value)
        stringstream ss(xy);
        ss >> ix;
        // This is here so that it ignores the comma
        if (ss.peek() == ',') {
            ss.ignore();
        }
        ss >> iy;
        // Redeclare the second stringstream for the second line
        ss = stringstream(wh);
        ss >> iWidth;
        // This is here so that it ignores the comma
        if (ss.peek() == ',') {
            ss.ignore();
        }
        ss >> iHeight;
        // Close the file
        fileInput.close();
        return true;
    }
}

// The DrawBox function that takes the coordinates and Draws the box onto the screen
void DrawBox(int ix, int iy, int iWidth, int iHeight) {
    // Declaration of any variables we need
    const int xLength = 40;
    int yLength = iHeight + iy;
    // Output of the y axis and the box
    for (int i = 1; i <= yLength; i++) {
        if (i == iy || i <= iHeight) {
            cout << "|" << setw(ix) << setfill(' ') << "*" << setw(iWidth) << setfill('*') << " " << endl;
        }
        else {
            cout << "|" << endl;
        }
    }
    // Output of the x axis
    cout << setfill('-') << setw(xLength) << "-" << endl;
    cout << "0,0" << endl;
}

int main()
{
    // All the variables will be declared here
    const string sTitle = " Welcome to my Box Drawing Program ";
    string fileInput;
    int ix;
    int iy;
    int iWidth;
    int iHeight;
    // Calling the DrawTitle function and passing in sTitle as the parameter
    DrawTitle(sTitle);
    // Ask the user for their input
    cout << "Enter another file to read or 'X' to exit." << endl;
    cin >> fileInput;
    cout << endl;
    // As long as the input isn't X, we want to run the program
    // I probably should've used a do while loop
    while (fileInput != "X") {
        // I called both the ReadFile and DrawBox function, but we only want to call DrawBox if ReadFile is true
        if (ReadFile(fileInput, ix, iy, iWidth, iHeight) == true) {
            DrawBox(ix, iy, iWidth, iHeight);
        }
        system("pause");
        system("cls");
        // Do this again
        DrawTitle(sTitle);
        cout << "Enter another file to read or 'X' to exit." << endl;
        cin >> fileInput;
        cout << endl;
    }
    if (fileInput == "X") {
        cout << "Good bye." << endl;
        system("pause");
        return 0;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
