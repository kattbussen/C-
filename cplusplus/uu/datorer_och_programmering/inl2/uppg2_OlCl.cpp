/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2016

Inlämningsuppgift nr 2

Namn: Olle Claeson

Personummer: 820710-2750

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): xcode / 7.2
s
Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : El Capitan / 10.11.2

Jag har arbetat ungefär 2 timmar med denna uppgift

================================================================================
*/
#include <iostream>
#include <limits.h>
using namespace std;

int main(){
 
	int startNr = 1;
  int bestTime = INT_MAX;
  int bestNr = 0;
  int startTime1 = 0;
  int startTime2 = 0;
  int startTime3 = 0;
  int goalTime1 = 0;
  int goalTime2 = 0;
  int goalTime3 = 0;
  int nrCompetitors = 0;
  int totTime = 0;
  int totGoal = 0;
  int totStart = 0;
   
  while(startNr > 0)
  {
    cout << "Skriv in startNr: ";
    cin >> startNr;
     
    if(startNr > 0)
    {
      nrCompetitors++;
     
      /***********
      * Read start and goal times. 
      ***********/
      cout << "Skriv in starttid: ";
      cin >> startTime1 >> startTime2 >> startTime3;
      cout << "Skriv in måltid: ";
      cin >> goalTime1 >> goalTime2 >> goalTime3;
       
      totGoal = goalTime1*60*60 + goalTime2*60 + goalTime3;
      totStart = startTime1*60*60 + startTime2*60 + startTime3;
      
      /***********
      * Negative times are not possible.
      * In this case, add 24h to goaltime. (GoalTime is after 00h) 
      ***********/
      if(totStart > totGoal)
        totGoal += 24*60*60;
      
      totTime = totGoal - totStart;
      
      /***********
      * If we have a new best time, store it. 
      ***********/
      if(totTime > 0 && totTime < bestTime)
      { 
        bestTime = totTime;
        bestNr = startNr;
      } 
    } 
  } 
 
  /***********
  * Turn the total time in seconds into h, min and sec.
  ***********/
  int tim = bestTime / (60 * 60);
  int min = (bestTime - tim*60*60)/60;
  int sek = (bestTime - tim*60*60 - min*60);
  
  /***********
  * If we had any competitors, print the results of the winner.
  ***********/
  if(nrCompetitors > 0)
  {
    cout << "Vinnare är startnr: " << bestNr << endl;
    cout << "Tim: " << tim << " Min: " << min << " Sek: " << sek << endl;
    cout << "Antal tävlande: " << nrCompetitors << endl;
	} 
  else
  	cout << "Inga tävlande." << endl;
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
Testdata1:
kriv in startNr: 33
Skriv in starttid: 17 30 15
Skriv in måltid: 18 22 35
Skriv in startNr: -1
Vinnare är startnr: 33
Tim: 0 Min: 52 Sek: 20
Antal tävlande: 1
Programmet avslutas

Testdata2:
Skriv in startNr: 33
Skriv in starttid: 00 30 15
Skriv in måltid: 19 22 35
Skriv in startNr: -1
Vinnare är startnr: 33
Tim: 18 Min: 52 Sek: 20
Antal tävlande: 1
Programmet avslutas

Testdata3:
Skriv in startNr: 33
Skriv in starttid: 17 30 15
Skriv in måltid: 18 22 35
Skriv in startNr: 14
Skriv in starttid: 23 35 00
Skriv in måltid: 0 12 24
Skriv in startNr: 26
Skriv in starttid: 10 11 12
Skriv in måltid: 20 21 22
Skriv in startNr: -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas

Testdata4:
Skriv in startNr: 14
Skriv in starttid: 23 35 00
Skriv in måltid: 0 12 24
Skriv in startNr: 26
Skriv in starttid: 10 11 12
Skriv in måltid: 20 21 22
Skriv in startNr: 33
Skriv in starttid: 17 30 15
Skriv in måltid: 18 22 35
Skriv in startNr: -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas

Testdata5:
kriv in startNr: 26
Skriv in starttid: 10 11 12
Skriv in måltid: 20 21 22
Skriv in startNr: 33
Skriv in starttid: 17 30 15
Skriv in måltid: 18 22 35
Skriv in startNr: 14
Skriv in starttid: 23 35 00
Skriv in måltid: 0 12 24
Skriv in startNr: -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas

Testdata6:
Skriv in startNr: 17 
Skriv in starttid: 00 00 50
Skriv in måltid: 00 00 30
Skriv in startNr: -1
Vinnare är startnr: 17
Tim: 23 Min: 59 Sek: 40
Antal tävlande: 1
Programmet avslutas

Testdata7:
Skriv in startNr: -1
Inga tävlande.
Programmet avslutas

Testdata8:
Skriv in startNr: 15
Skriv in starttid: 10 00 00 
Skriv in måltid: 11 00 00
Skriv in startNr: 12
Skriv in starttid: 11 00 00
Skriv in måltid: 10 00 10
Skriv in startNr: -1
Vinnare är startnr: 15
Tim: 1 Min: 0 Sek: 0
Antal tävlande: 2
Programmet avslutas

Testdata9:
Skriv in startNr: 8
Skriv in starttid: 00 00 10
Skriv in måltid: 00 00 20
Skriv in startNr: -1
Vinnare är startnr: 8
Tim: 0 Min: 0 Sek: 10
Antal tävlande: 1
Programmet avslutas

================================================================================
- Det är den första som sparas, detta pga jag kolla om det nya resultatet är strikt mindre (<) och inte <=.
- Varje testdata testar ett eget fall som programmet måste klara av.
- Skriver man testfallen efteråt är det lätt hänt att man testar koden man skrivt och inte det man vill att den ska göra.
*/
