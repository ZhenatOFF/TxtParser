#pragma once
#include <string>
using namespace std;

class PersonInformation {
public:
	PersonInformation(const string& information);
	PersonInformation(const string& name, const int& requestPerHour, const int& hours, const string& additionalInformation);
	void SetName(const string& information);
	void SetRequestPerHour(const string& information);
	void SetHours(const string& information);
	void SetAdditionalInformation(const string& information);

	string GetName();
	int GetRequestPerHour();
	int GetHours();
	string GetAdditionalInformation();
private:
	string name;
	int requestPerHour;
	int hours;
	string additionalInformation;
};