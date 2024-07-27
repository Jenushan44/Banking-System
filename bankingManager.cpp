#include <iostream>

void checkBalance(double balance);
double makeDeposit();
double makeWithdrawal(double balance);

int main() {

    int choice;
    double balance = 0.0;

    std::cout<<"Welcome to the Bank Manager\n";

    do {
    std::cout<<"What would you like to do?\n";
    std::cout<<"1. Check Balance\n";
    std::cout<<"2. Make a Deposit\n";
    std::cout<<"3. Make a Withdrawal\n";
    std::cout<<"4. Exit\n";

    std::cin>>choice;

    switch(choice) {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            balance += makeDeposit();
            checkBalance(balance);
            break;
        case 3:
            balance -= makeWithdrawal(balance);
            checkBalance(balance);
            break;
        case 4: 
            std::cout<<"Thank you for using the bank manager";
            break;
        default:
            std::cout<<"Please enter a valid choice\n";
        }
    } while(choice != 4);
}

void checkBalance(double balance) {
    std::cout<<"Your balance is " << balance << "\n";
}

double makeDeposit() {
    
    double amount = 0.0;

    std::cout<<"Please enter the amount you would like to deposit: ";
    std::cin>>amount;
    return amount;
}

double makeWithdrawal(double balance) {

    double amount = 0.0;

    std::cout<<"Please enter the amount you would like to withdraw: ";
    std::cin>>amount;

    if (amount < 0) {
        std::cout<<"Please enter a valid amount to withdraw";
        return 0;
    } else if (amount > balance) {
        std::cout<<"Insufficient Funds";
        return 0;
    } 
    return amount;
}