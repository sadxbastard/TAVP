#include <iostream>
#include <windows.h>
using namespace std;

const char* Output[4] = { "Red for cars\nGreen for people\n", "Red and yellow for cars\nRed for people\n",
						  "Green for cars\nRed for people\n","Yellow for cars\nRed for people\n" };

class TraficLightsClass
{
public:
    int Time, State;
    void SwitchingLights();
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

int main()
{
    TraficLightsClass TraficLights;
    TraficLights.State = 0;
    while(true)
    {
        switch(TraficLights.State)
    	{
            case 0:
                TraficLights.Time = 10;
                TraficLights.SwitchingLights();
                TraficLights.State = 1;
                break;
			case 1:
                TraficLights.Time = 2;
                TraficLights.SwitchingLights();
                TraficLights.State = 2;
                break;
			case 2:
                TraficLights.Time = 10;
                TraficLights.SwitchingLights();
                TraficLights.State = 3;
                break;
			case 3:
                TraficLights.Time = 2;
                TraficLights.SwitchingLights();
                TraficLights.State = 0;
                break;
        }
    }
    return 0;
}
