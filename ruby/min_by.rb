def min_by(ary, fn)
  first, *rest = ary;
  min_elem, _ = rest.reduce([first, fn.call(first)]) do |(min_elem, min), new_elem|
    if (new_min = f.call(new_elem)) < min
      [ new_elem, new_min ]
    else
      [ min_elem, min ]
    end
  end
  min_elem
end
