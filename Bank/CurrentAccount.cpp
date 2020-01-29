#include <iostream>

#include "CurrentAccount.h"

CurrentAccount::CurrentAccount() : Account()
{
}

CurrentAccount::CurrentAccount(const char * iban, const char * ownerName, double amount) : Account(iban, ownerName, amount)
{
}

void CurrentAccount::deposit(double sum)
{
	if (sum >= 0)
	{
		this->setAmount(this->getBalance() + sum);
	}
}

bool CurrentAccount::withdraw(double sum)
{
	if (sum >= 0)
	{
		if (this->getBalance() - sum >= 0)
		{
			this->setAmount(this->getBalance() - sum);
			return true;
		}
		return false;
	}
	return false;
}

void CurrentAccount::display()
{
	std::cout << "Current account \nIban: " << this->getIban() << "\tOwnerId: " << 
		this->getOwnerId() << "\tAmount: " << this->getBalance() << "\n";
}
