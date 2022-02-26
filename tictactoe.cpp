#include <iostream>
using namespace std;

int ifWinGame(int arr[9], int player) {
    int check = 0;
    for (int i = 1; i <= 4; i++) {
        check = 0;
        switch (i) {
        case 1:
            for (int j = 0; j < 7; j += 3) {
                check = 0;
                for (int k = 0; k < 3; k++)
                    check += arr[j + i * k];
                if (check == 3 * player)
                    return player;
            }
        case 2:
            check = 0;
            for (int k = 0; k < 3; k++)
                check += arr[2 + i * k];
            if (check == 3 * player)
                return player;
        case 3:
            for (int j = 0; j < 3; j++) {
                check = 0;
                for (int k = 0; k < 3; k++)
                    check += arr[j + i * k];
                if (check == 3 * player)
                    return player;
            }
        case 4:
            check = 0;
            for (int k = 0; k < 3; k++)
                check += arr[0 + i * k];
            if (check == 3 * player) {
                return player;
            }
        }
    }
    return 0;
}

void ifGameEnd(int winner) {
    if (winner == 0)
        return;
    else if (winner == 1) {
        cout << "Player 1 wins!" << endl;
        exit(0);
    }
    else if (winner == -1) {
        cout << "Player 2 wins!" << endl;
        exit(0);
    }
}

bool ifAvailable(int arr[9], int num) {
    if (arr[num-1] != 0){
        cout << "Not Available!" << endl;
        return false;
    }
    else if (arr[num-1] == 0)
        return true;
}

int main() {
    int p1 = 1, p2 = -1;
    int arr[9] = { 0 };
    int winner = 0;
    //playing
    for (int n = 0; n < 9; n++) {
        for (int i = 0; i < 9; i++) {
            cout << arr[i] << "\t";
            if (i == 2 || i == 5 || i == 8)
                cout << endl;
        }
        do {
        cout << "p1 : ";
        cin >> p1;
        } while (ifAvailable(arr, p1) == false);
        arr[p1 - 1] = 1;
        winner = ifWinGame(arr, 1);
        ifGameEnd(winner);
        for (int i = 0; i < 9; i++) {
            cout << arr[i] << "\t";
            if (i == 2 || i == 5 || i == 8)
                cout << endl;
        }
        do {
        cout << "p2 : ";
        cin >> p2;
        } while (ifAvailable(arr, p2) == false);
        arr[p2 - 1] = -1;
        winner = ifWinGame(arr, -1);
        ifGameEnd(winner);
    }
    return 0;
}