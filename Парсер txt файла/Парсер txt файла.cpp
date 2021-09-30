#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include "PersonInformation.h"

using namespace std;

vector<PersonInformation> ReadFromFile(const string& fileName);
void LoadToFile(const vector<PersonInformation>& informationList, const string& fileName);
void Sort(vector<PersonInformation>& informationList);
PersonInformation operator +(PersonInformation& left, PersonInformation& right);//перегруженный оператор для суммирования информации об одном человеке

int main()
{
	setlocale(LC_ALL, "rus");

	vector<PersonInformation> informationList = ReadFromFile("Input.txt");
	Sort(informationList);
	LoadToFile(informationList, "Output.txt");
}

vector<PersonInformation> ReadFromFile(const string& fileName)
{
	vector<PersonInformation> informationList;
	ifstream file(fileName);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {                                    //читаем построчно
			informationList.push_back(*(new PersonInformation(line)));	 //в конструкторе и методах класса PersonInformation выделяется нужная информация и добавляется в массив
		}
	}
	else{
		cout << "Файл не найден." << endl;
	}
	return informationList;
}

void LoadToFile(const vector<PersonInformation>& informationList, const string& fileName)
{
	ofstream file(fileName);
	for (auto i : informationList) {
		file << i.GetName() << " " << i.GetRequestPerHour() << " " << i.GetHours() << " "<< i.GetRequestPerHour()* i.GetHours() <<" "<< i.GetAdditionalInformation() << endl;
	}
}

void Sort(vector<PersonInformation>& informationList)
{
	//суммируем показатели для каждого человека 
	for (int i = 0; i < informationList.size(); i++) {
		for (int k = i+1; k < informationList.size(); k++) {
			if (informationList[i].GetName() == informationList[k].GetName()) {
				informationList[i] = informationList[i] + informationList[k];
				informationList.erase(informationList.begin() + k);
			}
		}
	}
	//сортируем в алфавитном порядке(аналогично сортировке пузырьком)
	for (int i = 0; i < informationList.size(); i++) {
		for (int k = 0; k < informationList.size() - 1; k++) {
			if (informationList[k].GetName() > informationList[k+1].GetName()) {
				swap(informationList[k], informationList[k + 1]);
			}
		}
	}
}

PersonInformation operator +(PersonInformation& left, PersonInformation& right) {
	return *(new PersonInformation(left.GetName(), left.GetRequestPerHour() + right.GetRequestPerHour(), left.GetHours() + right.GetHours(), left.GetAdditionalInformation()));
}
