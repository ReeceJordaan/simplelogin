#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

bool IsLoggedIn() {

    string username, password, un, pw, filename;

    cout << "Enter username : ";
    cin >> username;

    cout << "Enter password : ";
    cin >> password;

    filename = username + ".txt";

    ifstream readAkun (filename.c_str());
    getline(readAkun, un);
    getline(readAkun, pw);

    if (un == username && pw == password) {

        return true;

    }

    else {

        return false;

    }

}

int main() {

    int choice;

    cout << "1) Register\n2) Login\nYour choice : ";
    cin >> choice;

    if ( choice == 1) {

        string username, password, filename;

        cout << "Select a username : ";
        cin >> username;

        cout << "Select a password : ";
        cin >> password;

        filename = username + ".txt";

        ofstream file (filename.c_str());
        file << username << endl;
        file << password << endl;
        file.close();

        main();

    }
    
    else if (choice == 2) {

        bool status = IsLoggedIn();

        if (!status) {

            cout << "False Login!" << endl;
            system ("PAUSE");
            return 0;

        }

        else {

            cout << "Succesfully loggged in!" << endl;
            system ("PAUSE");
            return 1;

        }

    }

    return 0;

}