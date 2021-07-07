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
	system("title RTWRP by OCOD ~ ver 1.0.0.2");
	
	cout << "\n INSTRUCTION:  download  the twrp  image  to your device," << endl;
	cout << " connect your device to the PC and  press  [ENTER],  on  the" << endl;
	cout << " next screen, move the twrp image file to the command prompt" << endl;
	cout << " press [ENTER] again and  wait  for  the  image  to install." << endl;
	
	cout << "\n ! it is not necessary to rename the file to (twrp.img)," << endl;
	cout << "     the program will do this during the installation process..." << endl;
	
	cout << "\n\n connect your device to PC in recovery mode and press [ENTER]..." << endl;
	getch();
	
	system("cls");
	
	char path[100];
	
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
	pFile = fopen ("grab.txt","wt"); //cria e abre o arquivo em modo de gravaçao
	fprintf (pFile, "move %s",path); //grava uma string seguida de uma variavel
	fclose (pFile); //fecha o arquivo
   	
   	system("ren grab.txt grab.bat"); //renomeia o arquivo criado para .bat
   	system("grab.bat"); //executa o arquivo .bat
   	system("del grab.bat"); //deleta o arquivo .bat depois da sua execuçao
	
	system("cls");
	
	system("title RTWRP by OCOD _ recognizing the device...");
	system("fastboot devices"); //reconhece qualquer aparelho conectado
	Sleep(2000);
	
	system("cls");
	
	system("title RTWRP by OCOD _ renaming file...");
	system("ren *.img twrp.img"); //renomeia todos os arquivos de imagem para twrp.img
	Sleep(1000);
	
	system("cls");
	
	system("title RTWRP by OCOD _ flashing the device...");
	system("fastboot flash recovery twrp.img"); //flesha o twrp no celular
	Sleep(3000);
	
	system("cls");
	
	system("title RTWRP by OCOD _ restarting the device...");
	system("fastboot boot twrp.img"); //reinicia o aparelho no modo de recuperaçao
	Sleep(1000);
	
	system("cls");
	
	system("title RTWRP by OCOD _ done!");
	cout << "\n if everything worked out your device will restart in TWRP recovery mode." << endl;
	cout << "\n press [enter] to exit..." << endl;
	getch();
	
	system("taskkill /im cmd.exe");	
}
