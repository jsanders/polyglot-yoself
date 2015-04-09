// Pretty much a direct port of the C++98 version. Probably lots of room for improvement!

static FIRST_YEAR: usize = 1900;
static LAST_YEAR: usize = 2000;

struct Person {
  birth_year: usize,
  death_year: usize
}

impl Person {
  fn new(birth_year: usize, death_year: usize) -> Person {
    let error = format!("Must be born between {} and {}", FIRST_YEAR, LAST_YEAR);
    assert!(birth_year >= FIRST_YEAR, error);
    assert!(death_year <= LAST_YEAR, error);
    Person { birth_year: birth_year, death_year: death_year }
  }
}

fn find_max(people: Vec<Person>) -> (usize, i32) {
  let mut years = [0i32; 101];

  for person in people.iter() {
    let birth_year_idx = person.birth_year - FIRST_YEAR;
    let death_year_idx = person.death_year - FIRST_YEAR;
    years[birth_year_idx] += 1i32;
    years[death_year_idx] -= 1i32;
  }

  let (mut current, mut max) = (0i32, 0i32);
  let mut max_year = FIRST_YEAR;
  for (idx, year) in years.iter().enumerate() {
    current += *year;
    if current > max {
      max_year = FIRST_YEAR + idx;
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
