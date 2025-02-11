#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

struct userDC {
string name, pass, email, std_info;
string eventPTYPE;
double balance;
vector<double> tuitionFee;
vector<double> misceFee;
vector<double> eventPart;
vector<string> notifications;
};

struct refundREQS {
    string name, refundREQ, refundREA;
};

vector<userDC> usersD;
vector<refundREQS> refundREQUESTS;
string REGISname;
double adminCODE = 2706;

string adRESPO(string inquiry);
void Registration();
void SAVEDFILES();
void LOADFILES();
void Login();
void Exit();
void roles();
void AdminMENU();
void AdminLOGIN();
void EWallet();
void cashIN();
void sendMONE();
void payREQS();
void curBA();
void accENTER();
void noTIF();
void tuitionFEE();
void misceFEE();
void eventPART();
void reFUND();
void inQUIRE();
void refundADMIN();
void tuitionADMIN();
void misceADMIN();
void eventADMIN();

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
    newUSERS.tuitionFee = {};
    newUSERS.misceFee = {};
    newUSERS.eventPart = {};
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
        } if (REGISname == "") {
            break;
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
        cout << "\n6. Notifications";
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
            noTIF();
            break;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        } if (REGISname == "") {
            break;
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
        sender->notifications.push_back("You sent " + to_string(amountSEND) + " PHP to " + recipientNAME);
        recipient->notifications.push_back(REGISname + " sent you " + to_string(amountSEND) + " PHP");
        SAVEDFILES();
        cout << "\n[TRANSFER SUCCESSFUL]\n";
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
        cout << "\n4. Go Back";
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
            case 4:
            return;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        }
        }
    }

    void curBA() {
        for (const auto &user : usersD) {
            if (user.name == REGISname) {
                cout << "\nYOUR CURRENT BALANCE: " << user.balance << " PHP\n";
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
        cout << "\n4. Go Back";
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
            REGISname = "";
            return;
            case 4:
            return;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        }
    }
    }

    void noTIF() {
        cout << "\n[NOTIFICATIONS]";
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                if (user.notifications.empty()) {
                    cout << "\nNo new notifications\n";
                    return;
                } for (size_t i = 0; i < user.notifications.size(); ++i) {
                    cout << "[" << (i+1) << "] " << user.notifications[i];
                } user.notifications.clear();
                SAVEDFILES();
                return;
            }
        } cout << "\n[ERROR USER NOT FOUND]";
    }

    void reFUND() {
        refundREQS newREQS;
        newREQS.name = REGISname;
        cout << "\n[REQUEST A REFUND]";
        cout << "\nType of Refund: ";
        getline(cin, newREQS.refundREQ);
        cout << "\nReason for refund: ";
        getline(cin, newREQS.refundREA);
        refundREQUESTS.push_back(newREQS);
        cout << "\n[REQUEST FOR REFUND SUCCESS]\nWAIT FOR FURTHER NOTICE\n";
    }

    void tuitionFEE() {
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                if (user.tuitionFee.empty()) {
                    cout << "\n[THERE ARE NO TUITION DUE]\n";
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
                    user.tuitionFee.erase(remove(user.tuitionFee.begin(), user.tuitionFee.end(), tuitionPYT), user.tuitionFee.end());
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
                if (user.misceFee.empty()) {
                    cout << "\n[THERE ARE NO MISCELLANEOUS DUE]\n";
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
                    user.misceFee.erase(remove(user.misceFee.begin(), user.misceFee.end(), miscePYT), user.misceFee.end());
                    SAVEDFILES();
                    cout << "\n[PAYMENT SUCCESSFUL]";
                    cout << "\nAMOUNT PAID: " << miscePYT << " PHP";
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance << " PHP";
                    cout << "\n[ADMIN WILL SOON EMAIL UPDATED MISCELLANEOUS INFORMATION]\n";
                } else {
                    cout << "\n[ERROR]\nDUE TO INSUFFIECIENT BALANCE\n";
                } return;
            }
        } cout << "\n[ERROR]\nUSER NOT FOUND";
    }

    void eventPART() {
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                if (user.eventPart.empty()) {
                    cout << "\n[THERE ARE NO EVENTS DUE]\n";
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
                    user.eventPart.erase(remove(user.eventPart.begin(), user.eventPart.end(), eventPYT), user.eventPart.end());
                    SAVEDFILES();
                    cout << "\n[PAYMENT SUCCESSFUL]";
                    cout << "\nAMOUNT PAID: " << eventPYT << " PHP";
                    cout << "\nREMAINING E-WALLET BALANCE: " << user.balance << " PHP\n";
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
            cout << "\n[INCORRECT OUTPUT]\n";
        }
    }
    }

    void AdminMENU() {
        int choice;
        while (true) {
        cout << "\n[ADMIN MENU]";
        cout << "\n1. Requests for refund";
        cout << "\n2. Navigate Tuition Updates";
        cout << "\n3. Navigate Miscellaneous Updates";
        cout << "\n4. Navigate Event Payment Updates";
        cout << "\n5. Log out";
        cout << "\nEnter: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
            refundADMIN();
            break;
            case 2:
            tuitionADMIN();
            break;
            case 3:
            misceADMIN();
            break;
            case 4:
            eventADMIN();
            break;
            case 5:
            cout << "\n[LOGGING OUT]\n";
            return;
            default:
            cout << "\n[PLEASE ENTER A VALID INPUT]\n";
        }
    }
    }

    void refundADMIN() {
        double refundAMT;
        cout << "\n[REFUND REQUESTS]";
        if (refundREQUESTS.empty()) {
            cout << "\n--NO REFUND REQUESTS--\n";
            return;
        } for (size_t i = 0; i < refundREQUESTS.size(); i++) {
        const auto &refund = refundREQUESTS[i];
            cout << "\nREQUEST #" << (i + 1);
            cout << "\nNAME: " << refund.name;
            cout << "\nREFUND REQUEST: " << refund.refundREQ[i];
            cout << "\nREASON FOR REFUND: " << refund.refundREA[i];
            cout << "\nEnter amount of refund: ";
            cin >> refundAMT;
            cin.ignore();
            for (auto &user : usersD) {
                if (user.name == refund.name) {
                    user.balance += refundAMT;
                    user.notifications.push_back("Your refund request for " + to_string(refundAMT) + " PHP has been processed");
                    SAVEDFILES();
                    cout << "\n[REFUND SUCCESSFUL]\n";
                    break;
                }
            } cout << "\n[ERROR]\n";
        } refundREQUESTS.clear();
    }

    void tuitionADMIN() {
        double tuitionDUE;
        cout << "\n[NAVIGATE TUITION UPDATES]\n";
        cout << "\nEnter amount of tuition due: ";
        cin >> tuitionDUE;
        cin.ignore();
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                user.tuitionFee.push_back(tuitionDUE);
                user.notifications.push_back("Tuition fee of " + to_string(tuitionDUE) + " PHP has been assigned to your account.");
                SAVEDFILES();
                cout << "\nUPDATED TUITION DUE FOR: " << user.name << "\n";
                return;
            }
        }
    }

    void misceADMIN() {
        double misceDUE;
        cout << "\n[NAVIGATE MISCELLANEOUS UPDATES]\n";
        cout << "\nEnter amount of miscellaneous due: ";
        cin >> misceDUE;
        cin.ignore();
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                user.misceFee.push_back(misceDUE);
                user.notifications.push_back("Miscellaneous fee of " + to_string(misceDUE) + " PHP has been assigned to your account.");
                SAVEDFILES();
                cout << "\nUPDATED MISCELLANEOUS DUE FOR: " << user.name << "\n";
                return;
            }
        }
    }

    void eventADMIN() {
        double eventDUE;
        cout << "\n[NAVIGATE EVENTS UPDATES]";
        cout << "\nEnter amount of events due: ";
        cin >> eventDUE;
        cin.ignore();
        for (auto &user : usersD) {
            if (user.name == REGISname) {
                user.eventPart.push_back(eventDUE);
                user.notifications.push_back("Event fee of " + to_string(eventDUE) + " PHP has been assigned to your account.");
                SAVEDFILES();
                cout << "\nUPDATED EVENT DUE FOR: " << user.name << "\n";
                return;
            }
        }
    }

    void inQUIRE() {
        cout << "\n[INQUIRY]";
        do {
            cout << "\nEnter inquiry: ";
            string inquiry;
            getline(cin, inquiry);
            string response = adRESPO(inquiry);
            cout << "\nresponse: " << response << "\n";
            cout << "\n[WOULD YOU LIKE TO SEND ANOTHER INQUIRY?]";
            cout << "\nEnter: ";
            string answer;
            getline(cin, answer);
            if (!(answer == "yes")) {
                break;
            }
        } while (true);
    }

    string adRESPO(string inquiry) {
        if (inquiry.find("creator") != string::npos || inquiry.find("program") != string::npos) {
            return "Kenth Jarren S. Mariano, is the name of the creator of this program.";
        } if (inquiry.find("purpose") != string::npos) {
            return "This program was created for practice program of the creator";
        } if (inquiry.find("updates") != string::npos) {
            return "provide suggestions, then the creator will work on it :DD";
        } return "\n[PLEASE EMAIL THE CREATOR FOR ENTERPRISE INQUIRIES]\nEMAIL OF THE CREATOR: kenthjarren2706@gmail.com\n";
    }

    void SAVEDFILES() {
        ofstream file("users.txt");
        for (const auto &user : usersD) {
            file << "NAME: " << user.name << "\n"
            << "PASSWORD: " << user.pass << "\n"
            << "EMAIL: " << user.email << "\n"
            << "ACADEMIC LEVEL/STRAND/COURSE: " << user.std_info << "\n"
            << "BALANCE: " << user.balance << "\n";
            file << "TUITION FEE: ";
            for (double fee : user.tuitionFee) {
                file << fee << " ";
            } file << "\n";
            
            file << "MISCELLANEOUS FEE: ";
            for (double fee : user.misceFee) {
                file << fee << " ";
            } file << "\n";
            
            file << "EVENTS DUE: ";
            for (double fee : user.eventPart) {
                file << fee << " ";
            } file << "\n";

        } file.close();
    }

    void LOADFILES() {
        ifstream file("users.txt");
        userDC user;
        string line;
        while (getline(file, line)) {
            if (line.find("NAME: ") != string::npos) {
                user.name = line.substr(6);
            } if (line.find("PASSWORD: ") != string::npos) {
                user.pass = line.substr(10);
            } if (line.find("EMAIL: ") != string::npos) {
                user.email = line.substr(7);
            } if (line.find("ACADEMIC LEVEL/STRAND/COURSE: ") != string::npos) {
                user.std_info = line.substr(30);
            } if (line.find("BALANCE: ") != string::npos) {
                user.balance = stod(line.substr(9));
            } if (line.find("TUITION FEE: ") != string::npos) {
                stringstream ss(line.substr(14));
                double fee;
                while (ss >> fee) {
                    user.tuitionFee.push_back(fee);
                }
            } if (line.find("MISCELLANEOUS FEE: ") !=string::npos) {
                stringstream ss(line.substr(11));
                double fee;
                while (ss >> fee) {
                    user.misceFee.push_back(fee);
                }
            } if (line.find("EVENTS DUE: ") != string::npos) {
                stringstream ss(line.substr(12));
                double fee;
                while (ss >> fee) {
                    user.eventPart.push_back(fee);
                }
            } if (line.empty() || file.peek() == EOF) {
                usersD.push_back(user);
                user = userDC();
            }
        }
        file.close();
    }
