#include <iostream>
#include <string>
#include <Windows.h>

#define TIME 600

enum class States { q0, q1, q2, q3 };

int main()
{
	std::string input;
	States state = States::q0;
	bool flag = true;
	int counter = 0;

	std::cout << std::endl;
	std::cin >> input;
	input.insert(0, " ");
	input.push_back(' ');
	
	std::string readingHead(input.size(), ' ');
	system("cls");

	while(flag)
	{
		switch (state)
		{
		case States::q0:
			if (input[counter] == '+' or input[counter] == ' ')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q0\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				counter += 1;

				std::cout << "Next state: q0\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			else if (input[counter] == '1')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q0\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				input[counter] = ' ';
				counter += 1;
				state = States::q1;

				std::cout << "Next state: q1\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			else if (input[counter] == '=')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q0\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				input[counter] = ' ';
				counter -= 1;
				state = States::q3;

				std::cout << "Next state: q3\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			break;
		case States::q1:
			if (input[counter] == '1' or input[counter] == '+' or input[counter] == '=')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q1\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				counter += 1;

				std::cout << "Next state: q1\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			else if (input[counter] == ' ')
			{
				readingHead.push_back(' ');
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q1\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				input[counter] = '1';
				input.push_back(' ');
				counter -= 1;
				state = States::q2;

				std::cout << "Next state: q2\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			break;
		case States::q2:
			if (input[counter] == '1' or input[counter] == '+' or input[counter] == '=')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q2\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				counter -= 1;

				std::cout << "Next state: q2\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			else if (input[counter] == ' ')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q2\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				counter += 1;
				state = States::q0;

				std::cout << "Next state: q0\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			break;
		case States::q3:
			if (counter == 0)
			{
				std::cout << std::endl << input << std::endl;
				flag = false;
			}
			else if (input[counter] == '+' or input[counter] == ' ')
			{
				readingHead[counter] = '|';
				std::cout << readingHead << std::endl;
				readingHead[counter] = ' ';
				std::cout << input;
				std::cout << "\n\nCurrent state: q3\nCurrent value: |" << input[counter] << "|" << std::endl << std::endl;

				input[counter] = ' ';
				counter -= 1;

				std::cout << "Next state: q3\nNext value: |" << input[counter] << "|" << std::endl;
				Sleep(TIME);
				system("cls");
			}
			break;
		}
	}
	return 0;
}
