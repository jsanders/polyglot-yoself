// Given a list of people with birth year and death year from 1900 to 2000,
// find the year in which the most people were alive. The algorithm here
// scans the list of people and a list of years once each. Made to work with
// C++98 just for "fun".

#include <stdexcept>
#include <vector>
#include <iostream>

#define FIRST_YEAR 1900
#define LAST_YEAR 2000
#define NUM_YEARS (LAST_YEAR - FIRST_YEAR + 1)

bool valid_year(int year) {
    return year >= FIRST_YEAR && year <= LAST_YEAR;
}

struct Person {
    int birth_year;
    int death_year;

    Person(int by, int dy) : birth_year(by), death_year(dy) {
        if(!valid_year(birth_year) || !valid_year(death_year)) { throw std::out_of_range("bad year"); }
    }
};

std::pair<int, int> find_max(std::vector<Person> people) {
    int years[NUM_YEARS] = {};

    for(std::vector<Person>::iterator it = people.begin(); it != people.end(); ++it) {
        int birth_year_idx = it->birth_year - FIRST_YEAR;
        int death_year_idx = it->death_year - FIRST_YEAR;
        ++years[birth_year_idx];
        --years[death_year_idx];
    }

    int current = years[0], max = years[0];
    int max_year = FIRST_YEAR;
    for(int i = 1; i < NUM_YEARS; ++i) {
        current += years[i];
        if(current > max) {
            max_year = FIRST_YEAR + i;
            max = current;
        }
    }

    return std::make_pair(max_year, max);
}

int main() {
    std::vector<Person> people;
    people.push_back(Person(1901,1903));
    people.push_back(Person(1902,1998));
    people.push_back(Person(1903,1997));
    people.push_back(Person(1904,1996));
    people.push_back(Person(1905,1995));

    std::pair<int, int> max = find_max(people);
    std::cout << "Max of " << max.second << " in " << max.first << std::endl;

    return 0;
}
