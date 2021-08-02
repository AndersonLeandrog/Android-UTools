#ifndef TWRP_H_INCLUDED
#define TWRP_H_INCLUDED

void twrp()
{
	textcolor(15);

	cout << "\n INSTRUCTION:  download  the twrp  image  to your device,\n";
	cout << " connect your device to the PC and  press  [ENTER],  on  the\n";
	cout << " next screen, move the twrp image file to the command prompt\n";
	cout << " press [ENTER] again and  wait  for  the  image  to install.\n";
    textcolor(6);

	cout << "\n ! it is not necessary to rename the file to (twrp.img),\n";
	cout << "     the program will do this during the installation process...\n";
	cout << "\n\n connect your device to PC in recovery mode and press [ENTER]...\n";
	textcolor(15);
	getch();

	clrscr();

	cout << "\n REQUIREMENTS FOR INSTALATION\n";
	cout << "\n * ADB and Fastboot drivers, visit: https://adb.clockworkmod.com/\n";
	cout << " * Drivers of your mobile device (look for the driver for your device model)\n";
	cout << " * Unlocked bootloader (see the video on how to unlock on my youtube channel)\n";
	cout << "   [https://www.youtube.com/channel/UCqnVsLksN6n7XjpDP-urM5Q]\n\n\n\n";
    textcolor(6);

	cout << "   DRAG THE IMG FILE HERE,         \n";
	cout << "   AND PRESS [ENTER] TO CONTINUE!  \n";
	cout << "                                   \n";
	cout << "   0 0   0 00000  0000 0 0    0000 \n";
	cout << "   0 0 0 0 0      0    0 0    0    \n";
	cout << "   0 0   0 0  00  000  0 0    0000 \n";
	cout << "   0 0   0 0   0  0    0 0    0    \n";
	cout << " 0 0 0   0 00000  0    0 0000 0000 \n";
	cout << "\n\n digit '/r' to return \n\n > ";
	cin >> archives; //grava o caminho do arquivo na variável path

    clrscr();

    if(archives == "/r") { system("AndroidUserTools.exe"); }

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravação e em seguida grava uma
	string seguida do código dentro da variável path
	*/

	ofstream file_path;
	file_path.open("path.txt");
	file_path << "move " << archives;
	file_path.close();

	/*
	Renomeia o arquivo criado de txt p/ bat, executa o bat e em seguida remove o arquivo
	após a sua execução.
	*/

	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();

	/*
	Renomeia o arquivo de imagem do usuário para twrp.img e em seguida realiza o processo
	de instalação do recovery

	O primeiro comando flasheia o twrp renomeado no aparelho.
	O segundo reinicia o aparelho após o processo.
	*/

	system("ren *.img twrp.img");
	system("fastboot flash recovery twrp.img");
	system("fastboot boot twrp.img");
	textcolor(15); //branco brilhante

	clrscr();

	cout << "\n if everything worked out your device will restart in TWRP recovery mode.\n";
	cout << "\n press [enter] to exit...\n";
	getch(); //Se o botão enter for pressionado o programa será finalizado.

	exit(0);
}

#endif // TWRP_H_INCLUDED
