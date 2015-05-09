use std::{fmt,iter};

pub struct SortedVec {
    raw: Vec<u8>
}

impl SortedVec {
    fn push(&mut self, val: u8) {
        let index = self.raw.iter().position(|&elem| val < elem);

        match index {
            Some(_index) => self.raw.insert(_index, val),
            None => self.raw.push(val)
        };
    }
}

impl fmt::Debug for SortedVec {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:?}", self.raw)
    }
}

impl iter::FromIterator<u8> for SortedVec {
    fn from_iter<I: IntoIterator<Item=u8>>(iterable: I) -> SortedVec {
        let iterator = iterable.into_iter();
        let (lower, _) = iterator.size_hint();
        let mut vec = SortedVec { raw: Vec::with_capacity(lower) };
        for element in iterator {
            vec.push(element);
        }
        vec
    }
}

