#ifndef PRINTSTATS_H_
#define PRINTSTATS_H_


void PrintStats(vector<Person> persons) {
	cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;

	auto females = partition(persons.begin(), persons.end(), [] (const Person& p)
			{
				return (p.gender == Gender::FEMALE) ;
			});
	cout << "Median age for females = " << ComputeMedianAge(persons.begin(), females) << endl;
	cout << "Median age for males = " << ComputeMedianAge(females, persons.end()) << endl;

	auto employed_females = partition(persons.begin(), females, [] (const Person& p)
	{
		return (p.is_employed);
	});

	cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), employed_females) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(employed_females, females) << endl;

	auto employed_males = partition(females, persons.end(), [] (const Person& p)
		{
			return (p.is_employed);
		});
	cout << "Median age for employed males = " << ComputeMedianAge(females, employed_males) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAge(employed_males, persons.end()) << endl;
}



#endif /* PRINTSTATS_H_ */
