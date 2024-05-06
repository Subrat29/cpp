# C++ Container Comparison: `set`, `unordered_set`, `multiset`, `unordered_multiset`

This README.md file explains the differences between four commonly used containers in C++: `set`, `unordered_set`, `multiset`, and `unordered_multiset`.

## Set (`set`)

- Stores a collection of unique elements.
- Elements are stored in sorted order based on a comparison function (`less` by default).
- Operations like insertion, removal, and search have a time complexity of O(log n) on average.
- Uses a balanced binary search tree (usually Red-Black Tree) internally.

## Unordered Set (`unordered_set`)

- Stores a collection of unique elements.
- Elements are not stored in any particular order; they are placed based on their hash values.
- Operations like insertion, removal, and search have an average time complexity of O(1) (constant time).
- Uses a hash table internally to store elements.

## Multiset (`multiset`)

- Stores a collection of elements where duplicates are allowed.
- Elements are stored in sorted order based on a comparison function (`less` by default).
- Operations like insertion, removal, and search have a time complexity of O(log n) on average.
- Uses a balanced binary search tree (usually Red-Black Tree) internally.

## Unordered Multiset (`unordered_multiset`)

- Stores a collection of elements where duplicates are allowed.
- Elements are not stored in any particular order; they are placed based on their hash values.
- Operations like insertion, removal, and search have an average time complexity of O(1) (constant time).
- Uses a hash table internally to store elements.

---
