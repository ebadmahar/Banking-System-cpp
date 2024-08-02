//Program is made by ebadmahar 
//github.com/ebadmahar
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

class Database 
{
public:
    Database() {
        loadUsersFromFile();
        loadManagersFromFile();
    }

    void saveUsersToFile() {
        ofstream userFile("users.txt");
        for (const auto &user : users) {
            userFile << user.first << " " << user.second.first << " " << user.second.second << endl;
        }
    }
//Program is made by ebadmahar 
//github.com/ebadmahar
    bool loadUsersFromFile() {
        ifstream userFile("users.txt");
        if (!userFile) return false;
        string line;
        while (getline(userFile, line)) {
            istringstream iss(line);
            string username, password;
            double balance;
            if (iss >> username >> password >> balance) {
                users[username] = make_pair(password, balance);
            }
        }
        return true;
    }

    bool loadManagersFromFile() {
        ifstream managerFile("managers.txt");
        if (!managerFile) return false;
        string line;
        while (getline(managerFile, line)) {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password) {
                managers[username] = password;
            }
        }
        return true;
    }
//Program is made by ebadmahar 
//github.com/ebadmahar
    bool usernameExists(const string &username) {
        return users.find(username) != users.end();
    }

    void createUser(const string &username, const string &password) {
        if (!usernameExists(username)) {
            users[username] = make_pair(password, 0.0);
            saveUsersToFile();
            cout << "User created successfully." << endl;
        } else {
            cout << "Username already exists. Choose a different username." << endl;
        }
    }

    void deleteUser(const string &username) {
        users.erase(username);
        saveUsersToFile();
    }

    void editUserBalance(const string &username, double newBalance) {
        if (usernameExists(username)) {
            users[username].second = newBalance;
            saveUsersToFile();
            cout << "Balance updated successfully." << endl;
        } else {
            cout << "User not found." << endl;
        }
    }

    bool login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        if (users.find(username) != users.end()) {
            cout << "Enter password: ";
            cin >> password;
            if (users[username].first == password) return true;
        }
        cout << "Incorrect username or password. Try again." << endl;
        return false;
    }
//Program is made by ebadmahar 
//github.com/ebadmahar
private:
    unordered_map<string, pair<string, double>> users;
    unordered_map<string, string> managers;
};

class Transaction {
public:
    string type;
    double amount;

    Transaction(const string &t, double a) : type(t), amount(a) {}
};

class BankAccount {
public:
    BankAccount(const string &username, Database &db) : username(username), open(true), balance(0), database(db) {
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string storedUsername, storedPassword;
            double storedBalance;
            if (iss >> storedUsername >> storedPassword >> storedBalance) {
                if (storedUsername == username) {
                    balance = storedBalance;
                    break;
                }
            }
        }
    }

    void Withdraw(double amount) {
        if (open && amount <= balance && amount > 0) {
            balance -= amount;
            transactions.emplace_back("Withdrawal", amount);
            cout << "Successfully withdrew $" << amount << " from your account." << endl;
            cout << "Your new balance is: " << balance << endl;
            updateBalanceInFile();
        } else {
            cout << "Invalid amount provided or account is deactivated." << endl;
        }
    }

    void Deposit(double amount) {
        if (open && amount > 0) {
            balance += amount;
            transactions.emplace_back("Deposit", amount);
            cout << "Successfully deposited $" << amount << " to your account." << endl;
            cout << "Your new balance is: " << balance << endl;
            updateBalanceInFile();
        } else {
            cout << "Invalid amount provided or account is deactivated." << endl;
        }
    }

    void PrintAccountSummary() {
        cout << "Account Holder: " << username << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Transactions:" << endl;
        for (const Transaction &transaction : transactions) {
            cout << transaction.type << ", Amount: $" << transaction.amount << endl;
        }
    }

    void CloseAccount(Database &database) {
        open = false;
        database.deleteUser(username);
        cout << "Your account has been closed." << endl;
    }

    void setUsername(const string &newUsername) {
        username = newUsername;
    }
//Program is made by ebadmahar 
//github.com/ebadmahar
    void updateBalanceInFile() {
        ifstream inputFile("users.txt");
        ofstream outputFile("temp.txt");
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string storedUsername, storedPassword;
            double storedBalance;
            if (iss >> storedUsername >> storedPassword >> storedBalance) {
                if (storedUsername == username) {
                    outputFile << username << " " << storedPassword << " " << balance << endl;
                } else {
                    outputFile << line << endl;
                }
            }
        }
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }

private:
    string username;
    bool open;
    double balance;
    vector<Transaction> transactions;
    Database &database;
};

class BankManager {
public:
    BankManager() {
        loadManagersFromFile();
    }

    bool login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        if (managers.find(username) != managers.end()) {
            cout << "Enter password: ";
            cin >> password;
            if (managers[username] == password) return true;
        }
        cout << "Incorrect login. Please try again." << endl;
        return false;
    }
//Program is made by ebadmahar 
//github.com/ebadmahar
    bool loadManagersFromFile() {
        ifstream managerFile("managers.txt");
        if (!managerFile) return false;
        string line;
        while (getline(managerFile, line)) {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password) {
                managers[username] = password;
            }
        }
        return true;
    }
//Program is made by ebadmahar 
//github.com/ebadmahar
private:
    unordered_map<string, string> managers;
};

int main() {
    Database database;
    BankManager manager;
    string username, password;
    double initBalance;
    BankAccount acc("", database);
    int choice;
    int bankingOption;
    double withdrawAmt;
    double depositAmt;
    bool loggedIn = false;
    bool managerLoggedIn = false;

    while (true) {
        if (!loggedIn) {
            cout << "1. Login\n2. Create Account\n3. Manager Login\n4. Exit\n";
            cin >> choice;

            if (choice == 1) {
                if (database.login()) {
                    loggedIn = true;
                    username = username;
                    acc.setUsername(username);
                }
            } else if (choice == 2) {
                cout << "Enter new username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                database.createUser(username, password);
                acc.setUsername(username);
            } else if (choice == 3) {
                if (manager.login()) {
                    loggedIn = true;
                    managerLoggedIn = true;
                    cout << "Manager Options\n";
                    cout << "1. Get List of Users and Account Details\n2. Edit User Balance\n3. Logout\n";
                    cin >> bankingOption;
                    if (bankingOption == 1) {
                        ifstream userFile("users.txt");
                        if (userFile.is_open()) {
                            string line;
                            while (getline(userFile, line)) {
                                cout << line << endl;
                            }
                        }
                    } else if (bankingOption == 2) {
                        string userToEdit;
                        double newBalance;
                        cout << "Enter username to edit: ";
                        cin >> userToEdit;
                        cout << "Enter new balance: ";
                        cin >> newBalance;
                        database.editUserBalance(userToEdit, newBalance);
                    } else if (bankingOption == 3) {
                        managerLoggedIn = false;
                        loggedIn = false;
                    }
                }
            } else if (choice == 4) {
                break;
            }
        } else {
            if (managerLoggedIn) {
                cout << "Manager Options\n";
                cout << "1. Get List of Users and Account Details\n2. Edit User Balance\n3. Logout\n";
                cin >> bankingOption;
                if (bankingOption == 1) {
                    ifstream userFile("users.txt");
                    if (userFile.is_open()) {
                        string line;
                        while (getline(userFile, line)) {
                            cout << line << endl;
                        }
                    }
                } else if (bankingOption == 2) {
                    string userToEdit;
                    double newBalance;
                    cout << "Enter username to edit: ";
                    cin >> userToEdit;
                    cout << "Enter new balance: ";
                    cin >> newBalance;
                    database.editUserBalance(userToEdit, newBalance);
                } else if (bankingOption == 3) {
                    loggedIn = false;
                }
            } else {
                cout << "User Options:\n";
                cout << "1. Withdraw\n2. Deposit\n3. Get Account Summary\n4. Close Account\n5. Logout\n";
                cin >> bankingOption;
                if (bankingOption == 1) {
                    cout << "Please enter withdrawal amount: ";
                    cin >> withdrawAmt;
                    acc.Withdraw(withdrawAmt);
                } else if (bankingOption == 2) {
                    cout << "Please enter deposit amount: ";
                    cin >> depositAmt;
                    acc.Deposit(depositAmt);
                } else if (bankingOption == 3) {
                    acc.PrintAccountSummary();
                } else if (bankingOption == 4) {
                    acc.CloseAccount(database);
                    loggedIn = false;
                } else if (bankingOption == 5) {
                    loggedIn = false;
                }
            }
        }
    }
    return 0;
}
//Program is made by ebadmahar 
//github.com/ebadmahar
//Program is made by ebadmahar 
//github.com/ebadmahar