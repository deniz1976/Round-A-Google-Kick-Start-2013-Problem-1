#include <iostream>
#include <list>
#include <algorithm>
#include <string>

/**
 * @name Deniz Mutlu.
 */

/**
 * Problem
 *
 *
Alex and Bob are brothers and they both enjoy reading very much. They have widely different tastes on books so they keep
their own books separately. However, their father thinks it is good to promote exchanges if they can put their books
together. Thus he has bought an one-row bookshelf for them today and put all his sons' books on it in random order.
He labeled each position of the bookshelf the owner of the corresponding book ('Alex' or 'Bob').

Unfortunately, Alex and Bob went outside and didn't know what their father did. When they were back, they came to
realize the problem: they usually arranged their books in their own orders, but the books seem to be in a great mess on
the bookshelf now. They have to sort them right now!!

Each book has its own worth, which is represented by an integer. Books with odd values of worth belong to Alex and the
books with even values of worth belong to Bob. Alex has a habit of sorting his books from the left to the right in an
increasing order of worths, while Bob prefers to sort his books from the left to the right in a decreasing order of
worths.

At the same time, they do not want to change the positions of the labels, so that after they have finished sorting the
books according their rules, each book's owner's name should match with the label in its position.

Here comes the problem. A sequence of N values s0, s1, ..., sN-1 is given, which indicates the worths of the books from
the left to the right on the bookshelf currently. Please help the brothers to find out the sequence of worths after
sorting such that it satisfies the above description.

Input
The first line of input contains a single integer T, the number of test cases. Each test case starts with a line
containing an integer N, the number of books on the bookshelf. The next line contains N integers separated by spaces,
representing s0, s1, ..., sN-1, which are the worths of the books.

Output
For each test case, output one line containing "Case #X: ", followed by t0, t1, ..., tN-1 in order, and separated by
spaces. X is the test case number (starting from 1) and t0, t1, ..., tN-1 forms the resulting sequence of worths of the
books from the left to the right.

Limits
Time limit: 30 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 30.

Test set 1 - Visible
1 ≤ N ≤ 100
-100 ≤ si ≤ 100

Test set 2 - Hidden
1 ≤ N ≤ 1000
-1000 ≤ si ≤ 1000
 */

using namespace std;

int main() {
    bool loop = true;
    int arrLength;
    while (loop) {
        std::cout << "Enter the length of books" << std::endl;
        std::cin >> arrLength;
        if (arrLength < 0 || arrLength > 1000) {
            arrLength = 0;
        } else {
            loop = false;
        }
    }

    int books[arrLength];
    std::cout << "Enter integers (one integer per line)" << std::endl;
    for (int i = 0; i < arrLength; i++) {
        cin >> books[i];
    }

    list<int> evens;
    for (int &book: books) {
        if (book % 2 == 0) {
            evens.push_front(book);
        }
    }
    list<int> odds;
    for (int &book: books) {
        if (book % 2 != 0) {
            odds.push_back(book);
        }
    }

    evens.sort();
    evens.reverse();
    odds.sort();
    auto iteratorEven = evens.begin();
    auto iteratorOdd = odds.begin();
    for (int i = 0; i < arrLength; i++) {
        if (books[i] % 2 == 0) {
            books[i] = *iteratorEven;
            iteratorEven++;
        } else {
            books[i] = *iteratorOdd;
            iteratorOdd++;
        }
    }
    std::destroy(evens.begin(), evens.end());
    std::destroy(odds.begin(), odds.end());
    for (int book: books) {
        std::cout << book << " ";
    }
}
