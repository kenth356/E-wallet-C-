#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct userDC {
string name, pass, email, std_info;
string eventPTYPE;
double balance;
double tuitionFee;
double misceFee;
double eventPart;
};

vector<userDC> usersD;
string REGISname;

void Registration();
void SAVEDFILES();
void LOADFILES();
void Login();
void Exit();
void roles();
void AdminMENU();
void roleSELECT();
void EWallet();
void cashIN();
void sendMONE();
void payREQS();
void curBA();
void accENTER();
void tuitionFEE();
void misceFEE();
void eventPART();
int main() {
    LOADFILES();
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
    userDC newUSERS;
    cout << "\n--REGISTRATION--";
    cout << "\nENTER YOUR NAME: ";
    getline(cin, newUSERS.name);
    cout << "\nCREATE YOUR PASSWORD: ";
    getline(cin, newUSERS.pass);
    cout << "\nENTER YOUR EMAIL: ";
    getline(cin, newUSERS.email);
    cout << "\nENTER ACADEMIC LEVEL/STRAND/COURSE: ";
    getline(cin, newUSERS.std_info);
    newUSERS.balance = 0.0;
    newUSERS.tuitionFee = 0.0;
    usersD.push_back(newUSERS);
    SAVEDFILES();
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
    for (const auto &user : usersD) {
        if (user.name == Loginname && user.pass == Loginpass && user.email == Loginemail) {
            cout << "\n[LOGIN SUCCESSFUL]";
            REGISname = user.name;
            roles();
            return;
        }
    } cout << "\n[INCORRECT OUTPUT]\n[PLEASE TRY AGAIN]\n";
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
        cout << "\n4. Go Back";
        cout << "\nEnter: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
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
        cout << "\n4. Current Balance";
        cout << "\n5. Account Center";
        cout << "\n6. Go Back";
        cout << "\nEnter: ";
        int answer;
        cin >> answer;
        cin.ignore();
        switch (answer) {
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
            curBA();
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

    void cashIN() {
        double amountCASHIN;
        cout << "\n[CASH-IN]";
        cout << "\nEnter Cash Amount: ";
        cin >> amountCASHIN;
        cin.ignore();
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                user.balance += amountCASHIN;
                SAVEDFILES();
                cout << "\n[SUCCESSFUL]";
                cout << "\nCURRENT BALANCE: " << user.balance;
                return;
            }
        } cout << "\n[ERROR]";
    }

    void sendMONE() {
        string recipientNAME;
        double amountSEND;
        cout << "\n[SEND/TRANSFER MONEY]";
        cout << "\nEnter recipient name: ";
        getline(cin, recipientNAME);
        cout << "\nEnter amount to transfer: ";
        cin >> amountSEND;
        cin.ignore();
        userDC *sender = nullptr, *recipient = nullptr;
        for (auto &user : usersD) {
            if (user.name == REGISname) sender = &user;
            if (user.name == recipientNAME) recipient = &user;
        } if (!recipient) {
            cout << "\n[ERROR]\n RECIPIENT NOT FOUND";
            return;
        } if (sender->balance < amountSEND) {
            cout << "\n[ERROR]\n INSUFFICIENT BALANCE";
            return;
        } sender->balance -= amountSEND;
        recipient->balance += amountSEND;
        SAVEDFILES();
        cout << "\n[TRANSFER SUCCESSFUL]";
        return;
    }

    void payREQS() {
        string requisiteNAME;
        int answer;
        double amountPAY;
        while (true) {
        cout << "\n[PAY SCHOOL REQUISITES]";
        cout << "\n1. Tuition Fee";
        cout << "\n2. Miscellaneous Fee/s";
        cout << "\n3. Event Participation";
        cout << "\nEnter: ";
        cin >> answer;
        cin.ignore();
        switch (answer) {
            case 1:
            tuitionFEE();
            break;
            case 2:
            misceFEE();
            break;
            case 3:
            eventPART();
            break;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]";
        }
        }
    }

    void curBA() {
        for (const auto &user : usersD) {
            if (user.name == REGISname) {
                cout << "\nYOUR CURRENT BALANCE: " << user.balance;
                return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void tuitionFEE() {
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                if (user.tuitionFee == 0) {
                    cout << "\n[ERROR]";
                    return;
                }
                double tuitionPYT;
                string tuitionOPTIONS;
                cout << "\n[PAYMENTS OF TUITION FEE]";
                cout << "\nPayment Option: ";
                getline(cin, tuitionOPTIONS);
                cout << "\nEnter amount to pay: ";
                cin >> tuitionPYT;
                cin.ignore();
                if (user.balance >= tuitionPYT) {
                    user.balance -= tuitionPYT;
                    user.tuitionFee -= tuitionPYT;
                    SAVEDFILES();
                    cout << "\n[PAYMENT SUCCESSFUL]";
                    cout << "\nAMOUNT PAID: " << tuitionPYT;
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance;
                    cout << "\n[ADMIN WILL EMAIL YOUR NEW TUITION FEE INFORMATION]\n";
                } else {
                    cout << "\n[ERROR]\nDUE TO INSUFFIECIENT BALANCE\n";
                } return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void misceFEE() {
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                if (user.misceFee == 0) {
                    cout << "\n[ERROR]";
                    return;
                }
                double miscePYT;
                string misceTYPE;
                cout << "\n[PAYMENTS OF MISCELLANEOUS FEE]";
                cout << "\nType of miscellaneous: ";
                getline(cin, misceTYPE);
                cout << "\nEnter amount to pay: ";
                cin >> miscePYT;
                cin.ignore();
                if (user.balance >= miscePYT) {
                    user.balance -= miscePYT;
                    user.misceFee -= miscePYT;
                    SAVEDFILES();
                    cout << "\n[PAYMENT SUCCESSFUL]";
                    cout << "\nAMOUNT PAID: " << miscePYT;
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance;
                    cout << "\n[ADMIN WILL SOON EMAIL UPDATED MISCELLANEOUS INFORMATION]";
                } else {
                    cout << "\n[ERROR]\nDUE TO INSUFFIECIENT BALANCE\n";
                } return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void eventPART() {
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                if (user.eventPart == 0) {
                    cout << "\n[ERROR]";
                    return;
                }
                double eventPYT;
                string eventTYPE;
                cout << "\n[PAYMENTS OF EVENTS NECESSITIES]";
                cout << "\nType of event necessity: ";
                getline(cin, eventTYPE);
                cout << "\nEnter amount to pay: ";
                cin >> eventPYT;
                cin.ignore();
                if (user.balance >= eventPYT) {
                    user.balance -= eventPYT;
                    user.eventPart -= eventPYT;
                    SAVEDFILES();
                    cout << "\n[PAYMENT SUCCESSFUL]";
                    cout << "\nAMOUNT PAID: " << eventPYT;
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance;
                } else {
                    cout << "\n[ERROR]\nDUE TO INSUFFIECIENT BALANCE\n";
                } return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void SAVEDFILES() {
        ofstream file("users.txt");
        if (!file.is_open()) {
            cout << "\n[ERROR]";
            return;
        } for (const auto &user : usersD) {
            file << user.name << " " << user.pass << " "
            << user.email << " " << user.balance << " " << user.tuitionFee << user.misceFee << " " << user.eventPart << "\n";
        } file.close();
    }

    void LOADFILES() {
        ifstream file("users.txt");
        if (!file.is_open()) {
            cout << "\n[NO USER DATA FOUND]";
            return;
        } userDC user;
        while (file >> user.name >> user.pass >> user.email >> user.balance >> user.tuitionFee >> user.misceFee >> user.eventPart) {
            usersD.push_back(user);
        } file.close();
    }
