#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice;
    string username, password;
    string storedUser, storedPass;

    cout << "----- Login and Registration System -----" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ofstream file("users.txt", ios::app);
        file << username << " " << password << endl;
        file.close();

        cout << "\nRegistration Successful!" << endl;
    }

    else if (choice == 2)
    {
        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ifstream file("users.txt");
        bool found = false;

        while (file >> storedUser >> storedPass)
        {
            if (username == storedUser && password == storedPass)
            {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
        {
            cout << "\nLogin Successful!" << endl;
        }
        else
        {
            cout << "\nInvalid Username or Password!" << endl;
        }
    }

    else
    {
        cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}