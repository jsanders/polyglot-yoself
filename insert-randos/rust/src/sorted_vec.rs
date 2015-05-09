use std::{fmt,iter};

pub struct SortedVec<T> {
    raw: Vec<T>
}

impl<T: PartialOrd> SortedVec<T> {
    fn push(&mut self, val: T) {
        let index = self.raw.iter().position(|elem| val < *elem);

        match index {
            Some(_index) => self.raw.insert(_index, val),
            None => self.raw.push(val)
        };
    }
}

impl<T: PartialOrd> iter::FromIterator<T> for SortedVec<T> {
    fn from_iter<I: IntoIterator<Item=T>>(iterable: I) -> SortedVec<T> {
        let iterator = iterable.into_iter();
        let (lower, _) = iterator.size_hint();
        let mut vec = SortedVec { raw: Vec::with_capacity(lower) };
        for element in iterator {
            vec.push(element);
        }
        vec
    }
}

impl<T: fmt::Debug> fmt::Debug for SortedVec<T> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:?}", self.raw)
    }
}

