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
	system("title AndroidUserTools by OCOD ~ ver 1.2.3 (stable)");

	//cria a variavel proc de 'processo' e key de 'chave'
	int proc;
	char key[30];
	
	/*exibe uma mensagem perguntando sobre o tipo de proceso a ser realizado para o usuario e grava a
	resposta na variavel proc*/
	cout << "\n Select a process to start\n\n  [1] TWRP Install\n  [2] Bootloader Unlock (Motorola)\n  [3] Magisk/Tutorial\n\n > ";
	cin >> proc;
	
	system("cls");
	
	switch(proc)
	{
		case 1:
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
			
			
			cout << "               DRAG THE TWRP IMAGE FILE HERE,             " << endl;
			cout << "               AND PRESS [ENTER] TO CONTINUE!             " << endl;
			cout << "                                                          " << endl;
			cout << "                           _______                        " << endl;
			cout << "                         _|       |                       " << endl;
			cout << "                        | |       |                       " << endl;
			cout << "                        | |       |                       " << endl;
			cout << "                        | |       |                       " << endl;
			cout << "                        | |       |                       " << endl;
			cout << "                        | |       |                       " << endl;
			cout << "                        | |       |                       " << endl;
			cout << "                        | |_______|                       " << endl;
			cout << "                        |________|                        " << endl;
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
			
		case 2:
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
		
		case 3:
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
	}
		
}
