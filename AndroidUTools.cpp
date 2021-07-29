#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <conio2.h>
#include <fstream>

//define uma variável que recebe a versão do programa.
#define VERSION "1.3.8"

//var global: recebe o caminho dos arquivos nas funções twrp, bootloader, bootloaderLogo e apkInstall.
std::string archives;

void twrp();
void bootloader();
void bootloaderLogo();
void magisk();
void apkInstall();
void apkUninstall();

int main(int argc, char * argv[]) {

	system("title AndroidUserTools (EN-US)");

	int processo;

	textcolor(3);
	std::cout << "\n Github.com/AndersonLeandrog";
	std::cout << "\n Youtube.com/OCodificador";
	std::cout << "\n\n [@OCOD * STABLE * " << "VER: " << VERSION << "]\n\n";

    	textcolor(15);
	std::cout << "\n  Select a process to start\n\n";
    	std::cout << "   [1] TWRP Install\n\n";
    	std::cout << "   [2] Bootloader Unlock (Motorola)\n";
    	std::cout << "   [3] Remove bootloader logo\n\n";
    	std::cout << "   [4] Magisk/Tutorial\n\n";
    	std::cout << "   [5] Install APK/ADB\n";
    	std::cout << "   [6] Unistall APK/ADB\n\n > ";
    	std::cin >> processo;

	clrscr();

	switch(processo) {

		case 1: //Caso o processo seja igual a 1
			twrp(); //Executa a função twrp();
			break;

		case 2: //Caso o processo seja igual a 2
			bootloader(); //Executa a função bootloader()
			break;

		case 3: //Caso o processo seja igual a 3
			bootloaderLogo(); //Executa a função bootloaderlogo()
			break;

		case 4: //Caso o processo seja igual a 4
			magisk(); //Executa a função magisk();
			break;

		case 5: //Caso o processo seja igual a 5
			apkInstall(); //Executa a função apkInstall()
			break;

		case 6: //Caso o processo seja igual a 6
			apkUninstall(); //Executa a função apkUninstall()
			break;
	}
}




//FUNÇÃO TWRP
void twrp() {
	
	textcolor(15);

	std::cout << "\n INSTRUCTION:  download  the twrp  image  to your device," << std::endl;
	std::cout << " connect your device to the PC and  press  [ENTER],  on  the" << std::endl;
	std::cout << " next screen, move the twrp image file to the command prompt" << std::endl;
	std::cout << " press [ENTER] again and  wait  for  the  image  to install." << std::endl;
    	textcolor(6);

	std::cout << "\n ! it is not necessary to rename the file to (twrp.img)," << std::endl;
	std::cout << "     the program will do this during the installation process..." << std::endl;
	std::cout << "\n\n connect your device to PC in recovery mode and press [ENTER]..." << std::endl;
	textcolor(15);
	getch();

	clrscr();

	std::cout << "\n REQUIREMENTS FOR INSTALATION" << std::endl;
	std::cout << "\n * ADB and Fastboot drivers, visit: https://adb.clockworkmod.com/" << std::endl;
	std::cout << " * Drivers of your mobile device (look for the driver for your device model)" << std::endl;
	std::cout << " * Unlocked bootloader (see the video on how to unlock on my youtube channel)" << std::endl;
	std::cout << "   [https://www.youtube.com/channel/UCqnVsLksN6n7XjpDP-urM5Q]\n\n\n\n";

    	textcolor(6);
	std::cout << "   DRAG THE IMG FILE HERE,         \n";
	std::cout << "   AND PRESS [ENTER] TO CONTINUE!  \n";
	std::cout << "                                   \n";
	std::cout << "   0 0   0 00000  0000 0 0    0000 \n";
	std::cout << "   0 0 0 0 0      0    0 0    0    \n";
	std::cout << "   0 0   0 0  00  000  0 0    0000 \n";
	std::cout << "   0 0   0 0   0  0    0 0    0    \n";
	std::cout << " 0 0 0   0 00000  0    0 0000 0000 \n";
	std::cout << "\n\n digit '/r' to return \n\n > ";
	std::cin >> archives; //grava o caminho do arquivo na variável path

    	clrscr();

    	if(archives == "/r") { system("AndroidUserTools.exe"); }

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravação e em seguida grava uma
	string seguida do código dentro da variável path
	*/

	std::ofstream file_path;
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

	std::cout << "\n if everything worked out your device will restart in TWRP recovery mode." << std::endl;
	std::cout << "\n press [enter] to exit..." << std::endl;
	getch(); //Se o botão enter for pressionado o programa será finalizado.

	exit(0);
}


//FUNÇÃO BOOTLOADER
void bootloader() {

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


//FUNÇÃO BOOTLOADERLOGO
void bootloaderLogo() {

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


//FUNÇÃO MAGISK
void magisk() {

	textcolor(15);

	//Instalação do Magisk tutorial.
	std::cout << "\n Magisk/Tutorial";
	std::cout << "\n  How to install Magisk";
	std::cout << "\n\n 1. Go to Magisk page on GitHub: https://github.com/topjohnwu/Magisk";
	std::cout << "\n\n 2. Download the Magisk zip file and move the zip from your PC\n    to your device's SD card (recommended)";
	std::cout << "\n\n 3. Open TWRP on your device, click 'install'\n    and look for the magisk zip file";
	std::cout << "\n\n 4. Select the zip and flash file...";
	std::cout << "\n\n 5. After flashing the file, boot the system and install\n    the latest version of margisk.apk";
	std::cout << "\n\n\n done! now you can enjoy the magic!";
	getch();

	exit(0);
}


//FUNÇÃO APKINSTALL
void apkInstall() {

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


//FUNÇÃO APKUNINSTALL
void apkUninstall() {

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
