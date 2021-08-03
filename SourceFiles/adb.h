#ifndef ADB_H_INCLUDED
#define ADB_H_INCLUDED

void adbPull()
{
    reload:
    
    cout << "\n All your moved files go to the program root\n folder called 'files'\n\n";
    cout << " Copy files from device to PC\n";
    cout << " enter the path of the file that will\n be moved from your phone to your computer.\n\n\n";

    textcolor(10);
    cout << "           * from your device"; textcolor(4);
    cout << "                      * to PC\n"; textcolor(15);
    cout << "  Exemple: "; textcolor(10);
    cout << "sdcard/android/data/your-file.extension"; textcolor(4);
    cout << " /files"; textcolor(15);
    cout << "\n\n digit '/r' to return";
    cout << "\n\n > ";
    cin >> archives;

    clrscr();
    
    //se o usuário der o comando /r o programa será reaberto.
    
    if(archives == "/r") { 
        system("AndroidUserTools.exe"); 
    }
    
    //cria uma pasta na raiz do programa
    
    system("mkdir files");
    
    //cria um arquivo de texto chamado path.txt e insere o comando (adb pull (archives) files) onde:
    //'adb pull' refere-se ao comando para enviar um arquivo do Android para o PC via adb.
    //'archives' é a variável que armazena o diretório do arquivo que será movido.
    //'files' é a pasta criada, que receberá o arquivo do diretório de 'archives'.
    
    ofstream adbPullD;
    adbPullD.open("path.txt");
    adbPullD << "adb pull" << " " << archives  << " " << "files";
    adbPullD.close();
    
    //converte o txt anteriormente criado para batchScript, em seguida executa esse script
    //e ao final de sua execução ele irá remover o batchScript.
    
    system("ren path.txt path.bat");
    system("path.bat");
    system("del path.bat");

    Sleep(5000);
    clrscr();

    goto reload;
}


void adbPush()
{
    reload:

    cout << "\n All your moved files go to the 'usr.files'\n folder in your device's internal directory!\n";
    cout << "\n Copy files from PC to Device";
    cout << "\n enter the path of the file that will\n be moved from your PC to your phone\n or drag the file into the program.\n\n\n";

    textcolor(10);
    cout << "           * from your PC"; textcolor(4);
    cout << "                  * to Device\n"; textcolor(15);
    cout << "  Exemple: "; textcolor(10);
    cout << "user/desktop/yourfile.extension"; textcolor(4);
    cout << " sdcard/usr.files"; textcolor(15);
    cout << "\n\n digit '/r' to return";
    cout << "\n\n > ";
    cin >> archives;

    clrscr();
    
    //se o usuário der o comando /r o programa será reaberto.
    
    if(archives == "/r") {
        system("AndroidUserTools.exe"); 
    }
    
    //cria uma pasta na raiz do programa chamada 'usr.files'.
    
    system("mkdir usr.files");
    
    //cria um arquivo de texto chamado path.txt e insere o comando (adb push usr.files sdcard/)
    //seguido do comando (adb push (archives) sdcard/usr.files) onde:
    
    //O primeiro comando copia a pasta que foi criada na raiz do programa e cola ela na memória interna do Android.
    //O segundo move os arquivos do diretório informado pelo usuário dentro da variável 'archives' para a pasta
    //que foi colada na memória interna, isso é: a pasta 'usr.files'
    
    ofstream adbPushD;
    adbPushD.open("path.txt");
    adbPushD << "adb push usr.files" << " " << "sdcard/" << "\n" << "adb push" << " " << archives << " " << "sdcard/usr.files";
    adbPushD.close();

    getch();

    //converte o txt anteriormente criado para batchScript, em seguida executa esse script
    //e ao final de sua execução ele irá remover o batchScript.
    
    system("ren path.txt path.bat");
    system("path.bat");
    system("del path.bat");

    Sleep(5000);
    clrscr();

    goto reload;
}

#endif // ADB_H_INCLUDED
