#include "Lib.h"
#include "Date.h"
#include "Computer.h"
struct Personal {
	char name[50] = "";
	int experience = 0;
	char graphic[50] = "";
	char cashier_or_owner[50] = "";
	int size_computers = 0;
	Computer* arr = nullptr;
	void add_computer(Computer pc) {
		Computer* tmp = new Computer[++size_computers];
		for (int i = 0; i < size_computers - 1; i++)
		{
			tmp[i] = arr[i];
		}
		if (arr != nullptr) delete[] arr;
		tmp[size_computers - 1] = pc;
		arr = tmp;

	}
	void show_personal() {
		cout << "Name: " << name << endl;
		cout << "Experience: " << experience << " years" << endl;
		cout << "Graphic: " << graphic << endl;
	}
	void show_cashier(int input) {
		cout << "Name cahier: " << name << endl;
		cout << "Expirience " << experience << endl;
		if (size_computers == 0) cout << "None yet\n";
		else {
			for (int i = 0; i < size_computers; i++)
			{
				cout << "#" << i + 1 << endl;
				arr[i].show_computer(input);

			}cout << "----------------------" << endl;
		}
	}
	void add_computer1() {
		Computer* arr = new Computer[++size_computers];
		arr->add_computer1();
		FILE* fp = nullptr;
		fopen_s(&fp, "Anton's_PCS.bin", "ab");
		if (fp == NULL) cout << "ERROR";
		else {
			fwrite(&arr, sizeof(Computer), 1, fp);
		}
		delete[] arr;
		fclose(fp);
	}
	void add_computer2() {
		Computer* arr = new Computer[++size_computers];
		arr->add_computer1();
		FILE* fp = nullptr;
		fopen_s(&fp, "Bobs_PCS.bin", "ab");
		if (fp == NULL) cout << "ERROR";
		else {
			fwrite(&arr, sizeof(Computer), 1, fp);
		}
		delete[] arr;
		fclose(fp);
	}

	void add_personal(int& size) {
		Personal* arr = new Personal[++size];
		arr->add_computer1();
		FILE* fp = nullptr;
		fopen_s(&fp, "Anton's_PCS.bin", "ab");
		if (fp == NULL) cout << "ERROR";
		else {
			fwrite(&arr, sizeof(Computer), 1, fp);
		}
		delete[] arr;
		fclose(fp);
	}
	bool isEnoughCashiers() {
		FILE* fp = nullptr;
		fopen_s(&fp, "Personal.bin", "rb");
		if (fp == NULL) {
			cout << "ERROR. FILE NOT OPEN OR NOT FOUND" << endl;
			return false;
		}
		int cashierCount = 0;
		fseek(fp, 0, SEEK_END);
		long fileSize = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		while (ftell(fp) < fileSize) {
			char name[100] = "";
			int experience = 0;
			char graphic[100] = "";
			int len1 = 0;
			int len2 = 0;
			fread(name, sizeof(char), len1, fp);
			fread(&experience, sizeof(int), 1, fp);
			fread(graphic, sizeof(char), len2, fp);
			if (strcmp(graphic, "Cashier") == 0) {
				cashierCount++;
				if (cashierCount >= 2) {
					cout << "You cannot have more than two cashiers." << endl;
					fclose(fp);
					return false;
				}
			}
		}
		fclose(fp);
		return true;
	}
	void add_personal() {
		if (isEnoughCashiers() == 0) {
			FILE* fp = nullptr;
			cout << "Enter Second name and First name: ";
			cin.getline(name, 100);
			cout << "Enter his/her expirience: ";
			cin >> experience;
			cout << "Enter his/her graphic: ";
			cin.ignore();
			cin.getline(graphic, 100);
			fopen_s(&fp, "Personal.bin", "ab");
			if (fp == NULL) cout << "ERROR. FILE DONT OPEN OR FIND";
			else {
				int len1 = strlen(name) + 1;
				int len2 = strlen(graphic) + 1;
				fwrite(name, sizeof(char), len1, fp);
				fwrite(&experience, sizeof(int), 1, fp);
				fwrite(graphic, sizeof(char), 1, fp);

			}
			fclose(fp);
		}
		else cout << "You cant pay salary more then 2 peoples.";
	}
};
 