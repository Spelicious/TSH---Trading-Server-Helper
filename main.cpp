#define WINVER 0x0500
#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>
#include "iostream"
#include <dinput.h>


int main()
{
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "               TradingServerHelper v0.3              " << std::endl;
    std::cout << "   Copyright 2020 - https://github.com/Spelicious/   " << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "                                                     " << std::endl;
    std::cout << " To start TradingServerHelper press '1' on numpad.   " << std::endl;
    std::cout << " If you want to close the program press '0' on numpad" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;

    int timer = 0;
    int stalking = 0;
    while (true) {
        timer++;
        Sleep(100);
        if (GetAsyncKeyState(VK_NUMPAD0)) { //EXIT
            std::cout << "Trading Helper will close in 3 seconds." << std::endl;
            Sleep(3000);
            return 0;
        }
        if (GetAsyncKeyState(VK_NUMPAD1)) { //xd
            std::cout << "Trading Helper is started!" << std::endl;
            stalking = 1;
        }
            /*
            IF timer > 100 = 10 seconds + 5 seconds (to execute keys)
            IF timer > 150 = 15 seconds + 5 seconds (to execute keys)
            IF timer > 200 = 20 seconds + 5 seconds (to execute keys)
            IF timer > 250 = 25 seconds + 5 seconds (to execute keys)
            IF timer > 300 = 30 seconds + 5 seconds (to execute keys)
            IF timer > 350 = 35 seconds + 5 seconds (to execute keys)
            */
            if (timer > 150) {
                timer = 0;
                if (stalking) {
               
                    INPUT ip;
                    // Set up a generic keyboard event.
                    ip.type = INPUT_KEYBOARD;
                    ip.ki.wScan = 0; // hardware scan code for key
                    ip.ki.time = 0;
                    ip.ki.dwExtraInfo = 0;

                    // Press the "Y" key
                    ip.ki.wScan = DIKEYBOARD_Y;
                    ip.ki.dwFlags = 0; // 0 for key press
                    SendInput(1, &ip, sizeof(INPUT));

                    // Release the "Y" key
                    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                    SendInput(1, &ip, sizeof(INPUT));

                    std::cout << "Key 'Y' is pressed." << std::endl;
                    Sleep(2000);
                    ////

                    // Press the CTRL
                    ip.type = INPUT_KEYBOARD;
                    ip.ki.wScan = 0;
                    ip.ki.wVk = VK_CONTROL;
                    ip.ki.dwFlags = 0;
                    SendInput(1, &ip, sizeof(INPUT));

                    // Press V
                    ip.ki.wVk = 'V';
                    ip.ki.dwFlags = 0;
                    SendInput(1, &ip, sizeof(INPUT));
                    Sleep(1000);

                    // Release the "V" key
                    ip.ki.wVk = 'V';
                    ip.ki.dwFlags = KEYEVENTF_KEYUP;
                    SendInput(1, &ip, sizeof(INPUT));

                    //Release the ctrl
                    ip.ki.wVk = VK_CONTROL;
                    ip.ki.dwFlags = KEYEVENTF_KEYUP;
                    SendInput(1, &ip, sizeof(INPUT));

                    std::cout << "Keys 'CTRL+V' is pressed." << std::endl;
                    ////////
                    Sleep(2000);

                    ip.type = INPUT_KEYBOARD;
                    ip.ki.wScan = 0; // hardware scan code for key
                    ip.ki.time = 0;
                    ip.ki.dwExtraInfo = 0;

                    // Press the "Enter" key
                    ip.ki.wVk = VK_RETURN;
                    ip.ki.dwFlags = 0; // 0 for key press
                    SendInput(1, &ip, sizeof(INPUT));

                    // Release the "Enter" key
                    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                    SendInput(1, &ip, sizeof(INPUT));
                    std::cout << "Key 'Enter' is pressed. Starting again in a few seconds." << std::endl;
                    std::cout << "--------------------------------------------------------" << std::endl;
                    
                }
            }
    }
}
