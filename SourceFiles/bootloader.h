#ifndef BOOTLOADER_H_INCLUDED
#define BOOTLOADER_H_INCLUDED

void bootloader()
{
	textcolor(15);
	cout << "\n connect your device in recovery mode and press [ENTER]...";
	getch();

	clrscr();
	system("fastboot oem get_unlock_data");

	cout << "\n\n\n Copy all the code above and press [ENTER] <-";
	cout << "\n\n  > right click on the code and select (mark),";
	cout << "\n    select the entire code and click again with";
	cout << "\n    the right mouse button to copy!";
	cout << "\n\n    paste the code on the motorola website and";
	cout << "\n    don't forget to remove the spaces between the code.";
	cout << "\n\n    Exemple:";
	cout << "\n\n     XXXXXXXXXXXXXXXX# XXXXXXXXXXXXXXXXX# XXXXXXXXXXXXXXXXX# XXXXXXXXXXXX";
	cout << "\n                      ^                  ^                  ^\n\n > ";
	getch();

	clrscr();
	system("unlock.htm");

	cout << "\n Put Your Unlock code here and press [ENTER] > ";
	cin >> archives;

	ofstream KeyPath;
	KeyPath.open("path.txt");
	KeyPath << "fastboot oem unlock " << archives;
	KeyPath.close();

	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();

	textcolor(6);
	cout << "\n Bootloader has been unlocked, press [ENTER] to exit...";
	getch();

	exit(0);
}

#endif // BOOTLOADER_H_INCLUDED
