#pragma once
#include "Lib.h"
#include "Configs.h"
#include "personal_function.h"
int find_Processors(char* input);
int find_VideoCards(char* input);
int find_ozu(char* input);
int find_rgb(char* input);
struct Computer {
	char name_user[50] = "";
	char name_pc[20] = "";
	char processor[75] = "";
	char VideoCard[100] = "";
	char ozu[75] = "";
	char rgb[50] = "";
	int price = 0;
	int size_computer = 0;
	void calc_price(Computer* arr) {
		int processor_price = find_Processors(arr->processor);
		int videocard_price = find_VideoCards(arr->VideoCard);
		int ozu_price = find_ozu(arr->ozu);
		int rgb_price = find_rgb(arr->rgb);
		arr->price = processor_price + videocard_price + ozu_price + rgb_price;
	}
	void order() {
		cout << "Your name: ";
		cin >> name_user;
		cout << "Name of pc: ";
		cin.ignore();
		cin.getline(name_pc, 50);
		cout << "Processor: ";
		cin.getline(processor, 75);
		if (find_Processors(processor) == -1) {
			cout << "Component is not in stock. But we will order it to make custom pc for you!" << endl;
		}
		cout << "VideoCard: ";
		cin.getline(VideoCard, 100);
		if (find_VideoCards(VideoCard) == -1) {
			cout << "Component is not in stock. But we will order it to make custom pc for you!" << endl;
		}
		cout << "OZU: ";
		cin.getline(ozu, 50);
		if (find_ozu(ozu) == -1) {
			cout << "Component is not in stock. But we will order it to make custom pc for you!" << endl;
		}
		cout << "Rgb Yes/ No: ";
		cin >> rgb;
		int processor_price = find_Processors(processor);
		int videocard_price = find_VideoCards(VideoCard);
		int ozu_price = find_ozu(ozu);
		int rgb_price = find_rgb(rgb);
		if (processor_price == -1 || videocard_price == -1 || ozu_price == -1 || rgb_price == -1) {
			cout << "One or more components are not in stock." << endl;
		}
		else {
			price = processor_price + videocard_price + ozu_price + rgb_price;
			cout << "Price: " << price << " uah" << endl;
		}
	}
	void show_computer(int input) {
		if (input == 1) {
			FILE* fp = nullptr;
			fopen_s(&fp, "Anton's_PCS.bin", "rb");
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
					
					for (int i = 0; i < num; i++) {
						cout << "PC: " << i + 1 << endl;
						int len = 0;
						fread(name_pc, sizeof(char), len, fp);
						cout << "Name of pc: " << name_pc << endl;
						fread(processor, sizeof(char), len, fp);
						cout << "Processor: " << processor << endl;
						fread(VideoCard, sizeof(char), len, fp);
						cout << "VideoCard: " << VideoCard << endl;
						fread(ozu, sizeof(char), len, fp);
						cout << "RAM: " << ozu << endl;
						fread(rgb, sizeof(char), len, fp);
						cout << "rgb: " << rgb<< endl;
						int processor_price = find_Processors(processor);
						int videocard_price = find_VideoCards(VideoCard);
						int ozu_price = find_ozu(ozu);
						int rgb_price = find_rgb(rgb);
						price = processor_price + videocard_price + ozu_price + rgb_price;
						cout << "Price: " << price << " uah" << endl;
					}
					fclose(fp);

				}
			}
		}
		else if (input == 2) {
			FILE* fp = nullptr;
			fopen_s(&fp, "Bobs_PCS.bin", "rb");
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

					for (int i = 0; i < 1; i++) {
						cout << "PC: " << i + 1 << endl;
						int len = 0;
						fread(name_pc, sizeof(char), len, fp);
						cout << "Name of pc: " << name_pc << endl;
						fread(processor, sizeof(char), len, fp);
						cout << "Processor: " << processor << endl;
						fread(VideoCard, sizeof(char), len, fp);
						cout << "VideoCard: " << VideoCard << endl;
						fread(ozu, sizeof(char), len, fp);
						cout << "RAM: " << ozu << endl;
						fread(rgb, sizeof(char), len, fp);
						cout << "rgb: " << rgb << endl;
						int processor_price = find_Processors(processor);
						int videocard_price = find_VideoCards(VideoCard);
						int ozu_price = find_ozu(ozu);
						int rgb_price = find_rgb(rgb);
						price = processor_price + videocard_price + ozu_price + rgb_price;
						cout << "Price: " << price << " uah" << endl;
					}
					fclose(fp);

				}
			}
		}
	}
	void add_computer1() {
		cin.ignore();
		cout << "Name of pc: ";
		cin.getline(name_pc, 50);
		cout << "Processor: ";
		cin.getline(processor, 100);
		if (find_Processors(processor) != 0) {
			size_arr_Processors++;
			cin.getline(arr_Processors->name, 100);
			cout << "Price of processor: ";
			cin >> arr_Processors->price;
		}
		cout << "VideoCard: ";
		cin.ignore();
		cin.getline(VideoCard, 100);
		if (find_VideoCards(VideoCard) != 0) {
			size_arr_VideoCards++;
			cin.getline(arr_VideoCards->name, 100);
			cout << "Price ofVideoCard: ";
			cin >> arr_VideoCards->price;
		}
		cout << "ozu: ";
		cin.ignore();
		cin.getline(ozu, 100);
		if (find_ozu(ozu) != 0)
		{
			size_arr_ozu++;
			cin.getline(arr_ozu->name, 100);
			cout << "Price of Ozu: ";
			cin >> arr_ozu->price;
		}
		cout << "rgb Yes/No: ";
		cin.ignore();
		cin.getline(rgb, 20);
		int processor_price = find_Processors(processor);
		int videocard_price = find_VideoCards(VideoCard);
		int ozu_price = find_ozu(ozu);
		int rgb_price = find_rgb(rgb);
		price = processor_price + videocard_price + ozu_price + rgb_price;
		cout << "Price: " << price << " uah" << endl;
	}
	static void sort1_max() {
		FILE* fp = nullptr;
		fopen_s(&fp, "Anton's_PCS.bin", "rb");
		if (fp == NULL) cout << "ERROR";
		else {
			fseek(fp, 0, SEEK_END);
			int num = ftell(fp) / sizeof(Computer);
			fseek(fp, 0, SEEK_SET);
			Computer* arr = new Computer[num];
			fread(arr, sizeof(Computer), num, fp);
			fclose(fp);
			for (int i = 0; i < num; i++) {
				arr[i].calc_price(&arr[i]);
			}
			for (int i = 0; i < num - 1; i++) {
				for (int j = 0; j < num - i - 1; j++) {
					if (arr[j].price < arr[j + 1].price) {
						Computer temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < num; i++)
			{
				cout << arr[i].name_pc << "." << "Price: " << arr[i].price << endl;
			}
		}
	}
	static void sort2_max() {
		FILE* fp = nullptr;
		fopen_s(&fp, "Bobs_PCS.bin", "rb");
		if (fp == NULL) cout << "ERROR";
		else {
			fseek(fp, 0, SEEK_END);
			int num = ftell(fp) / sizeof(Computer);
			fseek(fp, 0, SEEK_SET);
			Computer* arr = new Computer[num];
			fread(arr, sizeof(Computer), num, fp);
			fclose(fp);
			for (int i = 0; i < num; i++) {
				arr[i].calc_price(&arr[i]);
			}
			for (int i = 0; i < num - 1; i++) {
				for (int j = 0; j < num - i - 1; j++) {
					if (arr[j].price < arr[j + 1].price) {
						Computer temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < num; i++)
			{
				cout << arr[i].name_pc << "." << "Price: " << arr[i].price << endl;
			}
		}
	}
	static void sort1_min() {
		FILE* fp = nullptr;
		fopen_s(&fp, "Anton's_PCS.bin", "rb");
		if (fp == NULL) cout << "ERROR";
		else {
			fseek(fp, 0, SEEK_END);
			int num = ftell(fp) / sizeof(Computer);
			fseek(fp, 0, SEEK_SET);
			Computer* arr = new Computer[num];
			fread(arr, sizeof(Computer), num, fp);
			fclose(fp);
			for (int i = 0; i < num; i++) {
				arr[i].calc_price(&arr[i]);
			}
			for (int i = 0; i < num - 1; i++) {
				for (int j = 0; j < num - i - 1; j++) {
					if (arr[j].price > arr[j + 1].price) {
						Computer temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < num; i++)
			{
				cout << arr[i].name_pc << "." << "Price: " << arr[i].price << endl;
			}
		}
	}
	static void sort2_min() {
		FILE* fp = nullptr;
		fopen_s(&fp, "Bobs_PCS.bin", "rb");
		if (fp == NULL) cout << "ERROR";
		else {
			fseek(fp, 0, SEEK_END);
			int num = ftell(fp) / sizeof(Computer);
			fseek(fp, 0, SEEK_SET);
			Computer* arr = new Computer[num];
			fread(arr, sizeof(Computer), num, fp);
			fclose(fp);
			for (int i = 0; i < num; i++) {
				arr[i].calc_price(&arr[i]);
			}
			for (int i = 0; i < num - 1; i++) {
				for (int j = 0; j < num - i - 1; j++) {
					if (arr[j].price > arr[j + 1].price) {
						Computer temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < num; i++)
			{
				cout << arr[i].name_pc << "." << "Price: " << arr[i].price << endl;
			}
		}
	}
};