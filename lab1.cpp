#include <iostream>
#include <windows.h>
using namespace std;

const char* Output[4] = { "Red for cars\nGreen for people\n", "Red and yellow for cars\nRed for people\n",
						  "Green for cars\nRed for people\n","Yellow for cars\nRed for people\n" };

class TraficLightsClass
{
public:
    int Time, State = 0;
    void SwitchingLights();
    void MainFun();
};

void TraficLightsClass::SwitchingLights()
{
	for(; Time > 0; Time--)
	{
        cout << Output[State];
        cout << "Remaining time: " << Time << endl;
        Sleep(1000);
        system("cls");
	}
}

void TraficLightsClass::MainFun()
{
    while (true)
    {
        switch (State)
        {
        case 0:
            Time = 10;
            SwitchingLights();
            State = 1;
            break;
        case 1:
            Time = 2;
            SwitchingLights();
            State = 2;
            break;
        case 2:
            Time = 10;
            SwitchingLights();
            State = 3;
            break;
        case 3:
            Time = 2;
            SwitchingLights();
            State = 0;
            break;
        }
    }
}


int main()
{
    TraficLightsClass TraficLights;
    TraficLights.MainFun();
    return 0;
}