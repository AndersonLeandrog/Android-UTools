#ifndef BOOTLOADERLOGO_H_INCLUDED
#define BOOTLOADERLOGO_H_INCLUDED

void bootloaderLogo()
{
	textcolor(15);

	std::cout << "\n Connect your device in fastboot mode and press [ENTER]...";
	getch();

	clrscr();

	std::cout << "\nCheck if your device has been recognized, if so press [ENTER] again...\n\n";
	system("fastboot devices"); //Verifica se existe algum aparelho conectado.
	getch();

	clrscr();

	std::cout << "\n You will need the logo file for your cell phone model\n in .bin format, drag the file to the console below and press [ENTER]\n\n\n";
	textcolor(6);

	std::cout << "   DRAG THE BIN FILE HERE,          \n";
	std::cout << "   AND PRESS [ENTER] TO CONTINUE!   \n";
	std::cout << "                                    \n";
	std::cout << "   0000  0 0   0  0000 0 0    0000  \n";
	std::cout << "   0   0 0 00  0  0    0 0    0     \n";
	std::cout << "   0000  0 0 0 0  000  0 0    0000  \n";
	std::cout << "   0   0 0 0  00  0    0 0    0     \n";
	std::cout << " 0 0000  0 0   0  0    0 0000 0000  \n";
	std::cout << "\n\n digit '/r' to return \n\n > ";
	std::cin >> archives; //grava o caminho do arquivo

    clrscr();

    if(archives == "/r") { system("AndroidUserTools.exe"); }

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravação e em seguida grava uma
	string seguida do código dentro da variavel bin.
	*/

	std::ofstream BinPath;
	BinPath.open("path.txt");
	BinPath << "fastboot flash logo " << archives;
	BinPath.close();

	/*
	Renomeia o arquivo txt para bat, executa e após sua execução remove o arquivo.
	*/

	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();

	/*exibe a mensagem de que o bin foi injetado com sucesso*/
	textcolor(15);
	std::cout << "\n Success! the " << archives << " file was injected!";
	getch();

	exit(0);
}

#endif // BOOTLOADERLOGO_H_INCLUDED
