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






#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve_case(const int case_num) {
    int N;
    cin >> N;
    
    vector<int> books;
    vector<int> evens;
    vector<int> odds;
    books.reserve(N);
    evens.reserve(N); 
    odds.reserve(N);  
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        books.emplace_back(value);
        
        if (value % 2 == 0) {
            evens.emplace_back(value);
        } else {
            odds.emplace_back(value);
        }
    }
    
    sort(evens.rbegin(), evens.rend()); 
    sort(odds.begin(), odds.end());      
    
    cout << "Case #" << case_num << ":";
    
    size_t even_idx = 0;
    size_t odd_idx = 0;
    
    for (const int& book : books) {
        cout << ' ' << ((book % 2 == 0) ? evens[even_idx++] : odds[odd_idx++]);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; ++i) {
        solve_case(i);
    }
    
    return 0;
}
