#ifndef APK_H_INCLUDED
#define APK_H_INCLUDED

void apkInstall()
{
	reload: //Recarrega o código a partir daqui.

	char answer;

	textcolor(15);
	std::cout << "\n Enable usb debugging on your device,";
	std::cout << "\n\n  Go to your device settings, enable developer mode\n  and within that option enable usb debug mode!\n\n";
	textcolor(6);

	std::cout << "   DRAG THE APK FILE HERE,             \n";
	std::cout << "   AND PRESS [ENTER] TO CONTINUE!      \n";
	std::cout << "                                       \n";
	std::cout << "     0   0000  0  0  0000 0 0    0000  \n";
	std::cout << "    0 0  0   0 0 0   0    0 0    0     \n";
	std::cout << "   00000 0000  00    000  0 0    0000  \n";
	std::cout << "   0   0 0     0 0   0    0 0    0     \n";
	std::cout << " 0 0   0 0     0  0  0    0 0000 0000  \n";
	std::cout << "\n\n digit '/r' to return \n\n > ";
	std::cin >> archives; //grava o caminho do arquivo na variável apk

    clrscr();

    if(archives == "/r") { system("AndroidUserTools.exe"); }

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do codigo dentro da variavel apk
	*/

	std::ofstream ApkPath;
	ApkPath.open("path.txt");
	ApkPath << "adb install -r " << archives;
	ApkPath.close();

	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();

	//exibe uma mensagem de sucesso e pergunta se o usuário deseja executar o programa mais uma vez
	textcolor(15);
	std::cout << "\n " << archives << " - has been successfully installed!";
	std::cout << "\n\n Install another apk? [y]//[n]";
	std::cout << "\n\n > ";
	std::cin >> answer;

	//se sim ele carrega reload, caso nao ele sai do programa
	if (answer == 'y' or answer == 'Y') {
		system("cls");
	   	goto reload;
	} else {
		exit(0);
	}
}


void apkUninstall()
{
	textcolor(15);

	std::cout << "\n Enable usb debugging on your device,";
	std::cout << "\n\n  Go to your device settings, enable developer mode\n  and within that option enable usb debug mode!\n";
	std::cout << "\n\n  type the command followed by the package name as in\n  the example below and press [ENTER]\n";
	std::cout << "\n  exemple: pm uninstall -k --user 0 com.yourpackage.name";
	std::cout << "\n           ---------command-------- -----packagename----\n\n\n";

	//executa um comando
	system("adb shell");
	getch();

	exit(0);
}

#endif // APK_H_INCLUDED
