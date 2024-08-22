#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,string>database;
class BankApplication{
    public:
    static int count;
    //Encapsulation
    protected:
    string userName;
    string MobileNo;
    string BankId;
    int money;
    public:
    BankApplication(string BankId,string psswd)
    {
        this->BankId=BankId;
        database[BankId]=psswd;
        count++;
    }
    void setUserName(string userName)
    {
        this->userName=userName;
    }
    void setMobileNo(string MobileNo)
    {
        this->MobileNo=MobileNo;
    }
    void setMoney(int money=0)
    {
        this->money=money;
    }
    string getUserName(string psswd)
    {
        if(database[this->BankId]!=psswd) return "ACCESS DENIED";
        else return this->userName;
    }
    string getMobileNo(string psswd)
    {
        if(database[this->BankId]!=psswd) return "ACCESS DENIED";
        else return this->MobileNo;
    }
     string getBankId(string psswd)
    {
        if(database[this->BankId]!=psswd) return "ACCESS DENIED";
        else return this->BankId;
    }
    int getMoney(string psswd)
    {
        if(database[this->BankId]!=psswd)
        {
            cout<<"Access Denied"<<endl;
            return -1;
        }
        else return this->money;
    }
    //Abstraction
    void withdrawMoney(string psswd, int amount) {
        if (validateAccess(psswd)) {
            if (this->money >= amount) {
                this->money -= amount;
                cout << "Withdrew $" << amount << " from account " << BankId << endl;
            } else {
                cout << "Insufficient funds" << endl;
            }
        } else {
            cout << "Access Denied" << endl;
        }
    }
    void Netbanking(string Bankid,string psswd)
    {
        if(validateAccess(psswd)){
            cout<<"NetBanking Task Is Performed"<<endl;
        }
    }
    public:
     bool validateAccess(string psswd) const {
        return database.at(this->BankId) == psswd;
    }
};
class SavingsAccount : public BankApplication {
private:
    double interestRate;
    int minBalance;
    int interestPeriod; // in months

public:
    SavingsAccount(const string& bankId, const string& password, double rate, int minBal, int period)
        : BankApplication(bankId, password), interestRate(rate), minBalance(minBal), interestPeriod(period) {}

    void setInterestRate(double rate) {
        this->interestRate = rate;
    }

    double getInterestRate(const string& password) const {
        return validateAccess(password) ? this->interestRate : -1.0;
    }

    void setMinBalance(int minBal) {
        this->minBalance = minBal;
    }

    int getMinBalance(const string& password) const {
        return validateAccess(password) ? this->minBalance : -1;
    }

    void setInterestPeriod(int period) {
        this->interestPeriod = period;
    }

    int getInterestPeriod(const string& password) const {
        return validateAccess(password) ? this->interestPeriod : -1;
    }

    void applyInterest(const string& password) {
        if (validateAccess(password)) {
            int interest = static_cast<int>((money * interestRate * interestPeriod) / 1200);
            money += interest;
            cout << "Applied interest: $" << interest << " to account " << BankId << endl;
        } else {
            cout << "Access Denied" << endl;
        }
    }

    void displayAccountDetails(const string& password) const {
        if (validateAccess(password)) {
            cout << "Savings Account Details:" << endl;
            cout << "User Name: " << userName << endl;
            cout << "Mobile No: " << MobileNo << endl;
            cout << "Bank ID: " << BankId << endl;
            cout << "Balance: $" << money << endl;
            cout << "Interest Rate: " << interestRate << "%" << endl;
            cout << "Minimum Balance: $" << minBalance << endl;
            cout << "Interest Period: " << interestPeriod << " months" << endl;
        } else {
            cout << "Access Denied" << endl;
        }
    }
};
class CorporateAccout:public BankApplication{
    void brochure()
    {
        cout<<"Interest Rate is 5% \n Maintainence charge is 500Rs per Annum"<<endl;
    }
};
int BankApplication::count=0;
int main()
{
    BankApplication *user1=new BankApplication("98856677443","12345");
    BankApplication *user2=new BankApplication("98856677    413","13345");
    user1->setUserName("Yash");
    cout<<user1->getUserName("12345");
    // cout<<BankApplication::count;

}