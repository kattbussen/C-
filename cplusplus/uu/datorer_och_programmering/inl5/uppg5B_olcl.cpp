/*================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2016

Inlämningsuppgift nr 5B

Namn: Olle Claeson

Personummer: 820710-2750

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): xcode / 7.2
s
Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : El Capitan / 10.11.2

Jag har arbetat ungefär 1 timme med denna uppgift

================================================================================
*/
//
// Programskal till obluppg5A
//
// Hanterar fallet med 26 bokstäver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Använd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK 
// istället för värdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska.TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas 
// som parameter till den funktion som behöver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// Globala variabler är ej tillåtna

//--------------------------------------------------------
// Här kommer klassdeklarationen 
class Text
{
	public:
		string text;
		int absHist[ANTAL_BOKSTAVER];
		double relHist[ANTAL_BOKSTAVER];
		int totChars;

		Text();
		void setText(string nyText);
		bool beraknaHistogramAbs();
		void skrivHistogramAbs();
		void absTillRel();
		void plottaHistogramRel();
		void beraknaHistogram();
		string tolka();
};
// -------------------------------------------------------

//--------------------------------------------------------
// Här kommer funktionsdeklarationer 
string namn_pa_fil();

string inlasning(ifstream &file);
//--------------------------------------------------------

// Huvudprogram:

int main()
{
	string content = "";
  Text minText;
	string filNamn = namn_pa_fil();
	string result = "";

  ifstream myfile (filNamn);
  if(myfile.is_open())
  {
    cout << "laser ur filen " << filNamn << endl;

    string content = inlasning(myfile);

		minText.setText(content);

		minText.beraknaHistogram();

    minText.plottaHistogramRel();

    result = minText.tolka();
  
		cout << "det mest troliga spraket ar " << result << endl;
  }
  else
  {
    cout << "filnamnet du angav finns ej." << endl;
  }
  
	return 0;
}

// -------------------------------------------------------
// Här skriver du klassimplementationen
Text::Text()
{
	text = "";
	totChars = 0;
	fill(absHist, absHist+ANTAL_BOKSTAVER, 0);
	fill(relHist, relHist+ANTAL_BOKSTAVER, 0);
}

void Text::setText(string nyText)
{
	text = nyText;
}

bool Text::beraknaHistogramAbs()
{
	if(text.length() == 0)
		return false;

	totChars = 0;
	
	for(int i = 0; i < text.length(); i++)
	{
		if(isalpha(text[i]))
		{
			totChars++;
			int index = tolower(text[i]) - 97;
			absHist[index]++;
		}
	}

	return true;
}

void Text::skrivHistogramAbs()
{
	cout << endl << "Resultat for bokstaverna A-Z" << endl << endl;
	cout << "Totala antalet bokstaver: " << totChars << endl;
	cout << "Bokstavsfordelning:" << endl << endl;

	char printChar = 'A';

	for(int i = 0; i < ANTAL_BOKSTAVER; i++)
	{
		cout << printChar << ": " << absHist[i] << endl;
		printChar++;	
	}
}

void Text::absTillRel()
{
  for(int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    relHist[i] = absHist[i] / (double)totChars * 100;
  }
}

void Text::plottaHistogramRel()
{
  char printChar = 'A';

  for(int i = 0; i < ANTAL_BOKSTAVER; i++)
  {
    int number = relHist[i] / 0.5;
    cout << printChar << ": " << string(number, '*') << endl;;
    printChar++;
  }
}

void Text::beraknaHistogram()
{
	beraknaHistogramAbs();
	
	if(totChars > 0)
		absTillRel();
}

string Text::tolka()
{
	double bestResult = INT_MAX;
  string bestLang = "";
  double result = 0;
  string lang = "";

  for(int i = 0; i < ANTAL_SPRAK; i++)
  {
    result = 0;

    for(int j = 0; j < ANTAL_BOKSTAVER; j++)
    {
      double diff = relHist[j] - TOLK_HJALP[i][j];
      result += diff * diff;
    }

    if(i == 0)
      lang = "engelska";
    else if(i == 1)
      lang = "franska";
    else if(i == 2)
      lang = "svenska";
    else
      lang = "tyska";

	  cout << lang << " ger resultatet " << result << endl;

    if(result < bestResult)
    {
      bestResult = result;
      bestLang = lang;
    }
  }

	return bestLang;
}
//--------------------------------------------------------
// Funktionsdefinitioner:
string namn_pa_fil()
{
  string namn = ""; 
  cout << "Ange filnamn: " << endl;
  cin >> namn;
  
  if(namn.length() < 4)
    namn = namn + ".txt";
  else if(namn.substr(namn.length() - 4, 4) != ".txt")
    namn = namn + ".txt";

  return namn;
}

string inlasning(ifstream &file)
{
  string content = ""; 
  string row = ""; 

  while(getline(file, row))
    content += row;

  file.close();
  return content;
}
// -------------------------------------------------------
/* Rapport om uppgiften

Testdata1:
Ange filnamn: 
doyle
laser ur filen doyle.txt
A: ****************
B: **
C: ******
D: *******
E: ************************
F: ****
G: **
H: ************
I: ***************
J: 
K: *
L: *******
M: *****
N: ************
O: ***************
P: ***
Q: 
R: ***********
S: ************
T: ******************
U: *****
V: **
W: ****
X: 
Y: ****
Z: 
engelska ger resultatet 1.75771
franska ger resultatet 96.1956
svenska ger resultatet 73.3371
tyska ger resultatet 116.072
det mest troliga spraket ar engelska

Testdata2:
Ange filnamn: 
goethe.txt
laser ur filen goethe.txt
A: **********
B: ***
C: *******
D: *********
E: *********************************
F: **
G: ******
H: ***********
I: *****************
J: 
K: **
L: ******
M: ******
N: *********************
O: ****
P: 
Q: 
R: ************
S: *************
T: ***********
U: *******
V: *
W: ***
X: 
Y: *
Z: **
engelska ger resultatet 107.856
franska ger resultatet 85.205
svenska ger resultatet 160.318
tyska ger resultatet 1.04313
det mest troliga spraket ar tyska

Testdata3:
Ange filnamn: 
lagerlof
laser ur filen lagerlof.txt
A: **********************
B: *
C: **
D: ***********
E: *******************
F: ****
G: ********
H: *******
I: ********
J: **
K: ******
L: **********
M: *******
N: ******************
O: ********
P: **
Q: 
R: **************
S: *************
T: *****************
U: ***
V: ******
W: 
X: 
Y: 
Z: 
engelska ger resultatet 86.6804
franska ger resultatet 145.722
svenska ger resultatet 8.88258
tyska ger resultatet 170.223
det mest troliga spraket ar svenska

Testdata4:
Ange filnamn: 
verne.txt
laser ur filen verne.txt
A: ****************
B: **
C: *******
D: ********
E: **********************************
F: *
G: **
H: *
I: *************
J: 
K: 
L: **********
M: *****
N: ***************
O: **********
P: *****
Q: *
R: *************
S: ****************
T: *************
U: ***********
V: **
W: 
X: *
Y: 
Z: 
engelska ger resultatet 112.425
franska ger resultatet 0.885142
svenska ger resultatet 149.256
tyska ger resultatet 90.491
det mest troliga spraket ar franska

*/

/* Frågor
- Inte direkt, kanske är ointressant att bara veta om absHist och det är relHist som är användbar och därför finns det ingen anledning att bara göra "hälften" av beräkningen.
- Man kan tex nollställa absHist och relHist om man sätter en ny text.
- Ja det går utmärkt, det gör ingen skillnad. Jag ser inga egentliga fördelar förutom att funktionerna inte har något speciellt med resten av klassen att göra och därför med fördel lämnas utanför.
*/
