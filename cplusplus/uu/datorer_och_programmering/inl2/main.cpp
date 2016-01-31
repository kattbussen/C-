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

  cout << "Programmet avslutas" << endl;

  return 0;
}
