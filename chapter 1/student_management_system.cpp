#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 1. Define the Student structure
struct Student {
    int rollNo;
    string name;
    string branch;
};

// Global constant for the file name
const string FILE_NAME = "students.txt";

// --- Function Prototypes ---
void addStudent();
void displayStudents();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    // Menu loop
    do {
        cout << "\n=================================\n";
        cout << "    STUDENT MANAGEMENT SYSTEM    \n";
        cout << "=================================\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Update Student Record\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

// --- Function Implementations ---

// C: Create (Add)
void addStudent() {
    ofstream outFile(FILE_NAME, ios::app); // Open in append mode
    if (!outFile) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }

    Student s;
    cout << "\n-- Add Student --\n";
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;
    
    // Clear the input buffer before reading strings
    cin.ignore(); 
    
    cout << "Enter Full Name: ";
    getline(cin, s.name);
    
    cout << "Enter Branch: ";
    getline(cin, s.branch);

    // Save to file (each attribute on a new line makes it easy to read back)
    outFile << s.rollNo << '\n' << s.name << '\n' << s.branch << '\n';
    
    outFile.close();
    cout << "Student record added successfully!\n";
}

// R: Read (Display)
void displayStudents() {
    ifstream inFile(FILE_NAME); // Open in read mode
    if (!inFile) {
        cout << "\nNo records found (file does not exist yet).\n";
        return;
    }

    Student s;
    string rollStr;
    
    cout << "\n--- Student Records ---\n";
    bool hasRecords = false;

    // Read line by line. We read roll number as a string first, then convert it.
    while (getline(inFile, rollStr)) {
        if (rollStr.empty()) continue; // Skip empty lines
        
        hasRecords = true;
        s.rollNo = stoi(rollStr); // Convert string to integer
        getline(inFile, s.name);
        getline(inFile, s.branch);

        cout << "Roll No: " << s.rollNo << " | Name: " << s.name << " | Branch: " << s.branch << "\n";
    }

    if (!hasRecords) {
        cout << "The database is currently empty.\n";
    }

    inFile.close();
}

// U: Update
void updateStudent() {
    ifstream inFile(FILE_NAME);
    if (!inFile) {
        cout << "\nNo records found to update.\n";
        return;
    }

    int targetRoll;
    cout << "\nEnter the Roll Number of the student to update: ";
    cin >> targetRoll;

    ofstream tempFile("temp.txt"); // Temporary file to hold the updated data
    Student s;
    string rollStr;
    bool found = false;

    while (getline(inFile, rollStr)) {
        if (rollStr.empty()) continue;
        
        s.rollNo = stoi(rollStr);
        getline(inFile, s.name);
        getline(inFile, s.branch);

        // If this is the student we want to update
        if (s.rollNo == targetRoll) {
            found = true;
            cout << "Student Found! Entering new details:\n";
            
            cin.ignore(); // Clear buffer
            cout << "Enter New Name: ";
            getline(cin, s.name);
            cout << "Enter New Branch: ";
            getline(cin, s.branch);
            
            cout << "Record updated successfully.\n";
        }
        
        // Write data (either old or newly updated) to the temporary file
        tempFile << s.rollNo << '\n' << s.name << '\n' << s.branch << '\n';
    }

    inFile.close();
    tempFile.close();

    // Replace the old file with the new temporary file
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (!found) {
        cout << "Student with Roll Number " << targetRoll << " not found.\n";
    }
}

// D: Delete
void deleteStudent() {
    ifstream inFile(FILE_NAME);
    if (!inFile) {
        cout << "\nNo records found to delete.\n";
        return;
    }

    int targetRoll;
    cout << "\nEnter the Roll Number of the student to delete: ";
    cin >> targetRoll;

    ofstream tempFile("temp.txt");
    Student s;
    string rollStr;
    bool found = false;

    while (getline(inFile, rollStr)) {
        if (rollStr.empty()) continue;
        
        s.rollNo = stoi(rollStr);
        getline(inFile, s.name);
        getline(inFile, s.branch);

        // If we find the student to delete, we simply DO NOT write them to the temp file
        if (s.rollNo == targetRoll) {
            found = true;
            cout << "Record deleted successfully.\n";
            continue; // Skip the writing step below
        }
        
        // Write all other students to the temp file
        tempFile << s.rollNo << '\n' << s.name << '\n' << s.branch << '\n';
    }

    inFile.close();
    tempFile.close();

    // Replace old file with the temp file
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());

    if (!found) {
        cout << "Student with Roll Number " << targetRoll << " not found.\n";
    }
}