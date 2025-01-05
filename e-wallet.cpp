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
double adminCODE = 2706;

void Registration();
void SAVEDFILES();
void LOADFILES();
void Login();
void Exit();
void roles();
void AdminMENU();
void AdminLOGIN();
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
void reFUND();
void inQUIRE();

int main() {
    while (true) {
    cout << "\n[E-WALLET IN DYCI]";
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
    cout << "\n[REGISTRATION SUCCESSFUL]\n";
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
            cout << "\n[LOGIN SUCCESSFUL]\n";
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
            AdminLOGIN();
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
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
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
                cout << "\n[SUCCESSFUL]\n";
                cout << "\nCURRENT BALANCE: " << user.balance << " PHP\n";
                return;
            }
        } cout << "\n[ERROR]\n";
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
            cout << "\n[ERROR]\n RECIPIENT NOT FOUND\n";
            return;
        } if (sender->balance < amountSEND) {
            cout << "\n[ERROR]\n INSUFFICIENT BALANCE\n";
            return;
        } sender->balance -= amountSEND;
        recipient->balance += amountSEND;
        SAVEDFILES();
        cout << "\n[TRANSFER SUCCESSFUL]\n";
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
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        }
        }
    }

    void curBA() {
        for (const auto &user : usersD) {
            if (user.name == REGISname) {
                cout << "\nYOUR CURRENT BALANCE: " << user.balance << " PHP";
                return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void accENTER() {
        int choice;
        while (true) {
        cout << "\n[ACCOUNT CENTER]";
        cout << "\n1. Ask for Refunds";
        cout << "\n2. Inquire";
        cout << "\n3. Logout";
        cout << "\nEnter: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
            reFUND();
            break;
            case 2:
            inQUIRE();
            break;
            case 3:
            cout << "\n[LOGGING OUT]\n";
            return;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        }
    }
    }

    void reFUND() {
        cout << "\n[REFUND]";
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
                    cout << "\nAMOUNT PAID: " << tuitionPYT << " PHP";
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance << " PHP";
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
                    cout << "\nAMOUNT PAID: " << miscePYT << " PHP";
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance << " PHP";
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
                    cout << "\nAMOUNT PAID: " << eventPYT << " PHP";
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance << " PHP";
                } else {
                    cout << "\n[ERROR]\nDUE TO INSUFFIECIENT BALANCE\n";
                } return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void AdminLOGIN() {
        while (true) {
        double adminCODELOG;
        cout << "\n[ADMIN LOGIN]";
        cout << "\nENTER ADMIN USER CODE: ";
        cin >> adminCODELOG;
        cin.ignore();
        if (adminCODELOG == adminCODE) {
            AdminMENU();
            break;
        } else {
            cout << "\n[INCORRECT OUTPUT]";
            return;
        }
    }
    }

    void AdminMENU() {
        cout << "\n[ADMIN MENU]";
        cout << "\n";
    }

    void SAVEDFILES() {
        ofstream file("users.txt");
        for (const auto &user : usersD) {
            file << "NAME: " << user.name << "\n" << "PASSWORD: " << user.pass << "\n" << "EMAIL: "
            << user.email << "\n" << "ACADEMIC LEVEL/STRAND/COURSE: " << user.std_info << "\n" << "BALANCE: " << user.balance << "\n" << user.tuitionFee << "\n" << user.misceFee << "\n" << user.eventPart << "\n";
        } file.close();
    }

    void LOADFILES() {
        ifstream file("users.txt");
        userDC user;
        while (file >> user.name >> user.pass >> user.email >> user.balance >> user.std_info >> user.tuitionFee >> user.misceFee >> user.eventPart) {
            usersD.push_back(user);
        } file.close();
    }
