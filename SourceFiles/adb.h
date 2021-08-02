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

    if(archives == "/r") { system("AndroidUserTools.exe"); }

    system("mkdir files");

    std::ofstream adbPullD;
    adbPullD.open("path.txt");
    adbPullD << "adb pull" << " " << archives  << " " << "files";
    adbPullD.close();

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

    if(archives == "/r") { system("AndroidUserTools.exe"); }

    //creates a folder in the root directory of the program called 'usr.files' -
    system("mkdir usr.files");

    //generates a txt file with instructions to move the created folder to the device in sdcard/'usr.files'
    //and then moves the files from the address stored in the archives variable to that folder moved to the device.
    ofstream adbPushD;
    adbPushD.open("path.txt");
    adbPushD << "adb push usr.files" << " " << "sdcard/" << "\n" << "adb push" << " " << archives << " " << "sdcard/usr.files";
    adbPushD.close();

    getch();

    //to execute the commands stored in the file path.txt,
    //this same file is converted from txt to bat and then executed, after its execution the file is deleted.
    system("ren path.txt path.bat");
    system("path.bat");
    system("del path.bat");

    Sleep(5000);
    clrscr();

    goto reload;
}

#endif // ADB_H_INCLUDED
