#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateBIN(char* fname)
{
	ofstream fout(fname, ios::binary);
	char ch;
	string s; 
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		for (unsigned i = 0; i < s.length(); i++)
			fout.write((char*)&s[i], sizeof(s[i]));
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintBIN(char* fname)
{
	ifstream fin(fname, ios::binary);
	char c;
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c << endl;
	}
	cout << endl;
}
void ProcessBIN1(char* fname, char* gname)
{ 
	ifstream f(fname, ios::binary);
	ofstream g(gname, ios::binary);
	char c;
	while (f.read((char*)&c, sizeof(c)))
	{
		if (c >= '0' && c <= '9')
			g.write((char*)&c, sizeof(c));
	}
}
void SortBIN(char* fname, char* gname) 
{ 
	ofstream g(gname, ios::binary); 
	char s, mins, z = 0; 
	int k;
	do
	{ 
		k = 0; 

		ifstream f(fname, ios::binary);
			while (f.read((char*)&s, sizeof(char))) 
			{ 
				if (s <= z) 
					continue; 
				mins = s; 
				k++; 
				break;
			} 
		while (f.read((char*)&s, sizeof(char))) 
		{ 
			if (s <= z)
				continue;
			if (s < mins) 
			{ 
				mins = s; 
				k++; 
			} 
		}
		z = mins; 
		if (k > 0) 
			g.write((char*)&z, sizeof(char));
		f.close(); 
	}
	while (k > 0); 
}
void PrintBIN(char* fname)
{
	ifstream fin(fname, ios::binary);
	char c;
	while (fin.read((char*)&c, sizeof(c)))
	{
		cout << c << endl;
	}
	cout << endl;
}
void ProcessBIN1(char* fname, char* gname)
{
	ifstream f(fname, ios::binary);
	ofstream g(gname, ios::binary);
	char c;
	while (f.read((char*)&c, sizeof(c)))
	{
		if (c >= '0' && c <= '9')
			g.write((char*)&c, sizeof(c));
	}
}
void SortBIN(char* fname, char* gname)
{
	ofstream g(gname, ios::binary);
	char s, mins, z = 0;
	int k;
	do
	{
		k = 0;

		ifstream f(fname, ios::binary);
		while (f.read((char*)&s, sizeof(char)))
		{
			if (s <= z)
				continue;
			mins = s;
			k++;
			break;
		}
		while (f.read((char*)&s, sizeof(char)))
		{
			if (s <= z)
				continue;
			if (s < mins)
			{
				mins = s;
				k++;
			}
		}
		z = mins;
		if (k > 0)
			g.write((char*)&z, sizeof(char));
		f.close();
	} while (k > 0);
}
void SortBIN1(char* fname, char* gname)
{
	ofstream g(gname, ios::binary);
	char s, max, z = 0;
	int k;
	do
	{
		k = 0;

		ifstream f(fname, ios::binary);
		while (f.read((char*)&s, sizeof(char)))
		{
			if (s <= z)
				continue;
			max = s;
			k++;
			break;
		}
		while (f.read((char*)&s, sizeof(char)))
		{
			if (s <= z)
				continue;
			if (s > max)
			{
				max = s;
				k++;
			}
		}
		z = max;
		if (k > 0)
			g.write((char*)&z, sizeof(char));
		f.close();
	} while (k > 0);
}
int main()
{
	// binary files
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname); // ввели рядки файлу з клавіатури
	PrintBIN(fname); // вивели вміст першого файлу на екран
	char gname[100]; // ім'я другого файлу
	cout << "enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname); // вивели вміст другого файлу на екран
	SortBIN(fname, gname); // відсортували символи файлу,
	PrintBIN(gname); // вивели вміст файлу на екран
	SortBIN1(fname, gname); // відсортували символи файлу,
	PrintBIN(fname); // вивели вміст файлу на екран
	return 0;
}
