using namespace std;

#include <iostream>
#include <cstring>
#include <cctype>

char arr1[5];
char arr2[6][6] = {
        {'0', '0', '0', '0', '0', '0'},
        {'0', 'A', 'B', 'C', 'D', 'E'},
        {'0', 'F', 'G', 'H', 'I', 'K'},
        {'0', 'L', 'M', 'N', 'O', 'P'},
        {'0', 'Q', 'R', 'S', 'T', 'U'},
        {'0', 'V', 'W', 'X', 'Y', 'Z'},
};

void encryption() {
    string text = "";

    cout << "Enter text to be encrypted:";
    cin.ignore();
    getline(cin, text);

    for (int x = 0; x < text.length(); ++x) {
        text[x] = toupper(text[x]);

        if (text[x] == ' ') {
            cout << ' ';
            continue;
        }

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (text[x] == arr2[i][j]) {
                    cout << arr2[0][j] << arr2[i][0];
                }
            }
        }
    }
}

void decryption() {
    string decrypt;
    int column, row;

    cout << "Enter text to be decrypted:";
    cin.ignore();
    getline(cin, decrypt);

    for (int x = 0; x < decrypt.length()-1; x++) {
        if (decrypt[x] == ' ' ) {
            cout << ' ';
            continue;
        }
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (decrypt[x] == arr2[j][0]) {
                    column = j;
                    continue;
                } else if (decrypt[x + 1] == arr2[0][i]) {
                    row = i;
                    continue;
                }
            }
        }
        cout << arr2[row][column];
        x++;
    }

}

int main() {

    int choice;

    cout << "Encryption (1) " << endl
         << "Decryption (2) " << endl
         << "Quit (3) " << endl
         << "Choice:";
    cin >> choice;

    cout << "please enter your pattern of numbers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> arr1[i];
    }

    for (int i = 1; i <= 5; i++) {
        arr2[0][i] = arr1[i - 1];
    }

    for (int j = 1; j <= 5; j++) {
        arr2[j][0] = arr1[j - 1];
    }

//    // Remove
//    for (int i = 0; i < 6; i++) {
//        for (int j = 0; j < 6; j++) {
//            cout << arr2[i][j] << " ";
//        }
//        cout << endl;
//    }

    // Encryption
    if (choice == 1) {
        encryption();
    } else if (choice == 2) {
        decryption();
    } else if (choice == 3) {
        exit(0);
    } else {
        cout << "You Entered Wrong Choice";
    }

}