#include <Windows.h>
#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;





void decreaseClickSpeed(int* clickSpeed) {
	*clickSpeed-=1;
}
void increaseClickSpeed(int& clickSpeed) {
	clickSpeed += 1;
}

bool isOn() {
	if (GetKeyState(VK_MENU) & 0x8000) {
		if (GetAsyncKeyState(0x4B) & 1) {
			return true;
		}else if (GetAsyncKeyState(0x4A) & 1) { //ALT + J = CLOSE PROGRAM
			return false;
		}
	}

}

int timeDelayCounter(int clickSpeed) {
	double num = 871.62 / clickSpeed;
	return pow(num, 1 / 0.981);
}
void click() {
	INPUT mouse[2] = { 0 };
	mouse[0].type = INPUT_MOUSE;
	mouse[1].type = INPUT_MOUSE;
	mouse[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	mouse[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(2, mouse, sizeof(INPUT));
}


//ALT + K == ON
//ALT + L == OFF
int main() {
	bool runClicker = isOn();
	int clickSpeed = 10;
	int sleepTimer = timeDelayCounter(clickSpeed);
	while (1) {

		while (runClicker) {

			click();
			Sleep(sleepTimer);
			if (GetKeyState(VK_MENU) & 0x8000) { //Alt + L = OFF
				if (GetAsyncKeyState(0x4C) & 1) {
					break;
				}
				if (GetAsyncKeyState(0x4D) & 1) { //Alt + M = Increase Speed
					decreaseClickSpeed(&clickSpeed);
					cout << clickSpeed << endl;
				}
			}



		}
		if (GetKeyState(VK_MENU) & 0x8000) { //Alt + M = Increase Speed
			if (GetAsyncKeyState(0x4D) & 1) {
				increaseClickSpeed(clickSpeed);
				sleepTimer = timeDelayCounter(clickSpeed);
				cout << clickSpeed << endl;
			}
			if (GetAsyncKeyState(0x4E) & 1) { //Alt + N = Decrease Speed
				decreaseClickSpeed(&clickSpeed);
				sleepTimer = timeDelayCounter(clickSpeed);
				cout << clickSpeed << endl;
			}
		}


		runClicker = isOn();
	}

}