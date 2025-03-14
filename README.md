# Data-Structure-Comparison-for-BPE

Overview:
The aim of this project is to compare the performance of three different data structures in terms of time and memory usage for the purpose of finding the most optimal data structure to incorporate into my BPE algorithm. The three different data sturctures are as follows: a custom data structure of my own design, a vector, and a list. The custom data structure is a vector with elements of the type "node". the node is a union composed of a struct and a pointer of type node. For the purposes of testing, the struct is composed of two integer variables. The first titled "prev" and the second titled "current". The task used to test the respective data structures involved filling each structure with integers from 1 to "size - 1" inclusive. Then, the structures would be iterated through. If the value pointed to by an iterator plus the adjacent previous value were divisible by some divisor, the value that the iterator pointed to would be deleted. This process was run for three iterations. To give an example, say size = 10, thus the procession of numbers to be analyzed would be as follows: 1, 2, 3, 4, 5, 6, 7, 8, 9. (Note, a zero was generally included in the structure, but the zero would never be considered the "current" value as there would be no coincinding "prev" value). If we ran the test for two iterations and the divisor list contained {15, 8}, the first iteration would see 8 be deleted because (7 + 8) % 15 = 0, and thus the list would become 1, 2, 3, 4, 5, 6, 7, 9. The second iteration would see 9 deleted because (9 + 7) % 8 = 0, and thus the list would become 1, 2, 3, 4, 5, 6, 7. It is important to note that the custom data structure cheats somewhat because when a value is meant to be "deleted", no memory is actually deallocated. Instead, the address for the next node that contained integer values would be copied over the integer values of the current node. This allows the vector to act almost like a list, where "deletion" only takes O(1) time rather than O(n) time. By changing the value contained by the node from integers to address, the program is no longer required to iterate over invalid data to reach the next desired position. I will eventually incorporate my custom data structure into my BPE algorithm.
