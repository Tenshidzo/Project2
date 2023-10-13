#pragma once
#include "Lib.h"
#include "Date.h"
#include "personal_of_shop.h"
#include "Computer.h"
#include "Configs.h"
void show_personal(Personal* arr, int size) {
	int input = 0;
	cout << "1. First Cashier/ 2. Second cashier /3. Owner: ";
	cin >> input;
	if (input == 1) arr[0].show_cashier(input);
	else if (input == 2) arr[1].show_cashier(input);
	else if (input == 3) arr[2].show_cashier(input);
	else cout << "WRONG INPUT!!";
}
void show_all(Personal* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i].show_personal();
	}
}
void order_pc() {
	cin.ignore();
	int input = 0;
	cout << "From what cashier do you want to buy custom pc: (1/2): ";
	cin >> input;
	if (input > 0 && input < 3) {
		if (input == 1) {
			FILE* fp = nullptr;
			fopen_s(&fp, "Order_Cashier1.bin", "ab");
			if (fp == NULL) cout << "ERROR";
			else {
				Computer order;
				order.order();
				fwrite(&order, sizeof(Computer), 1, fp);
				fclose(fp);
				cout << "Order send to cashier!";
			}
		}
		else if (input == 2) {
			FILE* fp = nullptr;
			fopen_s(&fp, "Order_Cashier2.bin", "ab");
			if (fp == NULL) cout << "ERROR";
			else {
				Computer order;
				order.order();
				fwrite(&order, sizeof(Computer), 1, fp);
				fclose(fp);
				cout << "Order send to cashier";
			}
		}
	}
	else cout << "Incorrect input!" << endl;
}
void orders_cashier1() {
	FILE* fp = nullptr;
	fopen_s(&fp, "Order_Cashier1.bin", "rb");
	if (fp == NULL) cout << "ERROR";
	else {
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0) {
			cout << "You have 0 orders" << endl;
			fclose(fp);
		}
		else if (ftell(fp) > 0) {
			int num = ftell(fp) / sizeof(Computer);
			fseek(fp, 0, SEEK_SET);
			Computer* arr = new Computer[num];
			fread(arr, sizeof(Computer), num, fp);
			for (int i = 0; i < num; i++) {
				cout << "Order " << i + 1 << ":" << endl;
				cout << "Name of buyer: " << arr[i].name_user << endl;
				cout << "Name of computer: " << arr[i].name_pc << endl;
				cout << "Processor: " << arr[i].processor << endl;
				cout << "VideoCard: : " << arr[i].VideoCard << endl;
				cout << "OZU: " << arr[i].ozu << " Gb" << endl;
				cout << "RGB: " << arr[i].rgb << endl;
				cout << "Price: " << arr[i].price << " uah." << endl;
				cout << "--------------------------------" << endl;
			}
			fclose(fp);
			delete[] arr;

		}
	}
}
void orders_cashier2() {
	FILE* fp = nullptr;
	fopen_s(&fp, "Order_Cashier2.bin", "rb");
	if (fp == NULL) cout << "ERROR";
	else {
		fseek(fp, 0, SEEK_END);
		if (ftell(fp) == 0) {
			cout << "You have 0 orders" << endl;
			fclose(fp);
		}
		else if (ftell(fp) > 0) {
			int num = ftell(fp) / sizeof(Computer);
			fseek(fp, 0, SEEK_SET);
			Computer* arr = new Computer[num];
			fread(arr, sizeof(Computer), num, fp);
			for (int i = 0; i < num; i++) {
				cout << "Order " << i + 1 << ":" << endl;
				cout << "Name of buyer: " << arr[i].name_user << endl;
				cout << "Name of computer: " << arr[i].name_pc << endl;
				cout << "Processor: " << arr[i].processor << endl;
				cout << "VideoCard: : " << arr[i].VideoCard << endl;
				cout << "OZU: " << arr[i].ozu << " Gb" << endl;
				cout << "RGB: " << arr[i].rgb << endl;
				cout << "Price: " << arr[i].price << " uah." << endl;
				cout << "--------------------------------" << endl;
			}
			fclose(fp);
			delete[] arr;

		}
	}
}
void deleteOrder() {
	FILE* fp = nullptr;
	fopen_s(&fp, "Order_Cashier1.bin", "rb");
	if (fp == NULL) {
		cout << "ERROR" << endl;
	}
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0) {
		cout << "You have 0 orders" << endl;
		fclose(fp);
	}
	int num = ftell(fp) / sizeof(Computer);
	fseek(fp, 0, SEEK_SET);
	Computer* arr = new Computer[num];
	fread(arr, sizeof(Computer), num, fp);
	fclose(fp);
	int orderToDelete;
	cout << "Enter index of order: ";
	cin >> orderToDelete;
	if (orderToDelete < 1 || orderToDelete > num) {
		cout << "Incorrect order" << endl;
		return;
	}
	else {
		Computer elementToMove = arr[orderToDelete - 1];
		for (int i = orderToDelete; i < num - 1; i++) {
			arr[orderToDelete] = arr[i + 1];
			arr[i + 1] = arr[i];
		}
	}
	FILE* fp2 = nullptr;
	fopen_s(&fp2, "Order_Cashier1.bin", "wb");
	if (fp2 == NULL) {
		cout << "ERROR." << endl;
		delete[] arr;
	}
	for (int i = 0; i < num; i++) {
		if (i != orderToDelete - 1) {
			fwrite(&arr[i], sizeof(Computer), 1, fp2);
		}
	}
	fclose(fp2);
	delete[] arr;
	cout << "Order delete" << endl;
}
int find_Processors(char* input) {
	for (int i = 0; i < size_arr_Processors; i++) {
		if (strcmp(input, arr_Processors[i].name) == 0) {
			return arr_Processors[i].price;
		}
	}
	cout << "This component isn't in stock. ";
	return -1;
}int find_VideoCards(char* input) {
	for (int i = 0; i < size_arr_VideoCards; i++) {
		if (strcmp(input, arr_VideoCards[i].name) == 0) {
			return arr_VideoCards[i].price;
		}
	}
	cout << "This component isn't in stock. ";
	return -1;
}
int find_ozu(char* input) {
	for (int i = 0; i < size_arr_ozu; i++) {
		if (strcmp(input, arr_ozu[i].name) == 0) {
			return arr_ozu[i].price;
		}
	}
	cout << "This component isn't in stock. ";
	return -1;
}
int find_rgb(char* input) {
	if (strcmp(input, "Yes") == 0) {
		return 1000;
	}
	else if (strcmp(input, "No") == 0) {
		return 0;
	}
	else {
		cout << "Incorrect input: ";
		return -1;
	}
}	
void show_configs() {
	cout << "Processors: " << endl;
	for (int i = 0; i < size_arr_Processors; i++)
	{
		cout << "Processor " << i + 1 << ": " << endl;
		cout << "Name: " << arr_Processors[i].name << endl;
		cout << "Price: " << arr_Processors[i].price << endl;
		cout << "--------------------------------*" << endl;
	}
	cout << "VideCards: " << endl;
	for (int i = 0; i < size_arr_VideoCards; i++)
	{
		cout << "VideoCard " << i + 1 << ": " << endl;
		cout << "Name: " << arr_VideoCards[i].name << endl;
		cout << "Price: " << arr_VideoCards[i].price << endl;
		cout << "--------------------------------*" << endl;
	}
	cout << "RAM:: " << endl;
	for (int i = 0; i < size_arr_ozu; i++)
	{
		cout << "ram " << i + 1 << ": " << endl;
		cout << "Name: " << arr_ozu[i].name << endl;
		cout << "Price: " << arr_ozu[i].price << endl;
		cout << "--------------------------------*" << endl;
	}
	cout << "RGB: " << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "rgb " << i + 1 << ": " << endl;
		cout << "Name: " << arr_rgb[i].name << endl;
		cout << "Price: " << arr_rgb[i].price << endl;
		cout << "--------------------------------*" << endl;
	}
}
void sort_configs_min() {
	cout << "Processors: " << endl;
	for (int i = 0; i < size_arr_Processors - 1; i++) {
		for (int j = 0; j < size_arr_Processors - i - 1; j++) {
			if (arr_Processors[j].price > arr_Processors[j + 1].price) {
				Configs temp = arr_Processors[j];
				arr_Processors[j] = arr_Processors[j + 1];
				arr_Processors[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size_arr_Processors; i++)
	{
		cout << arr_Processors[i].name << "." << "Price: " << arr_Processors[i].price << endl;
		cout << "----------------------*" << endl;
	}
	cout << "VideoCards: " << endl;
	for (int i = 0; i < size_arr_VideoCards - 1; i++) {
		for (int j = 0; j < size_arr_VideoCards - i - 1; j++) {
			if (arr_VideoCards[j].price > arr_VideoCards[j + 1].price) {
				Configs temp = arr_VideoCards[j];
				arr_VideoCards[j] = arr_VideoCards[j + 1];
				arr_VideoCards[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size_arr_VideoCards; i++)
	{
		cout << arr_VideoCards[i].name << "." << "Price: " << arr_VideoCards[i].price << endl;
		cout << "----------------------*" << endl;
	}
	cout << "Ram: " << endl;
	for (int i = 0; i < size_arr_ozu - 1; i++) {
		for (int j = 0; j < size_arr_ozu - i - 1; j++) {
			if (arr_ozu[j].price > arr_ozu[j + 1].price) {
				Configs temp = arr_ozu[j];
				arr_ozu[j] = arr_ozu[j + 1];
				arr_ozu[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size_arr_ozu; i++)
	{
		cout << arr_ozu[i].name << "." << "Price: " << arr_ozu[i].price << endl;
		cout << "----------------------*" << endl;
	}
}void sort_configs_max() {
	cout << "Processors: " << endl;
	for (int i = 0; i < size_arr_Processors - 1; i++) {
		for (int j = 0; j < size_arr_Processors - i - 1; j++) {
			if (arr_Processors[j].price < arr_Processors[j + 1].price) {
				Configs temp = arr_Processors[j];
				arr_Processors[j] = arr_Processors[j + 1];
				arr_Processors[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size_arr_Processors; i++)
	{
		cout << arr_Processors[i].name << "." << "Price: " << arr_Processors[i].price << endl;
		cout << "----------------------*" << endl;
	}
	cout << "VideoCards: " << endl;
	for (int i = 0; i < size_arr_VideoCards - 1; i++) {
		for (int j = 0; j < size_arr_VideoCards - i - 1; j++) {
			if (arr_VideoCards[j].price < arr_VideoCards[j + 1].price) {
				Configs temp = arr_VideoCards[j];
				arr_VideoCards[j] = arr_VideoCards[j + 1];
				arr_VideoCards[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size_arr_VideoCards; i++)
	{
		cout << arr_VideoCards[i].name << "." << "Price: " << arr_VideoCards[i].price << endl;
		cout << "----------------------*" << endl;
	}
	cout << "Ram: " << endl;
	for (int i = 0; i < size_arr_ozu - 1; i++) {
		for (int j = 0; j < size_arr_ozu - i - 1; j++) {
			if (arr_ozu[j].price < arr_ozu[j + 1].price) {
				Configs temp = arr_ozu[j];
				arr_ozu[j] = arr_ozu[j + 1];
				arr_ozu[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size_arr_ozu; i++)
	{
		cout << arr_ozu[i].name << "." << "Price: " << arr_ozu[i].price << endl;
		cout << "----------------------*" << endl;
	}
}
void delete_pc1() {
	FILE* fp = nullptr;
	fopen_s(&fp, "Anton's_PCS.bin", "rb");
	if (fp == NULL) {
		cout << "ERROR" << endl;
	}
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0) {
		cout << "You have 0 pcs" << endl;
		fclose(fp);
	}
	int num = ftell(fp) / sizeof(Computer);
	fseek(fp, 0, SEEK_SET);
	Computer* arr = new Computer[num];
	fread(arr, sizeof(Computer), num, fp);
	fclose(fp);
	int orderToDelete;
	cout << "Enter index of pc: ";
	cin >> orderToDelete;
	if (orderToDelete < 1 || orderToDelete > num) {
		cout << "Incorrect order" << endl;
		return;
	}
	else {
		Computer elementToMove = arr[orderToDelete - 1];
		for (int i = orderToDelete; i < num - 1; i++) {
			arr[orderToDelete] = arr[i + 1];
			arr[i + 1] = arr[i];
		}
	}
	FILE* fp2 = nullptr;
	fopen_s(&fp2, "Anton's.bin", "wb");
	if (fp2 == NULL) {
		cout << "ERROR." << endl;
		delete[] arr;
	}
	for (int i = 0; i < num; i++) {
		if (i != orderToDelete - 1) {
			fwrite(&arr[i], sizeof(Computer), 1, fp2);
		}
	}
	fclose(fp2);
	delete[] arr;
	cout << "Order delete" << endl;
}
void delete_pc2() {
	FILE* fp = nullptr;
	fopen_s(&fp, "Bobs_PCS.bin", "rb");
	if (fp == NULL) {
		cout << "ERROR" << endl;
	}
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0) {
		cout << "You have 0 pcs" << endl;
		fclose(fp);
	}
	int num = ftell(fp) / sizeof(Computer);
	fseek(fp, 0, SEEK_SET);
	Computer* arr = new Computer[num];
	fread(arr, sizeof(Computer), num, fp);
	fclose(fp);
	int orderToDelete;
	cout << "Enter index of pc: ";
	cin >> orderToDelete;
	if (orderToDelete < 1 || orderToDelete > num) {
		cout << "Incorrect order" << endl;
		return;
	}
	else {
		Computer elementToMove = arr[orderToDelete - 1];
		for (int i = orderToDelete; i < num - 1; i++) {
			arr[orderToDelete] = arr[i + 1];
			arr[i + 1] = arr[i];
		}
	}
	FILE* fp2 = nullptr;
	fopen_s(&fp2, "Bobs_PCS.bin", "wb");
	if (fp2 == NULL) {
		cout << "ERROR." << endl;
		delete[] arr;
	}
	for (int i = 0; i < num; i++) {
		if (i != orderToDelete - 1) {
			fwrite(&arr[i], sizeof(Computer), 1, fp2);
		}
	}
	fclose(fp2);
	delete[] arr;
	cout << "Order delete" << endl;
}
void delete_person() {
	FILE* fp = nullptr;
	fopen_s(&fp, "Personal.bin", "rb");
	if (fp == NULL) {
		cout << "ERROR" << endl;
	}
	fseek(fp, 0, SEEK_END);
	int num = ftell(fp) / sizeof(Computer);
	fseek(fp, 0, SEEK_SET);
	Computer* arr = new Computer[num];
	fread(arr, sizeof(Computer), num, fp);
	fclose(fp);
	int PersonToDelete;
	cout << "Enter index of person: ";
	cin >> PersonToDelete;
	if (PersonToDelete < 1 || PersonToDelete > num) {
		cout << "Incorrect order" << endl;
		return;
	}
	else if (PersonToDelete == 3) {
		cout << "You cant retire yourself!";
		return;
	}
	else {
		Computer elementToMove = arr[PersonToDelete - 1];
		for (int i = PersonToDelete; i < num - 1; i++) {
			arr[PersonToDelete] = arr[i + 1];
			arr[i + 1] = arr[i];
		}
	}
	FILE* fp2 = nullptr;
	fopen_s(&fp2, "Personal.bin", "wb");
	if (fp2 == NULL) {
		cout << "ERROR." << endl;
		delete[] arr;
	}
	for (int i = 0; i < num; i++) {
		if (i != PersonToDelete - 1) {
			fwrite(&arr[i], sizeof(Computer), 1, fp2);
		}
	}
	fclose(fp2);
	delete[] arr;
	cout << "Order delete" << endl;
}
void addNewProcessor() {
	cout << "Enter the name of the new processor: ";
	cin.ignore();
	cin.getline(arr_Processors[size_arr_Processors].name, 1000);
	cout << "Enter the price of the new processor: ";
	cin >> arr_Processors[size_arr_Processors].price;
	size_arr_Processors++;
}

void addNewVideoCard() {
	cout << "Enter the name of the new video card: ";
	cin.ignore();
	cin.getline(arr_VideoCards[size_arr_VideoCards].name, 1000);
	cout << "Enter the price of the new video card: ";
	cin >> arr_VideoCards[size_arr_VideoCards].price;
	size_arr_VideoCards++;
}

void addNewOzu() {
	cout << "Enter the name of the new RAM: ";
	cin.ignore();
	cin.getline(arr_ozu[size_arr_ozu].name, 1000);
	cout << "Enter the price of the new RAM: ";
	cin >> arr_ozu[size_arr_ozu].price;
	size_arr_ozu++;
}
