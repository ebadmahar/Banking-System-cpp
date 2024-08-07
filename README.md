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

- `bank.cpp`: The main source code for the banking system.
- `users.txt`: Stores user information including usernames, passwords, and balances.
- `managers.txt`: Stores manager credentials.

## Setup

1. **Compile the Program**:
   To compile the program, use a C++ compiler like `g++`. Run the following command in your terminal:
   ```bash
   g++ bank.cpp
2. **Run the Program**:
 To Run the program, Run the following command in your terminal:
   ```bash
   ./a.exe
***USAGE***
**User Operations**
1. **Create Account**:

Select option 2 from the main menu.
Enter a new username and password.

2. **Login**:

Select option 1 from the main menu.
Enter your username and password.

After logging in, select option 1 from the user menu.

_Enter the amount to withdraw._

After logging in, select option 2 from the user menu.

_Enter the amount to deposit._

After logging in, select option 3 from the user menu.

_View Account Summary_

After logging in, select option 4 from the user menu.

_To Close Account_

After logging in, select option 4 from the user menu.

_To Logout_

**Manager Operations**

3. **Manager Login**:

Select option 3 from the main menu.
Enter the manager's username and password.

i) **View User List**

After logging in as a manager, select option 1 from the manager menu.
A list of users and their account details will be displayed.

ii) **Edit User Balance**

After logging in as a manager, select option 2 from the manager menu.
Enter the username of the account you wish to edit and the new balance.

iii) **Logout**

After logging in as a manager, select option 3 from the manager menu to log out.

4. **Exit**
