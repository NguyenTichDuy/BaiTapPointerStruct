#include<iostream>
#include<fstream>
#include<string>
using namespace std;

fstream fileInput;
const char* filePath = "Input.txt";

struct Student
{
	int id;
	string name;
	float score;
};

Student *student = new Student[100];
int ID;

int HamLuuID()
{
	static int numID = 0;
	numID++;
	return numID;
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
	ID = 0;
	while (check != 0)
	{
		ID++;
		student[ID].id = ID;
		
		cout << "Nhap ten hoc sinh ID " << student[ID].id << " : ";
		cin.ignore();

		getline(cin, student[ID].name, '\n');
		
		do
		{
			cout << "Score: ";
			cin >> student[ID].score;
		} while (student[ID].score < 0 && student[ID].score > 10);

		cin.ignore();

		cout << "Choose (1 - continue, 0 - EXIT):";
		cin >> check;
		cin.ignore();
	}
}

void SaveToFile()
{
	fileInput.open(filePath, ios::out);

	if (fileInput.is_open())
	{
		for (int i = 1; i <= ID; i++)
		{
			fileInput << student[i].id << '\t\t';
			getline(fileInput, student[i].name, '\n');
			fileInput << student[i].score;
		}
		cout << "Luu file thanh cong" << endl;
	}
	else
	{
		cout << "!!!!!!!!ERROR!!!!!!!" << endl;
	}
	fileInput.close();
}

void Display()
{
	system("cls");
	cout << "ID\t\t" << "FULL NAME\t\t" << "SCORE" << endl;
	for (int i = 1; i <= ID; i++)
	{
		cout << student[ID].id << "  \t\t" << student[ID].name << "\t\t" << student[ID].score << endl;
	}
	system("pause");
}

void LoadFromFile()
{
	fileInput.open(filePath, ios::in);

	if (fileInput.is_open())
	{
		for (int i = 1; i <= ID; i++)
		{
			fileInput >> student[i].id;
			getline(fileInput, student[i].name);
			fileInput >> student[i].score;
		}
	}

	fileInput.close();
}

void Select()
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
			SaveToFile();
			break;
		case 4:
			LoadFromFile();
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
	int check;
	if (fileInput.fail())
		cout << "Fail to open this file" << endl;

	Select();
	
	delete[] student;
	system("pause");
}

