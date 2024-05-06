# `map` vs. `unordered_map` in C++

## Overview

This README provides an overview of the differences between `map` and `unordered_map` in C++ along with code examples illustrating their usage.

### Ordering of Elements

- **`map`**:
  - Maintains elements in a sorted order based on the keys.
  - Uses a binary search tree for sorting, ensuring elements are stored in a specific order (e.g., ascending or descending).

- **`unordered_map`**:
  - Does not enforce any particular order among elements.
  - Utilizes a hash table for storage, providing faster access but no guaranteed order of elements.

### Performance

- **`map`**:
  - Offers `O(log n)` complexity for insertion, deletion, and search operations due to the binary search tree's structure.
  
- **`unordered_map`**:
  - Provides `O(1)` average-case complexity for operations like insertion, deletion, and search, although worst-case scenarios can degrade to `O(n)`.

### Memory Usage

- **`map`**:
  - Tends to consume more memory compared to `unordered_map` because of the overhead associated with maintaining a binary search tree and storing elements in sorted order.
  
- **`unordered_map`**:
  - Typically consumes less memory as it employs a hash table, which has a simpler structure than a binary search tree.

### Iterating Over Elements

- **`map`**:
  - Iterating over elements results in a sorted order based on keys, facilitating ordered traversal.
  
- **`unordered_map`**:
  - Iteration order is not guaranteed, and elements are accessed based on their hash values.

# Note
- If `mp[key]` is not present then it creates it and set its value to `0`.

