#include "phone_number.h"
using namespace std;
int main() {
	PhoneNumber num1("+7-22-111-22-33");
	cout << num1.GetCountryCode() << endl;
	cout << num1.GetCityCode() << endl;
	cout << num1.GetLocalNumber() << endl;
	cout << num1.GetInternationalNumber() << endl;
	{
		try {
			PhoneNumber num1("+7-22--111-22-33");
			cout << num1.GetCountryCode() << endl;
			cout << num1.GetCityCode() << endl;
			cout << num1.GetLocalNumber() << endl;
			cout << num1.GetInternationalNumber() << endl;


		}
		catch (std::exception const& e) {
			std::cout << e.what() << '\n';
		}

	}
		{
		try {
			PhoneNumber num1("+7---111-22-33");
			cout << num1.GetCountryCode() << endl;
			cout << num1.GetCityCode() << endl;
			cout << num1.GetLocalNumber() << endl;
			cout << num1.GetInternationalNumber() << endl;


		}
		catch (std::exception const& e) {
			std::cout << e.what() << '\n';
		}

	}
	return 0;
}
