#include "Date.h"
#include "Lib.h"
#include "personal_function.h" 
#define ADD_COMPUTER  0
int main()
{

	int menu = 0;
	int input = 0;
	int password_Anton = 213441;
	int password_Bob = 8773251;
	float password_Vasya = 3416;
	int tmp_password = 0;
	int sizePersonal = 3;
	int size_pc = 4;
	int menu1 = 0;
	int choose = 0;
	int choose2 = 0;
	Personal* arrPersonal = new Personal[sizePersonal]{
		{"Pekarov Anton", 3, "From 9 am to 17 p.m", "cashier",0, nullptr},
		{"Assov Bob",  6, "from 8 am to 14 pm", "cashier",0, nullptr},
		{"Hlebolobov Vasya",  15, "from 12 am to 17 pm", "owner",0, nullptr}
	};

	Computer v1 = { "Anton", "Blood Dragon", "Ryzen 5-3600", "Nvidia GTX 1080ti", "DDR4 8 gb", "Yes" };
	Computer v2 = { "Bob", "Sniper AWP", "Intel CORE i9-13600KF", "Nvidia RTX 3090ti", "DDR5 32 gb", "Yes" };
	Computer v3 = { "Bob", "ShadowRaze", "Intel CORE i7-10700KF", "Nvidia GTX 1050", "DDR4 16 gb", "No" };
#if ADD_COMPUTER == 1
	FILE* fp2 = nullptr;
	fopen_s(&fp2, "Anton's_PCS.bin", "wb");
	if (fp2 == NULL) cout << "ERROR";
	else {
		for (int i = 0; i < 1; i++)
		{
			fwrite(&v1, sizeof(Computer), 1, fp2);
		}
		fclose(fp2);
	}
	FILE* fp = nullptr;
	if (fopen_s(&fp, "Bobs_PCS.bin", "wb") != 0) {
		cout << "ERROR: Failed to open file" << endl;
	}
	else {
		fwrite(&v2, sizeof(Computer), 1, fp);
		fwrite(&v3, sizeof(Computer), 1, fp);
		fclose(fp);
	}
#endif
	arrPersonal[0].add_computer(v1);
	arrPersonal[1].add_computer(v3);
	arrPersonal[1].add_computer(v2);
	Personal person;
	cout << "Who are you: 1 - User/ 2 - Cashier1/3- Cashier2/ 4 - Owner(Vasya): ";
	cin >> input;
	if (input > 0 && input < 5) {
		switch (input)
		{
		case 1:
			do
			{
				cout << "*---------------------------------------------------------------*" << endl;
				cout << "|1 - show all personal\t\t\t\t\t\t|\n";
				cout << "|2 - choose show personal\t\t\t\t\t|\n";
				cout << "|3 - buy custom pc from choosen customer\t\t\t|\n";
				cout << "|4 - sort all pc from high price to low price\t\t\t|\n";
				cout << "|5 - sort all pc from low price to high price\t\t\t|\n";
				cout << "|6 - show all configs\t\t\t\t\t\t|\n";
				cout << "|7 - sort components for computer from high price to low price  |\n";
				cout << "|8 - sort components for computer from low price to high price  |\n";
				cout << "*---------------------------------------------------------------*" << endl;
				cin >> menu;
				switch (menu)
				{
				case 1:
					show_all(arrPersonal, sizePersonal);
					break;
				case 2:
					show_personal(arrPersonal, sizePersonal);
					break;
				case 3:
					order_pc();
					break;
				case 4:
					cout << "Cashier1 or Cashier2: ";
					cin >> choose;
					if (choose == 1) Computer::sort1_max();
					else if (choose == 2) Computer::sort2_max();
					else cout << "Incorect input";
					break;
					break;
				case 5:cout << "Cashier1 or Cashier2: ";
					cin >> choose;
					if (choose == 1) Computer::sort1_min();
					else if (choose == 2) Computer::sort2_min();
					else cout << "Incorect input";
					break;
					break;
				case 6:
					show_configs();
					break;
				case 7: 
					sort_configs_max();
					break;
				case 8: 
					sort_configs_min();
					break;
				default:
					break;
				}
			} while (true);
			break;
		case 2:
			cout << "Hello!" << endl;
			cout << "Enter your password: ";
			cin >> tmp_password;

			if (tmp_password == password_Anton) {
				do
				{
					cout << "*-------------------------------*" << endl;
					cout << "|1 - show orders\t\t|\n";
					cout << "|2 - Delete order\t\t|\n";
					cout << "|3 - Create new pc\t\t|\n";
					cout << "|4 - Delete pc\t\t\t|\n";
					cout << "*-------------------------------*" << endl;
					cin >> menu1;
					switch (menu1)
					{
					case 1:
						orders_cashier1();
						break;
					case 2:
						deleteOrder();
						break;
					case 3:
						arrPersonal[0].add_computer1();
						break;
					case 4:
						delete_pc1();
						break;
					default:
						break;
					}
				} while (true);

			}
			else cout << "Incorrect password.";
			break;
		case 3:
			cout << "Hello!";
			cout << "Enter your password: ";
			cin >> tmp_password;
			if (tmp_password == password_Bob) {
				do
				{
					cout << "*-------------------------------*" << endl;
					cout << "|1 - show orders\t\t|\n";
					cout << "|2 - Delete order\t\t|\n";
					cout << "|3 - Create new pc\t\t|\n";
					cout << "|4 - Delete pc\t\t\t|\n";
					cout << "*-------------------------------*" << endl;
					cin >> menu1;
					switch (menu1)
					{
					case 1:
						orders_cashier2();
						break;
					case 2:
						deleteOrder();
						break;
					case 3:
						arrPersonal[1].add_computer2();
						break;
					case 4:
						delete_pc2();
						break;
					default:
						break;
					}
				} while (true);
			}
			else cout << "Incorrect password.";
			break;
		case 4:
			cout << "Hello Boss!" << endl;
			cout << "Enter your password: ";
			cin >> tmp_password;
			if (tmp_password == password_Vasya) {
				cout << "*-------------------------------*" << endl;
				cout << "|1. Retire cashier.\t\t\|\n";
				cout << "|2. Hire cashier.\t\t|\n";
				cout << "|3. put a component up for sale |\n";
				cout << "*-------------------------------*" << endl;
				cin >> menu1;
				switch (menu1)
				{
				case 1:
					delete_person();
					break;
				case 2: 
					person.add_personal();
				case 3:
					cout << "*-------------------------------*" << endl;
					cout << "|1. Add Processor.\t\t\|\n";
					cout << "|2. Add Video Card.\t\t|\n";
					cout << "|3. Add RAM (Ozu) \t\t|\n";
					cout << "*-------------------------------*" << endl;
					cin >> choose;

					switch (choose) {
					case 1:
						addNewProcessor();
						break;
					case 2:
						addNewVideoCard();
						break;
					case 3:
						addNewOzu();
						break;
					default:
						cout << "Invalid choice." << endl;
						break;
					}
				default:
					break;
				}
			}
			else cout << "Incorrect password.";
			break;
		default:
			break;
		}
	}
	delete[] arrPersonal;
}