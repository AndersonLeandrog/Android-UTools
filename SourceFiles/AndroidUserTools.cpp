#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <conio2.h>
#include <windows.h>
#include <fstream>

#define VER "1.4.9"
std::string archives;

using namespace std;

#include "twrp.h"
#include "bootloader.h"
#include "bootloaderLogo.h"
#include "magisk.h"
#include "apk.h"
#include "adb.h"

int main(int argc, char * argv[]) 
{
	system("title AndroidUserTools");
	
	int processo;

	textcolor(3);
	cout << "\n Github.com/AndersonLeandrog\n";
	cout << " Youtube.com/OCodificador\n\n";
	cout << " @OCOD" << " * " << "VER" << " " << VER << " En-US\n\n\n";

    textcolor(15);
	cout << "   SELECT A PROCESS TO START\n\n";
    cout << "   [1] TWRP Install\n\n";
    cout << "   [2] Bootloader Unlock (Motorola)\n";
    cout << "   [3] Remove bootloader logo\n\n";
    cout << "   [4] Magisk/Tutorial\n\n";
    cout << "   [5] Install APK/ADB\n";
    cout << "   [6] Unistall APK/ADB\n\n";
    cout << "   [7] AdbPull * Move from mobile to PC\n";
    cout << "   [8] AdbPush * Move from PC to mobile\n\n > ";
	cin >> processo;

	clrscr();

	switch(processo)
	{
		case 1:
			twrp();
			break;

		case 2:
			bootloader();
			break;

		case 3:
			bootloaderLogo();
			break;

		case 4:
			magisk();
			break;

		case 5:
			apkInstall();
			break;

		case 6:
			apkUninstall();
			break;

        case 7:
			adbPull();
			break;

        case 8:
			adbPush();
			break;
	}
}
