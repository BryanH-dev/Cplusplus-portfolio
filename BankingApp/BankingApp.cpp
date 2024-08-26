#include <iostream>
#include <iomanip> // for std::setprecision
#include <cmath>   // for pow function

using namespace std;

// Function to get user input
void getUserInput(double& initialInvestment, double& monthlyDeposit, double& annualInterest, int& numYears) {
    cout << "Welcome to Airgead Banking Investment Calculator!" << endl;
    cout << "Enter the Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << "Enter the Monthly Deposit Amount: $";
    cin >> monthlyDeposit;
    cout << "Enter the Annual Interest Rate (as a percentage): ";
    cin >> annualInterest;
    cout << "Enter the Number of Years: ";
    cin >> numYears;
}

// Function to calculate investment balances and earned interest
void calculateInvestment(double initialAmount, double monthlyDeposit, double annualInterest, int numYears, double* balances, double* earnedInterests) {
    int months = numYears * 12;
    double monthlyInterestRate = annualInterest / 100 / 12;

    double balance = initialAmount;

    for (int month = 0; month < months; ++month) {
        double interest = (balance + monthlyDeposit) * monthlyInterestRate;
        balance += monthlyDeposit + interest;
        balances[month] = balance;
        earnedInterests[month] = interest;
    }
}

// Function to calculate balance without additional monthly deposits
void calculateBalanceWithoutMonthlyDeposit(double initialAmount, double annualInterest, int numYears, double* balances) {
    int months = numYears * 12;
    double monthlyInterestRate = annualInterest / 100 / 12;

    double balance = initialAmount;

    for (int month = 0; month < months; ++month) {
        balance = balance * (1 + monthlyInterestRate);
        balances[month] = balance;
    }
}

// Function to display results
void displayResults(double initialAmount, double monthlyDeposit, double annualInterest, int numYears) {
    const int months = numYears * 12;
    double* balancesNoDeposit = new double[months];
    double* earnedInterestsNoDeposit = new double[months];
    double* balancesWithDeposit = new double[months];
    double* earnedInterestsWithDeposit = new double[months];

    // Calculate results with no additional deposits
    calculateBalanceWithoutMonthlyDeposit(initialAmount, annualInterest, numYears, balancesNoDeposit);

    // Calculate results with monthly deposits
    calculateInvestment(initialAmount, monthlyDeposit, annualInterest, numYears, balancesWithDeposit, earnedInterestsWithDeposit);

    cout << fixed << setprecision(2); // Set output precision to 2 decimal places

    cout << "\nYear-End Balances Without Monthly Deposits:" << endl;
    for (int year = 1; year <= numYears; ++year) {
        int monthIndex = 12 * year - 1;
        cout << "Year " << year << ": Balance: $" << balancesNoDeposit[monthIndex] << endl;
    }

    cout << "\nYear-End Balances and Earned Interest With Monthly Deposits:" << endl;
    for (int year = 1; year <= numYears; ++year) {
        int monthIndex = 12 * year - 1;
        cout << "Year " << year << ": Balance: $" << balancesWithDeposit[monthIndex]
            << ", Earned Interest: $" << earnedInterestsWithDeposit[monthIndex] << endl;
    }

    // Free allocated memory
    delete[] balancesNoDeposit;
    delete[] earnedInterestsNoDeposit;
    delete[] balancesWithDeposit;
    delete[] earnedInterestsWithDeposit;
}

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int numYears;

    getUserInput(initialInvestment, monthlyDeposit, annualInterest, numYears);

    cout << "\nPress Enter to continue...";
    cin.ignore(); // To ignore any leftover characters in the buffer
    cin.get();    // To wait for the Enter key press

    displayResults(initialInvestment, monthlyDeposit, annualInterest, numYears);

    return 0;
}
