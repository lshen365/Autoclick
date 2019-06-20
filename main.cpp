#include <Windows.h>
#include <iostream>

using namespace std;



bool isOn() {
	if (GetKeyState(VK_MENU) & 0x8000) {
		if (GetAsyncKeyState(0x4B) & 1) {
			return true;
		}else if (GetAsyncKeyState(0x4C) & 1) {
			return false;
		}
	}

}


//ALT + K == ON
//ALT + L == OFF
int main() {
	bool runClicker = isOn();
	while (1) {
		
		while (runClicker) {
			cout << "test" << endl;

			if (GetKeyState(VK_MENU) & 0x8000) { //Alt + L = OFF
				if (GetAsyncKeyState(0x4C) & 1) {
					break;
				}
			}

		}

		runClicker = isOn();
	}
}