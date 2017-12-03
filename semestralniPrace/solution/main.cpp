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
#define OKAY        0
#define IO_ERROR    1

struct Mistnosti{

        int id;
        int patro;
        int jmenoMistnosti;
        int kapacitaSedadel;
        int cenaDen;
};
struct Rezervace {
        int id;
        int datum;

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
void nactiRezervace (ifstream &soubor, Rezervace rezervace[]){
    // OSETRIT I/O EXCEPTIONS
    soubor.clear();
    soubor.seekg(0, ios::beg);
    string radek,token;
    char ch;
    int i = 0;
    while(getline(soubor,radek)){
        istringstream ss(radek);
        ss >> rezervace[i].id;
        ss >> ch;
        ss >> rezervace[i].datum;
        i++;

    }
}
int startHTML(const char* htmlSoubor){

    ofstream myFile;
    myFile.exceptions ( ofstream::failbit | ofstream::badbit );
        try {
            myFile.open (htmlSoubor, std::ofstream::out);
            myFile << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">" << endl; //starting html
            myFile << "<html>" << endl << "<head>" << endl << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">" << endl << "<title>C++</title>" << endl << "</head>" << endl;
            myFile << "<body>" << endl;
            myFile << "<table width=\"900\">" << endl << "<tr><th width=\"180\">ID</th><th width=\"180\">PATRO</th><th width=\"180\">CISLO MISTNOSTI</th><th width=\"180\">KAPACITA</th><th width=\"180\">CENA ZA DEN</th></tr>" << endl;
        }
        catch (const ofstream::failure& e){
            return (IO_ERROR);
        }
    myFile.close();

return(OKAY);

}
int endHTML(const char* htmlSoubor){
    ofstream myFile;
    myFile.exceptions ( ofstream::failbit | ofstream::badbit );
     try {
        myFile.open (htmlSoubor, std::ofstream::out | std::ofstream::app);

        myFile << "</table>" << endl;
        myFile << "</body>" << endl;
        myFile << "</html>" << endl;
     }
     catch(const ofstream::failure& e){
        return(IO_ERROR);
     }
     myFile.close();


return (OKAY);

}
int zapisDoHTMLPrvnichX(Mistnosti mistnosti[], int pocetCiselMensich, const char* htmlSoubor){

startHTML(htmlSoubor);
for (int i = 0; i < pocetCiselMensich; i++){
        cout << mistnosti[i].id << "|" << mistnosti[i].patro << "|" << mistnosti[i].jmenoMistnosti << "|" << mistnosti[i].kapacitaSedadel << "|" << mistnosti[i].cenaDen << endl;
    }
endHTML(htmlSoubor);
return (0);
}
int zapisDoHTML(Mistnosti mistnosti[], int pocetMistnosti,const char* htmlSoubor){

return (0);
}
int vypisRezervace(Rezervace rezervace[],int pocetRezervace,const char* htmlSoubor){

return(0);

}
int vypisPodleMist(Mistnosti mistnosti[],int pocetMistnosti,const char* htmlSoubor){
    cout << "Jak chcete mistnosti vypsat?" << endl;
    cout << "Od nejmensiho poctu mist - 1" << endl;
    cout << "Od nejvyssiho poctu mist - 2" << endl;
    string cislicko;
    int cisloAkce;

    getline(cin,cislicko);

    if (cislicko.length() == 1){
        if (cislicko.at(0) < '0' || cislicko.at(0) > '9'){
            cout << "Spatne zadane cislo,zkuste to znovu." << endl << endl;
            return (vypisPodleMist(mistnosti,pocetMistnosti,htmlSoubor));
        }
        cisloAkce = cislicko.at(0)-'0';
    }
    else {
        cout << "Spatne zadane cislo,zkuste to znovu." << endl << endl;
        return (vypisPodleMist(mistnosti,pocetMistnosti,htmlSoubor));
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
            return (vypisPodleMist(mistnosti,pocetMistnosti,htmlSoubor));
            break;
        }
     }

    int i, j;
    struct Mistnosti temp;
if (vetsiMensi == 1){
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
if (vetsiMensi == 2){
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
zapisDoHTML(mistnosti,pocetMistnosti,htmlSoubor);

    for (i = 0; i < pocetMistnosti; i++){
        cout << mistnosti[i].id << "|" << mistnosti[i].patro << "|" << mistnosti[i].jmenoMistnosti << "|" << mistnosti[i].kapacitaSedadel << "|" << mistnosti[i].cenaDen << endl;
    }

return(0);

}
int vypisPodleCeny(Mistnosti mistnosti[], int pocetMistnosti,const char* htmlSoubor){

    cout << "Jaka ma byt maximalni cena?" << endl;
    string cislicko;
    int cisloAkce = 0;
    int pocetCiselMensich = 0;

    getline(cin,cislicko);
    int length = cislicko.length();
    for (int i = 0; i < length; i++){
        if (cislicko.at(i) < '0' || cislicko.at(i) > '9'){

            cout << "Spatne zadana cena, zkuste to znovu." << endl << endl;
            return (vypisPodleCeny(mistnosti,pocetMistnosti,htmlSoubor));
        }
    }
    if (length < 1){
            cout << "Nebylo zadano cislo, zkuste to znovu." << endl << endl;
            return (vypisPodleCeny(mistnosti,pocetMistnosti,htmlSoubor));
    }
        for (int j = 0; j < length;j++){
            cisloAkce += (cislicko.at(j)-'0') * pow(10,length-1-j);

        }



    int i, j;
    struct Mistnosti temp;

    for (i = 0; i < (pocetMistnosti-1);i++){
        for (j = 0; j < (pocetMistnosti-1-i);j++){
            if (mistnosti[j].cenaDen > mistnosti[j+1].cenaDen){
                temp = mistnosti[j];
                mistnosti[j] = mistnosti[j+1];
                mistnosti[j+1] = temp;
            }

        }

    }

    for (i = 0; i < (pocetMistnosti);i++){

            if (mistnosti[i].cenaDen <= cisloAkce){
                pocetCiselMensich++;
            }

    }
zapisDoHTMLPrvnichX(mistnosti,pocetCiselMensich,htmlSoubor);





return(0);

}
int vypisVolneMistnosti(Mistnosti mistnosti[],Rezervace rezervace[],int pocetMistnosti, const char* htmlSoubor){

return(0);

}
int rezervaceMista(ifstream &souborRezervace,Mistnosti mistnosti[], Rezervace rezervace[],const char* htmlSoubor){

return(0);

}
int askForAction(ifstream &souborRezervace, Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti, int pocetRezervace,const char* htmlSoubor){
 cout << "Zadejte cislo akce, kterou chcete provest" << endl;
 cout << "Rezervace mistnosti - 1" << endl;
 cout << "Vypis volnych mistnosti na dane datum - 2" << endl;
 cout << "Vypis mistnosti podle ceny - 3" << endl;
 cout << "Vypis mistnosti podle poctu mist - 4" << endl;
 cout << "Vypis rezervovanych mistnosti - 5" << endl << endl;
 int error = 0;
 string cislicko;
 int cisloAkce;

getline(cin,cislicko);

if (cislicko.length() == 1){
    if (cislicko.at(0) < '0' || cislicko.at(0) > '9')
        return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace, htmlSoubor));
    cisloAkce = cislicko.at(0)-'0';
}
else {
    return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace,htmlSoubor));
}


 switch(cisloAkce){
    case 1:{
        rezervaceMista(souborRezervace,mistnosti,rezervace,htmlSoubor);
        break;
    }
    case 2:{
        vypisVolneMistnosti(mistnosti,rezervace,pocetMistnosti,htmlSoubor);
        break;
    }
    case 3:{
        vypisPodleCeny(mistnosti,pocetMistnosti,htmlSoubor);
        break;
    }
    case 4:{
        vypisPodleMist(mistnosti,pocetMistnosti,htmlSoubor);
        break;
    }
    case 5:{
        vypisRezervace(rezervace,pocetRezervace,htmlSoubor);
        break;
    }
    default:{
        cout << "Spatne zadane cislo" << endl << endl;
        error++;
        break;
    }
 }
 if (error > 0){
    return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace,htmlSoubor));

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
    const char* stringToChar = htmlSoubor.c_str();
    askForAction(souborRezervace,mistnosti,rezervace, pocetMistnosti, pocetRezervace,stringToChar);
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
    nactiRezervace (fileRezervace,rezervace);
    nactiMistnosti (fileMistnosti,mistnosti);
    cout << startCom(fileRezervace,mistnosti,rezervace,pocetMistnosti,pocetRezervace);


    delete[] mistnosti;
    delete[] rezervace;
    return 0;
}
