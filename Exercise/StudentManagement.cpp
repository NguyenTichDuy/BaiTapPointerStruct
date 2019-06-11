#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student
{
	int id;
	string name;
	float score;
};

Student *student = new Student[100];
int ID(0);

void Display();
int HamLuuID();
void Menu();
void InPut();
void SaveToFile(string filePath);
void LoadFromFile(string filePath);
void Select(string filePath);

int HamLuuID()
{
	static int numID = 0;
	return ++numID;
}


void Menu()
{
	system("cls");
	cout << "----------------------MENU-------------------" << endl;
	cout << "\t1. Input" << endl;
	cout << "\t2. Display" << endl;
	cout << "\t3. Save to file" << endl;
	cout << "\t4. Load from file" << endl;
	cout << "\t0. Exit" << endl;
	cout << "---------------------------------------------" << endl;
}

void InPut()
{
	system("cls");
	int check = 1;

	while (check != 0)
	{
		ID++;
		student[ID].id = ID;
		cout << "Nhap ten hoc sinh ID " << student[ID].id << " : ";
		//cin.ignore();

		getline(cin, student[ID].name, '\n');

		do
		{
			cout << "Score: ";
			cin >> student[ID].score;

			if (student[ID].score < 0 || student[ID].score > 10)
			{
				cout << "Please choose in the range 0 - 10!!!!!\n";
				continue;
			}

		} while (student[ID].score < 0 || student[ID].score > 10);
		cin.ignore();

		cout << "Choose (1 - continue, 0 - EXIT):";
		cin >> check;
		cin.ignore();
	}
}

void SaveToFile(string filePath)
{
	ofstream fileOutput(filePath);

	if (!fileOutput.fail())
	{
		for (int i = 1; i <= ID; i++)
		{
			fileOutput << student[i].id << "\t\t";
			fileOutput << student[i].name << "\t\t";
			fileOutput << student[i].score << endl;
		}
		cout << "------Save the file successfully!!!!----------" << endl;
		system("pause");
	}
	else
	{
		cout << "!!!!!!!!ERROR!!!!!!!" << endl;
	}
	fileOutput.close();
}

void Display()
{
	system("cls");
	cout << "ID\t" << "FULL NAME\t\t" << "SCORE" << endl;
	for (int i = 1; i <= ID; i++)
	{
		cout << student[i].id << "\t" << student[i].name << "\t\t" << student[i].score << endl;
	}
	system("pause");
}

void LoadFromFile(string filePath)
{
	ifstream fileInput(filePath);

	if (fileInput.is_open())
	{
		for (int i = 1; i <= ID; i++)
		{
			fileInput >> student[i].id;
			fileInput.ignore(2);
			fileInput >> student[i].name;
			fileInput.ignore(2);
			fileInput >> student[i].score;
			fileInput.ignore(1);
		}
	}
	cout << "------Load from file successfuly!---------";
	fileInput.close();
}

void Select(string filePath)
{
	bool check = true;
	int choose = 1000;
	while (check)
	{
		Menu();
		cout << "Choose: ";
		cin >> choose;
		cin.ignore();
		switch (choose)
		{
		case 1:
			InPut();
			break;
		case 2:
			Display();
			break;
		case 3:
			SaveToFile(filePath);
			break;
		case 4:
			LoadFromFile(filePath);
			break;
		case 0:
			check = false;
			break;
		default:
			cout << "Vui long chon dung stt !!!!" << endl;
			break;
		}
	}
}

int main()
{
	string filePath = "Input.txt";

	Select(filePath);
	
	delete[] student;
	system("pause");
}

