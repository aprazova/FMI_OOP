#pragma once
class Customer
{
public:
	Customer();
	Customer(const char* id, const char* name, const char* address);
	~Customer();
	Customer(const Customer& rhs);
	Customer& operator = (const Customer& rhs);

	void setId(const char* id);
	void setName(const char* name);
	void setAddress(const char* address);

	char* getId() const;
	char* getName() const;
	char* getAddress() const;

	void display();

private:
	void copyFrom(const Customer& rhs);

private:
	char* id;
	char* name;
	char* address;
};