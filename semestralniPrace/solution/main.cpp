#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <cmath>

#include <stdlib.h>
#include <ctype.h>
using namespace std;


struct Mistnosti{

        int id;
        int patro;
        int jmenoMistnosti;
        int kapacitaSedadel;
        int cenaDen;
};
struct Rezervace {
        int id;
        string denRezervace;

};

int pocetRadku(ifstream &soubor){
    // OSETRIT I/O EXCEPTIONS
    int radky = 0;
    string nacteno;
    while (getline(soubor,nacteno)){
        radky++;

    }

    return (radky);
}
void nactiMistnosti (ifstream &soubor,Mistnosti mistnosti[]){
    // OSETRIT I/O EXCEPTIONS
    soubor.clear();
    soubor.seekg(0, ios::beg);
    string radek,token;
    char ch;
    int i = 0;
    while(getline(soubor,radek)){
        istringstream ss(radek);
        ss >> mistnosti[i].id;
        ss >> ch;
        ss >> mistnosti[i].patro;
        ss >> ch;

        ss >> mistnosti[i].jmenoMistnosti;
        ss >> ch;
        ss >> mistnosti[i].kapacitaSedadel;
        ss >> ch;
        ss >> mistnosti[i].cenaDen;
        i++;

    }

}
int vypisRezervace(Rezervace rezervace[],int pocetRezervace){

return(0);

}
int vypisPodleMist(Mistnosti mistnosti[],int pocetMistnosti){
    cout << "Jak chcete mistnosti vypsat?" << endl;
    cout << "Od nejmensiho poctu mist - 1" << endl;
    cout << "Od nejvyssiho poctu mist - 2" << endl;
    int error = 0;
    string cislicko;
    int cisloAkce;

    getline(cin,cislicko);

    if (cislicko.length() == 1){
        if (cislicko.at(0) < '0' || cislicko.at(0) > '9'){
            cout << "Spatne zadane cislo,zkuste to znovu." << endl << endl;
            return (vypisPodleMist(mistnosti,pocetMistnosti));
        }
        cisloAkce = cislicko.at(0)-'0';
    }
    else {
        cout << "Spatne zadane cislo,zkuste to znovu." << endl << endl;
        return (vypisPodleMist(mistnosti,pocetMistnosti));
    }
    int vetsiMensi = 0;

     switch(cisloAkce){
        case 1:{
            vetsiMensi = 1;
            break;
        }
        case 2:{
            vetsiMensi = 2;
            break;
        }
        default:{
            cout << "Spatne zadane cislo,zkuste to znovu." << endl << endl;
            return (vypisPodleMist(mistnosti,pocetMistnosti));
            break;
        }
     }

    int i, j;
    struct Mistnosti temp;
if (vetsiMensi = 1){
    for (i = 0; i < (pocetMistnosti-1);i++){
        for (j = 0; j < (pocetMistnosti-1-i);j++){
            if (mistnosti[j].kapacitaSedadel > mistnosti[j+1].kapacitaSedadel){
                temp = mistnosti[j];
                mistnosti[j] = mistnosti[j+1];
                mistnosti[j+1] = temp;
            }

        }

    }
}
if (vetsiMensi = 2){
    for (i = 0; i < (pocetMistnosti-1);i++){
        for (j = 0; j < (pocetMistnosti-1-i);j++){
            if (mistnosti[j].kapacitaSedadel < mistnosti[j+1].kapacitaSedadel){
                temp = mistnosti[j];
                mistnosti[j] = mistnosti[j+1];
                mistnosti[j+1] = temp;
            }

        }

    }

}
    for (i = 0; i < pocetMistnosti; i++){
        cout << mistnosti[i].id << "|" << mistnosti[i].patro << "|" << mistnosti[i].jmenoMistnosti << "|" << mistnosti[i].kapacitaSedadel << "|" << mistnosti[i].cenaDen << endl;
    }

return(0);

}
int vypisPodleCeny(Mistnosti mistnosti[], int pocetMistnosti){

return(0);

}
int vypisVolneMistnosti(Mistnosti mistnosti[],Rezervace rezervace[],int pocetMistnosti){

return(0);

}
int rezervaceMista(ifstream &souborRezervace,Mistnosti mistnosti[], Rezervace rezervace[]){

return(0);

}
int askForAction(ifstream &souborRezervace, Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti, int pocetRezervace){
 cout << "Zadejte cislo akce, kterou chcete provest" << endl;
 cout << "Rezervace mistnosti - 1" << endl;
 cout << "Vypis mistnosti podle jmena - 2" << endl;
 cout << "Vypis mistnosti podle ceny - 3" << endl;
 cout << "Vypis mistnosti podle poctu mist - 4" << endl;
 cout << "Vypis rezervovanych mistnosti - 5" << endl << endl;
 int error = 0;
 string cislicko;
 int cisloAkce;

getline(cin,cislicko);

if (cislicko.length() == 1){
    if (cislicko.at(0) < '0' || cislicko.at(0) > '9')
        return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));
    cisloAkce = cislicko.at(0)-'0';
}
else {
    return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));
}


 switch(cisloAkce){
    case 1:{
        rezervaceMista(souborRezervace,mistnosti,rezervace);
        break;
    }
    case 2:{
        vypisVolneMistnosti(mistnosti,rezervace,pocetMistnosti);
        break;
    }
    case 3:{
        vypisPodleCeny(mistnosti,pocetMistnosti);
        break;
    }
    case 4:{
        vypisPodleMist(mistnosti,pocetMistnosti);
        break;
    }
    case 5:{
        vypisRezervace(rezervace,pocetRezervace);
        break;
    }
    default:{
        cout << "Spatne zadane cislo" << endl << endl;
        error++;
        break;
    }
 }
 if (error > 0){
    return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));

 }
return(0);
}

int startCom(ifstream &souborRezervace, Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti, int pocetRezervace){
    string htmlSoubor;
    int error = 0;
    cout << "Zadejte jmeno souboru, do ktereho chcete ulozit informace." << endl;
    cout << "Jmeno souboru muze obsahovat:" << endl;
    cout << "mala i velka pismena, cislice, znak tecky,zpetneho lomitka,dopredneho lomitka nebo podtrzitka." << endl;
    cout << "Zadavejte ve formatu vasejmenosouboru.html" << endl;
    getline(cin,htmlSoubor);

    int length = htmlSoubor.length()-1;
    if (length+1 < 6){
        cout << "Spatne zadana adresa, Zkuste to znovu" << endl << endl;
        return (startCom(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));
    }
    if (htmlSoubor.at(length) != 'l' || htmlSoubor.at(length-1) != 'm' || htmlSoubor.at(length-2) != 't' || htmlSoubor.at(length-3) != 'h' || htmlSoubor.at(length-4) != '.')
       error++;
    for (int i = 0; i < length-5; i++){
        if (htmlSoubor.at(i) < 46 || (htmlSoubor.at(i) > 57 && htmlSoubor.at(i) <65) || (htmlSoubor.at(i) > 90 && htmlSoubor.at(i) < 97 && htmlSoubor.at(i) != 95 && htmlSoubor.at(i) != 92) || htmlSoubor.at(i) > 122){
            error++;
            break;
        }
    }
    if (error > 0){
        cout << "Spatne zadana adresa, Zkuste to znovu" << endl << endl;
        return (startCom(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));

        }
    else {
    askForAction(souborRezervace,mistnosti,rezervace, pocetMistnosti, pocetRezervace );
    return(0);
    }


return(0);
}


int main()
{
    ifstream fileMistnosti("..\\vstupnidata\\mistnosti.csv");
    ifstream fileRezervace("..\\vstupnidata\\rezervace.csv");

    int pocetMistnosti = pocetRadku(fileMistnosti);
    int pocetRezervace = pocetRadku(fileRezervace);

    Mistnosti* mistnosti = new Mistnosti[pocetMistnosti];
    Rezervace* rezervace = new Rezervace[pocetRezervace];
    nactiMistnosti (fileMistnosti,mistnosti);
    cout << startCom(fileRezervace,mistnosti,rezervace,pocetMistnosti,pocetRezervace);


    delete[] mistnosti;
    delete[] rezervace;
    return 0;
}
