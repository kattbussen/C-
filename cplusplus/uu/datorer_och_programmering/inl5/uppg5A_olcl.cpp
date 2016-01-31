/*================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2016

Inlämningsuppgift nr 5A

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

// Huvudprogram:

int main()
{
 // Deklarera variabler
  string text;
  bool histOK;
  Text minText;  // Ett objekt av typen Text skapas

  // Läs in en rad med text från tangentbordet
  cout <<"Ge en rad med text:" << endl;
  getline(cin,text);

  // Skicka strängen text till objektet minText
  minText.setText( text );

  // Beräkna och skriv ut histogrammet
  histOK = minText.beraknaHistogramAbs( );
  minText.skrivHistogramAbs( );

  return 0;
}

// -------------------------------------------------------
// Här skriver du klassimplementationen
Text::Text()
{
	text = "";
	totChars = 0;
	fill(absHist, absHist+ANTAL_BOKSTAVER, 0);
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

//--------------------------------------------------------
// Funktionsdefinitioner:

// -------------------------------------------------------
/* Rapport om uppgiften

Testdata1:
Ge en rad med text:
AbCdNNooPPwXyZ

Resultat for bokstaverna A-Z

Totala antalet bokstaver: 14
Bokstavsfordelning:

A: 1
B: 1
C: 1
D: 1
E: 0
F: 0
G: 0
H: 0
I: 0
J: 0
K: 0
L: 0
M: 0
N: 2
O: 2
P: 2
Q: 0
R: 0
S: 0
T: 0
U: 0
V: 0
W: 1
X: 1
Y: 1
Z: 1

Testdata2:
Ge en rad med text:
1234ddddacccbb!?

Resultat for bokstaverna A-Z

Totala antalet bokstaver: 10
Bokstavsfordelning:

A: 1
B: 2
C: 3
D: 4
E: 0
F: 0
G: 0
H: 0
I: 0
J: 0
K: 0
L: 0
M: 0
N: 0
O: 0
P: 0
Q: 0
R: 0
S: 0
T: 0
U: 0
V: 0
W: 0
X: 0
Y: 0
Z: 0

Testdata3:
Ge en rad med text:
Denna rad innehåller ett å!

Resultat for bokstaverna A-Z

Totala antalet bokstaver: 20
Bokstavsfordelning:

A: 2
B: 0
C: 0
D: 2
E: 4
F: 0
G: 0
H: 1
I: 1
J: 0
K: 0
L: 2
M: 0
N: 4
O: 0
P: 0
Q: 0
R: 2
S: 0
T: 2
U: 0
V: 0
W: 0
X: 0
Y: 0
Z: 0

Testdata4:
Ge en rad med text:


Resultat for bokstaverna A-Z

Totala antalet bokstaver: 0
Bokstavsfordelning:

A: 0
B: 0
C: 0
D: 0
E: 0
F: 0
G: 0
H: 0
I: 0
J: 0
K: 0
L: 0
M: 0
N: 0
O: 0
P: 0
Q: 0
R: 0
S: 0
T: 0
U: 0
V: 0
W: 0
X: 0
Y: 0
Z: 0

*/
