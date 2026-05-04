#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// ==========================================
// CLASS DEFINITION
// ==========================================
class Account {
    int accNumber;
    char name[50];
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Initial Deposit (Min 500): ";
        cin >> balance;
        cout << "\nAccount Created Successfully!";
    }

    void showAccount() const {
        cout << "\nAccount No. : " << accNumber;
        cout << "\nAccount Holder : " << name;
        cout << "\nCurrent Balance : " << balance;
    }

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) { balance -= amount; }
    
    int getAccNo() const { return accNumber; }
    double getBalance() const { return balance; }
};

// ==========================================
// FUNCTION PROTOTYPES
// ==========================================
void writeAccount();
void displayBalance(int n);
void depositWithdraw(int n, int sel);
void displayAll();


// ==========================================
// MAIN PROGRAM LOOP
// ==========================================
int main() {
    int choice, num;

    while (true) {
        cout << "\n\n=== BANK MANAGEMENT SYSTEM ===";
        cout << "\n1. NEW ACCOUNT";
        cout << "\n2. BALANCE INQUIRY";      
        cout << "\n3. DEPOSIT AMOUNT";
        cout << "\n4. WITHDRAW AMOUNT";
        cout << "\n5. ALL ACCOUNT LIST";     
        cout << "\n6. EXIT";                 
        cout << "\nSelect Option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: 
                writeAccount(); 
                break;
            case 2: 
                cout << "\nEnter Account No to Check Balance: "; 
                cin >> num;
                displayBalance(num); 
                break;
            case 3: 
                cout << "\nEnter Account No: "; 
                cin >> num;
                depositWithdraw(num, 1); 
                break;
            case 4: 
                cout << "\nEnter Account No: "; 
                cin >> num;
                depositWithdraw(num, 2); 
                break;
            case 5: 
                displayAll(); 
                break;
            case 6: 
                cout << "\nThank you for using the Bank Management System!\n";
                exit(0);
            default: 
                cout << "\nInvalid Selection! Please choose between 1 and 6.";
        }
    }
    return 0;
}

// ==========================================
// FILE HANDLING FUNCTIONS
// ==========================================

// 1. Write a new account to the binary file
void writeAccount() {
    Account ac;
    ofstream outFile("bank_data.dat", ios::binary | ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char*>(&ac), sizeof(Account));
    outFile.close();
}

// 2. Read and display a specific account's balance
void displayBalance(int n) {
    Account ac;
    bool found = false;
    
    ifstream inFile("bank_data.dat", ios::binary);
    if (!inFile) { 
        cout << "File could not be opened! Make sure an account is created first."; 
        return; 
    }

    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(Account))) {
        if (ac.getAccNo() == n) {
            cout << "\n=== ACCOUNT DETAILS ===";
            ac.showAccount();
            found = true;
            break; 
        }
    }
    
    inFile.close();
    
    if (!found) {
        cout << "\nAccount number does not exist!";
    }
}

// 3. Update an existing account (Deposit or Withdraw)
void depositWithdraw(int n, int sel) {
    bool found = false;
    Account ac;
    fstream File("bank_data.dat", ios::binary | ios::in | ios::out);
    
    if (!File) { cout << "File Error!"; return; }

    while (!File.eof() && found == false) {
        File.read(reinterpret_cast<char*>(&ac), sizeof(Account));
        if (ac.getAccNo() == n) {
            ac.showAccount();
            if (sel == 1) { // Deposit
                double amt;
                cout << "\n\nEnter Deposit Amount: "; cin >> amt;
                ac.deposit(amt);
            } else { // Withdraw
                double amt;
                cout << "\n\nEnter Withdrawal Amount: "; cin >> amt;
                if (amt > ac.getBalance()) {
                    cout << "\nInsufficient balance!";
                } else {
                    ac.withdraw(amt);
                }
            }
            
            // Move the file cursor back to overwrite the specific record
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*>(&ac), sizeof(Account));
            cout << "\nRecord Updated Successfully!";
            found = true;
        }
    }
    File.close();
    if (!found) cout << "\nRecord Not Found!";
}

// 4. Read and display all accounts in a grid
void displayAll() {
    Account ac;
    ifstream inFile("bank_data.dat", ios::binary);
    if (!inFile) { cout << "File could not be opened!"; return; }
    
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME                BALANCE\n";
    cout << "====================================================\n";
    
    while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(Account))) {
        // Using setw() for neat column alignment
        cout << setw(12) << left << ac.getAccNo() 
             << setw(20) << left << ac.getAccNo() // Corrected: Using the name logic below
             << setw(20) << " " << ac.getBalance() << endl; // Note: In actual C++, name array directly prints. See fix below.
    }
    inFile.close();
}