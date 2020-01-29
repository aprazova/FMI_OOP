#include <iostream>

#include "Customer.h"

Customer::Customer() : id(nullptr), name(nullptr), address(nullptr)
{
}

Customer::Customer(const char * id, const char * name, const char * address) : id(nullptr), name(nullptr), address(nullptr)
{
	this->setId(id);
	this->setName(name);
	this->setAddress(address);
}

Customer::~Customer()
{
	delete[] this->id;
	delete[] this->name;
	delete[] this->address;
}

Customer::Customer(const Customer & rhs)
{
	copyFrom(rhs);
}

Customer & Customer::operator=(const Customer & rhs)
{
	if (this != &rhs)
	{
		copyFrom(rhs);
	}
	return *this;
}

void Customer::setId(const char * id)
{
	this->id = nullptr;
	if (id == nullptr)
	{
		return;
	}
	delete[] this->id;
	int len = strlen(id);
	this->id = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->id[i] = id[i];
	}
	this->id[len] = 0;
}

void Customer::setName(const char * name)
{
	this->name = nullptr;
	if (name == nullptr)
	{
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

void Customer::setAddress(const char * address)
{
	this->address = nullptr;
	if (address == nullptr)
	{
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

char * Customer::getId() const
{
	return this->id;
}

char * Customer::getName() const
{
	return this->name;
}

char * Customer::getAddress() const
{
	return this->address;
}

void Customer::display()
{
	std::cout << "\nID: " << this->id << "\tName:  " << this->name << "\tAddress: " << this->address << " \n";
}

void Customer::copyFrom(const Customer & rhs)
{
	this->setId(rhs.getId());
	this->setName(rhs.getName());
	this->setAddress(rhs.getAddress());
}
