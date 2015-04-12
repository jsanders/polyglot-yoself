// Pretty much a direct port of the C++98 version. Probably lots of room for improvement!

extern crate rand;
use rand::{thread_rng, Rng};

use std::env;

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

fn make_people(how_many: usize) -> Vec<Person> {
  let mut vec = Vec::with_capacity(how_many);
  let mut rng = thread_rng();
  for _ in (0..how_many) {
    let birth_year = rng.gen_range(FIRST_YEAR, LAST_YEAR-1);
    let death_year = rng.gen_range(birth_year, LAST_YEAR);
    vec.push(Person::new(birth_year, death_year));
  }
  vec
}

fn main() { 
  let how_many: usize = env::args()
    .nth(1).and_then(|n| n.parse().ok())
    .unwrap_or(1000);
  let people = make_people(how_many);

  let (year, pop) = find_max(people);
  println!("Max of {} in {}", pop, year);
}
