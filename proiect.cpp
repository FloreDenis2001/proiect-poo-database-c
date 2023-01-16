#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
// CREATE TABLE nume_tabel ((nume_coloană_1, tip, dimensiune, valoare_implicită), (nume_coloană_2, tip, dimensiune, valoare_implicită))
using namespace std;
class Inregistrari
{

private:
    int numarParametri;
    string *denumiri;

public:
    Inregistrari() { cout << "Constructoru fara parametri" << endl; }

    Inregistrari(int numarParametri, string *denumiri)
    {
        this->numarParametri = numarParametri;

        if (numarParametri > 0 && denumiri != NULL)
        {
            this->denumiri = new string[this->numarParametri];
            for (int i = 0; i < this->numarParametri; i++)
            {
                this->denumiri[i] = denumiri[i];
            }
        }
    }

    void afisare()
    {
        cout << "\n-----------------";
        cout << "\nNumar Parametri :" << this->numarParametri;
        if (this->numarParametri > 0 && this->denumiri != nullptr)
        {
            cout << "\nDenumirI :  ";
            for (int i = 0; i < this->numarParametri; i++)
                cout << "\nColoana [" << i + 1 << "]= " << this->denumiri[i] << " " << endl;
        }
        cout << "\n-------------";
    }

    Inregistrari(const Inregistrari &in)
    {
        this->numarParametri = in.numarParametri;

        if (in.numarParametri > 0 && in.denumiri != NULL)
        {
            this->denumiri = new string[this->numarParametri];
            for (int i = 0; i < this->numarParametri; i++)
            {
                this->denumiri[i] = in.denumiri[i];
            }
        }
    }

    ~Inregistrari()
    {
        if (numarParametri > 0 && denumiri != NULL)
        {
            delete[] this->denumiri;
        }
    }
};

class Tabel
{
private:
    string numetabel = "tabel1";
    int numarColoane = 0;
    string *tipColoana = NULL;
    string *dimensiuneColoana = NULL;
    string *numeColoana = NULL;
    string *valoareImplicita = NULL;
    int numarInregistrariTabel = 0;
    Inregistrari **inregistrari = NULL;

public:
    Tabel()
    {
        cout << "Constructor fara parametri " << endl;
    }

    Tabel(string numetabel, int numarColoane, string *numeColoana, int numarInregistrariTabel,
          string *tipColoana, string *dimensiuneColoana, string *valoareImplicita, Inregistrari **inregistrari)
    {
        cout << "Constructorul cu parametrii " << endl;
        this->numetabel = numetabel;

        // PENTRU COLOANE
        if (numarColoane > 0 && numeColoana != NULL && tipColoana != NULL && dimensiuneColoana != NULL && valoareImplicita != NULL)
        {
            this->numarColoane = numarColoane;
            this->numeColoana = new string[this->numarColoane];
            this->tipColoana = new string[this->numarColoane];
            this->dimensiuneColoana = new string[this->numarColoane];
            this->valoareImplicita = new string[this->numarColoane];

            for (int i = 0; i < this->numarColoane; i++)
            {
                this->numeColoana[i] = numeColoana[i];
                this->tipColoana[i] = tipColoana[i];
                this->dimensiuneColoana[i] = dimensiuneColoana[i];
                this->valoareImplicita[i] = valoareImplicita[i];
            }
        }
        // PENTRU INREGISTRARI HAS-A
        if (inregistrari != NULL && numarInregistrariTabel > 0)
        {
            this->inregistrari = new Inregistrari *[this->numarInregistrariTabel];
            this->numarInregistrariTabel = numarInregistrariTabel;
            for (int i = 0; i < this->numarInregistrariTabel; i++)
            {
                // deep cpy
                this->inregistrari[i] = new Inregistrari(*inregistrari[i]);
                // shallow copy this->inregistrari[i]=inregistrari[i];
            }
        }
    }

    Tabel(const Tabel &t)
    {
        this->numetabel = t.numetabel;

        // PENTRU COLOANE
        if (t.numarColoane > 0 && t.numeColoana != NULL && t.tipColoana != NULL && t.dimensiuneColoana != NULL && t.valoareImplicita != NULL)
        {
            this->numarColoane = t.numarColoane;
            this->numeColoana = new string[this->numarColoane];
            this->tipColoana = new string[this->numarColoane];
            this->dimensiuneColoana = new string[this->numarColoane];
            this->valoareImplicita = new string[this->numarColoane];

            for (int i = 0; i < this->numarColoane; i++)
            {
                this->numeColoana[i] = t.numeColoana[i];
                this->tipColoana[i] = t.tipColoana[i];
                this->dimensiuneColoana[i] = t.dimensiuneColoana[i];
                this->valoareImplicita[i] = t.valoareImplicita[i];
            }
        }

        if (t.inregistrari != NULL && t.numarInregistrariTabel > 0)
        {
            this->inregistrari = new Inregistrari *[this->numarInregistrariTabel];
            this->numarInregistrariTabel = t.numarInregistrariTabel;
            for (int i = 0; i < this->numarInregistrariTabel; i++)
            {
                this->inregistrari[i] = new Inregistrari(*t.inregistrari[i]);
            }
        }
    }

    void afisare()
    {
        cout << "\n-----------------";
        cout << "\nDenumire tabel :" << this->numetabel;
        if (this->numarColoane > 0 && this->numeColoana != nullptr)
        {
            cout << "\nNumar Coloane : " << this->numarColoane;
            cout << "\nDenumire coloane :  ";
            for (int i = 0; i < this->numarColoane; i++)
            {
                cout << "\nColoana Nume [" << i + 1 << "]= " << this->numeColoana[i] << " " << endl;
                cout << "\nColoana Tip [" << i + 1 << "]= " << this->tipColoana[i] << " " << endl;
                cout << "\nColoana Dimensiune [" << i + 1 << "]= " << this->dimensiuneColoana[i] << " " << endl;
                cout << "\nColoana Valori [" << i + 1 << "]= " << this->valoareImplicita[i] << " " << endl;
            }
        }

        
        if (this->inregistrari != NULL && this->numarInregistrariTabel > 0)
        {
            for (int i = 0; i < this->numarInregistrariTabel; i++)
            {
              cout<<"\n Inregistrare "<<i+1<<this->inregistrari[i];
            }
        }
        cout << "\n-------------";
    }

    /* --------- GETTERI TABEL -------------*/
    string getNumeTabel()
    {
        return this->numetabel;
    }

    int getnumarColoane()
    {
        return this->numarColoane;
    }

    string *getNumeColoana()
    {
        return this->numeColoana;
    }

    /* --------- SETTERI TABEL -------------*/
    void setNumeTabel(string nume)
    {
        this->numetabel = nume;
    }

    void setNumarColoane()
    {
    }

    Tabel &operator=(const Tabel &t)
    {
        if (this != &t)
        {
            delete[] this->numeColoana;
            cout << "\nOperatorul egal" << endl;
            this->numetabel = t.numetabel;
            this->numarColoane = t.numarColoane;
            this->numeColoana = new string[this->numarColoane];
            for (int i = 0; i < this->numarColoane; i++)
            {
                this->numeColoana[i] = t.numeColoana[i];
            }
        }
        return *this;
    }

    ~Tabel()
    {

        if (this->numarColoane > 0 && this->numeColoana != nullptr)
        {
            cout << "\nDestructorul a fost apelat" << endl;
            delete[] this->numeColoana;
        }
    }
};

vector<string> splitfunction(string comanda, const char del)
{

    string token;
    stringstream ss(comanda);

    vector<string> results;
    while (getline(ss, token, del))
    {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        results.push_back(token);
    }

    return results;
}

string removeDel(string results)

{
    string output;
    for (int i = 0; i < results.length(); i++)
    {
        if (results[i] != '(' && results[i] != ')')
        {
            output += results[i];
        }
    }
    return output;
}

int main()
{
    int numarParametri;
    cin >> numarParametri;
    string *denumiri = new string[numarParametri];
    for (int i = 0; i < numarParametri; i++)
    {
        cin >> denumiri[i];
    }
    Inregistrari in(4, denumiri);
    in.afisare();

    string numeTabel = "Denis";
    int numarColoane = 2;
    string *numeColoana = new string[numarColoane];
    numeColoana[0] = "ID";
    numeColoana[1] = "MODEL";
    string *tipColoana = new string[numarColoane];
    tipColoana[0] = "INT";
    tipColoana[1] = "VARCHAR";
    string *dimensiuneColoana = new string[numarColoane];
    dimensiuneColoana[0] = "4";
    dimensiuneColoana[1] = "25";
    string *valoareColoana = new string[numarColoane];
    valoareColoana[0] = "0";
    valoareColoana[1] = "noName";
    int numarInregistrariTabel = 1;

    Inregistrari **inregistrari = new Inregistrari *[numarInregistrariTabel];
    *inregistrari[0] = in;

    Tabel proba(numeTabel, numarColoane, numeColoana, numarInregistrariTabel,
                tipColoana, dimensiuneColoana, valoareColoana, inregistrari);
    proba.afisare();

    /* string comanda;
     getline(cin, comanda);
     vector<string> results = splitfunction(comanda, ' ');

     if (results[0].compare("create") == 0)
     {

         if (results[1] != "" && results[1].compare("table") == 0)
         {
             if (results[2] != "")
             {
                 string nameOfTable = results[2];
                 string valoriColoane = removeDel(results[3]);
                 vector<string> detalicolumn = splitfunction(valoriColoane, ',');
                 int nrcoloane = detalicolumn.size() / 4;
                 if (detalicolumn.size() % 4 == 0)
                 {
                     vector<string> numecoloane;
                     vector<string> tipulcoloanei;
                     vector<string> dimensiunecoloana;
                     vector<string> valoriImplicite;
                     int j = 0;
                     for (int i = 0; i < detalicolumn.size(); i = i + 4)
                     {
                         cout << "COLOANA : " << detalicolumn[i];
                         numecoloane.push_back(detalicolumn[i]);
                     }

                     for (int i = 1; i < detalicolumn.size(); i = i + 4)
                     {
                         tipulcoloanei.push_back(detalicolumn[i]);
                     }

                     for (int i = 2; i < detalicolumn.size(); i = i + 4)
                     {
                         dimensiunecoloana.push_back(detalicolumn[i]);
                     }

                     for (int i = 3; i < detalicolumn.size(); i = i + 4)
                     {
                         valoriImplicite.push_back(detalicolumn[i]);
                     }

                     for (int i = 0; i < nrcoloane; i++)
                     {
                         cout << "---------------" << endl;
                         cout << numecoloane[i] << endl;
                         cout << tipulcoloanei[i] << endl;
                         cout << dimensiunecoloana[i] << endl;
                         cout << valoriImplicite[i] << endl;
                     }

                     //  Tabel(nameOfTable,nrcoloane,numecoloane)
                 }
                 else
                 {
                     cout << "Erroare de sintaxa ! ";
                 }
             }
             else
             {
                 cout << "Erroare de sintaxa ! ";
             }
         }
         else
         {
             cout << "Erroare de sintaxa ! ";
         }
     } else {
          cout<<"Erroare de sintaxa ! ";
     }*/

    return 0;
}