static FIRST_YEAR: i32 = 1900;
static LAST_YEAR: i32 = 2000;
// static NUM_YEARS: usize = (LAST_YEAR - FIRST_YEAR + 1);

struct Person {
  birth_year: i32,
  death_year: i32
}

fn find_max(people: Vec<Person>) -> (i32, i32) {
  let years = [0i32; 101];

  for person in people.iter() {
    let birth_year_idx = person.birth_year - FIRST_YEAR;
    let death_year_idx = person.death_year - FIRST_YEAR;
    years[birth_year_idx] += 1;
    years[death_year_idx] -= 1;
  }

  let (mut current, mut max) = (0i32, 0i32);
  let max_year = FIRST_YEAR;
  for &year in years.iter() {
    current += year;
    if current > max {
      max_year = FIRST_YEAR;
      max = current;
    }
  }

  (max_year, max)
}

fn main() {
  let people = vec![
    Person::new(1901,1903), Person::new(1902,1998), Person::new(1903,1997),
    Person::new(1904,1996), Person::new(1905,1995)
  ];

  let (year, pop) = find_max(people);
  println!("Max of {} in {}", pop, year);
}
