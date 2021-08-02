#ifndef BOOTLOADER_H_INCLUDED
#define BOOTLOADER_H_INCLUDED

void bootloader()
{
	textcolor(6);

	std::cout << "\n connect your device in recovery mode and press [ENTER]...";
	getch();

	clrscr();

	//Executa o comando para obter o código de desbloqueio do aparelho
	system("fastboot oem get_unlock_data");

	std::cout << "\n\n\n Copy all the code above and press [ENTER] <-";
	std::cout << "\n\n  > right click on the code and select (mark),";
	std::cout << "\n    select the entire code and click again with";
	std::cout << "\n    the right mouse button to copy!";
	std::cout << "\n\n    paste the code on the motorola website and";
	std::cout << "\n    don't forget to remove the spaces between the code.";
	std::cout << "\n\n    Exemple:";
	std::cout << "\n\n     XXXXXXXXXXXXXXXX# XXXXXXXXXXXXXXXXX# XXXXXXXXXXXXXXXXX# XXXXXXXXXXXX";
	std::cout << "\n                      ^                  ^                  ^\n\n > ";
	getch();

	clrscr();

	//Abre o arquivo unlock.html
	system("unlock.htm");
    textcolor(15);

	//Exige o código de desbloqueio enviado ao e-mail, key armazena o código de ate 30 caracteres.
	std::cout << "\n Put Your Unlock code here and press [ENTER] > ";
	std::cin >> archives;

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do código dentro da variável key
	*/

	std::ofstream KeyPath;
	KeyPath.open("path.txt");
	KeyPath << "fastboot oem unlock " << archives;
	KeyPath.close();

	/*
	Renomeia o arquivo de texto para bat e em seguida executa o arquivo
	e após a sua execução o arquivo é excluído.
	*/

	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();

	//Se o bootloader for desbloqueado ele exibe uma mensagem de sucesso!
	textcolor(6);
	std::cout << "\n Bootloader has been unlocked, press [ENTER] to exit...";
	getch();

	exit(0);
}

#endif // BOOTLOADER_H_INCLUDED
