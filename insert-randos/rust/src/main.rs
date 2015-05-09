extern crate rand;
use rand::Rng;

mod sorted_vec;
use sorted_vec::SortedVec;

fn main() {
    let mut rng = rand::thread_rng();
    let vec: SortedVec<_> = rng.gen_iter::<i64>().take(100).collect();
    println!("{:?}", vec);
}
