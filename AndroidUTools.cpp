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
	int processo;

	//Exibe um título e modifica a cor do texto
	system("title @OCOD ~ AndroidUserTools_v1.3.7 (stable)");
	textcolor(15);

	//Exibe uma mensagem ao usuário e grava o valor na variável 'processo'
	cout << "\n Select a process to start\n\n  [1] TWRP Install\n\n  [2] Bootloader Unlock (Motorola)\n  [3] Remove bootloader logo\n\n  [4] Magisk/Tutorial\n\n  [5] Install APK/ADB\n  [6] Unistall APK/ADB\n\n > ";
	cin >> processo;

	clrscr();

	switch(processo) 
	{
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



/*
	FUNÇÃO TWRP
*/

void twrp() { 
	char path[100];
	textcolor(15); //Branco brilhante

	cout << "\n INSTRUCTION:  download  the twrp  image  to your device," << endl;
	cout << " connect your device to the PC and  press  [ENTER],  on  the" << endl;
	cout << " next screen, move the twrp image file to the command prompt" << endl;
	cout << " press [ENTER] again and  wait  for  the  image  to install." << endl;
    	textcolor(6); //Cinza (Opaco)

	cout << "\n ! it is not necessary to rename the file to (twrp.img)," << endl;
	cout << "     the program will do this during the installation process..." << endl;
	cout << "\n\n connect your device to PC in recovery mode and press [ENTER]..." << endl;
	textcolor(15); //Branco brilhante
	getch();

	clrscr();

	cout << "\n REQUIREMENTS FOR INSTALATION" << endl;
	cout << "\n * ADB and Fastboot drivers, visit: https://adb.clockworkmod.com/" << endl;
	cout << " * Drivers of your mobile device (look for the driver for your device model)" << endl;
	cout << " * Unlocked bootloader (see the video on how to unlock on my youtube channel)" << endl;
	cout << "   [https://www.youtube.com/channel/UCqnVsLksN6n7XjpDP-urM5Q]\n\n\n\n";

    	textcolor(6); //Verde
	cout << "   DRAG THE IMG FILE HERE,         \n";
	cout << "   AND PRESS [ENTER] TO CONTINUE!  \n";
	cout << "                                   \n";
	cout << "   0 0   0 00000  0000 0 0    0000 \n";
	cout << "   0 0 0 0 0      0    0 0    0    \n";
	cout << "   0 0   0 0  00  000  0 0    0000 \n";
	cout << "   0 0   0 0   0  0    0 0    0    \n";
	cout << " 0 0 0   0 00000  0    0 0000 0000 \n";
	cout << "\n\n > ";
	cin >> path; //grava o caminho do arquivo na variável path

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravação e em seguida grava uma
	string seguida do código dentro da variável path
	*/

	FILE * file_path;
	file_path = fopen ("path.txt","wt");
	fprintf (file_path, "move %s",path);
	fclose (file_path);

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

	cout << "\n if everything worked out your device will restart in TWRP recovery mode." << endl;
	cout << "\n press [enter] to exit..." << endl;
	getch(); //Se o botão enter for pressionado o programa será finalizado.

	exit(0);
}

/*
	FUNÇÃO BOOTLOADER
*/

void bootloader() {
	char key[30];
	textcolor(6);

	cout << "\n connect your device in recovery mode and press [ENTER]...";
	getch();

	clrscr();

	//Executa o comando para obter o código de desbloqueio do aparelho
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

	//Abre o arquivo unlock.html
	system("unlock.htm");
    	textcolor(15);
	
	//Exige o código de desbloqueio enviado ao e-mail, key armazena o código de ate 30 caracteres.
	cout << "\n Put Your Unlock code here and press [ENTER] > ";
	cin >> key;

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do código dentro da variável key
	*/
	
	FILE * file_key;
	file_key = fopen ("key.txt","wt");
	fprintf (file_key, "fastboot oem unlock %s",key);
	fclose (file_key);

	/*
	Renomeia o arquivo de texto para bat e em seguida executa o arquivo
	e após a sua execução o arquivo é excluído.
	*/
	
	system("ren key.txt key.bat");
	system("key.bat");
	system("del key.bat");
	
	clrscr();

	//Se o bootloader for desbloqueado ele exibe uma mensagem de sucesso!
	textcolor(6);
	cout << "\n Bootloader has been unlocked, press [ENTER] to exit...";
	getch();

	exit(0);
}

/*
	FUNÇÃO BOOTLOADERLOGO
*/

void bootloaderLogo() {
	char bin[120];
	textcolor(15);
	
	cout << "\n Connect your device in fastboot mode and press [ENTER]...";
	getch();

	clrscr();

	cout << "\nCheck if your device has been recognized, if so press [ENTER] again...\n\n";
	system("fastboot devices"); //Verifica se existe algum aparelho conectado.
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

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravação e em seguida grava uma
	string seguida do código dentro da variavel bin.
	*/
	
	FILE * file_bin;
	file_bin = fopen ("bin.txt","wt");
	fprintf (file_bin, "fastboot flash logo %s",bin);
	fclose (file_bin);

	/*
	Renomeia o arquivo txt para bat, executa e após sua execução remove o arquivo.
	*/
	
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
	textcolor(15);
	
	//Instalação do Magisk tutorial.
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
	reload: //Recarrega o código a partir daqui. 
	
	char apk[500];
	char answer;

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
	cin >> apk; //grava o caminho do arquivo na variável apk

	/*
	Cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
	string seguida do codigo dentro da variavel apk
	*/
	
	FILE * file_apk;
	file_apk = fopen ("apk.txt","wt");
	fprintf (file_apk, "adb install -r %s",apk);
	fclose (file_apk);

	system("ren apk.txt apk.bat");
	system("apk.bat");
	system("del apk.bat");

	clrscr();

	//exibe uma mensagem de sucesso e pergunta se o usuário deseja executar o programa mais uma vez
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
