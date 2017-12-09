#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
#define OKAY        0
#define IO_ERROR    1

/** \brief This is a brief description.
 *
 * \param	p1 The first parameter.
 * \param	p2 The second parameter.
 * \return	Return value.
 *
 * This is a detailed description.
 */
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

int pocetRadku(const char* soubor){

   ifstream fileMistnosti(soubor);
   int radky = 0;
   string nacteno;
   if (fileMistnosti){




        while (getline(fileMistnosti,nacteno)){
            radky++;


        }
   }
   else {
        cout << "Soubor se nenacetl" << endl;
        return(0);
   }
    return (radky);
}
int nactiMistnosti (const char* soubor,Mistnosti mistnosti[]){

    ifstream fileStream(soubor);

    if (fileStream){
        string radek,token;
        char ch;
        int i = 0;

        while(getline(fileStream,radek)){
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
    else {
        cout << "Soubor se nenacetl" << endl;
        return(IO_ERROR);
    }


return(OKAY);
}
int nactiRezervace (const char* souborRezervace, Rezervace rezervace[]){
    ifstream fileStream(souborRezervace);
    if (fileStream){
    string radek,token;
    char ch;
    int i = 0;

         while(getline(fileStream,radek)){
            istringstream ss(radek);
            ss >> rezervace[i].id;
            ss >> ch;
            ss >> rezervace[i].datum;
            i++;

        }
    }
    else {
        cout << "Soubor se nenacetl" << endl;
        return(IO_ERROR);
    }


return (OKAY);
}
int getTime(){

        tm* my_time;
        time_t t = time(NULL);
        my_time = localtime(&t);
        int currentYear = 1900+my_time->tm_year;
        int currentMonth = (my_time ->tm_mon)+1;
        int currentDay = my_time ->tm_mday;
        int currentDate = (currentYear*10000)+(currentMonth*100)+currentDay;
        return (currentDate);
}
int zadavaniCisel(int typOperace,int druhVypoctu){
    string danyString;
    getline(cin,danyString);
    int cislo = 0;
    int length = danyString.length();

    if (druhVypoctu == 1){
            typOperace = length;
    }



    if (druhVypoctu == 0 || druhVypoctu == 2){
        if (length != typOperace){
                cout << "Spatne zadana informace, zkuste to znovu." << endl;
                return (zadavaniCisel(typOperace,druhVypoctu));
        }
    }
    if (druhVypoctu == 1){
        if (length < 1){
                cout << "Spatne zadana informace, zkuste to znovu." << endl;
                return (zadavaniCisel(typOperace,druhVypoctu));
        }
    }
    for (int i = 0; i < typOperace; i++){
        if (danyString.at(i) < '0' || danyString.at(i) > '9'){

            cout << "Spatne zadana informace, zkuste to znovu." << endl;
            return (zadavaniCisel(typOperace,druhVypoctu));
        }
    }

    cislo = atoi(danyString.c_str());

    if (druhVypoctu == 2){

        int year = cislo/10000;
        int month = (cislo%10000)/100;
        int day = (cislo%10000)%100;

            if (cislo < getTime()){
                cout << "Spatne zadana informace, zkuste to znovu." << endl;
                return (zadavaniCisel(typOperace,druhVypoctu));
            }
            if ((month == 1 && day > 31) || (year%4 == 0 && month == 2 && day > 29) || (year%4 != 0 && month == 2 && day > 28) || (month == 3 && day > 31) || (month == 4 && day > 30) || (month == 5 && day > 31) || (month == 6 && day > 30) || (month == 7 && day > 31) || (month == 8 && day > 31) || (month == 9 && day > 30) || (month == 10 && day > 31) || (month == 11 && day > 30) || (month == 12 && day > 31)){
                cout << "Spatne zadana informace, zkuste to znovu." << endl;
                return (zadavaniCisel(typOperace,druhVypoctu));
            }
    }

return(cislo);
}
string getSoubor(int mistnostiNeboRezervace){

    string CSVsoubor;
    int error = 0;
    if (mistnostiNeboRezervace == 0){
        cout << "Zadejte jmeno CSV souboru, ktery se nachazi ve slozce vstupnidata a obsahuje vsechny mistnosti. ";
        cout << endl << "Zadavejte ve formatu vasejmeno.csv" << endl;
    }
    if (mistnostiNeboRezervace == 1){
        cout << "Zadejte jmeno CSV souboru, ktery se nachazi ve slozce vstupnidata a obsahuje rezervace mistnosti. ";
        cout << endl << "Zadavejte ve formatu vasejmeno.csv" << endl;
    }

    getline (cin,CSVsoubor);
    int length = CSVsoubor.length();
    if (length < 5){
       error++;
    }
    if (CSVsoubor.at(length-1)!= 'v' || CSVsoubor.at(length-2) != 's' || CSVsoubor.at(length-3) != 'c' || CSVsoubor.at(length-4) != '.')
        error++;
    for (int i = 0; i < length-5; i++){
        if (CSVsoubor.at(i) < 46 || (CSVsoubor.at(i) > 57 && CSVsoubor.at(i) <65) || (CSVsoubor.at(i) > 90 && CSVsoubor.at(i) < 97 && CSVsoubor.at(i) != 95 && CSVsoubor.at(i) != 92) || CSVsoubor.at(i) > 122){
            error++;
            break;
        }
    }

    if (error > 0){
        cout << "Spatne zadane jmeno souboru, Zkuste to znovu" << endl;
        return (getSoubor(mistnostiNeboRezervace));
    }
    return (CSVsoubor);
}
string startCom(){
    string htmlSoubor;
    int error = 0;
    cout << "Zadejte jmeno souboru, do ktereho chcete ulozit informace o nejblizsich rezervacich." << endl;
    cout << "Jmeno souboru muze obsahovat:" << endl;
    cout << "mala i velka pismena, cislice, znak tecky,zpetneho lomitka,dopredneho lomitka nebo podtrzitka." << endl;
    cout << "Zadavejte ve formatu vasejmenosouboru.html" << endl;
    getline(cin,htmlSoubor);
    int length = htmlSoubor.length()-1;
    if (length+1 < 6){
        cout << "Spatne zadane jmeno, Zkuste to znovu" << endl;
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
        cout << "Spatne zadana adresa, Zkuste to znovu" << endl;
        return (startCom());

        }

    cout << "HTML soubor byl vygenerovan a informace do nej byly zapsany" << endl;

return(htmlSoubor);
}

int zapisDoCSV(Rezervace rezervace[], int id, int date){

    const char* soubor = "..\\vstupnidata\\rezervace.csv";

    ofstream myFile;
    myFile.exceptions (ofstream::failbit |ofstream::badbit);
     try {
        myFile.open (soubor, std::ofstream::out | std::ofstream::app);
        myFile << id << ";" << date << endl;
     }
     catch(const ofstream::failure& e){
        cout << "nastala chyba v zapisu do souboru." << endl;
        return(IO_ERROR);
     }
     myFile.close();

    cout << "Mistnost uspesne zarezervovana" << endl;

return(OKAY);
}


int zapisDoHTML(Mistnosti mistnosti[], int pocetMistnosti,int datum,string htmlSoubor,const char* souborRezervace){

    ifstream fileRezervace(souborRezervace);
    int pocetRezervace = pocetRadku(souborRezervace);
    Rezervace* rezervace = new Rezervace[pocetRezervace];
    nactiRezervace (souborRezervace,rezervace);
    int currentDate = getTime();


    int prvniVysledek = 0;

    htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions (ofstream::failbit | ofstream::badbit);

     try {
        myFile.open (stringToChar, std::ofstream::out);
        myFile << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">" << endl; //starting html
        myFile << "<html>" << endl << "<head>" << endl << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">" << endl << "<title>C++</title>" << endl << "</head>" << endl;
        myFile << "<body>" << endl;
        myFile << "<table width=\"900\">" << endl << "<tr><th width=\"180\">ID</th><th width=\"180\">PATRO</th><th width=\"180\">CISLO MISTNOSTI</th><th width=\"180\">KAPACITA</th><th width=\"180\">CENA ZA DEN</th><th width=\"180\">REZERVOVANO</th></tr>" << endl;

        struct Rezervace temp;
         for(int i = 0; i < pocetRezervace;i++){
            for (int j = 0; j < pocetRezervace-i-1; j++){
                if (rezervace[j].datum > rezervace[j+1].datum){
                    temp = rezervace[j];
                    rezervace[j] = rezervace[j+1];
                    rezervace[j+1] = temp;

                }
            }

        }
            for (int m = 0; m < pocetRezervace; m++){
                for (int n = 0; n < pocetRezervace-m-1; n++){
                    if (rezervace[n].id > rezervace[n+1].id && rezervace[n].datum == rezervace[n+1].datum){
                        temp = rezervace[n];
                        rezervace[n] = rezervace[n+1];
                        rezervace[n+1] = temp;

                    }
                }
            }
            for (int p = 0; p < pocetRezervace; p++){
                if (rezervace[p].datum >= currentDate){
                    prvniVysledek = p;
                    break;
                }
            }

        for (int i = prvniVysledek; i < prvniVysledek+15; i++){

                int datumInt = rezervace[i].datum;
                int yearDatum = datumInt/10000;
                int monthDatum = (datumInt%10000)/100;
                int dayDatum = ((datumInt%10000)%100);
                int id = rezervace[i].id-1;

                myFile << "<tr><td align=\"center\">";
                myFile << mistnosti[id].id;
                myFile << "</td><td align=\"center\">";
                myFile << mistnosti[id].patro;
                myFile << "</td><td align=\"center\">";
                myFile << mistnosti[id].jmenoMistnosti;
                myFile << "</td><td align=\"center\">";
                myFile << mistnosti[id].kapacitaSedadel;
                myFile << "</td><td align=\"center\">";
                myFile << mistnosti[id].cenaDen;
                myFile << "</td><td align=\"center\">";
                myFile << dayDatum << "." << monthDatum << "." << yearDatum;
                myFile << "</td></tr>" << endl;
           }

        myFile << "</table>" << endl;
        myFile << "</body>" << endl;
        myFile << "</html>" << endl;
     }
     catch(const ofstream::failure& e){
        cout << "nastala chyba v zapisu do souboru." << endl;
        return(IO_ERROR);
     }
     myFile.close();

return (0);
}


int vypisPrvnichX(Mistnosti docasneMistnosti[], int pocetCiselMensich){

        cout << "ID" << "\t" << "PATRO" << "\t" << "JMENO" << "\t" << "MISTA" << "\t" << "CENA" << endl;
       for (int i = 0; i < pocetCiselMensich; i++){

            cout << docasneMistnosti[i].id << "\t" << docasneMistnosti[i].patro << "\t" << docasneMistnosti[i].jmenoMistnosti << "\t" << docasneMistnosti[i].kapacitaSedadel << "\t" << docasneMistnosti[i].cenaDen << endl;
       }

return (0);
}





int vypisNejblizsiRezervace(Mistnosti mistnosti[],Rezervace rezervace[],int pocetRezervace,int pocetMistnosti){
    cout << "Zadejte cislo mistnosti" << endl;

    int cislo = zadavaniCisel(3,0);

    int id = 0;
    for (int i = 0; i < pocetMistnosti; i++){
        if (mistnosti[i].jmenoMistnosti == cislo){
            id = mistnosti[i].id;
            break;
        }

    }
    if (id == 0 ){
        cout << "Tato mistnost neexistuje, zkuste to znovu." << endl;
        return(vypisNejblizsiRezervace(mistnosti,rezervace,pocetRezervace,pocetMistnosti));

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
    if (pocetRezervaciDen > 0){
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
    if (pocetRezervaciDen == 0){
        cout << "Tato mistnost neni vubec rezervovana" << endl;
        return (0);
    }
    string htmlSoubor = startCom();
    htmlSoubor = "..\\vystupnidata\\" + htmlSoubor;
    const char* stringToChar = htmlSoubor.c_str();
    ofstream myFile;
    myFile.exceptions (ofstream::failbit | ofstream::badbit);
    try {
        myFile.open (stringToChar, std::ofstream::out);
        myFile << "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">" << endl;
        myFile << "<html>" << endl << "<head>" << endl << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">" << endl << "<title>C++</title>" << endl << "</head>" << endl;
        myFile << "<body>" << endl;
        myFile << "<h1 align=\"center\"> REZERVACE MISTNOSTI " << mistnosti[id-1].jmenoMistnosti << "</h1>" << endl;
        myFile << "<table width=\"100%\">" << endl << "<tr><th width=\"20%\">DEN REZERVACE</th></tr>" << endl;
        id = rezervace[0].id;
        cout << "Nejblizsi rezervace mistnosti " << mistnosti[id-1].jmenoMistnosti << endl;
        for (int i = 0; i < pocetRezervaciDen; i++){

            int datumInt = rezervace[i].datum;
            int yearDatum = datumInt/10000;
            int monthDatum = (datumInt%10000)/100;
            int dayDatum = ((datumInt%10000)%100);
            myFile << "<tr><td align=\"center\">";
            myFile << dayDatum << "." << monthDatum << "." << yearDatum;
            myFile << "</td></tr>" << endl;
            cout << dayDatum << "." << monthDatum << "." << yearDatum << endl;

        }

           cout << endl;

    }
    catch(const ofstream::failure& e){
        cout << "nastala chyba v zapisu do souboru." << endl;
        return(IO_ERROR);
    }


return(0);

}


int vypisPodleParametru(Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti,int pocetRezervace){

    cout << "Maximalni cena:" << endl;
    int maxCena = zadavaniCisel(0,1);

    cout << "Minimalni kapacita:" << endl;
    int minPocetMist = zadavaniCisel(0,1);

    cout << "Datum, pro ktere chcete vypsat mistnosti:" << endl;
    int datum = zadavaniCisel(8,2);

    int pocetCisel = 0;
    int id = 0;
    int pocetZabrane = 0;
    struct Mistnosti temp;

    for (int i = 0; i < pocetRezervace; i++){
        if (rezervace[i].datum == datum){
            id = rezervace[i].id-1;
            temp = mistnosti[id];
            mistnosti[id] = mistnosti[pocetMistnosti-1-pocetZabrane];
            mistnosti[pocetMistnosti-1-pocetZabrane] = temp;
            pocetZabrane++;
        }
    }

    int pocetZbytek = pocetMistnosti - pocetZabrane;
    Mistnosti* docasneMistnosti = new Mistnosti[pocetZbytek];

    for (int k = 0; k < pocetZbytek;k++){
        docasneMistnosti[k] = mistnosti[k];
    }

        for (int m = 0; m < pocetZbytek; m++){
            if (docasneMistnosti[m].cenaDen <= maxCena && docasneMistnosti[m].kapacitaSedadel >= minPocetMist){

                temp = docasneMistnosti[m];
                docasneMistnosti[m] = docasneMistnosti[pocetCisel];
                docasneMistnosti[pocetCisel] = temp;
                pocetCisel++;
            }
        }
        vypisPrvnichX(docasneMistnosti,pocetCisel);

    delete[] docasneMistnosti;
return(0);

}

int rezervaceMista(Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti,int pocetRezervace, const char* souborRezervace){

    cout << "Zadejte cislo mistnosti" << endl;
    int cislo = zadavaniCisel(3,0);

    int id = 0;
    int good = 0;

    for (int k = 0; k < pocetMistnosti;k++){
        if (mistnosti[k].jmenoMistnosti == cislo){
            id = mistnosti[k].id;
            good++;
            break;
        }

    }
    if (good == 0){
        cout << "Dana mistnost neexistuje, zkuste to znovu" << endl;
        return (rezervaceMista(mistnosti,rezervace,pocetMistnosti,pocetRezervace, souborRezervace));
    }

    cout << "Zadejte datum, pro ktere chcete rezervovat zadanou mistnost ve formatu YYYYMMDD" << endl;
    int validate = zadavaniCisel(8,2);

    if(validate > 0){

        for (int m = 0; m < pocetRezervace; m++){
                if (rezervace[m].id == id && rezervace[m].datum == validate){
                    cout << "Mistnost je v tomto datu jiz rezervovana." << endl;
                    return (rezervaceMista(mistnosti,rezervace,pocetMistnosti,pocetRezervace,souborRezervace));
                }

        }

        int error = zapisDoCSV(rezervace,id,validate);
        if (error == 1){
            return(IO_ERROR);
        }
        string htmlSoubor = startCom();
        zapisDoHTML(mistnosti,pocetMistnosti,id,htmlSoubor,souborRezervace);


    }

return(0);

}
int askForAction(Mistnosti mistnosti[], Rezervace rezervace[], int pocetMistnosti, int pocetRezervace,const char* souborRezervace){
 cout << "Zadejte cislo akce, kterou chcete provest:" << endl;
 cout << "Rezervace mistnosti - 1" << endl;
 cout << "Vypis volnych mistnosti na dane datum podle ceny,poctu mist - 2" << endl;
 cout << "Vypis nejblizsich rezervaci dane mistnosti - 3" << endl;

 int cisloAkce = zadavaniCisel(1,0);
 int error = 0;
 bool breakTheCode = false;

 switch(cisloAkce){
    case 1:{
        rezervaceMista(mistnosti,rezervace,pocetMistnosti,pocetRezervace,souborRezervace);
        breakTheCode = true;
        break;
    }
    case 2:{
        vypisPodleParametru(mistnosti,rezervace,pocetMistnosti,pocetRezervace);
        break;
    }
    case 3:{
        vypisNejblizsiRezervace(mistnosti,rezervace,pocetRezervace,pocetMistnosti);
        break;
    }

    default:{
        error++;
        break;
    }
 }
 if (error > 0){
    cout << "Spatne zadane cislo akce, zkuste to znovu." << endl;
    return (askForAction(mistnosti,rezervace,pocetMistnosti, pocetRezervace,souborRezervace));

 }


if (!breakTheCode)
    return(askForAction(mistnosti,rezervace,pocetMistnosti, pocetRezervace,souborRezervace));

return (0);

}


int main()
{
    string csvMistnosti = "..\\vstupnidata\\" + getSoubor(0);
    string csvRezervace = "..\\vstupnidata\\"+ getSoubor(1);

    const char* souborMistnosti = csvMistnosti.c_str();
    const char* souborRezervace = csvRezervace.c_str();

   /* ifstream fileMistnosti(souborMistnosti);
    ifstream fileRezervace(souborRezervace);*/

    int pocetMistnosti = pocetRadku(souborMistnosti);
    if (pocetMistnosti == 0){
        return (IO_ERROR);
    }
    int pocetRezervace = pocetRadku(souborRezervace);
    if (pocetRezervace == 0){
        return(IO_ERROR);
    }

    Mistnosti* mistnosti = new Mistnosti[pocetMistnosti];
    Rezervace* rezervace = new Rezervace[pocetRezervace];
    int i = nactiRezervace (souborRezervace,rezervace);
    if (i == 1){
        return (IO_ERROR);
    }
    int j = nactiMistnosti (souborMistnosti,mistnosti);
    if (j == 1){
        return (IO_ERROR);
    }

    askForAction(mistnosti,rezervace,pocetMistnosti,pocetRezervace,souborRezervace);

    delete[] mistnosti;
    delete[] rezervace;
    return 0;
}
