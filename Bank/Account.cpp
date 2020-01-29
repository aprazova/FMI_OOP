#include <iostream>

#include "Account.h"

Account::Account() : iban(nullptr), ownerId(nullptr), amount(0.0)
{
}

Account::Account(const char * iban, const char * ownerId, double amount) : iban(nullptr), ownerId(nullptr)
{
	this->setIban(iban);
	this->setOwnerId(ownerId);
	this->setAmount(amount);
}

Account::Account(const Account & rhs)
{
	copyFromAccount(rhs);
}

Account & Account::operator=(const Account & rhs)
{
	if (this != &rhs)
	{
		copyFromAccount(rhs);
	}
	return *this;
}

Account::~Account()
{
	delete[] this->iban;
	delete[] this->ownerId;
}

void Account::setIban(const char * iban)
{
	if (iban == nullptr)
	{
		this->iban = nullptr;
		return;
	}
	delete[] this->iban;
	int len = strlen(iban);
	this->iban = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->iban[i] = iban[i];
	}
	this->iban[len] = 0;
}

void Account::setOwnerId(const char * ownerId)
{
	if (ownerId == nullptr)
	{
		this->ownerId = nullptr;
		return;
	}
	delete[] this->ownerId;
	int len = strlen(ownerId);
	this->ownerId = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->ownerId[i] = ownerId[i];
	}
	this->ownerId[len] = 0;
}

void Account::setAmount(double amount)
{
	this->amount = amount;
}

char * Account::getIban() const
{
	return this->iban;
}

char * Account::getOwnerId() const
{
	return this->ownerId;
}

double Account::getBalance() const
{
	return this->amount;
}

void Account::copyFromAccount(const Account & rhs)
{
	this->setIban(rhs.getIban());
	this->setOwnerId(rhs.getOwnerId());
	this->setAmount(rhs.getBalance());
}
