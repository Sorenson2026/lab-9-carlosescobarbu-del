//Carlos Escobar
//3/17/2026
//This program will read student names from a file with one name per line, and will tell the first and last name in alphabetical order, and it also counts the names that are included in it. 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//This program will read student names from a file with one name per line, and will tell the first and last name in alphabetical order 
int main()
{
    cout << "This program will read student names from a file, and will tell the first and last name in alphabetical order, and it also counts the names that are included in it. \n" ;
    // Variable to store the file name entered by the user
    string filename;

    // Ask user for file name
    cout << "Enter the file name: ";
    cin >> filename;

    // Try to open the file
    ifstream file(filename);

    // Check if file exists or failed to open
    if (!file)
    {
        cout << "Error: File does not exist.\n";
        return 0;
    }

    // Variables to store each name and results
    string name;
    string firstName, lastName;
    int count = 0;

    // Read the first name to initialize variables
    if (getline(file, name))
    {
        firstName = name;
        lastName = name;
        count = 1;
    }

    // Loop through the rest of the file
    while (getline(file, name))
    {
        count++; // Increase total count

        if (name < firstName)
            firstName = name;

        if (name > lastName)
            lastName = name;
    }

    // Close the file 
    file.close();

    // Display results 
    cout << "First alphabetically: " << firstName << endl;
    cout << "Last alphabetically: " << lastName << endl;
    cout << "Total number of names: " << count << endl;

    return 0;
}
