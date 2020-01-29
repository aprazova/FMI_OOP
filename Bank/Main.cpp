#include <iostream>
#include <vector>

#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PivilegeAccount.h"
#include "Bank.h"

void menu()
{
	std::cout << " 1 List customers"<<
		"\n 2 Add new customer"<<
		"\n 3 Delete customer"<<
		"\n 4 List all accounts"<<
		"\n 5 List customer accounts"<<
		"\n 6 Add new account"<<
		"\n 7 Delete account"<<
		"\n 8 Withdraw from account"<<
		"\n 9 Deposit to account"<<
		"\n 10 Transfer"<<
		"\n 11 Display info for the bank"<<
		"\n 12 Quit"<<
		"\n 13 Menu\n";
}

int main()
{
	Bank myBank;
	myBank.setName("Bank's name");
	myBank.setAddress("Plovdiv");
	menu();

	std::cout << "Enter number: ";
	int number;
	std::cin >> number;
	while (true)
	{
		if (number == 1)
		{
			myBank.listCustomers();
		}
		else if (number == 2)
		{
			std::cout << "\nEnter id: ";
			char id[20];
			std::cin >> id;
			std::cout << "Enter name: ";
			char name[20];
			std::cin >> name;
			std::cout << "Enter address: ";
			char customer[20];
			std::cin >> customer;
			myBank.addCustomer(id, name, customer);
		}
		else if (number == 3)
		{
			std::cout << "\nEnter customerId: ";
			char customerId[20];
			std::cin >> customerId;
			myBank.deleteCustomer(customerId);
		}
		else if (number == 4)
		{
			myBank.listAccounts();
		}
		else if (number == 5)
		{
			std::cout << "\nEnter customerId: ";
			char customerId[20];
			std::cin >> customerId;
			myBank.listCustomerAccount(customerId);
		}
		else if (number == 6)
		{
			std::cout << "\nEnter account type: ";
			char accountType[20];
			std::cin >> accountType;
			std::cout << "Enter iban: ";
			char iban[20];
			std::cin >> iban;
			std::cout << "Enter ownerID: ";
			char ownerId[20];
			std::cin >> ownerId;
			std::cout << "Enter amount: ";
			double amount;
			std::cin >> amount;
			myBank.addAccount(accountType, iban, ownerId, amount);
		}
		else if (number == 7)
		{
			std::cout << "\nEnter iban : ";
			char iban[20];
			std::cin >> iban;
			myBank.deleteAccount(iban);
		}
		else if (number == 8)
		{
			myBank.withdraw();

		}
		else if (number == 9)
		{
			myBank.deposit();
		}
		else if (number == 10)
		{
			std::cout << "\nEnter fromIBAN: ";
			char fromIBAN[20];
			std::cin >> fromIBAN;
			std::cout << "Enter toIBAN: ";
			char toIBAN[20];
			std::cin >> toIBAN;
			std::cout << "Enter amount: ";
			double amount;
			std::cin >> amount;
			myBank.transfer(fromIBAN, toIBAN, amount);
		}
		else if (number == 11)
		{
			myBank.display();
		}
		else if (number == 12)
		{
			return 0;
		}
		else if (number == 13)
		{
			menu();
		}
		else
		{
			std::cout << "\nIncorrect command.";

		}
		std::cout << "\nEnter number: ";
		std::cin >> number;
	}
	return 0;
}