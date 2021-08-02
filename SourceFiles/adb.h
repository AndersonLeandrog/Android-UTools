#ifndef ADB_H_INCLUDED
#define ADB_H_INCLUDED

void adbPull()
{
    reload:

    std::cout << "\n All your moved files go to the program root\n folder called 'files'\n\n";
    std::cout << " Copy files from device to PC\n";
    std::cout << " enter the path of the file that will\n be moved from your phone to your computer.\n\n\n";

    textcolor(10);

    std::cout << "           * from your device"; textcolor(5);
    std::cout << "                      * to PC\n"; textcolor(15);
    std::cout << "  Exemple: "; textcolor(10);
    std::cout << "sdcard/android/data/your-file.extension"; textcolor(5);
    std::cout << " /files"; textcolor(15);
    std::cout << "\n\n digit '/r' to return";
    std::cout << "\n\n > ";
    std::cin >> archives;

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

    std::cout << "\n All your moved files go to the 'usr.files'\n folder in your device's internal directory!\n";
    std::cout << "\n Copy files from PC to Device";
    std::cout << "\n enter the path of the file that will\n be moved from your PC to your phone\n or drag the file into the program.\n\n\n";

    textcolor(10);

    std::cout << "           * from your PC"; textcolor(5);
    std::cout << "                  * to Device\n"; textcolor(15);
    std::cout << "  Exemple: "; textcolor(10);
    std::cout << "user/desktop/yourfile.extension"; textcolor(5);
    std::cout << " sdcard/usr.files"; textcolor(15);
    std::cout << "\n\n digit '/r' to return";
    std::cout << "\n\n > ";
    std::cin >> archives;

    clrscr();

    if(archives == "/r") { system("AndroidUserTools.exe"); }

    //creates a folder in the root directory of the program called 'usr.files' -
    system("mkdir usr.files");

    //generates a txt file with instructions to move the created folder to the device in sdcard/'usr.files'
    //and then moves the files from the address stored in the archives variable to that folder moved to the device.
    std::ofstream adbPushD;
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
