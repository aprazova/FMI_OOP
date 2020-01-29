#include <iostream>

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account(), interestRate(0)
{
}

SavingsAccount::SavingsAccount(const char * iban, const char * ownerId, double amount, double interestRate) : Account(iban, ownerId, amount)
{
	this->setInterestRate(interestRate);
}

void SavingsAccount::setInterestRate(double interestRate)
{
	if (interestRate >= 0 && interestRate <= 100)
	{
		this->interestRate = interestRate;
		return;
	}
	this->interestRate = 0;

}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(double sum)
{
	if (sum >= 0)
	{
		this->setAmount(this->getBalance() + sum);
	}
}

bool SavingsAccount::withdraw(double sum)
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

void SavingsAccount::display()
{
	std::cout << "Saving account \nIban: " << this->getIban() << "\tOwnerId: " << this->getOwnerId() << "\tAmount: " 
		<< this->getBalance() << "\tInterestRate: " << this->getInterestRate() << "\n";
}
