#include "Book.h"

Book::Book(){}
Book::~Book(){}

Book::Book(string id, string name, int year, int amount, bool status)
{
    this->ID = id;
    this->Name = name;
    this->Year = year;
    this->Amount = amount;
    this->Status = status;
}

string Book::GetID()
{
    return this->ID;
}

string Book::GetName()
{
    return this->Name;
}

int Book::GetYear()
{
    return this->Year;
}

int Book::GetAmount()
{
    return this->Amount;
}

bool Book::GetStatus()
{
    return this->Status;
}

void Book::SetID(string id)
{
    this->ID = id;
}

void Book::SetName(string name)
{
    this->Name = name;
}

void Book::SetYear(int year)
{
   this->Year = year;
}

void Book::SetAmount(int amount)
{
    this->Amount = amount;
}

void Book::SetStatus(bool status)
{
    this->Status = status;
}

