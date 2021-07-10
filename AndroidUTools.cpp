#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "windows.h"
#include <string.h>

using namespace std;

int main() 
{
	//exibe o titulo do programa (nao esqueÃ§a de dar os creditos ao desenvolvedor original do projeto)
	system("title AndroidUserTools by OCOD ~ ver 1.3.4 (beta)");

	//cria a variavel proc de 'processo' e key de 'chave'
	int proc;
	char key[30];
	
	/*exibe uma mensagem perguntando sobre o tipo de proceso a ser realizado para o usuario e grava a
	resposta na variavel proc*/
	cout << "\n Select a process to start\n\n  [1] TWRP Install\n\n  [2] Bootloader Unlock (Motorola)\n  [3] Remove bootloader logo\n\n  [4] Magisk/Tutorial\n\n  [5] Install APK/ADB\n  [6] Unistall APK/ADB\n\n > ";
	cin >> proc;
	
	system("cls");
	
	switch(proc)
	{
		case 1: //twrp 
			//exibe uma mensagem de instruÃ§ao para a instalaÃ§ao do TWRP e aguarda ate que uma tecla seja pressionada
			cout << "\n INSTRUCTION:  download  the twrp  image  to your device," << endl;
			cout << " connect your device to the PC and  press  [ENTER],  on  the" << endl;
			cout << " next screen, move the twrp image file to the command prompt" << endl;
			cout << " press [ENTER] again and  wait  for  the  image  to install." << endl;
			
			cout << "\n ! it is not necessary to rename the file to (twrp.img)," << endl;
			cout << "     the program will do this during the installation process..." << endl;
			
			cout << "\n\n connect your device to PC in recovery mode and press [ENTER]..." << endl;
			getch();
			
			system("cls");
			
			//cria uma variavel com o nome path 
			char path[100];
			
			//>> aqui!
			cout << "\n REQUIREMENTS FOR INSTALATION" << endl;
			cout << "\n * ADB and Fastboot drivers, visit: https://adb.clockworkmod.com/" << endl;
			cout << " * Drivers of your mobile device (look for the driver for your device model)" << endl;
			cout << " * Unlocked bootloader (see the video on how to unlock on my youtube channel)" << endl;
			cout << "   [https://www.youtube.com/channel/UCqnVsLksN6n7XjpDP-urM5Q]\n\n\n\n";
			
			
			cout << "                   DRAG THE IMG FILE HERE,                \n";
			cout << "               AND PRESS [ENTER] TO CONTINUE!             \n";
			cout << "                                                          \n";
			cout << "               0 0   0 00000  0000 0 0    0000            \n";
			cout << "               0 0 0 0 0      0    0 0    0               \n";
			cout << "               0 0   0 0  00  000  0 0    0000            \n";
			cout << "               0 0   0 0   0  0    0 0    0               \n";
			cout << "             0 0 0   0 00000  0    0 0000 0000            \n";
			cout << "\n\n > ";
			cin >> path;
			
			FILE * pFile; //cria um ponteiro para o arquivo
			pFile = fopen ("grab.txt","wt"); //cria e abre o arquivo em modo de gravaï¿½ao
			fprintf (pFile, "move %s",path); //grava uma string seguida de uma variavel
			fclose (pFile); //fecha o arquivo
		   	
		   	system("ren grab.txt grab.bat"); //renomeia o arquivo criado para .bat
		   	system("grab.bat"); //executa o arquivo .bat
		   	system("del grab.bat"); //deleta o arquivo .bat depois da sua execuï¿½ao
			
			system("cls");
			
			system("title AndroidUserTools by OCOD _ recognizing the device...");
			system("fastboot devices"); //reconhece qualquer aparelho conectado
			Sleep(2000);
			
			system("cls");
			
			system("title AndroidUserTools by OCOD _ renaming file...");
			system("ren *.img twrp.img"); //renomeia todos os arquivos de imagem para twrp.img
			Sleep(1000);
			
			system("cls");
			
			system("title AndroidUserTools by OCOD _ flashing the device...");
			system("fastboot flash recovery twrp.img"); //flesha o twrp no celular
			Sleep(3000);
			
			system("cls");
			
			system("title AndroidUserTools by OCOD _ restarting the device...");
			system("fastboot boot twrp.img"); //reinicia o aparelho no modo de recuperaï¿½ao
			Sleep(1000);
			
			system("cls");
			
			system("title AndroidUserTools by OCOD _ done!");
			cout << "\n if everything worked out your device will restart in TWRP recovery mode." << endl;
			cout << "\n press [enter] to exit..." << endl;
			getch();
			
			exit(0);
		break;
			
		case 2: //Bootloader
			//exibe uma mensagem ao usuario
			cout << "\n connect your device in recovery mode and press [ENTER]...";
			getch();
			
			system("cls");
			
			//executa o comando para obter o codigo de desbloqueio do aparelho
			system("fastboot oem get_unlock_data");
	
			/*exibe um pequeno tutorial de como obter o codigo de desbloqueio e aguarda ate que
			uma tecla seja pressionada para continuar*/
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
			
			/*limpa a tela e abre o arquivo web unlock.html para que o usuario insira o codigo
			obtido pelo prompt de comando*/
			system("cls");
			system("unlock.htm");
	
			/*exige o codigo de desbloqueio enviado ao e-mail para o usuario
			e grava o codigo na variavel do tipo char key*/
			cout << "\n Put Your Unlock code here and press [ENTER] > ";
			cin >> key;
			
			/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
			string seguida do codigo dentro da variavel key*/
			FILE * arq_key; 
			arq_key = fopen ("key.txt","wt"); 
			fprintf (arq_key, "fastboot oem unlock %s",key); 
			fclose (arq_key); 
			
			/*renomeia o arquivo key.txt criado para key.bat e executa esse arquivo em seguida,
			apos sua execuÃ§ao o arquivo e removido da pasta raiz*/
			system("ren key.txt key.bat");
	   		system("key.bat"); 
	   		system("del key.bat"); 
	   		system("cls");
	   		
			/*exibe a mensagem de sucesso, bootloader foi desbloqueado! e aguarda ate que uma tecla
			seja pressionada para continuar*/
	   		cout << "\n Bootloader has been unlocked, press [ENTER] to exit...";
	   		getch();
	   		
	   		exit(0); //finaliza o programa
		break;
		
		case 3: //bootloader logo
			char bin[10];
			
			cout << "\n Connect your device in fastboot mode and press [ENTER]...";
			getch();
			
			system("cls");
			
			cout << "\nCheck if your device has been recognized, if so press [ENTER] again...\n\n";
			system("fastboot devices");
			getch();
			
			system("cls");
			
			cout << "\n You will need the logo file for your cell phone model\n in .bin format, drag the file to the console below and press [ENTER]\n\n\n";
			cout << "                   DRAG THE BIN FILE HERE,                \n";
			cout << "               AND PRESS [ENTER] TO CONTINUE!             \n";
			cout << "                                                          \n";
			cout << "              0000  0 0   0  0000 0 0    0000             \n";
			cout << "              0   0 0 00  0  0    0 0    0                \n";
			cout << "              0000  0 0 0 0  000  0 0    0000             \n";
			cout << "              0   0 0 0  00  0    0 0    0                \n";
			cout << "            0 0000  0 0   0  0    0 0000 0000             \n";
			cout << "\n\n > ";	
			cin >> bin;
			
			/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
			string seguida do codigo dentro da variavel bin*/
			FILE * arq_bin; 
			arq_bin = fopen ("bin.txt","wt"); 
			fprintf (arq_bin, "fastboot flash logo %s",bin); 
			fclose (arq_bin); 
			
			/*renomeia o arquivo bin.txt criado para bin.bat e executa esse arquivo em seguida,
			apos sua execuÃ§ao o arquivo e removido da pasta raiz*/
			system("ren bin.txt bin.bat");
	   		system("bin.bat"); 
	   		system("del bin.bat"); 
	   		system("cls");
	   		
			/*exibe a mensagem de que o bin foi injetado com sucesso*/
	   		cout << "\n Success! the " << bin << " file was injected!";
			getch();
			
			exit(0);
			break;
			
		case 4: //Magisk
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
			break;
			
		case 5:	//apk install
			reload:
				
			char apk[500];
			char answer;
			
			cout << "\n Enable usb debugging on your device,";
			cout << "\n\n  Go to your device settings, enable developer mode\n  and within that option enable usb debug mode!\n\n";
			cout << "                   DRAG THE APK FILE HERE,                \n";
			cout << "               AND PRESS [ENTER] TO CONTINUE!             \n";
			cout << "                                                          \n";
			cout << "               0   0000  0  0  0000 0 0    0000          \n";
			cout << "              0 0  0   0 0 0   0    0 0    0             \n";
			cout << "             00000 0000  00    000  0 0    0000          \n";
			cout << "             0   0 0     0 0   0    0 0    0             \n";
			cout << "           0 0   0 0     0  0  0    0 0000 0000          \n";
			cout << "\n\n > ";	
			cin >> apk;
			
			/*cria e abre um arquivo do tipo .txt em modo de gravacao e em seguida grava uma
			string seguida do codigo dentro da variavel apk*/
			FILE * arq_apk; 
			arq_apk = fopen ("apk.txt","wt"); 
			fprintf (arq_apk, "adb install -r %s",apk); 
			fclose (arq_apk); 
			
			/*renomeia o arquivo apk.txt criado para key.bat e executa esse arquivo em seguida,
			apos sua execuÃ§ao o arquivo e removido da pasta raiz*/
			system("ren apk.txt apk.bat");
	   		system("apk.bat"); 
	   		system("del apk.bat"); 
	   		system("cls");
	   		
			/*exibe a mensagem de sucesso, aplicativo foi instalado com sucesso!*/
	   		cout << "\n " << apk << " - has been successfully installed!";
	   		cout << "\n\n Install another apk? [y]//[n]";
	   		cout << "\n\n > ";
	   		cin >> answer;
	   		
	   		if (answer == 'y' or answer == 'Y')
	   		{
	   			system("cls");
	   			goto reload;
			} else {
				exit(0);
			}
			break;
			
		case 6: //apk uninstall
			cout << "\n Enable usb debugging on your device,";
			cout << "\n\n  Go to your device settings, enable developer mode\n  and within that option enable usb debug mode!\n";	
			cout << "\n\n  type the command followed by the package name as in\n  the example below and press [ENTER]\n";
			cout << "\n  exemple: pm uninstall -k --user 0 com.yourpackage.name";	
			cout << "\n           ---------command-------- -----packagename----\n\n\n";
			
			system("adb shell");
	   		getch();
			
			exit(0);
			break;
	}
		
}
