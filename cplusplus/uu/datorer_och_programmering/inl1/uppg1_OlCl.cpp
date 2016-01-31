//Använd nedanstående mall för din redovisningsfil:
//
//(Allt mellan /* och */ är kommentarer i C++-koden)
//

/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2016

Inlämningsuppgift nr 1

Namn: Olle Claeson

Personummer: 820710-2750

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): xcode / 7.2
s
Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : El Capitan / 10.11.2

Jag har arbetat ungefär 0.5 timme med denna uppgift

================================================================================
*/
// Slut på kommentar

#include <iostream>
using namespace std;

int main(){
    
    int a;
    int b = 12;
    a = 0;
    
    cout << "a = " << a << endl;
    cout << a+b << '\n' << "a-b = " << a-b << endl;
    
    return 0;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
 a = 0
 12
 a-b = -12
================================================================================
- Rätta kompileringsfel, saknas bara ett ";".
*/
