#ifndef MAGISK_H_INCLUDED
#define MAGISK_H_INCLUDED

void magisk()
{
	textcolor(14);
	cout << "\n Magisk/Tutorial";
	cout << "\n  How to install Magisk";
	cout << "\n\n 1. Go to Magisk page on GitHub: https://github.com/topjohnwu/Magisk";
	cout << "\n\n 2. Download the Magisk zip file and move the zip from your PC\n    to your device's SD card (recommended)";
	cout << "\n\n 3. Open TWRP on your device, click 'install'\n    and look for the magisk zip file";
	cout << "\n\n 4. Select the zip and flash file...";
	cout << "\n\n 5. After flashing the file, boot the system and install\n    the latest version of margisk.apk";
	cout << "\n\n\n done! now you can enjoy the magic!";

	textcolor(15);
	cout << "\n\n digit '/r' to return \n\n > ";
	cin >> archives;

    clrscr();

    if(archives == "/r") { system("AndroidUserTools.exe"); }
	exit(0);
}

#endif // MAGISK_H_INCLUDED
