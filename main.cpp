#include <Windows.h>
#include <iostream>

using namespace std;





void decreaseClickSpeed(int currentSpeed) {
	currentSpeed -= 10;
}

bool isOn() {
	if (GetKeyState(VK_MENU) & 0x8000) {
		if (GetAsyncKeyState(0x4B) & 1) {
			return true;
		}else if (GetAsyncKeyState(0x4C) & 1) {
			return false;
		}
	}

}

void click() {
	INPUT mouse[4] = { 0 };
	mouse[0].type = INPUT_MOUSE;
	mouse[1].type = INPUT_MOUSE;
	mouse[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	mouse[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	mouse[2].type = INPUT_MOUSE;
	mouse[3].type = INPUT_MOUSE;
	mouse[2].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	mouse[3].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(4, mouse, sizeof(INPUT));
}


//ALT + K == ON
//ALT + L == OFF
int main() {
	bool runClicker = isOn();
	
	while (1) {
		
		while (runClicker) {
			cout << "test" << endl;
			click();
			if (GetKeyState(VK_MENU) & 0x8000) { //Alt + L = OFF
				if (GetAsyncKeyState(0x4C) & 1) {
					break;
				}
			}

		}

		runClicker = isOn();
	}
}