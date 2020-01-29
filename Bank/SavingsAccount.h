#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount();
	SavingsAccount(const char* iban, const char* ownerId, double amount, double interestRate);

	void setInterestRate(double interestRate);
	double getInterestRate() const;

	void deposit(double sum);
	bool withdraw(double sum);
	void display();
private:
	double interestRate;
};