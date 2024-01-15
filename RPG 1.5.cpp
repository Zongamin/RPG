/* Hallo an alle, die diese Repository testen und/oder forken möchten eine kurze aber wichtige Info:
Auf Github wird dieser Code leider nicht funktionieren, da das Terminal auf Github auf Linux basiert, der Code aber unter
Windows geschrieben wurde und 2 Windows Librarys enthält (#include conio.h / #include windows.h) die hier auch als Fehler
angezeigt werden, aber für die Funktionalität unbedingt notwendig sind! Des Weiteren enthält er Textfärbungen (z.B.: \033[94m
oder \033[0m) die nur bedingt bis gar nicht in einer Linux-Derivat - Shell funktionieren! Das Spiel ist auch noch "far from 
finish" und muss wohl an mancher Stelle mit 'ctrl + c' unterbrochen werden! Benutzung auf eigene Gefahr! ;)
Ansonsten HF! 

Gruß Zongamin*/



#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

// Globale Variablen (Spieler)

bool LevelUp[4];
int RegenOn[4];
int Faura[4];
int RundenManager = 0;
int SpielerAnzahl = 1; 
int SkillPunkte[4];
int SpielerLevel[4];
int Schluessel[4];
int Trap[4];
int Ruestung[4][500];
int Waffe[4][500];
double Altmetall[4];
double Heiltrank[4];
double Manatrank[4];
double RegenTrank[4];
double Exp[4];
double LevelExp[4];
double Staerke[4];
double Intelligenz[4];
double Ausdauer[4];
double Geschick[4];
double Gesundheit[4];
double TatsaechlicheGesundheit[4];
double Mana[4];
double TatsaechlichesMana[4];
double Glueck[4];
double Tragekapazitaet[4];
double Gold[4];
double Raeume[4];
double Monster[4];
double Bosse[4];
double Crafted[4];
string SpielerName[4];

// Globale Variablen (Gegner)

double GegnerLeben = 0;
double GegnerTatsaechlichesLeben = 0;
double GegnerMana = 0;
double GegnerTatsaechlichesMana = 0;
double GegnerStaerke = 0;
double GegnerIntelligenz = 0;
double GegnerGeschick = 0;
double GegnerGlueck = 0;
double GegnerRuestung = 0;
double GegnerWaffe = 0;
string GegnerName = "Gegner";

// Zufall Min/Max errechnen

int zufall(int min, int max)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int ZufallsZahl = rand() % (max - min + 1) + min;
    return ZufallsZahl;
}

// Zuweisung aller Charakterwerte

void zuweisung()
{
    SpielerName[1] = "Hans Wurst";
    SpielerName[2] = "Napalm Norbert";
    SpielerName[3] = "Max Mustermann";
    SpielerName[4] = "Jane Doe";
   
    for (int i = 1; i < 5; i++)
        {
        Staerke[i] = 5;
        Intelligenz[i] = 5;
        Ausdauer[i] = 5;
        Geschick[i] = 5;
        Glueck[i] = 5;
        SpielerLevel[i] = 1;
        SkillPunkte[i] = 5;
        LevelExp[i] = 1000;
        Gesundheit[i] = (Staerke[i] * 15) + (Ausdauer[i] * 5);
        Mana[i] = (Intelligenz[i] * 3) + (Ausdauer[i] * 2);
        TatsaechlicheGesundheit[i] = Gesundheit[i];
        TatsaechlichesMana[i] = Mana[i];
        Glueck[i] = (Ausdauer[i] * 0.01) + (Geschick[i] * 0.1);
        Tragekapazitaet[i] = (Staerke[i] * 15) + (Ausdauer[i] * 5);
        RegenOn[i] = 0;
        Faura[i] = 0;
        }
    RundenManager = 0;
    return;
}

// Funktion Press any key

void getKey() 
{
    char key;
    cout << "\n\n<<<< Press any key >>>>";
    key = _getch();
    return;
}

// Funktion Bilschirm leeren

void clrScr() 
{
    system("cls");
    return;
}

// Funktion Auswahl des Spielers

int auswahl()
{
    char key;
    key = _getch(); 
    if (key >= '0' && key <= '9') {
        return key - '0'; // ASCII-Wert in Zahl umwandeln
    } else {
        return -1;
    }

}

// Wahr - Falsch Abfrage

bool boolWert()
{
    char key;
    
    while (true)
    { 
    key = _getch(); 
    if (key == 'j') {bool Auswahl = true; return Auswahl;} else if (key == 'n') {bool Auswahl = false; return Auswahl;}

    cout << "Falsche Eingabe!";
    getKey();
    break;
    }
}

// Spiel laden

int LoadGame()
{   
    clrScr();
    cout << "\033[94m __                            __                                                            \n";
    cout << "/\\ \\                          /\\ \\    __                                                \n";
    cout << "\\ \\ \\        ___      __      \\_\\ \\  /\\_\\     ___       __                          \n";
    cout << " \\ \\ \\  __  / __`\\  /'__`\\    /'_` \\ \\/\\ \\  /' _ `\\   /'_ `\\                     \n";
    cout << "  \\ \\ \\L\\ \\/\\ \\L\\ \\/\\ \\L\\.\\_ /\\ \\L\\ \\ \\ \\ \\ /\\ \\/\\ \\ /\\ \\L\\ \\   \n";
    cout << "   \\ \\____/\\ \\____/\\ \\__/.\\_\\\\ \\___,_\\ \\ \\_\\\\ \\_\\ \\_\\\\ \\____ \\              \n";
    cout << "    \\/___/  \\/___/  \\/__/\\/_/ \\/__,_ /  \\/_/ \\/_/\\/_/ \\/___L\\ \\                  \n";  
    cout << "                                                         /\\____/                            \n";
    cout << "                                                         \\_/__/                             \033[0m \n";
    cout << "\n---------------------------------------------------------------------------------------------------------------\n\n";
    getKey();
    return 0;
}

// Spielende

void SpielEnde()
{
clrScr();
cout << "                                                    ######## \n";                    
cout << "######################                              #::::::# \n";                    
cout << "#::::::::::::::::::::#                              #::::::# \n";                    
cout << "#::::::::::::::::::::#                              #::::::# \n";                    
cout << "##::::::#########::::#                              #:::::#  \n";                     
cout << "  #:::::#       ###### ###  ########        #########:::::#     #############     \n";    
cout << "  #:::::#             #:::##::::::::##    ##::::::::::::::#   ##::::::::::::##    \n";  
cout << "  #::::::##########   #::::::::::::::##  #::::::::::::::::#  #::::::####:::::##   \n";
cout << "  #:::::::::::::::#   ##:::::::::::::::##:::::::#####:::::# #::::::#     #:::::#  \n";
cout << "  #:::::::::::::::#     #:::::####:::::##::::::#    #:::::# #:::::::#####::::::#  \n";
cout << "  #::::::##########     #::::#    #::::##:::::#     #:::::# #:::::::::::::::::#   \n"; 
cout << "  #:::::#               #::::#    #::::##:::::#     #:::::# #::::::###########    \n";  
cout << "  #:::::#       ######  #::::#    #::::##:::::#     #:::::# #:::::::#             \n";           
cout << "##::::::########:::::#  #::::#    #::::##::::::#####::::::###::::::::#            \n";          
cout << "#::::::::::::::::::::#  #::::#    #::::# #:::::::::::::::::# #::::::::########    \n";  
cout << "#::::::::::::::::::::#  #::::#    #::::#  #:::::::::###::::#  ##:::::::::::::#    \n";  
cout << "######################  ######    ######   #########   #####    ##############    \n";
cout << "\n\nHaben Sie noch einen schoenen Tag :) \n";
getKey();
exit(0);  
}
// Funktion Hauptmenue

void Hauptmenue()
{
    bool Running = true;
    bool Korrekt = false; 

    while(Running)
    {
        clrScr();
        cout << "\033[94m __  __                                  __                                                                                            \n";                                                 
        cout << "/\\ \\/\\ \\                                /\\ \\__                                                                                           \n";                                                 
        cout << "\\ \\ \\_\\ \\      __      __  __   _____   \\ \\ ,_\\    ___ ___       __     ___     __  __     __                                          \n";   
        cout << " \\ \\  _  \\   /'__`\\   /\\ \\/\\ \\ /\\ '__`\\  \\ \\ \\/  /' __` __`\\   /'__`\\  /'_ `\\  /\\ \\/\\ \\  /'__`\\                           \n";
        cout << "  \\ \\ \\ \\ \\ /\\ \\L\\.\\_ \\ \\ \\_\\ \\ \\\\ \\L\\ \\  \\ \\ \\_\\ \\ \\/\\ \\/\\ \\ /\\  __/ /\\ \\/\\ \\ \\ \\ \\_\\ \\/\\  __/        \n";
        cout << "   \\ \\_\\ \\_\\\\ \\__/.\\_\\ \\ \\____/ \\ \\ ,__/   \\ \\__\\\\ \\_\\ \\_\\ \\_\\\\ \\____\\\\ \\_\\ \\_\\ \\ \\____/\\ \\____\\           \n";
        cout << "    \\/_/\\/_/ \\/__/\\/_/  \\/___/   \\ \\ \\/     \\/__/ \\/_/\\/_/\\/_/ \\/____/ \\/_/\\/_/  \\/___/  \\/____/                              \n";
        cout << "                                  \\ \\_\\                                                                                                     \n";                                                     
        cout << "                                   \\/_/                                                                                               \n \033[0m";                   
        cout << "\n---------------------------------------------------------------------------------------------------------------\n\n";
        cout << "\033[42m[ 1 ]\033[0m ------> \033[32mSpiel starten\n\n\033[0m";
        cout << "\033[107;30m[ 2 ]\033[0m ------> Spieleranzahl\n\n";
        cout << "\033[107;30m[ 3 ]\033[0m ------> Spielernamen\n\n";
        cout << "\033[107;30m[ 4 ]\033[0m ------> Spielstand laden\n\n";
        cout << "\033[41m[ 5 ]\033[0m ------> \033[31mSpiel beenden\n\n\033[0m";
        cout << "---------------------------------------------------------------------------------------------------------------\n\n";
        int Ergebnis = auswahl();
        switch (Ergebnis)
        {
        case 1:            
            cout << "Spieleranzahl : " << SpielerAnzahl;
            for (int i = 1; i < SpielerAnzahl + 1; i++)
            {
            cout << "\n\nSpielername Spieler "<< i << " :" << SpielerName[i];            
            }
            cout << "\nSind Sie mit den Eingaben zufrieden (J/N) ?";
            Korrekt = boolWert();
            if (Korrekt == true) {Running = false; break;} else {break;}
            break;

        case 2:
            cout << "\n\nBitte geben Sie die Anzahl der Spieler ein (1 - 4) :\n";
            cin >> SpielerAnzahl;
            if (SpielerAnzahl > 0 && SpielerAnzahl < 5) {cout << "\n\nDie Spieleranzahl wurde auf " << SpielerAnzahl << " geaendert.";}
            getKey();
            break;

        case 3:
            for (int i = 1; i < SpielerAnzahl + 1; i++)
            {
            cout << "\n\nBitte geben Sie Ihren Spielernamen ein Spieler " << i << " : \n";
            cin >> SpielerName[i];
            }
            break;

        case 4:
            
            LoadGame();
            break;
        
        case 5:
            
            cout << "\n\nSind Sie sicher, dass Sie das Spiel beenden moechten (J/N)?\n";
            Korrekt = boolWert();

            if (Korrekt == true) {SpielEnde();} else {break;}

        default:
            cout << "\033[31mUngueltige Eingabe!\033[0m";
            getKey();
            break;
        }
    }
}

// Regenerationszyklus

double RegenRound()
{
    double Genesung = 0;
    RegenOn[RundenManager]--;
    Genesung = round(Gesundheit[RundenManager] * 0.1) + Intelligenz[RundenManager];
    return Genesung;
}

// Charkter Uebersicht und Levelup

void Charakter()
{
    bool check = false;
    bool Running = true;
    int Vstaerke = 0;
    int Vintelligenz = 0;
    int Vgeschick = 0;
    int Vausdauer = 0;

    while (Running)
    {

        Gesundheit[RundenManager] = (Staerke[RundenManager] * 15) + (Ausdauer[RundenManager] * 5);
        Mana[RundenManager] = (Intelligenz[RundenManager] * 3) + (Ausdauer[RundenManager] * 2);
        TatsaechlicheGesundheit[RundenManager] = Gesundheit[RundenManager];
        TatsaechlichesMana[RundenManager] = Mana[RundenManager];
        Glueck[RundenManager] = (Ausdauer[RundenManager] * 0.01) + (Geschick[RundenManager] * 0.1);
        Tragekapazitaet[RundenManager] = (Staerke[RundenManager] * 15) + (Ausdauer[RundenManager] * 5);

        clrScr();
        cout << "\033[36m _____     __                                   __        __ \n";                     
        cout << "/\\  _ `\\  /\\ \\                                 /\\ \\      /\\ \\__ \n";                  
        cout << "\\ \\ \\/\\_\\ \\ \\ \\___       __      _ __     __   \\ \\ \\/'\\  \\ \\ ,_\\     __    _ __  \n";  
        cout << " \\ \\ \\/_/_ \\ \\  _ `\\   /'__`\\   /\\`'__\\ /'__`\\  \\ \\ , <   \\ \\ \\/   /'__`\\ /\\`'__\\ \n";
        cout << "  \\ \\ \\L\\ \\ \\ \\ \\ \\ \\ /\\ \\L\\.\\_ \\ \\ \\/ /\\ \\L\\.\\_ \\ \\ \\ \\`\\ \\ \\ \\_ /\\  __/ \\ \\ \\/ \n";  
        cout << "   \\ \\____/  \\ \\_\\ \\_\\\\ \\__/.\\_\\ \\ \\_\\ \\ \\__/.\\_\\ \\ \\_\\ \\_\\ \\ \\__\\\\ \\____\\ \\ \\_\\ \n";
        cout << "    \\/___/    \\/_/\\/_/ \\/__/\\/_/  \\/_/  \\/__/\\/_/  \\/_/\\/_/  \\/__/ \\/____/  \\/_/ \033[0m";
        cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n";
        cout << "\033[93m" << SpielerName[RundenManager] << "s Werte\033[0m\n\n";
        cout << "---------------------------------------------------------------------------------------------------------------\n\n";
        cout << "\033[95mLevel\033[0m -----------> \033[95m" << SpielerLevel[RundenManager] << "\033[0m";
        cout << "\033[31m\nStaerke\033[0m ---------> \033[31m" << Staerke[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (" << Vstaerke << ") (Staerke beeinflusst die Angriffsstaerke und das Leben.) \033[0m";}
            cout << "\033[34m\nIntelligenz\033[0m -----> \033[34m" << Intelligenz[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (" << Vintelligenz << ") (Intelligenz beeinflusst die Zauberintensitaet und das Mana.)\033[0m";}
            cout << "\033[33m\nAusdauer\033[0m --------> \033[33m" << Ausdauer[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (" << Vausdauer << ") (Ausdauer beeinflusst sowohl Leben, Mana als auch Glueck.)\033[0m";}
            cout << "\033[32m\nGeschick\033[0m --------> \033[32m" << Geschick[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (" << Vgeschick << ") (Geschick beeinflusst das Glueck.)\033[0m";}
            cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n";
            cout << "\033[91mLeben\033[0m -----------> \033[91m" << Gesundheit[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (Leben wird durch die Werte Staerke und Ausdauer beeinflusst.)\033[0m";}
            cout << "\033[94m\nMana\033[0m ------------> \033[94m" << Mana[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (Mana wird durch die Werte Intelligenz und Ausdauer beeinflusst.)\033[0m";}
            cout << "\033[92m\nGlueck\033[0m ----------> \033[92m" << Glueck[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (Glueck beeinflusst die Kritische Trefferquote, die Beute und gesonderte Optionen.)\033[0m";}
            cout << "\033[37m\nTragekapazitaet\033[0m -> \033[37m" << Tragekapazitaet[RundenManager] << "\033[0m";
        if (SkillPunkte > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0) { cout << " (Tragekapazitaet wird durch Staerke und Auddauer beeinflusst.)\033[0m";}
            cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n";
            cout << "\033[35mSkillpunkte\033[0m -----> \033[35m" << SkillPunkte[RundenManager] << "\033[0m\n";
            cout << "\n---------------------------------------------------------------------------------------------------------------\n\n";
                     
        if (SkillPunkte[RundenManager] > 0 || Vstaerke + Vintelligenz + Vausdauer + Vgeschick > 0)
        {
            cout << " \033[30;102m* 1 *\033[0m ------> \033[31mStaerke (+)\033[0m                              \033[41;97m* 5 *\033[0m ------> \033[31mStaerke (-)\033[0m \n\n";
            cout << " \033[30;102m* 2 *\033[0m ------> \033[34mIntelligenz (+)\033[0m                          \033[41;97m* 6 *\033[0m ------> \033[34mIntelligenz (-)\033[0m \n\n";
            cout << " \033[30;102m* 3 *\033[0m ------> \033[33mAusdauer (+)\033[0m                             \033[41;97m* 7 *\033[0m ------> \033[33mAusdauer (-)\033[0m \n\n";
            cout << " \033[30;102m* 4 *\033[0m ------> \033[32mGeschick (+)\033[0m                             \033[41;97m* 8 *\033[0m ------> \033[32mGeschick (-)\033[0m \n\n";
            cout << " \033[30;47m* 9 *\033[0m ------> Fertig\n";
    
            int Ergebnis = auswahl();
            switch (Ergebnis)
            {
            case 1:
                if (SkillPunkte[RundenManager] > 0) {Staerke[RundenManager]++; SkillPunkte[RundenManager]--; Vstaerke++; break;} else {cout << "\n\nZu wenig Skillpunkte!"; getKey();} break;
    
            case 2:
                if (SkillPunkte[RundenManager] > 0) {Intelligenz[RundenManager]++; SkillPunkte[RundenManager]--; Vintelligenz++; break;} else {cout << "\n\nZu wenig Skillpunkte!"; getKey();} break;

            case 3:
                if (SkillPunkte[RundenManager] > 0) {Ausdauer[RundenManager]++; SkillPunkte[RundenManager]--; Vausdauer++; break;} else {cout << "\n\nZu wenig Skillpunkte!"; getKey();} break;
    
            case 4:
                if (SkillPunkte[RundenManager] > 0) {Geschick[RundenManager]++; SkillPunkte[RundenManager]--; Vgeschick++; break;} else {cout << "\n\nZu wenig Skillpunkte!"; getKey();} break;

            case 5:
                if (Vstaerke > 0) {Vstaerke--; SkillPunkte[RundenManager]++; Staerke[RundenManager]--; break;} else {cout << "\n\n Es wurden noch keine Skillpunkte auf Staerke verteilt!"; getKey();} break;

            case 6:
                if (Vintelligenz > 0) {Vintelligenz--; SkillPunkte[RundenManager]++; Intelligenz[RundenManager]--; break;} else {cout << "\n\nEs wurden noch keine Skillpunkte auf Intelligenz verteilt!"; getKey();} break;

            case 7:
                if (Vausdauer > 0) {Vausdauer--; SkillPunkte[RundenManager]++; Ausdauer[RundenManager]--; break;} else {cout << "\n\nEs wurden noch keine Skillpunkte auf Ausdauer verteilt!"; getKey();} break;

            case 8:
                if (Vgeschick > 0) {Vgeschick--; SkillPunkte[RundenManager]++; Geschick[RundenManager]--; break;} else {cout << "\n\nEs wurden noch keine Skillpunkte auf Geschick verteilt!"; getKey();} break;
    
            case 9:
                cout << "\n\nSind Ihre Aenderungen korrekt (J/N) ?\n";
                check = boolWert();
                if (check == true){Running = false; Vstaerke = 0; Vintelligenz = 0; Vausdauer = 0; Vgeschick = 0;}
                break;

            default:
                cout << "Das geht nicht!";
                getKey();       
                break;
            }
        }
        else
        {
        getKey();
        Running = false;
        break;
        }   
    }
}

// Lebensanzeige

void ShowLife()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 22;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    cout << "--------------------------------------------------------------------------------------------------------------\n";
    cout << "| Leben |\033[41m                                                                                                    \033[0m|\n";
    cout << "--------------------------------------------------------------------------------------------------------------\n";
    cout << "| Mana  |\033[41m                                                                                                    \033[0m|\n";
    cout << "--------------------------------------------------------------------------------------------------------------\n";
        
    coord.X = 9;
    coord.Y = 23;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
    int Laenge = 100 * (TatsaechlicheGesundheit[RundenManager] / Gesundheit[RundenManager]);
    for (int i = 0; i < Laenge; i++)
    {
    cout << "\033[42m ";
    }
    coord.X = 9;
    coord.Y = 25;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    Laenge = 100 * (TatsaechlichesMana[RundenManager] / Mana[RundenManager]);
    for (int x = 0; x < Laenge; x++)
    {
    cout << "\033[104m ";
    }
    cout << "\n\n\n\033[0m";
    return;
}

// Schalter Farbauswahl

void SchalterFarbe(int Color)
{
    if (Color == 1) {cout << "\033[30;102m";} else if (Color == 2) {cout << "\033[30;103m";} else if (Color == 3) {cout << "\033[41m";}
    return;
}

// Farbauswahl

void Farbe (int Color)
{
    if (Color == 1) {cout << "\033[92m";} else if (Color == 2) {cout << "\033[93m";} else if (Color == 3) {cout << "\033[31m";}
    return;
}

// Tod

void Tod()
{
clrScr();

cout << "              ####                     \n";
cout << "            ########                   --------------------------------------------------------------\n";
cout << "           ##########                  ---              Leider wurden Sie getoetet!               ---\n";
cout << "           ##########                  --------------------------------------------------------------\n";
cout << "             ######                    ---   Oger, Goblins, Orks, Imps und Gewürm fallen ueber    ---\n";
cout << "         ooo ###### ooo                --- Ihren kalten Leichnam her und was noch von Ihnen uebrig---\n";
cout << "           o ###### o                  ---   geblieben ist wird von Ihren Gegnern verwurstet und  ---\n";
cout << "    ####  oo ###### oo  ####           --- abgehangen, um es auch später noch genießen zu koennen!---\n";
cout << "   #####     ######     #####          ---  Wenigstens haben Sie sich als gute Wurst einen Namen  ---\n";
cout << " ##############################        ---                        gemacht!                        ---\n"; 
cout << " ##############################        --------------------------------------------------------------\n";
cout << "   ##########################          \n";
cout << "    ####     ######     ####           --------------------------------------------------------------\n";
cout << "             ######                    ---                        Statistik                       ---\n";
cout << "      ooooo  ######  ooooo             --------------------------------------------------------------\n";
cout << "         oo  ######  oo                --- Spieler Level ------->                                 ---\n";
cout << "          o  ######  o                 --- Besuchte Raeume ----->                                 ---\n";
cout << "          o  ######  o                 --- Erbeutetes Gold ----->                                 ---\n";
cout << "        ooo  ######  ooo               --- Gecraftets Items ---->                                 ---\n";
cout << "             ######                    --- Getoetete Monster --->                                 ---\n";
cout << "             ######                    --- Getoetete Bosse ----->                                 ---\n";
cout << "           ##########                  --------------------------------------------------------------\n";
cout << "           ##########                  ---       Moechten Sie einen Spielstand laden (J/N)?       ---\n";
cout << "            ########                   --------------------------------------------------------------\n";
cout << "              ####                     \n";

COORD coord;
coord.X = 64;
coord.Y = 15;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << SpielerLevel;
coord.Y = 16;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << Raeume;
coord.Y = 17;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << Gold;
coord.Y = 18;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << Crafted;
coord.Y = 19;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << Monster;
coord.Y = 20;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << Bosse;

bool Check = boolWert();
if (Check == true)
{
    LoadGame();
}
if (Check == false)
{
    SpielEnde();
}
}

// Stufenaufstieg

void StufenAufstieg()
{
    clrScr();
    
    SpielerLevel[RundenManager]++; 
    SkillPunkte[RundenManager] = SkillPunkte[RundenManager] + 5;
    LevelExp[RundenManager] = round(LevelExp[RundenManager] * 1.2);
    
    cout << "\033[36m __                                 ___          __  __               __                            \n";
    cout << "/\\ \\                               /\\_ \\        /\\ \\/\\ \\             /\\ \\                         \n";
    cout << "\\ \\ \\         __    __  __     __  \\//\\ \\       \\ \\ \\ \\ \\    _____   \\ \\ \\                    \n";
    cout << " \\ \\ \\  __  /'__`\\ /\\ \\/\\ \\  /'__`\\  \\ \\ \\       \\ \\ \\ \\ \\  /\\ '__`\\  \\ \\ \\           \n";
    cout << "  \\ \\ \\L\\ \\/\\  __/ \\ \\ \\_/ |/\\  __/   \\_\\ \\_      \\ \\ \\_\\ \\ \\ \\ \\L\\ \\  \\ \\_\\      \n";
    cout << "   \\ \\____/\\ \\____\\ \\ \\___/ \\ \\____\\  /\\____\\      \\ \\_____\\ \\ \\ ,__/   \\/\\_\\           \n";
    cout << "    \\/___/  \\/____/  \\/__/   \\/____/  \\/____/       \\/_____/  \\ \\ \\/     \\/_/                     \n";
    cout << "                                                               \\ \\_\\                                     \n";
    cout << "                                                                \\/_/                               \033[0m \n";
    cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n\n";
    cout << SpielerName[RundenManager] << " ist jetzt Level : " << SpielerLevel[RundenManager];
    cout << "\n\nSkillpunkte sind um 5 gestiegen!";
    
    getKey();
    return;
}

// Funktion Exp Up

void ExpUp()
{
    int Laenge = 0;
    bool Running = true;
        
    while(Running)
    {
    
    clrScr();
    cout << "\033[36m ____     __   __    ____           __  __                                 \n";             
    cout << "/\\  _`\\  /\\ \\ /\\ \\  /\\  _`\\        /\\ \\/\\ \\                            \n";           
    cout << "\\ \\ \\__  \\ `\\`\\/'/' \\ \\ \\L\\ \\      \\ \\ \\ \\ \\    _____              \n";  
    cout << " \\ \\  _\\  `\\/ > <    \\ \\ ,__/       \\ \\ \\ \\ \\  /\\ '__`\\               \n";
    cout << "  \\ \\ \\____ \\/'/\\`\\   \\ \\ \\/         \\ \\ \\_\\ \\ \\ \\ \\L\\ \\        \n";
    cout << "   \\ \\____/ /\\_\\  \\_\\  \\ \\_\\          \\ \\_____\\ \\ \\ ,__/             \n";
    cout << "    \\/___/  \\/_/ \\/_/   \\/_/           \\/_____/  \\ \\ \\/                    \n";
    cout << "                                                  \\ \\_\\                         \n"; 
    cout << "                                                   \\/_/                    \n\033[0m";
    cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
    if (Exp[RundenManager] > LevelExp[RundenManager]) {cout << "\n Expierience : "<< Exp[RundenManager] - LevelExp[RundenManager] << "/" << round(LevelExp[RundenManager] * 1.2) << "\n\n";}
    else
    {cout << "\n Expierience : "<< Exp[RundenManager] << "/" << LevelExp[RundenManager] << "\n\n";}
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "| Exp |\033[41m                                                                                                    \033[0m|\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";

    COORD coord;
    coord.X = 7;
    coord.Y = 16;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
        if (Exp[RundenManager] > LevelExp[RundenManager])
        {
        double px = LevelExp[RundenManager];
        Laenge = 100 * (px / LevelExp[RundenManager]);
        for (int i = 0; i < Laenge; i++)
            {
            cout << "\033[103m ";
            Sleep(10);
            cout << "\033[0m";
            }
            getKey();
            Exp[RundenManager] = Exp[RundenManager] - LevelExp[RundenManager];
            StufenAufstieg();
            break;
        }
        else
        {
            Laenge = 100 * (Exp[RundenManager] / LevelExp[RundenManager]);
            for (int i = 0; i < Laenge; i++)
            {
            cout << "\033[103m ";
            Sleep(10);
            cout << "\033[0m";
            }
            Running = false;
            break;
        }
    }
    getKey();
    return;
}

// Falle erstellen

void Falle (int Gefahr)
{
    if (Gefahr == 1) {Trap[RundenManager] = 0; return;} 
    
    if (Gefahr == 2) {int Fallus = zufall(1,100); if (Fallus < 38 && Fallus > 63) {Trap[RundenManager] = 1; return;} else {Trap[RundenManager] = 0; return;}}

    if (Gefahr == 3) {int Fallus = zufall(1,100); if (Fallus > 0 & Fallus < 26 || Fallus > 50 & Fallus < 76) {Trap[RundenManager] = 1; return;} else {return;}}
}

// Falle auslösen

void TrapTap()
{
    cout << "\n\nSie sind in eine Falle getappt!\n";
    
    double DMG = Gesundheit[RundenManager] / 25;
    double Schaden = round(DMG);
    DMG = 0; DMG = zufall(10, Schaden);
    TatsaechlicheGesundheit[RundenManager] = TatsaechlicheGesundheit[RundenManager] - DMG;
    Trap[RundenManager] = Trap[RundenManager] - 1;

    cout << "\nSie erleiden " << DMG << " Schaden!";
        
    if (TatsaechlicheGesundheit[RundenManager] < 1)
    {
        getKey();
        Tod();
    }
    return;
}

// Gegner Build

void GegnerBuild(int Gegner)
{
    return;
}

// Gegner Bilder (Imp)

void ImpBild()
{
    cout << "\033[0m_______________________________________________________\n";
    cout << "|_____|_____|_____|_____|_IMP_|_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|_____|\\___/|_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|__(.) (.)__|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|_____| . . |_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|__|-----|__|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|_____|\\___/|_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|____| |____|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|___/         \\___|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____| /       \\ |_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|__| ||     || |__|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|_|_|   |_|_|_____|_____|_____|__|\n";
    cout << "|_____|_____|_____|_____|  |  |_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|\033[0m\n";    
    return;
}


// Funktion Kampf - Schriftzug

void Kampf()
{
    clrScr();
    cout << "\033[36m __  __                                        ___          \n";  
    cout << "/\\ \\/\\ \\                                     /'___\\            \n"; 
    cout << "\\ \\ \\/'/'      __       ___ ___     _____   /\\ \\__/            \n";
    cout << " \\ \\ , <     /'__`\\   /' __` __`\\  /\\ '__`\\ \\ \\ ,__\\       \n";
    cout << "  \\ \\ \\`\\  /\\ \\L\\.\\_ /\\ \\/\\ \\/\\ \\ \\ \\ \\L\\ \\ \\ \\ \\_/       \n";
    cout << "   \\ \\_\\ \\_\\ \\__/.\\_\\ \\_\\ \\_\\ \\_\\ \\ \\ ,__/  \\ \\_\\            \n";
    cout << "    \\/_/\\/_/ \\/__/\\/_/ \\/_/\\/_/\\/_/  \\ \\ \\/    \\/_/      \n";
    cout << "                                      \\ \\_\\                      \n";
    cout << "                                       \\/_/                \033[0m \n";
    cout << "\n---------------------------------------------------------------------------------------------------------------\n";
    return;
}

// Funktion Kampfaufbau

void Fight(int Gegner)
{
    GegnerBuild(Gegner);    
    Kampf();
    return;
}

// Funktion Finden

void Find()
{
    double FindGold = 0;
    double Erfahrung = 0;
    int Heal = 0;
    int Manat = 0;
    int Regent = 0;
    int Metall = 0;
    int Chance = zufall(1,100);
    int xp = 0;
    int px = 0;

    cout << "\n";

    if (Chance > 0 & Chance < 26 || Chance > 49 & Chance < 76) 
    {
        FindGold = zufall((SpielerLevel[RundenManager] * 5), (SpielerLevel[RundenManager] * 25));
        Erfahrung = FindGold * 0.25;
        xp = round(Erfahrung);
        px = px + xp;
        cout << "\n\033[93mGold -------------------> " << FindGold << "\033[0m (" << xp << " EXP)";
        Gold[RundenManager] = Gold[RundenManager] + FindGold;

    }
    if (Schluessel[RundenManager] < 1)
    {
        Chance = 0; Chance = zufall(1,100);
        if (Chance > 0 & Chance < 26 || Chance > 49 & Chance < 76)
        {
            xp = 0;
            Erfahrung = 0;
            Erfahrung = (50 * (SpielerLevel[RundenManager] * 0.5));
            xp = round(Erfahrung);
            px = px + xp;
            cout << "\nSchluessel -------------> 1 (" << xp << " EXP)";
            Schluessel[RundenManager] = Schluessel[RundenManager] + 1;
        } 
    }
    Chance = 0; Chance = zufall(1,100);
    if (Chance > 0 & Chance < 26 || Chance < 49 & Chance < 76)
    {
        xp = 0;
        Erfahrung = 0;
        Heal = zufall(1, 3);
        Erfahrung = (Heal * 10) * (SpielerLevel[RundenManager] * 0.25);
        xp = round(Erfahrung);
        px = px + xp;
        cout << "\n\033[31mHeiltraenke ------------> " << Heal << "\033[0m (" << xp << " EXP)";
        Heiltrank[RundenManager] = Heiltrank[RundenManager] + Heal;
    }
    Chance = 0; Chance = zufall(1,100);
    if (Chance > 0 & Chance < 26 || Chance < 49 & Chance < 76)
    {
        xp = 0;
        Erfahrung = 0;
        Manat = zufall(1, 3);
        Erfahrung = (Manat * 15) * (SpielerLevel[RundenManager] * 0.25);
        xp = round(Erfahrung);
        px = px + xp;
        cout << "\n\033[34mManatraenke ------------> " << Manat << "\033[0m (" << xp << " EXP)";
        Manatrank[RundenManager] = Manatrank[RundenManager] + Manat;
    }
    Chance = 0; Chance = zufall(1,100);
    if (Chance > 0 & Chance < 26 || Chance < 49 & Chance < 76)
    {
        xp = 0;
        Erfahrung = 0;
        Regent = zufall(1, 3);
        Erfahrung = (Regent * 20) * (SpielerLevel[RundenManager] * 0.25);
        xp = round(Erfahrung);
        px = px + xp;
        cout << "\n\033[35mRegenerationstraenke ----> " << Manat << "\033[0m (" << xp << " EXP)";
        Manatrank[RundenManager] = Manatrank[RundenManager] + Manat;
    }
    Chance = 0; Chance = zufall(1,100);
    if (Chance > 0 & Chance < 26 || Chance < 49 & Chance < 76)
    {
        xp = 0;
        Erfahrung = 0;
        Metall = zufall(1, 5);
        Erfahrung = (Metall * 5) * (SpielerLevel[RundenManager] * 0.25);
        xp = round(Erfahrung);
        px = px + xp;
        cout << "\nAltmetall ----------> " << Metall << " (" << xp << " EXP)";
        Altmetall[RundenManager] = Altmetall[RundenManager] + Metall;
        Tragekapazitaet[RundenManager] = Tragekapazitaet[RundenManager] + (Metall * 0.1);
    }
    if (px < 1)
    {
        cout << "\n\nNichts!";
        getKey();
        return;
    }
    cout << "\nGesamt EXP ---------> " << px << " (EXP)";
    Exp[RundenManager] = Exp[RundenManager] + px;
    getKey();
    ExpUp();
    return;

}

// Funktion Umgebung absuchen

void Suche(int Gefahr)
{
    clrScr();
    Farbe(Gefahr);

    cout << "Sie begeben sich auf die Suche";
    for (int i = 0; i < 5; i++) {Sleep(100); cout << ".";}
    cout << "\nUnd finden:";
    if (Trap[RundenManager] > 0)
    {
        if (Gefahr == 2)
        {
            int Trapper = zufall(1,100);
            if(Trapper > 37 & Trapper < 64)
            {
                cout << "\nEine Falle!\n";
                TrapTap();
            }
        }
        if (Gefahr == 3)
        {
            int Trapper = zufall(1,100);
            if (Trapper > 25 & Trapper < 75)
            {
                cout << "\nEine Falle!\n";
                TrapTap();
            }
        } 
    }
    cout << "\033[0m";
    Find();
    return;

}

// Falle suchen

void FalleSuchen(int Gefahr)
{
    Farbe(Gefahr);

    if (Gefahr == 1)
    {
        cout << "\n\nDa die Gegend sicher ist, gibt es auch keine Fallen....\n";
        getKey();
        return;
    }
    if (Gefahr > 1 && Trap[RundenManager] < 1)
    {
        cout << "\n\nEs gibt keine Fallen....\n";
        getKey();
        return;
    }
    else if (Gefahr == 2)
    {
        int Fallus = zufall(1,100);
        if (Fallus < 16 && Fallus > 85)
        {
            int xp = 100 + (SpielerLevel[RundenManager] * 1.2);
            cout << "\n\nSie heben eine Falle gefunden und sie entschaerft. " << xp << " EXP.";
            Exp[RundenManager] = Exp[RundenManager] + xp;
            getKey();
            ExpUp();
            Trap[RundenManager] = 0;
            return;
        }
        else
        {
            cout << "\n\nSie konnten leider nichts finden, was nicht bedeutet, dass es keine Fallen gibt!\n";
            getKey();
            return;
        }
    }
    else if (Gefahr == 3)
    {
        int Fallus = zufall(1, 100);
        if (Fallus > 0 & Fallus < 26 || Fallus > 50 & Fallus < 76)
        {
            int xp = 100 + (SpielerLevel[RundenManager] * 1.2);
            cout << "\n\nSie haben eine Falle gefunden und sie entschaerft. " << xp << " EXP.";
            Exp[RundenManager] = Exp[RundenManager] + xp;
            getKey();
            ExpUp();
            Trap[RundenManager] = 0;
            return;
        }
        else
        {
            cout << "\n\nSie konnten leider nichts finden, was nicht bedeutet, dass es keine Fallen gibt!\n";
            getKey();
            return;
        }
    }
}

// Funktion Ausruhen

void Ausruhen(int Gefahr)
{
    clrScr();
    Farbe(Gefahr);

    cout << "Sie versuchen sich auszuruhen";
    for (int i = 0; i < 5; i++) {Sleep(400); cout << ".";}
    
    if (Trap[RundenManager] > 0)
    {
        if (Gefahr == 2)
        {
            int Trapper = zufall(1,100);
            if(Trapper > 37 & Trapper < 64)
            {
                cout << "\nAllerdings treten Sie erstmal in eine Falle!\n";
                TrapTap();
            }
        }
        if (Gefahr == 3)
        {
            int Trapper = zufall(1,100);
            if (Trapper > 25 & Trapper < 75)
            {
                cout << "\nAllerdings treten Sie erstmal in eine Falle!\n";
                TrapTap();
            }
        } 
    }
    cout << "\n\nSie regenerieren:\n";
    double reg01 = round(Gesundheit[RundenManager] * 0.25); double reg02 = (Gesundheit[RundenManager] * 0.75);
    double HealthReg = zufall(reg01, reg02);
    reg01 = 0; reg01 = round(Mana[RundenManager] * 0.25); reg02 = 0; reg02 = round(Mana[RundenManager] * 0.75);
    double ManaReg = zufall(reg01, reg02);
    cout << "\nLeben ---> " << HealthReg;
    cout << "\nMana ----> " << ManaReg;
    TatsaechlicheGesundheit[RundenManager] = TatsaechlicheGesundheit[RundenManager] + HealthReg;
    if (TatsaechlicheGesundheit[RundenManager] > Gesundheit[RundenManager]) {TatsaechlicheGesundheit[RundenManager] = Gesundheit[RundenManager];}
    ShowLife();
    getKey();
    return;
}

// Schriftzug Inventar

void InventarText()
{
    clrScr();
    cout << "\033[36m ______                                       __                                            \n";   
    cout << "/\\__  _\\                                     /\\ \\__                                             \n";   
    cout << "\\/_/\\ \\/      ___     __  __     __     ___  \\ \\ ,_\\     __      _ __                         \n";  
    cout << "   \\ \\ \\    /' _ `\\  /\\ \\/\\ \\  /'__`\\ /' _ `\\ \\ \\ \\/   /'__`\\   /\\`'__\\             \n";
    cout << "    \\_\\ \\__ /\\ \\/\\ \\ \\ \\ \\_/ |/\\  __/ /\\ \\/\\ \\ \\ \\ \\_ /\\ \\L\\.\\_ \\ \\ \\/     \n";
    cout << "    /\\_____\\\\ \\_\\ \\_\\ \\ \\___/ \\ \\____\\ \\_\\ \\_\\ \\ \\__\\ \\__/.\\_\\ \\ \\_\\       \n";
    cout << "    \\/_____/ \\/_/\\/_/  \\/__/   \\/____/ \\/_/\\/_/  \\/__/ \\/__/\\/_/  \\/_/           \033[0m \n";
    return;
}

// Heiltraenke

void Heal()
{
    if (Heiltrank[RundenManager] < 1) {cout << "\nSie haben leider keine Heiltraenke mehr!\n"; getKey(); return;}
            else if (TatsaechlicheGesundheit[RundenManager] == Gesundheit[RundenManager]) {cout << "\nSie haben bereits volle Gesundheit!\n"; getKey(); return;}
            else 
            {
                Heiltrank[RundenManager] = Heiltrank[RundenManager] - 1;
                TatsaechlicheGesundheit[RundenManager] = TatsaechlicheGesundheit[RundenManager] + round(Gesundheit[RundenManager] * 0.25); 
                if (TatsaechlicheGesundheit[RundenManager] > Gesundheit[RundenManager]) {TatsaechlicheGesundheit[RundenManager] = Gesundheit[RundenManager];}
                cout << "\nSie haben einen Heiltrank verbraucht.\n";
                cout << "Heilungsfaktor : " << round(Gesundheit[RundenManager] * 0.25) << " HP.\n";
                getKey();
                return;
            }
}

// Manatraenke

void Man()
{
    if (Manatrank[RundenManager] < 1) {cout << "\nSie haben leider keine Manatraenke mehr!\n"; getKey(); return;}
            else if (TatsaechlichesMana[RundenManager] == Mana[RundenManager]) {cout << "\nSie haben bereits volles Mana!\n"; getKey(); return;}
            else 
            {
                Manatrank[RundenManager] = Manatrank[RundenManager] - 1;
                TatsaechlichesMana[RundenManager] = TatsaechlichesMana[RundenManager] + round(Mana[RundenManager] * 0.25); 
                if (TatsaechlichesMana[RundenManager] > Mana[RundenManager]) {TatsaechlichesMana[RundenManager] = Mana[RundenManager];}
                cout << "\nSie haben einen Manatrank verbraucht.\n";
                cout << "Regenerationssfaktor : " << round(Mana[RundenManager] * 0.25) << " HP.\n";
                getKey();
                return;
            }
}

// Regenerationstraenke

void Regen()
{
    if (RegenTrank[RundenManager] < 1) {cout << "\nSie haben leider keine Regenerationstraenke mehr!\n"; getKey(); return;}
            else if (TatsaechlicheGesundheit[RundenManager] == Gesundheit[RundenManager] && TatsaechlichesMana[RundenManager] == Mana[RundenManager]) {cout << "\nSie haben bereits volle Gesundheit und Energie!\n"; getKey(); return;}
            else 
            {
                RegenTrank[RundenManager] = RegenTrank[RundenManager] - 1;
                TatsaechlicheGesundheit[RundenManager] = TatsaechlicheGesundheit[RundenManager] + round(Gesundheit[RundenManager] * 0.15);
                TatsaechlichesMana[RundenManager] = TatsaechlichesMana[RundenManager] + round(Mana[RundenManager] * 0.15); 
                if (TatsaechlicheGesundheit[RundenManager] > Gesundheit[RundenManager]) {TatsaechlicheGesundheit[RundenManager] = Gesundheit[RundenManager];}
                if (TatsaechlichesMana[RundenManager] > Mana[RundenManager]) {TatsaechlichesMana[RundenManager] = Mana[RundenManager];}
                cout << "\nSie haben einen Regenerationstrank verbraucht.\n";
                cout << "Regenerationsfaktor : " << round(Gesundheit[RundenManager] * 0.15) << " HP / " << round(Mana[RundenManager] * 0.15) << "MP.";
                getKey();
                return;
            }
}

// Inventar Ruestung

void Ruestungen()
{
    bool Running = true;

    while (Running)
    {
        InventarText();
        cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
        cout << "\n" << SpielerName[RundenManager] << "     Gold: " << Gold[RundenManager] << "     Altmetall: " << Altmetall[RundenManager] << "     Exp: " << Exp[RundenManager] << "/" << LevelExp[RundenManager];
        cout << "\n---------------------------------------------------------------------------------------------------------------\n";
        cout << "\n\033[31mIhre Ruestungen : \033[0m";
        cout << "\n---------------------------------------------------------------------------------------------------------------\n";
        ShowLife();

    }
    return;
}

// Inventar Waffen

void Waffen()
{
    bool Running = true;

    while (Running)
    {
        InventarText();
        cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
        cout << "\n" << SpielerName[RundenManager] << "     Gold: " << Gold[RundenManager] << "     Altmetall: " << Altmetall[RundenManager] << "     Exp: " << Exp[RundenManager] << "/" << LevelExp[RundenManager];
        cout << "\n---------------------------------------------------------------------------------------------------------------\n";
        cout << "\n\033[31mIhre Waffen : \033[0m";
        cout << "\n---------------------------------------------------------------------------------------------------------------\n";
        ShowLife();

    }
    return;
}

// Inventar Heiltraenke/Manatraenke

void InvPoition(int Poition)
{
    bool Running = true;

    while (Running)
    {
    InventarText();
    cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
    cout << "\n" << SpielerName[RundenManager] << "     Gold: " << Gold[RundenManager] << "     Altmetall: " << Altmetall[RundenManager] << "     Exp: " << Exp[RundenManager] << "/" << LevelExp[RundenManager];
    cout << "\n---------------------------------------------------------------------------------------------------------------\n";
    cout << "\n\033[31mIhre Heiltraenke : \033[0m" << Heiltrank[RundenManager];
    cout << "\n---------------------------------------------------------------------------------------------------------------\n";
    if (Poition == 1) {cout << "\n\n[ 1 ] -------> Heiltrank verwenden                 [ 2 ] ------> Zurueck";}
    else if (Poition == 2) {cout << "\n\n[ 1 ] -------> Manatrank verwenden                 [ 2 ] ------> Zurueck";}
    else if (Poition == 3) {cout << "\n\n[ 1 ] -------> Regenerationstrank verwenden        [ 2 ] ------> Zurueck";}
    ShowLife();
    int Ergebnis = auswahl();
    switch(Ergebnis)
    {
        case 1:
            if (Poition == 1) {Heal(); break;} else if (Poition == 2) {Man(); break;} else if (Poition == 3) {Regen(); break;}
            break;

        case 2:
            Running = false;
            break;
        
        default :
            cout << "\nDas geht nicht!\n";
            getKey();
            break;
    }

    }
    return;
}

// Inventar

void Inventar()
{
    bool Running = true;

    while(Running)
    {
        InventarText();
        cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
        cout << "\n" << SpielerName[RundenManager] << "     Gold: " << Gold[RundenManager] << "     Altmetall: " << Altmetall[RundenManager] << "     Exp: " << Exp[RundenManager] << "/" << LevelExp[RundenManager];
        cout << "\n---------------------------------------------------------------------------------------------------------------\n";
        cout << "\n\n\033[41m[ 1 ]\033[0m ------> \033[31mHeiltraenke\033[0m                   \033[43;30m[ 4 ]\033[0m ------> \033[33mRuestung\n\n\033[0m";
        cout << "\033[44m[ 2 ]\033[0m ------> \033[34mManatraenke\033[0m                   \033[103;30m[ 5 ]\033[0m ------> \033[93mWaffen\n\n\033[0m";
        cout << "\033[45m[ 3 ]\033[0m ------> \033[35mRegenerationstraenke\033[0m          \033[107;30m[ 6 ]\033[0m ------> Fertig\n\n\033[0m";
        int Ergebnis = auswahl();
        switch(Ergebnis)
        {
            case 1:
                InvPoition(1);
                break;
            
            case 2:
                InvPoition(2);
                break;
            
            case 3: 
                InvPoition(3);
                break;

            case 4:
                Ruestungen();
                break;

            case 5:
                Waffen();
                break;

            case 6:
                Running = false;
                break;
            
            default :
                cout << "\nDas geht nicht!\n";
                getKey();
                break;
        }
    }
    return;
}

// Magie Text

void MageText()
{
    clrScr();
    cout << "\033[36m /'\\_/`\\                      __                           \n";           
    cout << "/\\      \\      __        __  /\\_\\      __                        \n";
    cout << "\\ \\ \\__\\ \\   /'__`\\    /'_ `\\\\/\\ \\   /'__`\\               \n";
    cout << " \\ \\ \\_/\\ \\ /\\ \\L\\.\\_ /\\ \\L\\ \\\\ \\ \\ /\\  __/         \n";
    cout << "  \\ \\_\\\\ \\_\\\\ \\__/.\\_\\\\ \\____ \\\\ \\_\\ \\____\\          \n";
    cout << "   \\/_/ \\/_/ \\/__/\\/_/ \\/___L\\ \\/_/ \\/____/            \n";
    cout << "                         /\\____/                              \n";
    cout << "                         \\_/__/                              \033[0m \n";
    return;
}

// Magie Menue

void Magie()
{
    bool Running = true;
    double Heal = 0;
    COORD coord;
    
    while(Running)
    {
    MageText();
    cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
    cout << "\nIhre derzeitige Intelligenz : " << Intelligenz[RundenManager]; 
    cout << "\n\n---------------------------------------------------------------------------------------------------------------\n";
    if (Intelligenz[RundenManager] > 4) {cout << "\033[41m[ 1 ]\033[0m ------> \033[31mFeuerball\033[36m (10 Mana) \n\n";}
    if (Intelligenz[RundenManager] > 9) {cout << "\033[42m[ 2 ]\033[0m ------> \033[32mHeilung\033[36m (10 Mana) \033[0m \n\n";}
    if (Intelligenz[RundenManager] > 14) {cout << "\033[44m[ 3 ]\033[0m ------> \033[34mEiszapfen\033[36m (15 Mana) \n\n";}
    if (Intelligenz[RundenManager] > 19) {coord.X = 40; coord.Y = 15; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "\033[102m[ 4 ]\033[0m ------> \033[92mRegeneration\033[36m (20 Mana) \033[0m";}
    if (Intelligenz[RundenManager] > 24) {coord.X = 40; coord.Y = 17; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "\033[101m[ 5 ]\033[0m ------> \033[91mFeueraura\033[36m (20 Mana) \033[0m";}
    if (Intelligenz[RundenManager] > 29) {coord.X = 40; coord.Y = 19; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "\033[103m[ 6 ]\033[0m ------> \033[93mGoldsog\033[36m (25 Mana) \033[0m";}
    coord.X = 0; coord.Y = 21; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); cout << "\033[107;30m[ 7 ]\033[0m ------> Zurueck";
    ShowLife();
    int Ergebnis = auswahl();
    switch(Ergebnis)
    {
        case 1:
            if (Intelligenz[RundenManager] > 4) {cout << "\n\nIhr durchschnittlicher Feuerball - Schaden : " << Intelligenz[RundenManager] * 5 << " DMG\n"; getKey(); break;}

        case 2:
            if (Intelligenz[RundenManager] > 9 && TatsaechlichesMana[RundenManager] > 10) 
            {
                Heal = round(Intelligenz[RundenManager] * (5 + (SpielerLevel[RundenManager] * 0.20))); 
                cout << "\n\nSie heilen sich um " << Heal << " HP.\n";
                TatsaechlicheGesundheit[RundenManager] = TatsaechlicheGesundheit[RundenManager] + Heal;
                TatsaechlichesMana[RundenManager] = TatsaechlichesMana[RundenManager] - 10;
                if (TatsaechlicheGesundheit[RundenManager] > Gesundheit[RundenManager]) {TatsaechlicheGesundheit[RundenManager] = Gesundheit[RundenManager];}
                getKey();
                break;
            }
        
        case 3:
            if (Intelligenz[RundenManager] > 14) 
            {
                cout << "\n\nIhr durchschnittlicher Eiszapfen - Schaden : " << Intelligenz[RundenManager] * 6 << " DMG.\n";
                
            }

        case 4:
            if (Intelligenz[RundenManager] > 19)
            {
                if (TatsaechlichesMana[RundenManager] > 19)
                {
                    TatsaechlichesMana[RundenManager] = TatsaechlichesMana[RundenManager] - 20;
                    RegenOn[RundenManager] = RegenOn[RundenManager] + 5;
                    double Genesung = RegenRound(); 
                    cout << "\n\nSie sprechen Regeneration aus und heilen direkt " << Genesung << " Hitpoints.\nNoch " << RegenOn[RundenManager] << " Heilungen uebrig.";
                    getKey();
                    break;
                }
                cout << "\n\nSie haben nicht genuegend Mana!\n";
                getKey();
                break;
            }
        
        case 5:
            if (Intelligenz[RundenManager] > 24)
            {
                if (TatsaechlichesMana[RundenManager] > 19)
                {
                    TatsaechlichesMana[RundenManager] = TatsaechlichesMana[RundenManager] - 20;
                    Faura[RundenManager] = Faura[RundenManager] + 5;
                    cout << "\n\nSie zaubern eine Feuer Aura auf sich.\n";
                    cout << "Verbleibende Auren: " << Faura[RundenManager];
                    getKey();
                    break; 
                }
                cout << "\n\nSie haben nicht genug Mana!\n";
                getKey();
                break;
            }
        
        case 6:
            if (Intelligenz[RundenManager] > 29)
            {
                if (TatsaechlichesMana[RundenManager] > 24)
                {
                    TatsaechlichesMana[RundenManager] = TatsaechlichesMana[RundenManager] - 25;
                    double Goldie = round(Intelligenz[RundenManager] * 7.5);
                    cout << "\n\nSie zaubern Goldsog.\nSie erhalten " << Goldie << " Gold.";
                    Gold[RundenManager] = Gold[RundenManager] + Goldie;
                    getKey();
                    break;
                }
                cout << "\n\nSie haben nicht genug Mana!\n";
                getKey();
                break;
            }
        
        case 7:
            Running = false;
            break;

        default: 
            cout << "\nDas ist nicht moeglich.\n";
            getKey();
            break;
    }
    }
    return;
}

// Speichern

void SpielStand(int Choice)
{
    bool Running = true;
    string Spielstand[3];
    Spielstand[1] = "Spielstand 01.txt";
    Spielstand[2] = "Spielstand 02.txt";
    Spielstand[3] = "Spielstand 03.txt";

    ofstream datei(Spielstand[Choice].c_str());
                    if (datei.is_open()) 
                    {
                        datei << "LevelUp: ----- " << LevelUp[0] << " " << LevelUp[1] << " " << LevelUp[2] << " " << LevelUp[3] << " " << LevelUp[4]  << endl;
                        datei << "Rundenmanager: " << RundenManager << endl;
                        datei << "SpielerAnzahl: " << SpielerAnzahl << endl;
                        datei << "SkillPunkte: - " << SkillPunkte[0] << " " << SkillPunkte[1] << " " << SkillPunkte[2] << " " << SkillPunkte[3] << " " << SkillPunkte[4]  << endl;
                        datei << "SpielerLevel:- " << SpielerLevel[0] << " " << SpielerLevel[1] << " " << SpielerLevel[2] << " " << SpielerLevel[3] << " " << SpielerLevel[4] << endl;
                        datei << "Schluessel: -- " << Schluessel[0] << " " << Schluessel[1] << " " << Schluessel[2] << " " << Schluessel[3] << " " << Schluessel[4] << endl;
                        datei << "Trap: -------- " << Trap[0] << " " << Trap[1] << " " << Trap[2] << " " << Trap[3] << " " << Trap[4] << endl;
                        datei << "Altmetall: --- " << Altmetall[0] << " " << Altmetall[1] << " " << Altmetall[2] << " " << Altmetall[3] << " " << Altmetall[4] << endl;
                        datei << "Heiltrank: --- " << Heiltrank[0] << " " << Heiltrank[1] << " " << Heiltrank[2] << " " << Heiltrank[3] << " " << Heiltrank[4] << endl;
                        datei << "Manatrank: --- " << Manatrank[0] << " " << Manatrank[1] << " " << Manatrank[2] << " " << Manatrank[3] << " " << Manatrank[4] << endl;
                        datei << "RegenTrank: -- " << RegenTrank[0] << " " << RegenTrank[1] << " " << RegenTrank[2] << " " << RegenTrank[3] << " " << RegenTrank[4] << endl;
                        datei << "Exp: --------- " << Exp[0] << " " << Exp[1] << " " << Exp[2] << " " << Exp[3] << " " << Exp[4] << endl;
                        datei << "LevelExp: ---- " << LevelExp[0] << " " << LevelExp[1] << " " << LevelExp[2] << " " << LevelExp[3] << " " << LevelExp[4] << endl;
                        datei << "Staerke: ----- " << Staerke[0] << " " << Staerke[1] << " " << Staerke[2] << " " << Staerke[3] << " " << Staerke[4] << endl;
                        datei << "Intelligenz: - " << Intelligenz[0] << " " << Intelligenz[1] << " " << Intelligenz[2] << " " << Intelligenz[3] << " " << Intelligenz[4] << endl;
                        datei << "Ausdauer: ---- " << Ausdauer[0] << " " << Ausdauer[1] << " " << Ausdauer[2] << " " << Ausdauer[3] << " " << Ausdauer[4] << endl;
                        datei << "Geschick: ---- " << Geschick[0] << " " << Geschick[1] << " " << Geschick[2] << " " << Geschick[3] << " " << Geschick[4] << endl;
                        datei << "Gesundheit: -- " << Gesundheit[0] << " " << Gesundheit[1] << " " << Gesundheit[2] << " " << Gesundheit[3] << " " << Gesundheit[4] << endl;
                        datei << "TatsaechlicheGesundheit: " << TatsaechlicheGesundheit[0] << " " << TatsaechlicheGesundheit[1] << " " << TatsaechlicheGesundheit[2] << " " << TatsaechlicheGesundheit[3] << " " << TatsaechlicheGesundheit[4] << endl;
                        datei << "Mana: -------- " << Mana[0] << " " << Mana[1] << " " << Mana[2] << " " << Mana[3] << " " << Mana[4] << endl;
                        datei << "TatsaechlichesMana: ---- " << TatsaechlichesMana[0] << " " << TatsaechlichesMana[1] << " " << TatsaechlichesMana[2] << " " << TatsaechlichesMana[3] << " " << TatsaechlichesMana[4] << endl;
                        datei << "Glueck: ------ " << Glueck[0] << " " << Glueck[1] << " " << Glueck[2] << " " << Glueck[3] << " " << Glueck[4] << endl;
                        datei << "Tragekapazitaet: ------- " << Tragekapazitaet[0] << " " << Tragekapazitaet[1] << " " << Tragekapazitaet[2] << " " << Tragekapazitaet[3] << " " << Tragekapazitaet[4] << endl;
                        datei << "Gold: -------- " << Gold[0] << " " << Gold[1] << " " << Gold[2] << " " << Gold[3] << " " << Gold[4] << endl;
                        datei << "Raeume: ------ " << Raeume[0] << " " << Raeume[1] << " " << Raeume[2] << " " << Raeume[3] << " " << Raeume[4] << endl;
                        datei << "Monster: ----- " << Monster[0] << " " << Monster[1] << " " << Monster[2] << " " << Monster[3] << " " << Monster[4] << endl;
                        datei << "Bosse: ------- " << Bosse[0] << " " << Bosse[1] << " " << Bosse[2] << " " << Bosse[3] << " " << Bosse[4] << endl;
                        datei << "Crafted: ----- " << Crafted[0] << " " << Crafted[1] << " " << Crafted[2] << " " << Crafted[3] << " " << Crafted[4] << endl;
                        datei << "SpielerName: - " << SpielerName[0] << " " << SpielerName[1] << " " << SpielerName[2] << " " << SpielerName[3] << " " << SpielerName[4] << endl;

                        datei << "Waffe: --------";
                                                
                        while (Running)
                        {
                            for(int i = 1; i < (SpielerAnzahl + 1); i++)
                            {
                                for(int x = 0; Waffe[i][x] = 0; x++) 
                                {
                                    datei << Waffe[i][x] << " ";
                                }
                                datei << endl;
                            }
                            Running = false;
                            break;
                        }
                        
                        datei << "Ruestung: ------";

                        Running = true;

                        while (Running)
                        {
                            for(int i = 1; i < (SpielerAnzahl + 1); i++)
                            {
                                for(int x = 0; Ruestung[i][x] = 0; x++)
                                {
                                    datei << Ruestung[i][x] << " ";
                                }
                                Running = false;
                                break;
                            }
                        }
                        
                        datei.close();
                    }
    cout << "\n\nDatei wurde gespeichert.";
    getKey();
    return;

}


// Spielstand erstellen

void Save(int Choice)
{
    string Spielstand[3];
    Spielstand[1] = "Spielstand 01.txt";
    Spielstand[2] = "Spielstand 02.txt";
    Spielstand[3] = "Spielstand 03.txt";
    
    ifstream Pruefung(Spielstand[Choice].c_str());
            if (Pruefung.good()) 
            {
                Pruefung.close();
                cout << "\n\nDie Datei existiert bereits. Moechten Sie sie überschreiben? (J/N)";
                bool Auswahl = boolWert();
                if (Auswahl == true) 
                {
                   SpielStand(Choice);                  
                   cout << "\n\nDie Datei wurde überschrieben!";
                   getKey();
                }
                else
                {
                   cerr << "\n\nFehler beim Oeffnen der Datei!";
                   getKey();
                }
            }
            else
            {
                Pruefung.close();
                cout << "\n\nDie Datei existiert nicht. Soll sie erstellt werden? (J/N)";
                bool Auswahl = boolWert();
                if (Auswahl == true)
                {
                    SpielStand(Choice);
                    cout << "\n\nDie Datei wurde erstellt!";
                    getKey();
                }
                else
                {
                    cerr << "\n\nFehler beim oeffnen der Datei!";
                    getKey();
                }
            }
    return;
}

// Speichermenue

void SaveGame()
{
    bool Running = true;
    
    while(Running)
    {
    clrScr();
    cout << "\033[36m ____                                          /n";
    cout << "/\\  _`\\                                              /n";
    cout << "\\ \\,\\L\\_\\      __      __  __     __              /n";
    cout << " \\/_\\__ \\    /'__`\\   /\\ \\/\\ \\  /'__`\\        /n";
    cout << "   /\\ \\L\\ \\ /\\ \\L\\.\\_ \\ \\ \\_/ |/\\  __/     /n";
    cout << "   \\ `\\____\\ \\__/.\\_\\ \\ \\___/ \\ \\____\\      /n";
    cout << "    \\/_____/ \\/__/\\/_/  \\/__/   \\/____/           \033[0m\n";
    cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n";
    cout << "[ 1 ] ------> Spielstand 1\n\n";
    cout << "---------------------------------------------------------------------------------------------------------------\n\n";
    cout << "[ 2 ] ------> Spielstand 2\n\n";
    cout << "---------------------------------------------------------------------------------------------------------------\n\n";
    cout << "[ 3 ] ------> Spielstand 3\n\n";
    cout << "---------------------------------------------------------------------------------------------------------------\n\n";
    cout << "[ 4 ] ------> Zurueck";

    int Ergebnis = auswahl();
    switch (Ergebnis)
    {
        case 1:
            Save(1);
            break;
        
        case 2:
            Save(2);
            break;

        case 3:
            Save(3);
            break;
        
        case 4:
            Running = false;
            break;

        default :
            cout << "Das geht nicht!\n\n";
            getKey();
            break;
    }
    return;
}
}

// Namen Aendern

void Name()
{
    bool Running = true;

    while(Running)
    {
        clrScr();
        cout << "\033[36m /'\\_/`\\                                        ";
        cout << "/\\      \\      __     ___     __  __     __     ";
        cout << "\\ \\ \\__\\ \\   /'__`\\ /' _ `\\  /\\ \\/\\ \\  /'__`\\   ";
        cout << " \\ \\ \\_/\\ \\ /\\  __/ /\\ \\/\\ \\ \\ \\ \\_\\ \\/\\  __/   ";
        cout << "  \\ \\_\\ \\_\\ \\____\\ \\_\\ \\_\\ \\ \\____/\\ \\____\\  ";
        cout << "   \\/_/ \\/_/ \\/____/ \\/_/\\/_/  \\/___/  \\/____/ \033[0m \n";
        cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n";
        cout << "[ 1 ] ------> " << SpielerName[1] << "\n\n";
        if (SpielerAnzahl > 1) {cout << "[ 2 ] ------> " << SpielerName[2] << "\n\n";}
        if (SpielerAnzahl > 2) {cout << "[ 3 ] ------> " << SpielerName[3] << "\n\n";}
        if (SpielerAnzahl > 3) {cout << "[ 4 ] ------> " << SpielerName[4] << "\n\n";}
        cout << "[ 5 ] ------> Zurueck\n\n";
        cout << "Welcher Name soll geaendert werden ?";
        int Ergebnis = auswahl();
        switch(Ergebnis)
        {
            case 1:
                cout << "Geben Sie bitte den neuen Namen ein fuer Spieler " << SpielerName[Ergebnis] << "eingeben.\n";
                cin >> SpielerName[Ergebnis];
                break;

            case 2: 
                if (SpielerAnzahl < 2) {cout << "\n\nDas geht nicht!";}
                cout << "Geben Sie bitte den neuen Namen ein fuer Spieler " << SpielerName[Ergebnis] << "eingeben.\n";
                cin >> SpielerName[Ergebnis];
                break;

            case 3:
                if (SpielerAnzahl < 3) {cout << "\n\nDas geht nicht!";}
                cout << "Geben Sie bitte den neuen Namen ein fuer Spieler " << SpielerName[Ergebnis] << "eingeben.\n";
                cin >> SpielerName[Ergebnis];
                break;

            case 4:
                if (SpielerAnzahl < 2) {cout << "\n\nDas geht nicht!";}
                cout << "Geben Sie bitte den neuen Namen ein fuer Spieler " << SpielerName[Ergebnis] << "eingeben.\n";
                cin >> SpielerName[Ergebnis];
                break;

            case 5: 
                Running = false;
                break;

            default:
                cout << "\n\nDas geht nicht!";
                break;
        }
    }
}

// Ingame Menue

void SpielMenue()
{
    bool Running = true;
    bool Korrekt = false;
    
    while(Running)
    {
        clrScr();
        cout << "\033[36m /'\\_/`\\                                        ";
        cout << "/\\      \\      __     ___     __  __     __     ";
        cout << "\\ \\ \\__\\ \\   /'__`\\ /' _ `\\  /\\ \\/\\ \\  /'__`\\   ";
        cout << " \\ \\ \\_/\\ \\ /\\  __/ /\\ \\/\\ \\ \\ \\ \\_\\ \\/\\  __/   ";
        cout << "  \\ \\_\\ \\_\\ \\____\\ \\_\\ \\_\\ \\ \\____/\\ \\____\\  ";
        cout << "   \\/_/ \\/_/ \\/____/ \\/_/\\/_/  \\/___/  \\/____/ \033[0m \n";
        cout << "\n\n---------------------------------------------------------------------------------------------------------------\n\n";
        cout << "[ 1 ] ------> Spielstand speichern\n\n";
        cout << "[ 2 ] ------> Spielerame aendern\n\n";
        cout << "[ 3 ] ------> Zurueck zum Spiel\n\n";
        cout << "[ 4 ] ------> Spiel beenden";
        int Ergebnis = auswahl();
        switch(Ergebnis)
        {
            case 1:
                SaveGame();
                break;
        
            case 2:
                Name();
                break;
        
            case 3:
                Running = false;
                break;

            case 4:
                cout << "\n\nSind Sie sicher, dass Sie das Spiel beenden möchten (J/N)?\n";
                Korrekt = boolWert();
                if (Korrekt == true) {SpielEnde();} else {break;}                
            
            default:
                cout << "\n\nDas geht nicht!";
                getKey();
                break;
        }
    return;
    }
}

// Raum Optionen

int RaumOptionen(int Gefahr)
{
    SchalterFarbe(Gefahr); cout << "[ 1 ]\033[0m ------> "; Farbe(Gefahr); cout << "Weiter zum naechsten Raum\033[0m               \033[30;46m[ 5 ]\033[0m ------> \033[36mCharakter \033[0m \n\n";
    SchalterFarbe(Gefahr); cout << "[ 2 ]\033[0m ------> "; Farbe(Gefahr); cout << "Umgebung absuchen       \033[0m                \033[30;105m[ 6 ]\033[0m ------> \033[95mInventar \033[0m \n\n";
    SchalterFarbe(Gefahr); cout << "[ 3 ]\033[0m ------> "; Farbe(Gefahr); cout << "Nach Fallen suchen      \033[0m                \033[30;104m[ 7 ]\033[0m ------> \033[94mMagie \033[0m \n\n";
    SchalterFarbe(Gefahr); cout << "[ 4 ]\033[0m ------> "; Farbe(Gefahr); cout << "Ausruhen                \033[0m                \033[30;47m[ 8 ]\033[0m ------> Menue \n\n";

    int Ergebnis = auswahl();
    return Ergebnis;
}

// Erster Raum

void ErsterRaum()
{
int Gefahrstufe = zufall(1,3);
Falle(Gefahrstufe);
bool Running = true;

while (Running)
{
    clrScr();
    cout << "\033[0m_______________________________________________________                 \033[36mSpieler: " << SpielerName[RundenManager] << "        \033[0mRaum: " << Raeume[RundenManager] << "\n";
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "|__|_____|_____|_____|_____|_____|_____|_____|_____|__|                 --------------------------------------------------------\n";
    cout << "|_____|_____/ ___________________________ \\_____|_____|\n";             
    cout << "|__|_____|_/ /             |             \\ \\_|_____|__|                 Sie befinden sich vor der legendaeren Eingangstuer\n";
    cout << "|_____|___/ /              |              \\ \\___|_____|                 zum Endlosen Dungeon.\n";
    cout << "|__|_____| |               |               | |_____|__|                 Der Eingang wirkt sehr alt und Verheissungsvoll.\n";
    cout << "|_____|__| |               |               | |__|_____|                 Sie bilden sich ein, Goblin und Orkfuerze riechen zu\n";
    cout << "|__|_____| |               |               | |_____|__|                 koennen. Daher wissen Sie, dass Sie hier richtig sind.\n"; 
    cout << "|_____|__| |               |               | |__|_____|\n";
    cout << "|__|_____| |               |               | |_____|__|                 --------------------------------------------------------\n";
    cout << "|_____|__| |          ~(O  |  O)~          | |__|_____|\n";
    cout << "|__|_____| |            0  |  0            | |_____|__|                 "; if (Gefahrstufe == 1){cout << "\033[92mGefahrstufe : Sicher\033[0m \n";} else if (Gefahrstufe == 2){cout << "\033[33mGefahrstufe : Unsicher\033[0m \n";} else if (Gefahrstufe == 3){cout << "\033[31mGefahrstufe : Gefahr!\033[0m \n";}
    cout << "|_____|__| |               |               | |__|_____|\n";
    cout << "|__|_____| |               |               | |_____|__|                 --------------------------------------------------------\n";
    cout << "|_____|__| |               |               | |__|_____|\n";
    cout << "|__|_____| |               |               | |_____|__|\n";
    cout << "|_____|__| |               |               | |__|_____|\n";
    cout << "|__|_____|_|_______________|_______________|_|_____|__|\n\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------\n\n";
    ShowLife();
    int Ergebnis = RaumOptionen(Gefahrstufe);
    switch (Ergebnis)
    {
        case 1:
            if (Schluessel[RundenManager] < 1) 
            {
                cout << "Die Tuer ist verschlossen und Sie haben leider keinen Schluessel!\n (Tipp: Umgebung absuchen)";
                getKey();
                break;
            }
            else
            {
                cout << "Sie oeffnen die legendaere Tuer mit dem gefunden Schluessel und treten ein....\nHerzlich willkommen im endlosen Dungeon, " << SpielerName[RundenManager] << "!";
                getKey();
                Running = false;
                break;
            }
        case 2:
            Suche(Gefahrstufe);
            break;

        case 3:
            FalleSuchen(Gefahrstufe);
            break;
        
        case 4:
            Ausruhen(Gefahrstufe);
            break;

        case 5:
            Charakter();
            break;
        
        case 6:
            Inventar();
            break;
        
        case 7:
            Magie();
            break;

        case 8:
            SpielMenue();
            break;

        default:
            cout << "Das geht nicht!";
            getKey();
            break;
    }

}
return;
}

// Hauptprogramm

int main ()
{
    clrScr();
    cout << "Start\n";
    getKey();
    clrScr();

    cout << "\033[33mThe Big Random\n\n";
    cout << "\033[36m #################    #################           ############       #######             ##################\n"; 
    cout << " #::::::::::::::::#   #::::::::::::::::#       ###:::::::::::#      #::::::#             #::::::::::::::::#\n"; 
    cout << " #::::::######:::::#  #::::::######:::::#    ##::::::::::::::#     #:::::::#             #::::::::::::::::#\n"; 
    cout << " ##:::::#     #:::::###:::::#     #:::::#  #:::::########::::#     ###:::::#             #:::::############\n"; 
    cout << "   #::::#     #:::::#  #::::#     #:::::# #:::::#       ######        #::::#             #:::::#\n";            
    cout << "   #::::#     #:::::#  #::::#     #:::::##:::::#                      #::::#             #:::::#\n";            
    cout << "   #::::######:::::#   #::::######:::::# #:::::#                      #::::#             #:::::##########\n";     
    cout << "   #:::::::::::::##    #:::::::::::::##  #:::::#    ##########        #::::#             #:::::::::::::::#\n";  
    cout << "   #::::######:::::#   #::::#########    #:::::#    #::::::::#        #::::#             ############:::::#\n"; 
    cout << "   #::::#     #:::::#  #::::#            #:::::#    #####::::#        #::::#                         #:::::#\n";
    cout << "   #::::#     #:::::#  #::::#            #:::::#        #::::#        #::::#                         #:::::#\n";
    cout << "   #::::#     #:::::#  #::::#             #:::::#       #::::#        #::::#             #######     #:::::#\n";
    cout << " ##:::::#     #:::::###::::::##            #:::::########::::#     ###::::::###          #::::::#####::::::#\n";
    cout << " #::::::#     #:::::##::::::::#             ##:::::::::::::::#     #::::::::::#  ######   ##:::::::::::::##\n"; 
    cout << " #::::::#     #:::::##::::::::#               ###::::::###:::#     #::::::::::#  #::::#     ##:::::::::##\n";   
    cout << " ########     #################                  ######   ####     ############  ######       #########\033[0m\n";  
    cout << "\nWritten in 2023 by \033[34mZongamin\033[0m\n";
    cout << "\nIn an advisory function: \033[35mDecade\033[0m\n";
    cout << "\n© in 2023 by\n";
    cout << "\033[31m___  ___             _                    _               _ \n";
    cout << "|  \\/  |            | |                  (_)             | | \n";
    cout << "| .  . |  ___   ___ | |__    __ _  _ __   _   ___   __ _ | | \n";
    cout << "| |\\/| | / _ \\ / __|| '_ \\  / _` || '_ \\ | | / __| / _` || | \n";
    cout << "| |  | ||  __/| (__ | | | || (_| || | | || || (__ | (_| || | \n";
    cout << "\\_|  |_/ \\___| \\___||_| |_| \\__,_||_| |_||_| \\___| \\__,_||_| \n";
    cout << "\t _____ \n";                             
    cout << "\t|  __ \\ \n";                             
    cout << "\t| |  \\/  __ _  _ __ ___    ___  ___ \n"; 
    cout << "\t| | __  / _` || '_ ` _ \\  / _ \\/ __| \n";
    cout << "\t| |_\\ \\| (_| || | | | | ||  __/\\__ \\ \n";
    cout << "\t\\_____/ \\__,_||_| |_| |_| \\___||___/\033[0m\n";
    
    getKey();       
    zuweisung();
    Hauptmenue();
    bool Running = true;
    while(Running)
    {
        RundenManager++;

        if (RundenManager > SpielerAnzahl)
        {
            RundenManager = 0;
            Running = false;
            break;
        }
        else
        {    
            Charakter();
            ErsterRaum();
            break;
        }
        
    }

    bool NextRoom = true;
    int DerzeitigerRaum = 0;

    while (Running)
    {
        if (NextRoom == true)
        {
            NextRoom = false; Raeume[RundenManager]++;RundenManager++; DerzeitigerRaum = zufall(12,1);
            if (RundenManager > SpielerAnzahl) {RundenManager = 1;} 
        }

        clrScr();

    }
}



