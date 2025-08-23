#include <iostream>

class BankAcc{

    private:
    std::string OwName;
    int AccNum;
    double Balance;
    public:
    BankAcc(std::string OwName, int accnum, double balance){
        this->OwName = OwName;
        AccNum = accnum;
        Balance = balance;
    }
    void deposit(double amount){
        Balance += amount;
    }
    void withdraw(double amount){
        if(amount <= Balance){
            Balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }
    double getBalance(){
        return Balance;
    }
    std::string getName(){
        return OwName;
    }
    void displayDetails(){
        std::cout << "Account Number: " << AccNum << std::endl;
        std::cout << "Owner Name: " << OwName << std::endl;
        std::cout << "Balance: $" << Balance << std::endl;
    }




};

int main() {

    BankAcc acc("Alice", 12345, 1000.0);

    acc.deposit(500); 
    acc.withdraw(200); 
    acc.displayDetails(); 



    return 0;
    
}

// Encapsulation is important in a bank account class to protect sensitive data like acc balance or number.
// It prevents unauthorized access and modifications, ensuring data integrity and security.