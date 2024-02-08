# CLI-trigrams-parser
A program that prompts for two strings of arbitrary length from the user then computes and outputs how similar they are.

### Build instructions

#### Requirements
* C++ compiler supporting C++20, tested with
    * gcc 11.4.0 to compile for GNU/Linux
    * MSVC 19.33 to compile for Windows
* CMake (at least 3.16.0)
GoogleTest Framework will fetch content using internet connection

#### How to build
> cd CLI-trigrams-parser
>
> mkdir build
> 
> cd build
> 
> cmake ..
> 
> cmake --build .

How to run the app depends on your OS:
* for Linux
> ./CLI-Trigrams-parser
> 
> ./tests/CLI-Trigrams-parser-tests

* for Windows
> ./Debug/CLI-Trigrams-parser.exe
> 
> ./Debug/tests/CLI-Trigrams-parser-tests.exe

### Algorithm choice discussion
When tackling the problem of finding the longest common substring between two strings, I considered various algorithms, including both *dynamic programming* and *suffix tree-based* approaches. After analyzing the problem and evaluating the available algorithms, I chose to implement the solution using dynamic programming rather than the suffix tree approach with the Ukkonen algorithm. Below are the reasons for this choice:

* Efficiency and Simplicity:

Dynamic programming offers a straightforward and efficient solution to the problem. The time complexity of the dynamic programming approach is O(*m***n*), where *m* and *n* are the lengths of the input strings. This complexity is generally acceptable for moderate-sized inputs, providing a balance between efficiency and simplicity of implementation.
On the other hand, constructing suffix trees using the Ukkonen algorithm has a linear time complexity of O(*m+n*). While this may seem advantageous, the implementation complexity of the Ukkonen algorithm is higher compared to dynamic programming. It involves more intricate data structures and algorithms, making it more challenging to implement and debug.

* Space Complexity:

The dynamic programming approach typically requires additional memory to store the dynamic programming matrix, which has dimensions proportional to the lengths of the input strings. However, the space complexity remains O(*m×n*), which is manageable for reasonable input sizes.

Suffix trees, while space-efficient in terms of representing all suffixes of a string, may consume more memory and be less space-efficient compared to dynamic programming when dealing with large strings or many strings. This is because suffix trees store additional metadata to represent the relationships between suffixes.

* Scalability:

While suffix trees offer superior time complexities for certain string matching problems, such as finding repeated substrings or pattern matching, dynamic programming can be more scalable and easier to optimize for specific use cases. For large-scale applications where performance and ease of maintenance are crucial, dynamic programming may offer better long-term scalability and maintainability.

Considering these factors, I opted for the dynamic programming solution to find the longest common substring. It strikes a balance between efficiency, simplicity, ease of implementation, and scalability, making it a suitable choice for solving the problem at hand.
