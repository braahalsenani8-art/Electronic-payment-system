#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Payment {
protected:
    string name;
    int id;

public:
    Payment(string n) {
        name = n;
        id = rand() % 9000 + 1000;
    }

    virtual void pay(double a) = 0;

    void print(double a, string type) {
        cout << "\n-------------------\n";
        cout << "      INVOICE      \n";
        cout << "-------------------\n";
        cout << "ID: #" << id << endl;
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Amount: $" << a << endl;
        cout << "Status: Success\n";
        cout << "-------------------\n\n";
    }

    virtual ~Payment() {}
};

class Cash : public Payment {
public:
    Cash(string n) : Payment(n) {}

    void pay(double a) override {
        print(a, "Cash");
    }
};

class CreditCard : public Payment {
private:
    string card;
public:
    CreditCard(string n, string c) : Payment(n) {
        card = c;
    }

    void pay(double a) override {
        print(a, "Credit Card (" + card + ")");
    }
};

class PayPal : public Payment {
private:
    string email;
public:
    PayPal(string n, string e) : Payment(n) {
        email = e;
    }

    void pay(double a) override {
        print(a, "PayPal (" + email + ")");
    }
};

class BankTransfer : public Payment {
private:
    string acc;
public:
    BankTransfer(string n, string ac) : Payment(n) {
        acc = ac;
    }

    void pay(double a) override {
        print(a, "Bank (" + acc + ")");
    }
};

int main() {
    srand(time(0));

    string name;
    double amount;
    int ch;
    Payment* p = NULL;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Amount: ";
    cin >> amount;

    cout << "\n1. Cash\n2. Credit Card\n3. PayPal\n4. Bank\n";
    cout << "Choose: ";
    cin >> ch;

    if (ch == 1) {
        p = new Cash(name);
    }
    else if (ch == 2) {
        string card;
        cout << "Enter Card Num: ";
        cin >> card;
        p = new CreditCard(name, card);
    }
    else if (ch == 3) {
        string email;
        cout << "Enter Email: ";
        cin >> email;
        p = new PayPal(name, email);
    }
    else if (ch == 4) {
        string acc;
        cout << "Enter Account Num: ";
        cin >> acc;
        p = new BankTransfer(name, acc);
    }

    if (p != NULL) {
        p->pay(amount);
        delete p;
    }

    return 0;
}
