#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount();
	CurrentAccount(const char* iban, const char* ownerName, double amount);
	void deposit(double sum);
	bool withdraw(double sum);
	void display();
};