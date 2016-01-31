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
using namespace std;

// Deklarationer av funktionerna
void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &tal1, int &tal2);
double berakna(int small, int big, char oper);
void skrivResultat(double result);

int main(){
  
  // Här ska deklaration av variabler finnas
	int tal1 = 0;
	int tal2 = 0;  
	char op;
	double svar = 0;

  skrivInfo();
  tal1 = lasEttTal();
  tal2 = lasEttTal();
  op = lasOp();
	ordna(tal1, tal2);
  svar = berakna(tal1, tal2, op);
  skrivResultat(svar);

  return 0;
}
// Definitioner av funktionerna
void skrivInfo()
{
	cout << "How to use this prorgam:" << endl;
	cout << "Enter two numbers, positive or negative." << endl;
	cout << "Enter an operator; " << endl;
	cout << " a for addition" << endl;
	cout << " m for multiplication" << endl;
	cout << " k for for squared" << endl;
	cout << "The program will then use the selected operatoion and apply it to all integers between the lower and the higher given integer." << endl;
}

int lasEttTal()
{	
	int number = 0;
	cout << "Enter an integer: " << endl;
	cin >> number;
	return number;
}

char lasOp()
{
	char op = 'b';

	while(op != 'a' && op != 'm' && op != 'k')
	{
		cout << "Enter an operator: " << endl;
		cin >> op;
	}
	return op;
}

void ordna(int &tal1, int &tal2)
{
	if(tal1 > tal2)
	{
		int tmp = tal1;
		tal1 = tal2;
		tal2 = tmp;
	}
}

double berakna(int small, int big, char oper)
{
	int res = small;

	if(oper == 'k')
		res = small*small;

	for(int i = small+1; i <= big; i++)
	{
		if(oper == 'a')
			res += i;
		if(oper == 'm')
			res = res*i;
		if(oper == 'k')
			res = res + i*i;
	}

	return res;
}

void skrivResultat(double result)
{
	cout << "The result is: " << result << endl;
}

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
Testdata1:
Enter an integer: 
3
Enter an integer: 
5
Enter an operator: 
a
The result is: 12

Testdata2:
Enter an integer: 
3
Enter an integer: 
5
Enter an operator: 
m
The result is: 60

Testdata3:
Enter an integer: 
3
Enter an integer: 
5
Enter an operator: 
k
The result is: 50

Testdata4:
Enter an integer: 
-3
Enter an integer: 
5
Enter an operator: 
m
The result is: 0

Testdata5:
Enter an integer: 
5
Enter an integer: 
3
Enter an operator: 
a
The result is: 12

Testdata6:
Enter an integer: 
-3
Enter an integer: 
-5
Enter an operator: 
a
The result is: -12

Testdata7:
Enter an integer: 
1
Enter an integer: 
100
Enter an operator: 
k
The result is: 338350

================================================================================
- Många fördelar, blir enklare att implementera i delar, enklare att testa, enklare att läsa m.m.
- Det kanske inte alltid man vill ändra i variabeln man skickar in utan man vill behålla ursprungsvärdet.
*/
