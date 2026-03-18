#include "structures/warehouse.cpp"
#include "config.hpp"

/*
 * MADE BY:
 * - TOMA BOUROV 200274715
 * - HAYK MATEVOSYAN 200293223
*/

/*
 * THE APPROACH:
 *
 * The approach me and Hayk came up with trying to achieve the highest possible efficiency of shelf storage. (i.e. handling the general case)
 * On paper the approach (which was mildly reworked after a visit to your office hours) worked logically:
 *
 * 1. Create the 10 shelves.
 * 2. Try to add as many crates as possible to them, without needing to resort to reordering them.
 * 3. After you reach that point - try to reorder crates and if, for some reason, some of the crates cannot be put back
 * on the original shelf, add them to the sorting queue. Then, afterwards, you start again from the beginning (since it's a 'while' loop)
 * but you get the last shelf you put in the sorting floor. Since (obviously), you can't put it in the original shelf, you go to the next one
 * (the next iteration of the 'for' loop) and try the same approach - remove, reorder, repeat.
 *
 * In theory the approach works, however, the results code-wise have not been... perfect - at the moment, all shelves from the queue get sorted,
 * and it seems that in the print, they seem to be correctly sorted (i.e. following the rules of the shelves), however, what we have noticed is
 * around ten (10) or so crates go missing (who needs them anyway?).
 *
 * There is not a concrete theory as to why - lots and lots of more debugging is required - time which we, unfortunately, don't have. If we have
 * make an educated guess - the reason why the crates go missing has to do with the way crates get pushed into the sorting floor. Some shenanigans
 * occur and the state of the variable gets mashed maybe (?).
 *
 * The old approach that was made in 2026 B.H.O.H. (Before Hutchinson Office Hours) is commented out in the file, however, it is very unreliable
 * and hard to predict. Also the initial approach that we started working on, written in plain english.
 *
 * - - - - - - - - -
 *
 * There are also some quality of life upgrades to the codebase:
 *
 * - main.cpp is much cleaner - the code that's supposed to read the crates has been put in the warehouse.cpp file.
 * - The print function has been fixed (it did not meet the requirements from HW1)! - StackOverflow never fails in terms of quality
 * answers (posts read/used are referenced).
 * - The original sort function from HW1 is also working now (or used to before making changes to other parts of the code).
 * - A new linked list component has been made, that is simpler - uses tail as well, as opposed to only a head pointer. (reference is noted).
 * - Warehouse class has a destructor - should be more memory safe now.
 *
*/

int main() {
    Warehouse *wh = new Warehouse();

    wh->read_crates(FILENAME);

    wh->sort_hw2();

    wh->print();

    // Cleanup
    delete wh;

    return 0;
}
