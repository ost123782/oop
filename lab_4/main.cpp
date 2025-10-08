#include <iostream>
#include <tuple>

using namespace std;

#define PI 3.14

class Inductor {
	public:
		void setInductance (float _inductance);
		void setReactiveResistance (int frequency);
		float getReactiveResistance ();
		void getMaximumFrequency ();
		~Inductor ();

		Inductor () {
			bool isValid = false;
			while (!isValid) {
				cout << "Enter inductance, resistance, count of turns: ";
				cin >> inductance >> resistance >> turnsCount;

				if (inductance < 0 || resistance < 0 || turnsCount < 0) {
					cout << "Inductor is not valid!" << endl;
					continue;
				}

				isValid = true;
			}
		}

	private:
		float inductance;
		float resistance;
		int turnsCount;
		float reactiveResistance;
		float findReactiveResistance(int frequency);
		tuple<int, float> findMultiplier (float value);


};

void Inductor::setInductance(float _inductance) {
	if (_inductance < 0) {
		cout << "Not valid value \n";
		return;
	}
	inductance = _inductance;
}

float Inductor::findReactiveResistance(int frequency) {	
	return 2 * PI * frequency * inductance;
}

void Inductor::setReactiveResistance(int frequency) {
	if (frequency < 0) {
		cout << "No valid value";
		return;
	}
	reactiveResistance = findReactiveResistance(frequency);
}

float Inductor::getReactiveResistance () {
	return reactiveResistance;
}

void Inductor::getMaximumFrequency() {
	int frequency = 0;
	while (reactiveResistance / 1000 <= 10000) {
		setReactiveResistance(frequency);
		frequency += 10;
	}

	auto [multiplier, fomattedFrequency] = findMultiplier((float)frequency);

	cout << "Max. frequency: " << fomattedFrequency << " * 10^" << multiplier << endl;
}

tuple<int, float> Inductor::findMultiplier(float value) {
	int multiplier = 0;

	while (value > 10) {
		value /= 10;
		multiplier++;
	}

	return {multiplier, value};
}

Inductor::~Inductor() {
	cout << "FIRE" << endl;
}

int main() {
	Inductor 
	myInductor,
	myInductor2,
	myInductor3;

	myInductor.setReactiveResistance(0);
	myInductor2.setReactiveResistance(1000);
	myInductor3.setReactiveResistance(30000);

  	cout << "Inductor 1 " << myInductor.getReactiveResistance() / 1000.0 << " kOhm" << "\n";
	cout << "Inductor 2 " << myInductor2.getReactiveResistance() / 1000.0 << " kOhm" << "\n";
  	cout << "Inductor 3 " << myInductor3.getReactiveResistance() / 1000.0 << " kOhm" << "\n";

	myInductor.setInductance(4);
	myInductor.setReactiveResistance(25000);

	cout << "Inductor 1 " << myInductor.getReactiveResistance() / 1000.0 << " kOhm" << "\n";

	myInductor.getMaximumFrequency();

  	return 0;
}