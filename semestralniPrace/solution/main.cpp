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
string startCom(){
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
        return (startCom());
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
        return (startCom());

        }



return(htmlSoubor);
}

int startHTML(string htmlSoubor){
    htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions ( ofstream::failbit | ofstream::badbit );
        try {
            myFile.open (stringToChar, std::ofstream::out);
            myFile << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">" << endl; //starting html
            myFile << "<html>" << endl << "<head>" << endl << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">" << endl << "<title>C++</title>" << endl << "</head>" << endl;
            myFile << "<body>" << endl;

        }
        catch (const ofstream::failure& e){
            return (IO_ERROR);
        }
    myFile.close();

return(OKAY);

}

int endHTML(string htmlSoubor){
    htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions ( ofstream::failbit | ofstream::badbit );
     try {
        myFile.open (stringToChar, std::ofstream::out | std::ofstream::app);

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

int validateDate(string stringDate){
    int dateInt = 1;
    int length = stringDate.length();
    for (int j = 0;j < length;j++){
            dateInt+= (stringDate.at(j)-'0')*pow(10,length-j-1);
    }


    int year = dateInt/10000;
    int month = (dateInt%10000)/100;
    int day = (dateInt%10000)%100;
        if (((year == 2017 && month < 12)|| year < 2017 || year > 2050)||(month < 1 || month > 12) || day < 1)
            return(0);
        if ((month == 1 && day > 31) || (year%4 == 0 && month == 2 && day > 29) || (year%4 != 0 && month == 2 && day > 28) || (month == 3 && day > 31) || (month == 4 && day > 30) || (month == 5 && day > 31) || (month == 6 && day > 30) || (month == 7 && day > 31) || (month == 8 && day > 31) || (month == 9 && day > 30) || (month == 10 && day > 31) || (month == 11 && day > 30) || (month == 12 && day > 31)){
            return(0);
        }


return (dateInt);
}

int zapisDoHTMLPrvnichX(Mistnosti mistnosti[], int pocetCiselMensich, string htmlSoubor){

startHTML(htmlSoubor);

htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions (ofstream::badbit );

     try {
        myFile.open (stringToChar, std::ofstream::out | std::ofstream::app);
        myFile << "<table width=\"900\">" << endl << "<tr><th width=\"180\">ID</th><th width=\"180\">PATRO</th><th width=\"180\">CISLO MISTNOSTI</th><th width=\"180\">KAPACITA</th><th width=\"180\">CENA ZA DEN</th></tr>" << endl;
       for (int i = 0; i < pocetCiselMensich; i++){

            myFile << "<tr><td align=\"center\">";
            myFile << mistnosti[i].id;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].patro;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].jmenoMistnosti;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].kapacitaSedadel;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].cenaDen;
            myFile << "</td></tr>" << endl;
       }
     }
     catch(const ofstream::failure& e){
        cout << "Nepovedlo se zapsat do souboru" << endl << endl;
        return(IO_ERROR);
     }
     myFile.close();

endHTML(htmlSoubor);
return (0);
}




int zapisDoHTML(Mistnosti mistnosti[], int pocetMistnosti,string htmlSoubor){

    startHTML(htmlSoubor);

    htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions (ofstream::badbit );

     try {
        myFile.open (stringToChar, std::ofstream::out | std::ofstream::app);
        myFile << "<table width=\"900\">" << endl << "<tr><th width=\"180\">ID</th><th width=\"180\">PATRO</th><th width=\"180\">CISLO MISTNOSTI</th><th width=\"180\">KAPACITA</th><th width=\"180\">CENA ZA DEN</th></tr>" << endl;
       for (int i = 0; i < pocetMistnosti; i++){


            myFile << "<tr><td align=\"center\">";
            myFile << mistnosti[i].id;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].patro;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].jmenoMistnosti;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].kapacitaSedadel;
            myFile << "</td><td align=\"center\">";
            myFile << mistnosti[i].cenaDen;
            myFile << "</td></tr>" << endl;

       }
     }
     catch(const ofstream::failure& e){
        cout << "Nepovedlo se zapsat do souboru" << endl << endl;
        return(IO_ERROR);
     }
     myFile.close();

endHTML(htmlSoubor);
return (0);
}


int vypisNejblizsiRezervace(Mistnosti mistnosti[],Rezervace rezervace[],int pocetRezervace,int pocetMistnosti){
    cout << "Zadejte cislo mistnosti" << endl << endl;
    string cisloString;
    int cislo = 0;
    getline(cin,cisloString);
    int length = cisloString.length();
    for (int i = 0; i < length; i++){
        if (cisloString.at(i) < '0' || cisloString.at(i) > '9'){

            cout << "Spatne zadane cislo mistnosti, zkuste to znovu." << endl << endl;
            return (vypisNejblizsiRezervace(mistnosti,rezervace,pocetRezervace,pocetMistnosti));
        }
    }
    if (length != 3){
            cout << "Spatne zadane cislo mistnosti, zkuste to znovu." << endl << endl;
            return (vypisNejblizsiRezervace(mistnosti,rezervace,pocetRezervace,pocetMistnosti));
    }
        for (int j = 0; j < length;j++){
            cislo += (cisloString.at(j)-'0') * pow(10,length-1-j);

        }
    cislo++;
  /*  int cislo = stringToInt(stringDatum);
    if (cislo == 0){
        cout << "Spatne"
    }*/

    int id = 0;
    for (int i = 0; i < pocetMistnosti; i++){
        if (mistnosti[i].jmenoMistnosti == cislo){
            id = mistnosti[i].id;
            break;
        }

    }

    struct Rezervace temp;
    int pocetRezervaciDen = 0;
    for(int i = 0; i < pocetRezervace;i++){
            if (rezervace[i].id == id){
                temp = rezervace[i];
                rezervace[i] = rezervace[pocetRezervaciDen];
                rezervace[pocetRezervaciDen] = temp;
                pocetRezervaciDen++;

            }

    }
    if (pocetRezervaciDen > 1){
        for (int m = 0; m < pocetRezervaciDen; m++){
            for (int n = 0; n < pocetRezervaciDen-m-1; n++){
                if (rezervace[n].datum > rezervace[n+1].datum){
                    temp = rezervace[n];
                    rezervace[n] = rezervace[n+1];
                    rezervace[n+1] = temp;

                }
            }
        }
    }
     string htmlSoubor = startCom();
     startHTML(htmlSoubor);
     htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions (ofstream::badbit );

     try {
        myFile.open (stringToChar, std::ofstream::out | std::ofstream::app);
        myFile << "<table width=\"360\">" << endl << "<tr><th width=\"180\">CISLO MISTNOSTI</th><th width=\"180\">DATUM</th></tr>" << endl;
           for (int i = 0; i < 5; i++){

                int datumInt = rezervace[i].datum;
                int yearDatum = datumInt/10000;
                int monthDatum = (datumInt%10000)/100;
                int dayDatum = ((datumInt%10000)%100);

                myFile << "<tr><td align=\"center\">";
                myFile << mistnosti[id-1].jmenoMistnosti;
                myFile << "</td><td align=\"center\">";
                myFile << dayDatum << "." << monthDatum << "." << yearDatum;
                myFile << "</td></tr>" << endl;

           }
     }
     catch(const ofstream::failure& e){
        cout << "Nepovedlo se zapsat do souboru" << endl << endl;
        return(IO_ERROR);
     }
     myFile.close();


return(0);

}



int zadejMaxKapacitu(Mistnosti mistnosti[],int pocetMistnosti){
    cout << "Zadejte Maximalni pocet mist" << endl << endl;
    string cisloString;
    int cislo = 0;

    getline(cin,cisloString);
    int length = cisloString.length();
    for (int i = 0; i < length; i++){
        if (cisloString.at(i) < '0' || cisloString.at(i) > '9'){

            cout << "Spatne zadany pocet mist, zkuste to znovu." << endl << endl;
            return (zadejMaxKapacitu(mistnosti,pocetMistnosti));
        }
    }
    if (length < 1){
            cout << "Nebylo zadano zadne cislo, zkuste to znovu." << endl << endl;
            return (zadejMaxKapacitu(mistnosti,pocetMistnosti));
    }
        for (int j = 0; j < length;j++){
            cislo += (cisloString.at(j)-'0') * pow(10,length-1-j);

        }

    int i, j;
    struct Mistnosti temp;

    for (i = 0; i < (pocetMistnosti-1);i++){
        for (j = 0; j < (pocetMistnosti-1-i);j++){
            if (mistnosti[j].kapacitaSedadel > mistnosti[j+1].kapacitaSedadel){
                temp = mistnosti[j];
                mistnosti[j] = mistnosti[j+1];
                mistnosti[j+1] = temp;

            }


        }

    }
    int pocetCiselMensich = 0;
    for (i = 0; i < (pocetMistnosti);i++){

            if (mistnosti[i].kapacitaSedadel <= cislo){
                pocetCiselMensich++;
            }


    }
    if (pocetCiselMensich < 1){
        cout << "Zadna mistnost neodpovida zadani." << endl << endl;
        return (zadejMaxKapacitu(mistnosti,pocetMistnosti));
    }

    string htmlSoubor = startCom();
    zapisDoHTMLPrvnichX(mistnosti,pocetCiselMensich,htmlSoubor);

return(OKAY);
}

int vypisPodleMist(Mistnosti mistnosti[],int pocetMistnosti){
    cout << "Jak chcete mistnosti vypsat?" << endl;
    cout << "Od nejmensiho poctu mist - 1" << endl;
    cout << "Od nejvyssiho poctu mist - 2" << endl;
    cout << "Do maximalniho poctu mist - 3" << endl;
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
        case 3:{
            return (zadejMaxKapacitu(mistnosti,pocetMistnosti));
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
string htmlSoubor = startCom();

zapisDoHTML(mistnosti,pocetMistnosti,htmlSoubor);


  /*  for (i = 0; i < pocetMistnosti; i++){
        cout << mistnosti[i].id << "|" << mistnosti[i].patro << "|" << mistnosti[i].jmenoMistnosti << "|" << mistnosti[i].kapacitaSedadel << "|" << mistnosti[i].cenaDen << endl;
    }*/

return(0);

}
int vypisPodleCeny(Mistnosti mistnosti[], int pocetMistnosti){

    cout << "Jaka ma byt maximalni cena?" << endl;
    string cislicko;
    int cisloAkce = 0;
    int pocetCiselMensich = 0;

    getline(cin,cislicko);
    int length = cislicko.length();
    for (int i = 0; i < length; i++){
        if (cislicko.at(i) < '0' || cislicko.at(i) > '9'){

            cout << "Spatne zadana cena, zkuste to znovu." << endl << endl;
            return (vypisPodleCeny(mistnosti,pocetMistnosti));
        }
    }
    if (length < 1){
            cout << "Nebylo zadano cislo, zkuste to znovu." << endl << endl;
            return (vypisPodleCeny(mistnosti,pocetMistnosti));
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
    if (pocetCiselMensich < 1){
        cout << "Zadna mistnost neodpovida zadani." << endl << endl;
        return (vypisPodleCeny(mistnosti,pocetMistnosti));
    }
    string htmlSoubor = startCom();
    zapisDoHTMLPrvnichX(mistnosti,pocetCiselMensich,htmlSoubor);


return(0);

}
int vypisVolneMistnosti(Mistnosti mistnosti[],Rezervace rezervace[],int pocetMistnosti,int pocetRezervace){
    cout << "Zadejte datum, pro ktere chcete vyhledat volne mistnosti. Zadavejte ve formatu YYYYMMDD" << endl;
    string dateString;
    getline(cin,dateString);
    int length = dateString.length();


    if (length != 8){
        cout << "Spatne zadane datum,zkuste to znovu." << endl << endl;
        return(vypisVolneMistnosti(mistnosti,rezervace,pocetMistnosti,pocetRezervace));
    }
    for (int i = 0; i < length;i++){
        if (dateString.at(i) < '0' || dateString.at(i) > '9'){
            cout << "Spatne zadane datum,zkuste to znovu." << endl << endl;
            return(vypisVolneMistnosti(mistnosti,rezervace,pocetMistnosti,pocetRezervace));
        }
    }
    int validate = validateDate(dateString);
    if (validate == 0){
        cout << "Spatne zadane datum,zkuste to znovu." << endl << endl;
        return(vypisVolneMistnosti(mistnosti,rezervace,pocetMistnosti,pocetRezervace));
    }
    if(validate > 0){
        string htmlSoubor = startCom();
        int year = validate/10000;
        int month = (validate%10000)/100;
        int day = (validate%10000)%100;
        startHTML(htmlSoubor);
        int id = 0;
        htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
        const char* stringToChar = htmlSoubor.c_str();
        ofstream myFile;
        myFile.exceptions (ofstream::badbit );

        try {
            myFile.open (stringToChar, std::ofstream::out | std::ofstream::app);
            myFile << "<h1 align=\"center\")" << day << "." << month << "." << year << "</h1>" << endl;
            myFile << "<table width=\"360\">" << endl << "<tr><th width=\"180\">ID</th><th width=\"180\">PATRO</th><th width=\"180\">JMENO MISTNOSTI</th><th width=\"180\">KAPACITA</th><th width=\"180\">CENA ZA DEN</th></tr>" << endl;
            struct Mistnosti temp;
            int pocetShod = 0;
            for (int i = 0;i < pocetRezervace;i++){
                if (rezervace[i].datum == validate){
                    id = rezervace[i].id;
                    for (int j = 0;j < pocetMistnosti;j++){
                        if (mistnosti[j].id == id){
                            temp = mistnosti[j];
                            mistnosti[j] = mistnosti[pocetShod];
                            mistnosti[pocetShod] = temp;
                            pocetShod++;
                        }
                    }
                }

            }
            for (int j = pocetShod; j < pocetMistnosti; j++){
                    for (int k = pocetShod; k < pocetMistnosti-1-j;k++){
                        if (mistnosti[k].id > mistnosti[k+1].id){
                            temp = mistnosti[k];
                            mistnosti[k] = mistnosti[k+1];
                            mistnosti[k+1] = temp;
                        }
                    }
            }
            for (int l = pocetShod; l < pocetMistnosti; l++){
                            myFile << "<tr><td align=\"center\">";
                            myFile << mistnosti[l].id;
                            myFile << "</td><td align=\"center\">";
                            myFile << mistnosti[l].patro;
                            myFile << "</td><td align=\"center\">";
                            myFile << mistnosti[l].jmenoMistnosti;
                            myFile << "</td><td align=\"center\">";
                            myFile << mistnosti[l].kapacitaSedadel;
                            myFile << "</td><td align=\"center\">";
                            myFile << mistnosti[l].cenaDen;
                            myFile << "</td></tr>" << endl;
            }
        }

        catch(const ofstream::failure& e){
            cout << "Nepovedlo se zapsat do souboru" << endl << endl;
            return(IO_ERROR);
     }
     myFile.close();

    }


return(0);

}
int rezervaceMista(ifstream &souborRezervace,Mistnosti mistnosti[], Rezervace rezervace[]){

return(0);

}
int askForAction(ifstream &souborRezervace, Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti, int pocetRezervace){
 cout << "Zadejte cislo akce, kterou chcete provest" << endl;
 cout << "Rezervace mistnosti - 1" << endl;
 cout << "Vypis volnych mistnosti na dane datum - 2" << endl;
 cout << "Vypis mistnosti podle ceny - 3" << endl;
 cout << "Vypis mistnosti podle poctu mist - 4" << endl;
 cout << "Vypis nejblizsich rezervaci dane mistnosti - 5" << endl << endl;
 int error = 0;
 string cislicko;
 int cisloAkce;

getline(cin,cislicko);

if (cislicko.length() == 1){
    if (cislicko.at(0) < '0' || cislicko.at(0) > '9'){
        cout << "Spatne zadane cislo akce, zkuste to znovu." << endl << endl;
        return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));
    }
    cisloAkce = cislicko.at(0)-'0';
}
else {
    cout << "Spatne zadane cislo akce, zkuste to znovu." << endl << endl;
    return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));
}


 switch(cisloAkce){
    case 1:{
        rezervaceMista(souborRezervace,mistnosti,rezervace);
        break;
    }
    case 2:{
        vypisVolneMistnosti(mistnosti,rezervace,pocetMistnosti,pocetRezervace);
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
        vypisNejblizsiRezervace(mistnosti,rezervace,pocetRezervace,pocetMistnosti);
        break;
    }

    default:{
        cout << "Spatne zadane cislo akce, zkuste to znovu." << endl << endl;
        error++;
        break;
    }
 }
 if (error > 0){
    cout << "Spatne zadane cislo akce, zkuste to znovu." << endl << endl;
    return (askForAction(souborRezervace,mistnosti,rezervace,pocetMistnosti, pocetRezervace));

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
    cout << askForAction(fileRezervace,mistnosti,rezervace,pocetMistnosti,pocetRezervace);


    delete[] mistnosti;
    delete[] rezervace;
    return 0;
}
