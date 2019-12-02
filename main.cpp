#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "Log.h";

using namespace std;

int getNumCowboys();
int getNumIndians();
void printLeadIn(int numCowboys, int numIndians);
void printResults(int numCowboysLeft, int numIndiansLeft);
void printTitle();
void simulateBattle(int &numCowboys, int &numIndians);

int main()
{
	int numCowboys, numIndians, numCowboysLeft, numIndiansLeft;

	printTitle();

	numCowboys = getNumCowboys();
	numIndians = getNumIndians();
	numCowboysLeft = numCowboys;
	numIndiansLeft = numIndians;

	printLeadIn(numCowboys, numIndians);

	simulateBattle(numCowboysLeft, numIndiansLeft);

	printResults(numCowboysLeft, numIndiansLeft);
	
	system("PAUSE");
	return 0;
}

int getNumCowboys()
{
	int numCowboys;

	cout << "Enter the number of cowboys: ";
	cin >> numCowboys;

	return numCowboys;
}

int getNumIndians()
{
	int numIndians;

	cout << "Enter the number of indians: ";
	cin >> numIndians;

	return numIndians;
}

void printLeadIn(int numCowboys, int numIndians)
{
	cout << "\nThe stage is set! " << numCowboys << " cowboys and " << numIndians << " indians are ready to punk each other.\n\n";
	cout << "Let the battle begin ...\n\n";
	cout << "Shit's going down! ...\n\n";
}

void printResults(int numCowboysLeft, int numIndiansLeft)
{
	cout << "The battle has ended ... who won? ";

	if (numCowboysLeft > 0) {
		cout << "COWBOYS WIN!\n\n";
	}
	else {
		cout << "INDIANS WIN!\n\n";
	}
	cout << "There were " << numCowboysLeft << " cowboys left and " << numIndiansLeft << " indians left after all was said and done.\n\n";
	cout << "May God rest their souls.\n\n";
}

void printTitle()
{
	cout << "**** Battle Simulator ****\n\n";
}

void simulateBattle(int &numCowboys, int &numIndians)
{
	float hitProbabilityResult, hitDamageResult, currentCowboyHealth, currentIndianHealth;

	static default_random_engine randEngine(time(0));
	uniform_real_distribution<float> hitProbability(0.0f, 1.0f);
	uniform_real_distribution<float> hitDamage(0.0f, 1.0f);
	uniform_real_distribution<float> attackInitiative(0.0f, 1.0f);

	float numCowboyHit = 0.6f;
	float numMaxCowboyDamage = 100.0f;
	float numFullCowboyHealth = 80.0f;

	float cowboyInitiative = 0.5f;

	float numIndianHit = 0.45f;
	float numMaxIndianDamage = 80.0f;
	float numFullIndianHealth = 85.0f;

	currentCowboyHealth = numFullCowboyHealth;
	currentIndianHealth = numFullIndianHealth;

	while ((numCowboys != 0) && (numIndians != 0)) {
		hitProbabilityResult = hitProbability(randEngine);
		hitDamageResult = hitDamage(randEngine);

		if (attackInitiative(randEngine) <= cowboyInitiative) {
			// Cowboy attacks!
			if (hitProbabilityResult <= numCowboyHit) {
				// Cowboy hits the indian!
				currentIndianHealth -= (numMaxCowboyDamage * hitDamageResult);

				if (currentIndianHealth <= 0) {
					numIndians--;
					currentIndianHealth = numFullIndianHealth;
				}
			}
		}
		else {
			// Indian attacks!
			if (hitProbabilityResult <= numIndianHit) {
				// Indian hits the cowboy!
				currentCowboyHealth -= (numMaxIndianDamage * hitDamageResult);

				if (currentCowboyHealth <= 0) {
					numCowboys--;
					currentCowboyHealth = numFullCowboyHealth;
				}
			}
		}

	}
}