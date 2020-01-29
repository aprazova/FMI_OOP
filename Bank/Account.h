#pragma once

class Account
{
public:
	Account();
	Account(const char* iban, const char* ownerId, double amount);
	Account(const Account& rhs);
	Account& operator= (const Account& rhs);
	~Account();

	void setIban(const char* iban);
	void setOwnerId(const char* ownerId);
	void setAmount(double amount);

	char* getIban() const;
	char* getOwnerId() const;

	virtual void deposit(double sum) = 0;
	virtual bool withdraw(double sum) = 0;
	virtual void display() = 0;

	double getBalance() const;

private:

	void copyFromAccount(const Account& rhs);

private:
	char* iban;
	char* ownerId;
	double amount;
};