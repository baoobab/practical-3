#include <iostream>
#include "windows.h"
using namespace std;


int getRandomValueFromRange(int leftLimit, int rightLimit) {
    return leftLimit + rand() % (rightLimit - leftLimit + 1);
}

void matrixPrint(int *arr, const int N) {
    for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
        if (next - N == prev) {
            cout << "\n";
            prev = next;
        }
        printf("%02d ", *next);
    }    
    cout << "\n\n";
}

void matrixFill(int *arr, const int N, int number = 0) {
    for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
        *next = number;
    }    
}


int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Navigation:" << "\n"
    << "1) Fill a quadratic integer matrix NxN with random numbers" << "\n"
    << "2) Obtains a new matrix from the matrix of (1), rearranging its blocks" << "\n"
    << "3) Using pointer arithmetic, sorts elements (quick sort algorithm)" << "\n"
    << "4) Decrements, increases, multiplies, or divides all elements of a matrix by <number>" << "\n"
    << "5) IDZ (work in process)" << "\n";

    const int N = 6;
    int arr[N * N] = {};
    
    while(true) {
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        short int workPoint;
        
        cout << "Select point of work (number 1 to 5): ";
        cin >> workPoint;

        switch (workPoint)
        {   
            case 1: {
                cout << "1.A)\n";
                matrixFill(arr, N); // clear the matrix (for better visibility of the algorithm)

                int cnt = 1;
                int k = 1;

                while (cnt <= N * N) {
                    int *upLeftCorner = &arr[(k - 1) * N + (k - 1)]; 
                    int *upRightCorner = &arr[k * N - 1 - (k - 1)];
                    int *downLeftCorner = &arr[N * N - (k * N) + (k - 1)];
                    int *downRightCorner = &arr[N * N - ((k - 1) * N) - 1 - (k - 1)];

                    for (int *next = upLeftCorner, *end = upRightCorner; next <= end; next++) {
                        // *next = getRandomValueFromRange(1, arrSize);
                        *next = cnt;
                        cnt++;
                    } 
                    // matrixPrint(arr, N);
                    // Sleep(1000);

                    for (int *next = upRightCorner + N, *end = downRightCorner; next <= end; next += N) {
                        // *next = getRandomValueFromRange(1, arrSize);
                        *next = cnt;
                        cnt++;
                    }      
                    // matrixPrint(arr, N);
                    // Sleep(1000);

                    if (cnt > N * N) break;

                    for (int *next = downRightCorner - 1, *end = downLeftCorner; next >= end; next--) {
                        // *next = getRandomValueFromRange(1, arrSize);
                        *next = cnt;
                        cnt++;
                    } 
                    // matrixPrint(arr, N);
                    // Sleep(1000);

                    for (int *next = downLeftCorner - N, *end = upLeftCorner + N; next >= end; next -= N) {
                        // *next = getRandomValueFromRange(1, arrSize);
                        *next = cnt;
                        cnt++;
                    }      
                    // matrixPrint(arr, N);
                    // Sleep(1000);

                    k++;
                }

                cout << "\n" << "1.B)" << "\n";
                matrixFill(arr, N); // clear the matrix (for better visibility of the algorithm)

                cnt = 1;
                k = 0;

                int *upBorder = &arr[k]; 
                int *downBorder = &arr[N * N - N + k];

                while (cnt <= N * N) {
                    for (int *next = upBorder + k, *end = downBorder + k; next <= end; next += N) {
                        // *next = getRandomValueFromRange(1, arrSize);
                        *next = cnt;
                        cnt++;
                    } 
                    // matrixPrint(arr, N);
                    // Sleep(1000);

                    k++;

                    for (int *next = downBorder + k, *end = upBorder + k; next >= end; next -= N) {
                        // *next = getRandomValueFromRange(1, arrSize);
                        *next = cnt;
                        cnt++;
                    } 
                    // matrixPrint(arr, N);
                    // Sleep(1000);

                    k++;
                }

                break;
            }
            case 2: {
                cout << "\n" << "2.A)" << "\n";
                int arrNew[N * N] = {};

                int* blocks[4] = {&arr[0], &arr[N / 2], &arr[N / 2 + N * (N / 2)], &arr[(N * N) / 2]};
                int* blocksNew[4] = {&arrNew[N / 2], &arrNew[N / 2 + N * (N / 2)], &arrNew[(N * N) / 2], &arrNew[0]};

                for (int i = 0; i < 4; i++) {
                    for (int *next = blocks[i], *end = blocks[i] + N / 2 - 1, cnt = 1,
                    *next2 = blocksNew[i]; cnt < (N / 2) * (N / 2) - 1; next++, next2++ ) {                       
                        if (next == end) {
                            blocks[i] += N;
                            blocksNew[i] += N;

                            *next2 = *next;

                            next = blocks[i];
                            next2 = blocksNew[i];
                            end = blocks[i] + N / 2 - 1;
                        }
                        cnt++;
                        if (cnt >= (N / 2) * (N / 2) - 1) break;
                        *next2 = *next;
                    } 
                }

                matrixPrint(arrNew, N);
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "\n" << "You did not enter a number in the range from 1 to 5";
                break;
            }
        }

        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        
        char printMatrix;
        cout << "\n" << "Print the result matrix? (Y/N) ";
        cin >> printMatrix;
        
        if (printMatrix == 'Y' || printMatrix == 'y') {
            matrixPrint(arr, N);
        }
        cin.clear();
        cin.sync();

        char stopFlag;
        cout << "\n" << "Continue the program? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }
    
    return 0;
}