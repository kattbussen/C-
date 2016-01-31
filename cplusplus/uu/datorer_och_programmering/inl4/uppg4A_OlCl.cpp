/*================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2016

Inlämningsuppgift nr 4A

Namn: Olle Claeson

Personummer: 820710-2750

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): xcode / 7.2
s
Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : El Capitan / 10.11.2

Jag har arbetat ungefär 2 timmar med denna uppgift

================================================================================
*/
//
// Programskal till obluppg4 - deluppgift A
//
// Hanterar fallet med 26 bokstäver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


// Använd gärna denna globala konstant i programmet
// i stället för värdet 26
const int ANTAL_BOKSTAVER = 26;  //A-Z
// Globala variabler är ej tillåtna

//--------------------------------------------------------
// Funktionsdeklarationer:
// Använd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
int berakna_histogram_abs(int (&arr)[ANTAL_BOKSTAVER], string inLine);

// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int (&arr)[ANTAL_BOKSTAVER], int noChars);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // Deklarera variabler
  string inLine = "";
	int histo[ANTAL_BOKSTAVER];
	int noChars = 0;

  // Läs in en rad med text från tangentbordet
	cout << "Ge en rad med text: " << endl;
	getline(cin, inLine);

  // Anropa funktionen berakna_histogram_abs som beräknar histogrammet
  // och antalet bokstäver.  
 	noChars = berakna_histogram_abs(histo, inLine); 
 

  // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
  skriv_histogram_abs(histo, noChars);

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
int berakna_histogram_abs(int (&arr)[ANTAL_BOKSTAVER], string inLine)
{
	int treatedChars = 0;
	
	for(int i = 0; i < ANTAL_BOKSTAVER; i++)
			arr[i] = 0;

	for(int i = 0; i < inLine.length(); i++)
	{
		if(isalpha(inLine[i]))
		{
			treatedChars++;
			int index = tolower(inLine[i]) - 97;
			arr[index]++;
		}
	}
	return treatedChars;
}

void skriv_histogram_abs(int (&arr)[ANTAL_BOKSTAVER], int noChars)
{
	cout << endl << "Resultat for bokstaverna A-Z" << endl << endl;
	cout << "Totala antalet bokstaver: " << noChars << endl;
	cout << "Bokstavsfordelning:" << endl << endl;

	char printChar = 'A';

	for(int i = 0; i < ANTAL_BOKSTAVER; i++)
	{
		cout << printChar << ": " << arr[i] << endl;
		printChar++;	
	}
}

// Redovisning av uppgiften i ord. 

/*
Testadata1:
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
