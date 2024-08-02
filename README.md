# Banking-System-cpp
# Banking System

This is a simple banking system implemented in C++ that allows users to manage their bank accounts. The system supports user and manager functionalities, including account creation, login, balance management, and administrative tasks.

## Features

- **User Management**:
  - Create a new user account.
  - Log in to an existing user account.
  - Withdraw funds.
  - Deposit funds.
  - View account summary.
  - Close user account.

- **Manager Management**:
  - Log in as a manager.
  - View list of users and account details.
  - Edit user account balances.

## Files

- `main.cpp`: The main source code for the banking system.
- `users.txt`: Stores user information including usernames, passwords, and balances.
- `managers.txt`: Stores manager credentials.

## Setup

1. **Compile the Program**:
   To compile the program, use a C++ compiler like `g++`. Run the following command in your terminal:
   ```bash
   g++ -o banking_system main.cpp
2. **Run the Program**:
```bash
    ./banking_system
```
    **Usage**
**User Operations**
1. **Create Account**:

Select option 2 from the main menu.
Enter a new username and password.

2. **Login**:

Select option 1 from the main menu.
Enter your username and password.

3. **Withdraw Funds**:

After logging in, select option 1 from the user menu.
Enter the amount to withdraw.

4. **Deposit Funds**:

After logging in, select option 2 from the user menu.
Enter the amount to deposit.
5. **View Account Summary**:

After logging in, select option 3 from the user menu.
6. **Close Account**:

After logging in, select option 4 from the user menu.

**Manager Operations**

1. **Manager Login**:

Select option 3 from the main menu.
Enter the manager's username and password.

2. **View User List**:

After logging in as a manager, select option 1 from the manager menu.
A list of users and their account details will be displayed.
3. **Edit User Balance**:

After logging in as a manager, select option 2 from the manager menu.
Enter the username of the account you wish to edit and the new balance.

4.**Logout** :

After logging in as a manager, select option 3 from the manager menu to log out.
