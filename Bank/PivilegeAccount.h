#pragma once
#include "Account.h"

class PivilegeAccount : public Account
{
public:
	PivilegeAccount();
	PivilegeAccount(const char* iban, const char* ownerId, double amount, double overdraft);

	void setOverdraft(double sum);
	double getOverdraft() const;

	void deposit(double sum);
	bool withdraw(double sum);
	void display();
private:
	double overdraft;
};