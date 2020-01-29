#pragma once
#include <vector>

#include "Customer.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "PivilegeAccount.h"
#include "CurrentAccount.h"

class Bank
{
public:
	Bank();
	Bank(const char* name, const char* address, std::vector <Customer> customers, std::vector <Account*> accounts);
	~Bank();
	Bank(const Bank& rhs);
	Bank& operator=(const Bank& rhs);

	void copyFromBank(const Bank& rhs);

	void setName(const char* name);
	void setAddress(const char* address);

	char* getName() const;
	char* getAddress() const;

	void addCustomer(const char* customerId, const char* name, const char* address);

	void listCustomers();
	void deleteCustomer(const char* customerId);
	void addAccount(const char* accountType, const char* iban, const char* ownerId, const double amount);
	void deleteAccount(const char* iban);
	void listAccounts();
	void listCustomerAccount(const char* customerId);
	void transfer(const char* fromIBAN, const char* toIBAN, double amount);
	void display();
	void deposit();
	void withdraw();

private:
	char* name;
	char* address;
	std::vector <Account*> accounts;
	std::vector <Customer> customers;
};