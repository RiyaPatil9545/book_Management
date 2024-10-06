#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

typedef struct {
    int BookID;
    char BookName[50];
    char Author[50];
    char Category[50];
    float Rating;
    float Price;
} Book;

#define MAX_BOOKS 100

void AddBooks(Book books[], int *n, int count);
void DisplayAllBooks(Book books[], int n);
void SortBooks(Book books[], int n);
void SearchBook(Book books[], int n);
void UpdateBook(Book books[], int n);
void RemoveBook(Book books[], int *n);
void ShowTop3Books(Book books[], int n);

int main() {
    Book books[MAX_BOOKS] = {
        {1, "Book1", "Lippman", "Programming", 3.0, 200.0},
        {2, "Book2", "Robert C. Martin", "Programming", 4.0, 100.0},
        {3, "Book3", "Hunt & Thomas", "Programming", 1.0, 300.0},
        {4, "Book4", "GoF", "Programming", 5.0, 800.0},
        {5, "Book5", "Cormen", "Algorithms", 2.0, 400.0}
    };

    int n = 5; 
    int choice;

    while (true) {
        cout << "\n=============== MENU ===============\n";
        cout << "1. Add books\n";
        cout << "2. Display all books\n";
        cout << "3. Search book\n";
        cout << "4. Update a book\n";
        cout << "5. Remove a book\n";
        cout << "6. Sort books (Price or Rating)\n";
        cout << "7. Show Top 3 Books by Rating\n";
        cout << "8. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int count;
            cout << "\nHow many books do you want to add? ";
            cin >> count;
            AddBooks(books, &n, count);
        } else if (choice == 2) {
            DisplayAllBooks(books, n);  
        } else if (choice == 3) {
            SearchBook(books, n);   
        } else if (choice == 4) {
            UpdateBook(books, n);  
        } else if (choice == 5) {
            RemoveBook(books, &n); 
        } else if (choice == 6) {
            SortBooks(books, n);
        } else if (choice == 7) {
            ShowTop3Books(books, n);
        } else if (choice == 8) {
            cout << "\nThank you for using the system! Goodbye!\n";
            break;
        } else {
            cout << "\n[!] Invalid choice! Please enter again.\n";
        }
    }
    return 0;
}

void AddBooks(Book books[], int *n, int count) {
    if (*n + count > MAX_BOOKS) {
        cout << "\n[!] Not enough space to add more books.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nEnter BookID: ";
        cin >> books[*n].BookID;
        cout << "Enter BookName: ";
        cin.ignore(); // Clear the input buffer
        cin.getline(books[*n].BookName, 50); 
        cout << "Enter Author: ";
        cin.getline(books[*n].Author, 50);
        cout << "Enter Category: ";
        cin.getline(books[*n].Category, 50);
        cout << "Enter Rating (out of 5): ";
        cin >> books[*n].Rating;
        cout << "Enter Price: ";
        cin >> books[*n].Price;
        (*n)++;
        cout << "\n[+] Book added successfully!\n";
    }
}

void DisplayAllBooks(Book books[], int n) {
    if (n == 0) {
        cout << "\n[!] No books available.\n";
        return;
    }

    // Table header
    cout << "\n" << setiosflags(ios::left)
         << setw(5) << "ID"
         << setw(20) << "Book Name"
         << setw(20) << "Author"
         << setw(20) << "Category"
         << setw(15) << "Rating"
         << setw(10) << "Price" << "\n";
    cout << "-------------------------------------------------------------------------------------\n";

    // Display each book's details
    for (int i = 0; i < n; i++) {
        cout << setw(5) << books[i].BookID
             << setw(20) << books[i].BookName
             << setw(20) << books[i].Author
             << setw(20) << books[i].Category
             << setw(15) << fixed << setprecision(2) << books[i].Rating
             << setw(10) << fixed << setprecision(2) << books[i].Price << "\n";
    }
}

void SearchBook(Book books[], int n) {
    int searchChoice;
    cout << "\nChoose search option:\n";
    cout << "1. Search by ID\n";
    cout << "2. Search by Name\n";
    cout << "Enter your choice: ";
    cin >> searchChoice;

    if (searchChoice == 1) {
        int bookID;
        cout << "\nEnter Book ID: ";
        cin >> bookID;
        for (int i = 0; i < n; i++) {
            if (books[i].BookID == bookID) {
                cout << "\n" << setiosflags(ios::left)
                     << setw(5) << "ID"
                     << setw(20) << "Book Name"
                     << setw(20) << "Author"
                     << setw(20) << "Category"
                     << setw(15) << "Rating"
                     << setw(10) << "Price" << "\n";
                cout << "-------------------------------------------------------------------------------------\n";
                cout << setw(5) << books[i].BookID
                     << setw(20) << books[i].BookName
                     << setw(20) << books[i].Author
                     << setw(20) << books[i].Category
                     << setw(15) << fixed << setprecision(2) << books[i].Rating
                     << setw(10) << fixed << setprecision(2) << books[i].Price << "\n";
                return;
            }
        }
        cout << "\n[!] Book not found.\n";
    } else if (searchChoice == 2) {
        char bookName[50];
        cout << "\nEnter Book Name: ";
        cin.ignore();
        cin.getline(bookName, 50);
        
        for (int i = 0; i < n; i++) {
            if (strcmp(books[i].BookName, bookName) == 0) {
                cout << "\n" << setiosflags(ios::left)
                     << setw(5) << "ID"
                     << setw(20) << "Book Name"
                     << setw(20) << "Author"
                     << setw(20) << "Category"
                     << setw(15) << "Rating"
                     << setw(10) << "Price" << "\n";
                cout << "-------------------------------------------------------------------------------------\n";
                cout << setw(5) << books[i].BookID
                     << setw(20) << books[i].BookName
                     << setw(20) << books[i].Author
                     << setw(20) << books[i].Category
                     << setw(15) << fixed << setprecision(2) << books[i].Rating
                     << setw(10) << fixed << setprecision(2) << books[i].Price << "\n";
                return;
            }
        }
        cout << "\n[!] Book not found.\n";
    } else {
        cout << "\n[!] Invalid choice!\n";
    }
}

void UpdateBook(Book books[], int n) {
    int bookID, updateChoice;
    cout << "\nEnter BookID to update: ";
    cin >> bookID;

    for (int i = 0; i < n; i++) {
        if (books[i].BookID == bookID) {
            cout << "\nWhat do you want to update?\n";
            cout << "1. Update Author\n";
            cout << "2. Update Category\n";
            cout << "3. Update Rating\n";
            cout << "4. Update Price\n";
            cout << "Enter your choice: ";
            cin >> updateChoice;

            switch (updateChoice) {
                case 1:
                    cout << "\nEnter new Author: ";
                    cin.ignore(); // Clear the input buffer
                    cin.getline(books[i].Author, 50);
                    cout << "\n[+] Author updated successfully!\n";
                    break;
                case 2:
                    cout << "\nEnter new Category: ";
                    cin.ignore();
                    cin.getline(books[i].Category, 50);
                    cout << "\n[+] Category updated successfully!\n";
                    break;
                case 3:
                    cout << "\nEnter new Rating (out of 5): ";
                    cin >> books[i].Rating;
                    cout << "\n[+] Rating updated successfully!\n";
                    break;
                case 4:
                    cout << "\nEnter new Price: ";
                    cin >> books[i].Price;
                    cout << "\n[+] Price updated successfully!\n";
                    break;
                default:
                    cout << "\n[!] Invalid choice!\n";
            }
            return;
        }
    }
    cout << "\n[!] Book not found.\n";
}

void RemoveBook(Book books[], int *n) {
    int bookID;
    cout << "\nEnter BookID to remove: ";
    cin >> bookID;

    for (int i = 0; i < *n; i++) {
        if (books[i].BookID == bookID) {
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            cout << "\n[+] Book removed successfully!\n";
            return;
        }
    }
    cout << "\n[!] Book not found.\n";
}

void SortBooks(Book books[], int n) {
    int sortChoice;
    cout << "\nSort by:\n";
    cout << "1. Price\n";
    cout << "2. Rating\n";
    cout << "Enter your choice: ";
    cin >> sortChoice;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((sortChoice == 1 && books[i].Price > books[j].Price) ||
                (sortChoice == 2 && books[i].Rating < books[j].Rating)) {
                swap(books[i], books[j]);
            }
        }
    }

    cout << "\n[+] Books sorted successfully!\n";
}

void ShowTop3Books(Book books[], int n) {
    if (n == 0) {
        cout << "\n[!] No books available.\n";
        return;
    }

    cout << "\nTop 3 Books by Rating:\n";
    cout << setiosflags(ios::left)
         << setw(5) << "ID"
         << setw(20) << "Book Name"
         << setw(20) << "Author"
         << setw(20) << "Category"
         << setw(15) << "Rating"
         << setw(10) << "Price" << "\n";
    cout << "-------------------------------------------------------------------------------------\n";

    // Sort by Rating (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (books[i].Rating < books[j].Rating) {
                swap(books[i], books[j]);
            }
        }
    }

    // Display top 3 books
    for (int i = 0; i < 3 && i < n; i++) {
        cout << setw(5) << books[i].BookID
             << setw(20) << books[i].BookName
             << setw(20) << books[i].Author
             << setw(20) << books[i].Author
             << setw(20) << books[i].Category
             << setw(15) << fixed << setprecision(2) << books[i].Rating
             << setw(10) << fixed << setprecision(2) << books[i].Price << "\n";
    }
}
