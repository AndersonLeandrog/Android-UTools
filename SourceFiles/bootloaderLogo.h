#ifndef BOOTLOADERLOGO_H_INCLUDED
#define BOOTLOADERLOGO_H_INCLUDED

void bootloaderLogo()
{
	textcolor(15);
	cout << "\n Connect your device in fastboot mode and press [ENTER]...";
	getch();

	clrscr();

	cout << "\nCheck if your device has been recognized, if so press [ENTER] again...\n\n";
	system("fastboot devices"); //Verifica se existe algum aparelho conectado.
	getch();

	clrscr();

	cout << "\n You will need the logo file for your cell phone model\n in .bin format, drag the file to the console below and press [ENTER]\n\n\n";

	textcolor(8);
	cout << "   DRAG THE BIN FILE HERE,          \n";
	cout << "   AND PRESS [ENTER] TO CONTINUE!   \n";
	cout << "                                    \n";
	cout << "   0000  0 0   0  0000 0 0    0000  \n";
	cout << "   0   0 0 00  0  0    0 0    0     \n";
	cout << "   0000  0 0 0 0  000  0 0    0000  \n";
	cout << "   0   0 0 0  00  0    0 0    0     \n";
	cout << " 0 0000  0 0   0  0    0 0000 0000  \n";

	textcolor(15);
	cout << "\n\n digit '/r' to return \n\n > ";
	cin >> archives; //grava o caminho do arquivo

    clrscr();

    if(archives == "/r") { system("AndroidUserTools.exe"); }

	ofstream BinPath;
	BinPath.open("path.txt");
	BinPath << "fastboot flash logo " << archives;
	BinPath.close();

	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();
	
	textcolor(15);
	cout << "\n Success! the " << archives << " file was injected!";
	getch();

	exit(0);
}

#endif // BOOTLOADERLOGO_H_INCLUDED
