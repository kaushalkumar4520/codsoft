#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct Book {
    string title, author, isbn;
    bool available = true;
    time_t due = 0;
};

vector<Book> books;

void addBook() {
    Book z;
    cout << "Title: "; getline(cin, z.title);
    cout << "Author: "; getline(cin, z.author);
    cout << "ISBN: "; getline(cin, z.isbn);
    books.push_back(z);
}

void searchBook() {
    string key; cout << "Search(author,title,ISBN): "; getline(cin, key);
    for (auto &z : books)
        if (z.title.find(key) != string::npos || z.author.find(key) != string::npos || z.isbn == key)
            cout << z.title << " | " << z.author << " | " << z.isbn << " | " << (z.available ? "Available" : "Out") << endl;
}

void checkout() {
    string id; cout << "ISBN: "; getline(cin, id);
    for (auto &z : books)
        if (z.isbn == id && z.available) {
            z.available = false;
            z.due = time(0) + 7 * 86400;
            cout << "Checked out.\n"; return;
        }
    cout << "Not available.\n";
}

void retBook() {
    string id; cout << "ISBN: "; getline(cin, id);
    for (auto &z : books)
        if (z.isbn == id && !z.available) {
            z.available = true;
            double fine = max(0.0, difftime(time(0), z.due) /  86400);
            cout << "Returned. Fine: $" << fine << "\n"; return;
        }
    cout << "Not found.\n";
}
int main() {
    while (true) {
        cout << "1.Add\n2.Search\n3.Checkout\n4.Return\n5.Exit\n\nChoice: ";
        string chn; getline(cin, chn);
        if (chn == "1") addBook();
        else if (chn == "2") searchBook();
        else if (chn == "3") checkout();
        else if (chn == "4") retBook();
        else if (chn == "5") break;
    }
    return 0;
}