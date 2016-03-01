/*================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2016

Inlämningsuppgift nr 6B

Namn: Olle Claeson

Personummer: 820710-2750

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): xcode / 7.2
s
Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : El Capitan / 10.11.2

Jag har arbetat ungefär 6 timmar med denna uppgift

================================================================================
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

/******************
* Global Constants
******************/

/******************
* Pre-class declarations
******************/
class Transaktion;
class TransaktionsLista;
class Person;
class PersonLista;

/******************
* Class declarations
******************/
class Transaktion
{
	private:
		string datum;
		string typ;
		string namn;
		double belopp;
		int ant_kompisar;
		string *kompisar;

	public:	
		Transaktion();
		~Transaktion();
		Transaktion& operator=(const Transaktion &t);
		string haemta_namn();
		double haemta_belopp();
		int haemta_ant_kompisar();
		bool finnsKompis(string namnet);
		bool laesEnTrans(istream &is);
		void skrivEnTrans(ostream &os);
};

class TransaktionsLista
{
	private:
		Transaktion *trans;
		int antalTrans;

	public:
		TransaktionsLista();
		~TransaktionsLista();
		void laesin(istream &is);
		void laesin_single(istream &is);
		void skrivut(ostream &os);
		void laggTill(Transaktion &t);
		double totalkostnad();
		double liggerUteMed(string namnet);
		double aerSkyldig(string namnet);
		PersonLista fixaPersoner();
};

class Person
{
	private:
		string namn;
		double betalat_andras;
		double skyldig;

	public:
		Person();
		Person(string n, double b, double s);
		Person& operator=(const Person &p);
		string haemta_namn();
		double haemta_betalat();
		double haemta_skyldig();
		void skrivUt();
};

class PersonLista
{
	private:
		int antal_pers;
		Person *pers;
	
	public:
		PersonLista();
		~PersonLista();
		PersonLista& operator=(const PersonLista &pl);
		void laggTillEn(Person pny);
		void skrivUtOchFixa();
		double summaSkyldig();
		double summaBetalat();
		bool finnsPerson(const string &namn);
};

/******************
* Class Implementation
******************/
Transaktion::Transaktion()
{
	datum = "";
	typ = "";
	namn = "";
	belopp = -1;
	ant_kompisar = -1;
	kompisar = 0;
}

Transaktion::~Transaktion()
{
	delete[] kompisar;
}

Transaktion& Transaktion::operator=(const Transaktion &t)
{
	if(this != &t)
	{
		delete[] kompisar;
		datum = t.datum;
		typ = t.typ;
		namn = t.namn;
		belopp = t.belopp;
		ant_kompisar = t.ant_kompisar;
		kompisar = new string[ant_kompisar];
		for(int i = 0; i < ant_kompisar; i++)
			kompisar[i] = t.kompisar[i];
	}
	return *this;
}

string Transaktion::haemta_namn()
{
	return namn;
}

double Transaktion::haemta_belopp()
{
	return belopp;
}

int Transaktion::haemta_ant_kompisar()
{
	return ant_kompisar;
}

bool Transaktion::finnsKompis(string namnet)
{
	for(int i = 0; i < ant_kompisar; i++)
	{
		if(kompisar[i] == namnet)
			return true;
	}
	return false;
}

bool Transaktion::laesEnTrans(istream &is)
{
	int counter = 0;
	string trans = "";
	string bla = "";

	is >> datum;
 
  if(is.eof())
		return false;
 
  is >> typ;
  is >> namn;
  is >> belopp;
  is >> ant_kompisar;

	delete[] kompisar; 
	kompisar  = new string[ant_kompisar]; 
  for(int i = 0; i < ant_kompisar; i++)
    is >> kompisar[i];
 
  return true;
}

void Transaktion::skrivEnTrans(ostream &os)
{
	os << datum << " ";
	os << typ << " ";
	os << namn << " ";
	os << belopp << " ";
	os << ant_kompisar << " ";

	for(int i = 0; i < ant_kompisar; i++)
		os << kompisar[i] << " ";

	os << endl;
}

TransaktionsLista::TransaktionsLista()
{
	antalTrans = 0;
	trans = new Transaktion[antalTrans];
}

TransaktionsLista::~TransaktionsLista()
{
	delete[] trans;
}

void TransaktionsLista::laesin(istream &is)
{
	Transaktion t;
	while(t.laesEnTrans(is))
		laggTill(t);
}
	
void TransaktionsLista::laesin_single(istream &is)
{
	is.ignore();
	Transaktion t;
	t.laesEnTrans(is);
	laggTill(t);
}

void TransaktionsLista::skrivut(ostream &os)
{
	for(int i = 0; i < antalTrans; i++)
		trans[i].skrivEnTrans(os);
}

void TransaktionsLista::laggTill(Transaktion &t)
{
	Transaktion *nt = new Transaktion[antalTrans+1];
	for(int i = 0; i < antalTrans; i++)
		nt[i] = trans[i];
	
	nt[antalTrans] = t;
	antalTrans++;
	delete[] trans;
	trans = nt;
}

double TransaktionsLista::totalkostnad()
{
	double sum = 0;

	for(int i = 0; i < antalTrans; i++)
		sum += trans[i].haemta_belopp();

	return sum;
}

double TransaktionsLista::liggerUteMed(string namnet)
{
	double sum = 0;	

	for(int i = 0; i < antalTrans; i++)
	{
		if(trans[i].haemta_namn() == namnet)
		{
			int antal = trans[i].haemta_ant_kompisar();	
			double belopp = trans[i].haemta_belopp();
			double val = (belopp / (antal+1)) * antal;  
			sum += val;	
		}
	}

	return sum;
}

double TransaktionsLista::aerSkyldig(string namnet)
{
	double sum = 0;

	for(int i = 0; i < antalTrans; i++)
	{
		if(trans[i].finnsKompis(namnet))
			sum += trans[i].haemta_belopp() / (trans[i].haemta_ant_kompisar() + 1);
	}

	return sum;
}

PersonLista TransaktionsLista::fixaPersoner()
{
	PersonLista pl;
	for(int i = 0; i < antalTrans; i++)
	{
		string namn = trans[i].haemta_namn();
		if(!pl.finnsPerson(namn))
		{
			double skyldig = aerSkyldig(namn);
			double betalat = liggerUteMed(namn);

			Person p(namn, betalat, skyldig);
			pl.laggTillEn(p);
		}
	}
	return pl;
}

Person::Person()
{
	namn = "";
	betalat_andras = -1;
	skyldig = -1;
}

Person::Person(string n, double b, double s)
{
	namn = n;
	betalat_andras = b;
	skyldig = s;
}

Person& Person::operator=(const Person &p)
{
	if(this != &p)
	{
		namn = p.namn;
		betalat_andras = p.betalat_andras;
		skyldig = p.skyldig;
	}
	return *this;
}

string Person::haemta_namn()
{
	return namn;
}

double Person::haemta_betalat()
{
	return betalat_andras;
}

double Person::haemta_skyldig()
{
	return skyldig;
}	

void Person::skrivUt()
{
	double value = betalat_andras - skyldig;

	cout << namn << " ligger ute med: " << betalat_andras << " och är skyldig " << skyldig << ". ";
	if(value > 0)
		cout << "Skall ha " << value << " från potten!" << endl;
	else
		cout << "Skall lägga " << abs(value) << " till potten!" << endl;
}

PersonLista::PersonLista()
{
	antal_pers = 0;
	pers = new Person[antal_pers];
}

PersonLista::~PersonLista()
{
	delete[] pers;
}

PersonLista& PersonLista::operator=(const PersonLista &pl)
{
	if(this != &pl)
	{
		delete[] pers;
		antal_pers = pl.antal_pers;
		pers = new Person[antal_pers];
		for(int i = 0; i < antal_pers; i++)
			pers[i] = pl.pers[i];
	}
	return *this;
}

void PersonLista::laggTillEn(Person pny)
{
	Person *temp = new Person[antal_pers+1];
	for(int i = 0; i < antal_pers; i++)
	{
		temp[i] = pers[i];
	}	
	delete[] pers;
	string n = pny.haemta_namn();
	double b = pny.haemta_betalat();
	double s = pny.haemta_skyldig();
	Person p = Person(n, b, s);	
	temp[antal_pers] = p;
	antal_pers++;
	pers = temp;
}

void PersonLista::skrivUtOchFixa()
{
	double summaIn = 0;
	double summaUt = 0;
	double tmp = 0;	
	
	for(int i = 0; i < antal_pers; i++)
	{
		pers[i].skrivUt();
		tmp = pers[i].haemta_betalat() - pers[i].haemta_skyldig();
	
		if(tmp < 0)
			summaUt += abs(tmp);
		else
			summaIn += tmp;
	}

	if(summaIn - summaUt != 0)
		cout << "Summa skilt från noll, något har gått snett." << endl;
	else
		cout << "Inget kvar i potten, allt går jämt ut." << endl;
}

double PersonLista::summaSkyldig()
{
	double sum = 0;
	for(int i = 0; i < antal_pers; i++)
		sum += pers[i].haemta_skyldig();
	
	return sum;
}

double PersonLista::summaBetalat()
{
	double sum = 0;
	for(int i = 0; i < antal_pers; i++)
		sum += pers[i].haemta_betalat();

	return sum;
}

bool PersonLista::finnsPerson(const string& namn)
{
	for(int i = 0; i < antal_pers; i++)
	{
		if(pers[i].haemta_namn() == namn)
			return true;
	}
	return false;
}

/******************
* Other methods
******************/
void skrivMeny()
{
	cout << endl;
	cout << "Välj i menyn nedan:" << endl;
	cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
	cout << "1. Läs in en transaktion från tangentbordet." << endl;
	cout << "2. Skriv ut information om alla transaktioner." << endl;
	cout << "3. Beräkna totala kostnaden." << endl;
	cout << "4. Lista alla personer mm och fixa." << endl;
}

/******************
* Main Method
******************/
int main()
{
	PersonLista pl;
	TransaktionsLista tl;
	int selection = -1;
	
	cout << "Startar med att försöka läsa ifrån resa.txt." << endl;
	ifstream ifs("resa.txt");
	tl.laesin(ifs);
	ifs.close();

	skrivMeny();	

	while(selection != 0)
	{
		cin >> selection;
		switch(selection)
		{
			case 0:
				{
					cout << "Skriver ner alla transaktioner till ut.txt" << endl;
					ofstream os("ut.txt");
					tl.skrivut(os);
					os.close();
					cout << "Avslutar." << endl;
				}
				break;
			case 1:
				{
					tl.laesin_single(cin);
					cout << endl;
					skrivMeny();
				}
				break;
			case 2:
				{
					tl.skrivut(cout);
					cout << endl;
					skrivMeny();	
				}
				break;
			case 3:
				{
					cout << "Totala kostnaden är " << tl.totalkostnad() << endl;
					skrivMeny();
				}
				break;
			case 4:
				{
					pl = tl.fixaPersoner();
					pl.skrivUtOchFixa();
					cout << endl;
					skrivMeny();
				}	
				break;
			default:
				cout << "Unknown option, please select one of the following: " << endl;
				skrivMeny();
		}
	}
	
	return 0;
}
/*================================================================================
- Den används i funktionen laggTill och behövs för att se till att alla värden i en transaktion kopieras över korrekt.
  För att få en sk. deep copy.

- Det är en koll för att se om man försöker kopiera sig själv, gör man detta kan man bara returnera sig själv och behöver
	inte kopiera över värden m.m.

*/



