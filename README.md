# Purpose
This repo was made for an assignment during COS-2021 - Fundamental Data Structures. It was made in collaboration with Hayk Matevosyan. 

## Acknowledgements
This code, as of now (17-02-2026), does not work as per the instructions of the professor. It is supposed to read from a `crates.txt` and separate the crates on shelves.
The issue right now is that it manages to sort correctly the shelves up until shelf 9 (out of 10). Afterwards, it returns a segmentation fault.

My suspicion is that the linked list is the culprit - I have a suspicion that the `get_element_at()` method is the one that causes the issue.

## Future tasks
- [ ] Optimize the base structures (specifically queue and linked list) and add tail pointers for better speed and easier maneuvering.
- [ ] Cleanup the code
