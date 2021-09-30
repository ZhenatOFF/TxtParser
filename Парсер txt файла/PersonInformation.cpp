#include "PersonInformation.h"
#include <iterator>
#include <iostream>
using namespace std;

PersonInformation::PersonInformation(const string& information)
{
	SetName(information);
	SetRequestPerHour(information);
	SetHours(information);
	SetAdditionalInformation(information);
}
PersonInformation::PersonInformation(const string& name, const int& requestPerHour, const int& hours, const string& additionalInformation)
{
	this->name = name;
	this->requestPerHour = requestPerHour;
	this->hours = hours;
	this->additionalInformation = additionalInformation;
}
void PersonInformation::SetName(const string& information)
{
	size_t pos = information.find(" ");
	this->name = information.substr(0, pos);
}

void PersonInformation::SetRequestPerHour(const string& information)
{
	//находим индекс до нужной информации и после нее
	size_t posBefore = information.find(" ") + 1;
	size_t posAfter = information.find(" ", posBefore) + 1;
	string str = information.substr(posBefore, posAfter - posBefore);//после чего выделяем эту подстроку
	this->requestPerHour = atoi(str.c_str());//и конвертируем в целое число
}

void PersonInformation::SetHours(const string& information)
{
	//находим индекс до нужной информации и после нее
	size_t posBefore = 0;
	size_t posAfter = 0;
	for (int i = 0; i < 3; i++) {
		posBefore = posAfter;
		posAfter = information.find(" ", posBefore) + 1;
	}
	string str = information.substr(posBefore, posAfter - posBefore); //после чего выделяем эту подстроку
	this->hours = atoi(str.c_str()); //и конвертируем в целое число
}

void PersonInformation::SetAdditionalInformation(const string& information)
{
	//находим индекс до нужной информации и после нее
	size_t posBefore = 0;
	size_t posAfter = 0;
	for (int i = 0; i < 4; i++) {
		posBefore = posAfter;
		posAfter = information.find(" ", posBefore) + 1;
	}
	this->additionalInformation = information.substr(posBefore, posBefore);//после чего выделяем эту подстроку 
}

string PersonInformation::GetName()
{
	return this->name;
}

int PersonInformation::GetRequestPerHour()
{
	return this->requestPerHour;
}

int PersonInformation::GetHours()
{
	return this->hours;
}

string PersonInformation::GetAdditionalInformation()
{
	return this->additionalInformation;
}



