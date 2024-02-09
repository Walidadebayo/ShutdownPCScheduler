#include <iostream>
#include <cstdlib>
#include <vcl.h>
#pragma hdrstop
#include <sstream>
#include <string.h>
#include <fstream.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <vcl.h>
//---------------------------------------------------------------------------

#pragma argsused

int MainMenu();
int ShutDown();
int Restart();



int main(int argc, char *argv[])
{
    int mainstatus;
    do
    {
        mainstatus = MainMenu();
        switch (mainstatus)
        {
        case 1:
            ShutDown();
            break;
        case 2:
            Restart();
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (mainstatus != 3);
    return 0;
}

int MainMenu()
{
    clrscr();
    int choice;
    cout << "1. Schedule a shutdown" << endl;
    cout << "2. Schedule a restart" << endl;
    cout << "3. Exit the program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int ShutDown()
{
    clrscr();
    int minutes;
    int valid = 0;
    cout << "Enter the number of minutes after which to shut down the PC: ";
    cin >> minutes;
    int seconds = minutes * 60;
    stringstream ss;
    ss << seconds;
    string secondsStr = ss.str();
    string shutdownCommand = "shutdown /s /t " + secondsStr;
    int result = system(shutdownCommand.c_str());
    if (result)
    {
        cout << "Shutting down the PC in " << minutes << " minutes." << endl;
        valid = 1;
    }
    else
    {
        cout << "Failed to schedule shutdown." << endl;
    }
    return valid;
}

int Restart()
{
    clrscr();
    int valid = 0;
    int minutes;
    cout << "Enter the number of minutes after which to restart the PC: ";
    cin >> minutes;
    int seconds = minutes * 60;
    stringstream ss;    
    ss << seconds;
    string secondsStr = ss.str();

    string restartCommand = "shutdown /r /t " + secondsStr;
    int result = system(restartCommand.c_str());
    if (result)
    {
        cout << "Restarting the PC in " << minutes << " minutes." << endl;
        valid = 1;
    }
    else
    {
        cout << "Failed to schedule restart." << endl;
    }
    return valid;
}

