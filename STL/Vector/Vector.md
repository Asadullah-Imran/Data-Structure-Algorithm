# Introduction to Vectors in C++

A **vector** in C++ is part of the Standard Template Library (STL) and acts as a dynamic array. Vectors provide the ability to grow and shrink as needed, making them more versatile than traditional arrays.

---

## 1 Why Use Vectors?

- **Dynamic Size**: Automatically resizes as elements are added or removed.
- **Ease of Use**: Offers a variety of built-in functions.
- **Safety**: Functions like `.at()` help with bounds checking.

---

## 2 How to Use Vectors?

Before using vectors, include the `<vector>` header in your program.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declaration of a vector
    vector<int> myVector;

    return 0;
}
```
## 3 Common Operations on Vectors
A. Adding Elements
    - Use push_back(value) to add elements at the end.

```cpp
myVector.push_back(10);  // Adds 10
myVector.push_back(20);  // Adds 20
```
B. Accessing Elements
    - Use [] or .at() for accessing elements.
```cpp
cout << myVector[0];    // Output: 10
cout << myVector.at(1); // Output: 20
```
C. Removing Elements
pop_back() removes the last element.
```cpp
myVector.pop_back(); // Removes 20
```
D. Getting Size
Use .size() to get the number of elements.
```cpp
cout << myVector.size(); // Output: 1 (only 10 is left)
```
## 4 Traversing a Vector
A. Using a For Loop
```cpp
for (int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << " ";
}
```
B. Using a Range-based For Loop
```cpp
for (int value : myVector) {
    cout << value << " ";
}
```
C. Using Iterators
```cpp
for (auto it = myVector.begin(); it != myVector.end(); ++it) {
    cout << *it << " ";
}
```
## 5 Useful Functions of Vectors

| **Function**          | **Description**                                   | **Example**                                           |
|------------------------|---------------------------------------------------|-----------------------------------------------------|
| `empty()`             | Checks if the vector is empty.                    | `if (myVector.empty()) cout << "Vector is empty!";` |
| `clear()`             | Removes all elements from the vector.             | `myVector.clear();`                                 |
| `size()`              | Returns the number of elements in the vector.     | `cout << myVector.size();`                         |
| `front()`             | Returns the first element in the vector.          | `cout << myVector.front();`                        |
| `back()`              | Returns the last element in the vector.           | `cout << myVector.back();`                         |

These functions are extremely useful for managing and querying vector data in various scenarios.

## 6 Examples: Using Vectors
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;

    // Adding elements
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // Displaying elements
    cout << "Vector elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    // Removing last element
    numbers.pop_back();

    // Size of vector
    cout << "\nSize: " << numbers.size();

    return 0;
}
```
Output
```yaml
Vector elements: 1 2 3
Size: 2
```

## 7. Advantages of Vectors
    - Flexible sizing.
    - Built-in functions simplify coding.
    - Safer than raw arrays.
## 8. When to Use Vectors?
    - When you need a resizable array.
    - When array bounds checking is important.
    - For generic programming with containers.