#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <conio2.h>

using namespace std;

void twrp();
void bootloader();
void bootloaderLogo();
void magisk();
void apkInstall();
void apkUninstall();

int main() {

	//titulo do programa
	system("title @OCOD ~ AndroidUserTools_v1.3.6 (stable)");

	textcolor(15);

	//cria uma variavel um inteira
	int proc;

	//exibe uma mensagem ao usuario e grava a resposta na variavel
	cout << "\n Select a process to start\n\n  [1] TWRP Install\n\n  [2] Bootloader Unlock (Motorola)\n  [3] Remove bootloader logo\n\n  [4] Magisk/Tutorial\n\n  [5] Install APK/ADB\n  [6] Unistall APK/ADB\n\n > ";
	cin >> proc;

	clrscr();

	//executa um processo dependendo da resposta dentro de um bloco switch
	switch(proc) {
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
	}
}

void twrp() {

	char path[100]; //cria uma variavel com o nome path que suporte 100 caracteres

	textcolor(15); //exibe uma mensagem com o texto opaco em cinza
	cout << "\n INSTRUCTION:  download  the twrp  image  to your device," << endl;
	cout << " connect your device to the PC and  press  [ENTER],  on  the" << endl;
	cout << " next screen, move the twrp image file to the command prompt" << endl;
	cout << " press [ENTER] again and  wait  for  the  image  to install." << endl;

    textcolor(6); //cinza
	cout << "\n ! it is not necessary to rename the file to (twrp.img)," << endl;
	cout << "     the program will do this during the installation process..." << endl;

	cout << "\n\n connect your device to PC in recovery mode and press [ENTER]..." << endl;
	getch();

	clrscr();

    textcolor(15); //cinza
	cout << "\n REQUIREMENTS FOR INSTALATION" << endl;
	cout << "\n * ADB and Fastboot drivers, visit: https://adb.clockworkmod.com/" << endl;
	cout << " * Drivers of your mobile device (look for the driver for your device model)" << endl;
	cout << " * Unlocked bootloader (see the video on how to unlock on my youtube channel)" << endl;
	cout << "   [https://www.youtube.com/channel/UCqnVsLksN6n7XjpDP-urM5Q]\n\n\n\n";

    textcolor(6); //verde
	cout << "   DRAG THE IMG FILE HERE,         \n";
	cout << "   AND PRESS [ENTER] TO CONTINUE!  \n";
	cout << "                                   \n";
	cout << "   0 0   0 00000  0000 0 0    0000 \n";
	cout << "   0 0 0 0 0      0    0 0    0    \n";
	cout << "   0 0   0 0  00  000  0 0    0000 \n";
	cout << "   0 0   0 0   0  0    0 0    0    \n";
	cout << " 0 0 0   0 00000  0    0 0000 0000 \n";
	cout << "\n\n > ";
	cin >> path; //grava o caminho do arquivo em path

	/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do codigo dentro da variavel path*/
	FILE * file_path;
	file_path = fopen ("path.txt","wt");
	fprintf (file_path, "move %s",path);
	fclose (file_path);

	//operacoes com o arquivo criado
	system("ren path.txt path.bat");
	system("path.bat");
	system("del path.bat");

	clrscr();

	//operacoes com o arquivo de imagem
	system("ren *.img twrp.img");
	system("fastboot flash recovery twrp.img");
	system("fastboot boot twrp.img");

	clrscr();

    textcolor(15); //branco
	cout << "\n if everything worked out your device will restart in TWRP recovery mode." << endl;
	cout << "\n press [enter] to exit..." << endl;
	getch();

	exit(0);
}

void bootloader() {

	char key[30]; //cria uma variavel char que armazena ate 30 caracteres

	//exibe uma mensagem ao usuario
	textcolor(6);
	cout << "\n connect your device in recovery mode and press [ENTER]...";
	getch();

	clrscr();

	//executa o comando para obter o codigo de desbloqueio do aparelho
	system("fastboot oem get_unlock_data");

	//exibe uma mensagem ao usuario
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

	//abre o arquivo unlock.html
	system("unlock.htm");

	//exige o codigo de desbloqueio enviado ao e-mail, key armazena o codigo de ate 30 caracteres
	textcolor(15);
	cout << "\n Put Your Unlock code here and press [ENTER] > ";
	cin >> key;

	/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do codigo dentro da variavel key*/
	FILE * file_key;
	file_key = fopen ("key.txt","wt");
	fprintf (file_key, "fastboot oem unlock %s",key);
	fclose (file_key);

	//operecoes com o arquivo criado
	system("ren key.txt key.bat");
	system("key.bat");
	system("del key.bat");
	system("cls");

	//exibe uma mensagem de sucesso
	textcolor(6);
	cout << "\n Bootloader has been unlocked, press [ENTER] to exit...";
	getch();

	exit(0);
}

void bootloaderLogo() {

	//cria uma variavel do tipo char que suporta ate 120 caracteres
	char bin[120];

	//exibe uma cadeia de mensagens
	textcolor(15);
	cout << "\n Connect your device in fastboot mode and press [ENTER]...";
	getch();

	clrscr();

	cout << "\nCheck if your device has been recognized, if so press [ENTER] again...\n\n";
	system("fastboot devices"); //verfica se existe algum aparelho conectado
	getch();

	clrscr();

	cout << "\n You will need the logo file for your cell phone model\n in .bin format, drag the file to the console below and press [ENTER]\n\n\n";

	textcolor(6);
	cout << "   DRAG THE BIN FILE HERE,          \n";
	cout << "   AND PRESS [ENTER] TO CONTINUE!   \n";
	cout << "                                    \n";
	cout << "   0000  0 0   0  0000 0 0    0000  \n";
	cout << "   0   0 0 00  0  0    0 0    0     \n";
	cout << "   0000  0 0 0 0  000  0 0    0000  \n";
	cout << "   0   0 0 0  00  0    0 0    0     \n";
	cout << " 0 0000  0 0   0  0    0 0000 0000  \n";
	cout << "\n\n > ";
	cin >> bin; //grava o caminho do arquivo

	/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do codigo dentro da variavel bin*/
	FILE * file_bin;
	file_bin = fopen ("bin.txt","wt");
	fprintf (file_bin, "fastboot flash logo %s",bin);
	fclose (file_bin);

	//operacoes com o arquivo criado
	system("ren bin.txt bin.bat");
	system("bin.bat");
	system("del bin.bat");

	clrscr();

	/*exibe a mensagem de que o bin foi injetado com sucesso*/
	textcolor(15);
	cout << "\n Success! the " << bin << " file was injected!";
	getch();

	exit(0);
}

void magisk() {

	//exibe uma mensagem/tutorial de instalacao do magisk
	textcolor(15);
	cout << "\n Magisk/Tutorial";
	cout << "\n  How to install Magisk";
	cout << "\n\n 1. Go to Magisk page on GitHub: https://github.com/topjohnwu/Magisk";
	cout << "\n\n 2. Download the Magisk zip file and move the zip from your PC\n    to your device's SD card (recommended)";
	cout << "\n\n 3. Open TWRP on your device, click 'install'\n    and look for the magisk zip file";
	cout << "\n\n 4. Select the zip and flash file...";
	cout << "\n\n 5. After flashing the file, boot the system and install\n    the latest version of margisk.apk";
	cout << "\n\n\n done! now you can enjoy the magic!";
	getch();

	exit(0);
}

void apkInstall() {

	//usa goto, recarrega o codigo a partir daqui
	reload:

	//cria duas variaveis do tipo char, com uma suportando ate 500 caracteres
	char apk[500];
	char answer;

	//exibe uma mensagem
	textcolor(15);
	cout << "\n Enable usb debugging on your device,";
	cout << "\n\n  Go to your device settings, enable developer mode\n  and within that option enable usb debug mode!\n\n";

	textcolor(6);
	cout << "   DRAG THE APK FILE HERE,             \n";
	cout << "   AND PRESS [ENTER] TO CONTINUE!      \n";
	cout << "                                       \n";
	cout << "     0   0000  0  0  0000 0 0    0000  \n";
	cout << "    0 0  0   0 0 0   0    0 0    0     \n";
	cout << "   00000 0000  00    000  0 0    0000  \n";
	cout << "   0   0 0     0 0   0    0 0    0     \n";
	cout << " 0 0   0 0     0  0  0    0 0000 0000  \n";
	cout << "\n\n > ";
	cin >> apk; //grava o caminho do arquivo na variavel apk

	/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do codigo dentro da variavel apk*/
	FILE * file_apk;
	file_apk = fopen ("apk.txt","wt");
	fprintf (file_apk, "adb install -r %s",apk);
	fclose (file_apk);

	//operacoes com o arquivo criado
	system("ren apk.txt apk.bat");
	system("apk.bat");
	system("del apk.bat");

	clrscr();

	//exibe uma mensagem de sucesso e pergunta se o usuario deseja executar o programa mais uma vez
	textcolor(15);
	cout << "\n " << apk << " - has been successfully installed!";
	cout << "\n\n Install another apk? [y]//[n]";
	cout << "\n\n > ";
	cin >> answer;

	//se sim ele carrega reload, caso nao ele sai do programa
	if (answer == 'y' or answer == 'Y') {
		system("cls");
	   	goto reload;
	} else {
		exit(0);
	}
}

void apkUninstall() {

	//exibe uma mensagem
	textcolor(15);
	cout << "\n Enable usb debugging on your device,";
	cout << "\n\n  Go to your device settings, enable developer mode\n  and within that option enable usb debug mode!\n";
	cout << "\n\n  type the command followed by the package name as in\n  the example below and press [ENTER]\n";
	cout << "\n  exemple: pm uninstall -k --user 0 com.yourpackage.name";
	cout << "\n           ---------command-------- -----packagename----\n\n\n";

	//executa um comando
	system("adb shell");
	getch();

	exit(0);
}
