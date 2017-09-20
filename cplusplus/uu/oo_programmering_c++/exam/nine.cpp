#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

map<string, vector<string>> italian;
map<string, vector<string>> german;
map<string, vector<string>> czech;
map<string, vector<string>> hungarian;

void populateMaps() {
	ifstream istream("words.txt");

	string value1, value2, value3, value4;

	istream >> value1;
	
	while(!istream.eof()){
		istream >> value2;
		istream >> value3;
		istream >> value4;
		
		vector<string> it, ger, cz, hun;
		it.push_back(value2);
		it.push_back(value3);
		it.push_back(value4);
		italian[value1] = it;

		ger.push_back(value1);
		ger.push_back(value3);
		ger.push_back(value4);
		german[value2] = ger;	
	
		cz.push_back(value1);
		cz.push_back(value2);
		cz.push_back(value4);
		czech[value3] = cz;
		
		hun.push_back(value1);
		hun.push_back(value2);
		hun.push_back(value3);
		hungarian[value4] = hun;
		
		istream >> value1;
	}
}

int main() {
	populateMaps();	

	string lang;
	string word;
	vector<string> transVec;

	while(true) {
		cout << "Language: ";
		cin >> lang;
		cout << "Word: ";
		cin >> word;

		if(lang == "Italian"){
			transVec = italian[word];
			cout << " German: " << transVec[0] << ", Czech: " << transVec[1] << ", Hungarian: " << transVec[2] << endl;
		}
		else if(lang == "German") {
			transVec = german[word];
			cout << " Italian: " << transVec[0] << ", Czech: " << transVec[1] << ", Hungarian: " << transVec[2] << endl;
		}
		else if(lang == "Czech") {
			transVec = czech[word];
			cout << " Italian: " << transVec[0] << ", German: " << transVec[1] << ", Hungarian: " << transVec[2] << endl;
		}
		else if(lang == "Hungarian") {
			transVec = hungarian[word];
			cout << " Italian: " << transVec[0] << ", German: " << transVec[1] << ", Czech: " << transVec[2] << endl;
		}
		else
			cout << "Unknown Language" << endl;
	}

	return 0;
}
