#include <iostream>
#include <string>

enum class States { q0, q1, q2, q3 };

int main()
{
	std::string input;
	States state = States::q0;
	bool flag = true;
	int counter = 0;

	std::cout << "Enter an example: ";
	std::cin >> input;
	input.insert(0, " ");
	input.push_back(' ');

	while(flag)
	{
		switch (state)
		{
		case States::q0:
			if (input[counter] == '+' or input[counter] == ' ')
				counter += 1;
			else if (input[counter] == '1')
			{
				input[counter] = ' ';
				counter += 1;
				state = States::q1;
			}
			else if (input[counter] == '=')
			{
				input[counter] = ' ';
				counter = 0;
				state = States::q3;
			}
			break;
		case States::q1:
			if (input[counter] == '1' or input[counter] == '+' or input[counter] == '=')
				counter += 1;
			else if (input[counter] == ' ')
			{
				input[counter] = '1';
				input.push_back(' ');
				counter -= 1;
				state = States::q2;
			}
			break;
		case States::q2:
			if (input[counter] == '1' or input[counter] == '+' or input[counter] == '=')
				counter -= 1;
			else if (input[counter] == ' ')
			{
				counter += 1;
				state = States::q0;
			}
			break;
		case States::q3:
			if(input[counter] == ' ' or input[counter] == '+')
			{
				input.erase(counter, 1);
			}
			else
				flag = false;
			break;
		}
	}
	std::cout << "Answer: " << input << std::endl;
	return 0;
}