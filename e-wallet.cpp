#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string name, pass, email;
bool bypass = true;
void Registration();
void Login();
void Exit();
void roles();
void AdminMENU();
void roleSELECT();
void EWallet();
void cashIN();
void sendMONE();
void payREQS();
void proMOS();
void accENTER();
int main() {
    bool bypass = true;
    while (true) {
    cout << "[E-WALLET IN DYCI]";
    cout << "\n1. Registration";
    cout << "\n2. Login";
    cout << "\n3. Exit";
    cout << "\nEnter: ";
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
        Registration();
        break;
        case 2:
        Login();
        break;
        case 3:
        Exit();
        return 0;
        default:
        cout << "\n[PLEASE ENTER A VALID INPUT]\n";
    }
}
return 0;
}

    void Registration() {
    cout << "\n--REGISTRATION--";
    cout << "\nENTER YOUR NAME: ";
    getline(cin, name);
    cout << "\nCREATE YOUR PASSWORD: ";
    getline(cin, pass);
    cout << "\nENTER YOUR EMAIL: ";
    getline(cin, email);
    cout << "\n[REGISTRATION SUCCESSFUL]";
    return;
}

    void Login() {
    while (true) {
    string Loginname, Loginpass, Loginemail;
    cout << "\n--LOGIN--";
    cout << "\nENTER YOUR NAME: ";
    getline(cin, Loginname);
    cout << "\nENTER YOUR PASSWORD: ";
    getline(cin, Loginpass);
    cout << "\nENTER YOUR EMAIL: ";
    getline(cin, Loginemail);
    
    if (Loginname == name && Loginpass == pass && Loginemail == email) {
        cout << "\n[LOGIN SUCCESSFUL]";
        roles();
        break;
    } else {
        cout << "\n[INCORRECT OUTPUT]\n[PLEASE TRY AGAIN]";
    }
    }
    }

    void Exit() {
        cout << "\nTHANK YOU FOR USING MY INNOVATED E-WALLET!!";
    }

    void roles() {
        while (true) {
        cout << "\n--ROLES MENU--";
        cout << "\n1. Faculty";
        cout << "\n2. Student";
        cout << "\n3. Admin";
        cout << "\n4. Choose a role";
        cout << "\n5. Go Back";
        cout << "\nEnter: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (true) {
            case 1:
            EWallet();
            break;
            case 2:
            EWallet();
            break;
            case 3:
            AdminMENU();
            break;
            case 4:
            roleSELECT();
            break;
            case 5:
            return;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        }
    }
    }

    void EWallet() {
        while (true) {
        cout << "\n[WELCOME TO DYCIAN E-WALLET]";
        cout << "\n1. Cash-In";
        cout << "\n2. Send Money";
        cout << "\n3. Pay School Requisites";
        cout << "\n4. Promos";
        cout << "\n5. Account Center";
        cout << "\n6. Go Back";
        cout << "\nEnter: ";
        int answer;
        cin >> answer;
        cin.ignore();
        switch (true) {
            case 1:
            cashIN();
            break;
            case 2:
            sendMONE();
            break;
            case 3:
            payREQS();
            break;
            case 4:
            proMOS();
            break;
            case 5:
            accENTER();
            break;
            case 6:
            return;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]";
        }
    }
    }
