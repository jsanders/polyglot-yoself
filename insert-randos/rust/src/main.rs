extern crate rand;
use rand::Rng;

mod sorted_vec;
use sorted_vec::SortedVec;

fn main() {
    let mut rng = rand::thread_rng();
    let vec: SortedVec = rng.gen_iter::<u8>().take(100).collect();
    println!("{:?}", vec);
}
