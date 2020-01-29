#include <iostream>

#include "PivilegeAccount.h"

PivilegeAccount::PivilegeAccount() : Account(), overdraft(0)
{
}

PivilegeAccount::PivilegeAccount(const char * iban, const char * ownerId, double amount, double overdraft) : Account(iban, ownerId, amount)
{
	this->setOverdraft(overdraft);
}

void PivilegeAccount::setOverdraft(double sum)
{
	if (sum > -0)
	{
		this->overdraft = sum;
		return;
	}
	this->overdraft = 0;
}

double PivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}

void PivilegeAccount::deposit(double sum)
{
	if (sum >= 0)
	{
		this->setAmount(this->getBalance() + sum);
	}
}

bool PivilegeAccount::withdraw(double sum)
{
	if (sum >= 0)
	{
		if ((this->getBalance() + this->overdraft) - sum >= 0)
		{
			this->setAmount(this->getBalance() - sum);
			return true;
		}
		return false;
	}
	return false;
}

void PivilegeAccount::display()
{
	std::cout << "Pivilage accoutn \nIban: " << this->getIban() << "\tOwnerId: " << this->getOwnerId()
		<< "\tAmount: " << this->getBalance() << "\tOverdraft: " << this->getOverdraft() << "\n";
}
