#include <iostream>
#include <vector>

#include "Bank.h"

int strcmp(const char* one, const char* two)
{
	if (strlen(one) == strlen(two))
	{
		int length = strlen(one);
		for (int i = 0; i < length; i++)
		{
			if (one[i] != two[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

Bank::Bank() : name(nullptr), address(nullptr)
{
}

Bank::Bank(const char * name, const char * address, std::vector<Customer> customers, std::vector<Account*> accounts) : name(nullptr), address(nullptr)
{
	this->setName(name);
	this->setAddress(address);
	for (int i = 0; i < customers.size(); i++)
	{
		this->customers.push_back(customers[i]);
	}
	for (int i = 0; i < this->accounts.size(); i++)
	{
		this->accounts.push_back(accounts[i]);
	}

}

Bank::~Bank()
{
	delete[] this->name;
	delete[] this->address;
	for (int i = 0; i < accounts.size(); i++)
	{
		delete this->accounts[i];
	}
}

Bank::Bank(const Bank & rhs)
{
	copyFromBank(rhs);
}

Bank & Bank::operator=(const Bank & rhs)
{
	if (this != &rhs)
	{
		copyFromBank(rhs);
	}
	return *this;
}

void Bank::copyFromBank(const Bank & rhs)
{
	this->setName(rhs.getName());
	this->setAddress(rhs.getAddress());
	for (int i = 0; i < rhs.customers.size(); i++)
	{
		this->customers.push_back(rhs.customers[i]);
	}
	for (int i = 0; i < rhs.accounts.size(); i++)
	{
		this->accounts.push_back(rhs.accounts[i]);
	}
}

void Bank::setName(const char * name)
{
	if (name == nullptr)
	{
		this->name = nullptr;
		return;
	}
	delete[] this->name;
	int len = strlen(name);
	this->name = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->name[i] = name[i];
	}
	this->name[len] = 0;
}

void Bank::setAddress(const char * address)
{
	if (address == nullptr)
	{
		this->address = nullptr;
		return;
	}
	delete[] this->address;
	int len = strlen(address);
	this->address = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->address[i] = address[i];
	}
	this->address[len] = 0;
}

char * Bank::getName() const
{
	return this->name;
}

char * Bank::getAddress() const
{
	return this->address;
}

void Bank::addCustomer(const char * customerId, const char * name, const char * address)
{
	for (int i = 0; i < this->customers.size(); i++)
	{
		if (strcmp(customers[i].getId(), customerId) == 1)
		{
			std::cout << "\nThere is customer with this id!";
			return;
		}
	}
	this->customers.push_back(Customer(customerId, name, address));
}

void Bank::listCustomers()
{
	if (this->customers.size() == 0)
	{
		std::cout << "There are no customers.\n";
		return;
	}
	for (int i = 0; i < this->customers.size(); i++)
	{
		this->customers[i].display();
	}
}

void Bank::deleteCustomer(const char * customerId)
{
	int count = 0;
	for (int i = 0; i < this->customers.size(); i++)
	{
		if (strcmp(customers[i].getId(), customerId) == 1)
		{
			count++;
			for (int j = 0; j < this->accounts.size(); j++)
			{
				if (strcmp((accounts[j])->getOwnerId(), customers[i].getId()) == 1)
				{
					this->accounts.erase(accounts.begin() + j, accounts.begin() + j + 1);
				}
				j--;
			}
			this->customers.erase(customers.begin() + i, customers.begin() + i + 1);
			i--;
		}
	}
	if (count == 0)
	{
		std::cout << "There is no customer with this id.\n";
	}
}


void Bank::addAccount(const char * accountType, const char * iban, const char * ownerId, const double amount)
{
	int count = 0;
	for (int i = 0; i < this->customers.size(); i++)
	{
		if (strcmp(this->customers[i].getId(), ownerId) == 1)
		{
			count++;
		}
	}
	if (count == 0)
	{
		std::cout << "There is not customer with this id.\n";
		return;
	}

	if (strcmp(accountType, "CurrentAccount") == 1)
	{
		this->accounts.push_back(new CurrentAccount(iban, ownerId, amount));
	}
	else if (strcmp(accountType, "SavingsAccount") == 1)
	{
		std::cout << "Enter interestRate:";
		double interestRate;
		std::cin >> interestRate;
		this->accounts.push_back(new SavingsAccount(iban, ownerId, amount, interestRate));

	}
	else if (strcmp(accountType, "PivilegeAccount") == 1)
	{
		std::cout << "Enter overdraft: ";
		double overdraft;
		std::cin >> overdraft;
		this->accounts.push_back(new PivilegeAccount(iban, ownerId, amount, overdraft));
	}
	else
	{
		std::cout << "Incorrect type of account!\n";
		return;
	}

}

void Bank::deleteAccount(const char * iban)
{
	int count = 0;
	for (int i = 0; i < this->accounts.size(); i++)
	{
		if (strcmp((this->accounts[i])->getIban(), iban) == 1)
		{
			this->accounts.erase(this->accounts.begin() + i, this->accounts.begin() + i + 1);
			count++;
		}
	}
	if (count == 0)
	{
		std::cout << "There isn't account with this iban.\n";
	}
}

void Bank::listAccounts()
{
	if (this->accounts.size() == 0)
	{
		std::cout << "There are no accounts.\n";
		return;
	}
	for (int i = 0; i < this->accounts.size(); i++)
	{
		(this->accounts[i])->display();
	}
}

void Bank::listCustomerAccount(const char * customerId)
{
	int count = 0;
	for (int i = 0; i < this->customers.size(); i++)
	{
		if (strcmp(this->customers[i].getId(), customerId) == 1)
		{
			count++;
			for (int j = 0; j < this->accounts.size(); j++)
			{
				if (strcmp((this->accounts[j])->getOwnerId(), customers[i].getId()) == 1)
				{
					(this->accounts[j])->display();
				}
			}
		}
	}
	if (count == 0)
	{
		std::cout << "There is no customer with this id.\n";
	}
}

void Bank::transfer(const char * fromIBAN, const char * toIBAN, double amount)
{
	if (strcmp(fromIBAN, toIBAN) == 0)
	{
		for (int i = 0; i < this->accounts.size(); i++)
		{
			if (strcmp((this->accounts[i])->getIban(), fromIBAN) == 1)
			{
				for (int j = 0; j < this->accounts.size(); j++)
				{
					if (strcmp((this->accounts[j])->getIban(), toIBAN) == 1)
					{
						if ((accounts[i])->getBalance() >= amount)
						{
							accounts[i]->setAmount(accounts[i]->getBalance() - amount);
							accounts[j]->setAmount(accounts[j]->getBalance() + amount);
						}

					}
				}
			}
		}
	}
}

void Bank::display()
{
	std::cout << "Name:" << this->getName() << "\tAddres: " << this->getAddress() << "\tCustomers: " << this->customers.size() << "\tAccounts: " << this->accounts.size()  << "\n";

}

void Bank::withdraw()
{
		std::cout << "Enter iban: ";
		char iban[15];
		std::cin >> iban;
		for (int i = 0; i < this->accounts.size(); i++)
		{
			if (strcmp((this->accounts[i])->getIban(), iban) == 1)
			{
				std::cout << "Enter amount: ";
				double amount;
				std::cin >> amount;
				(this->accounts[i])->withdraw(amount);
			}
		}
}

void Bank::deposit()
{
	std::cout << "Enter iban: ";
	char iban[15];
	std::cin >> iban;
	for (int i = 0; i < this->accounts.size(); i++)
	{
		if (strcmp((this->accounts[i])->getIban(), iban) == 1)
		{
			std::cout << "Enter amount: ";
			double amount;
			std::cin >> amount;
			(this->accounts[i])->deposit(amount);
		}
	}
}
