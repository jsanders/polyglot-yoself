extern crate rand;

use std::thread;

fn main() {
  let vec: Vec<_> = (0u32..10).collect();
  let _guards: Vec<_> = vec.iter().map(|i| {
    thread::scoped(move || {
      thread::sleep_ms(rand::random::<u8>() as u32);
      println!("{}", i);
    })
  }).collect();
}
