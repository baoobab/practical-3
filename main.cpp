#include <iostream>
#include "windows.h"
using namespace std;


int getRandomValueFromRange(int leftLimit, int rightLimit) {
    return leftLimit + rand() % (rightLimit - leftLimit + 1);
}

void matrixBlockReplacement(int* blocks[], int* blocksNew[], const int N) {
    const int distance = (N - 4) / 2;
    for (int i = 0; i < 4; i++) {
        for (int *next = blocks[i], *end = blocks[i] + N / 2 - 1, cnt = 1,
        *next2 = blocksNew[i]; cnt < (N / 2) * (N / 2) - distance; next++, next2++ ) {                       
            if (next == end) {
                blocks[i] += N;
                blocksNew[i] += N;

                *next2 = *next;

                next = blocks[i];
                next2 = blocksNew[i];
                end = blocks[i] + N / 2 - 1;
            }
            cnt++;
            if (cnt >= (N / 2) * (N / 2) - distance) break;
            *next2 = *next;
        } 
    }    
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

void matrixOperation(int *arr, const int N, const int operationType, int number = 0) {
    switch (operationType) 
    {
        case 0: {
            for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
                *next += number;
            }   
            break;
        }
        case 1: {
            for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
                *next -= number;
            }   
            break;
        }
        case 2: {
            for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
                *next *= number;
            }   
            break;
        }
        case 3: {
            for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
                *next /= number;
            }   
            break;
        }
    }
}

void arrayPrint(int *arr, const int N) {
    for (int *next = arr, *prev = arr, *end = arr + N - 1; next <= end; next++) {
        printf("%02d ", *next);
    }    
    cout << "\n\n";
}

void bubbleSort(int *arr, const int N) {
    for (int *i = arr, *end = arr + N - 1; i <= end; i++) {
        for (int *j = arr, *end = arr + N - 0 - 1; j <= end; j++) {
            int swap = *j;
            if (*j > *(j + 1)) {
                *j = *(j + 1);
               *(j + 1) = swap;
            }
        } 
    } 
}

void shakerSort(int *arr, const int N) {
    for (int *i = arr, *end = arr + N / 2; i <= end; i++) {
        for (int *j = i, *end = arr + N - 0 - 1; j <= end; j++) {
            int swap = *j;
            if (*j > *(j + 1)) {
                *j = *(j + 1);
               *(j + 1) = swap;
            }
        } 
    } 

    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int swap = arr[j];
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }

        for (int j = N - i - 2; j > i; j--) {
            int swap = arr[j];
            if (arr[j - 1] > arr[j]) {
                arr[j] = arr[j - 1];
                arr[j - 1] = swap;
            }
        }
    } 
}

// void combSort(int *arr, const int N) {
// 	float k = 1.247;
//     float S = N - 1;
// 	int count = 0;

// 	while (S >= 1)
// 	{
// 		for (int *i = arr, *end = i + S; i + S < N; i++)
// 		{
// 			if (arr[i] > arr[int(i + S)])
// 			{
// 				int swap = arr[int(i + S)];
// 				arr[int(i + S)] = arr[i];
// 				arr[i] = swap;
// 			}
// 		}
// 		S /= k;
// 	}

//     bubbleSort(arr, N);
// }

void insertSort(int *arr, const int N) {
    int key;
    for (int *i = &arr[1], *j = 0, *end = arr + N - 1; i <= end; i++) {
        key = *i;
        j = i - 1;

        while (j >= arr && *j > key) {
            *(j + 1) = *j;
            j = j - 1;
        }
        *(j + 1) = key;
    }
}

// void quickSort(int *arr, int *start, int *end)
// {
// 	int mid;
// 	int *f = start; 
// 	int *l = end;
// 	mid = *((f + l) / 2);
// 	while (f < l)
// 	{
// 		while (arr[f] < mid) f++;
// 		while (arr[l] > mid) l--;
// 		if (f <= l)
// 		{
// 			swap(arr[f], arr[l]);
// 			f++;
// 			l--;
// 		}
// 	}
// 	if (start < l) quickSort(arr, start, l);
// 	if (f < end) quickSort(arr, f, end);
// }


int main() {
    setlocale(LC_ALL, "Russian");
    int a[5] = {5000,-874,3,2,-1};
    insertSort(a, 5);
    arrayPrint(a, 5);

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
                matrixPrint(arr, N);

                cout << "1.B)" << "\n";
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
                matrixPrint(arr, N);
                break;
            }
            case 2: {
                int arrNew[N * N] = {};

                cout << "\n" << "2.A)" << "\n";

                int* blocksA[4] = {&arr[0], &arr[N / 2], &arr[N / 2 + N * (N / 2)], &arr[(N * N) / 2]};
                int* blocksNewA[4] = {&arrNew[N / 2], &arrNew[N / 2 + N * (N / 2)], &arrNew[(N * N) / 2], &arrNew[0]};
                matrixBlockReplacement(blocksA, blocksNewA, N);
                matrixPrint(arrNew, N);

                cout << "\n" << "2.B)" << "\n";
                int* blocksB[4] = {&arr[0], &arr[N / 2 + N * (N / 2)], &arr[(N * N) / 2], &arr[N / 2]};
                int* blocksNewB[4] = {&arrNew[N / 2 + N * (N / 2)], &arrNew[0], &arrNew[N / 2], &arrNew[(N * N) / 2]};
                matrixBlockReplacement(blocksB, blocksNewB, N);
                matrixPrint(arrNew, N);

                cout << "\n" << "2.C)" << "\n";
                int* blocksC[4] = {&arr[0], &arr[(N * N) / 2], &arr[N / 2], &arr[N / 2 + N * (N / 2)]};
                int* blocksNewC[4] = {&arrNew[(N * N) / 2], &arrNew[0], &arrNew[N / 2 + N * (N / 2)], &arrNew[N / 2]};
                matrixBlockReplacement(blocksC, blocksNewC, N);
                matrixPrint(arrNew, N);

                cout << "\n" << "2.D)" << "\n";
                int* blocksD[4] = {&arr[0], &arr[N / 2], &arr[(N * N) / 2], &arr[N / 2 + N * (N / 2)]};
                int* blocksNewD[4] = {&arrNew[N / 2], &arrNew[0], &arrNew[N / 2 + N * (N / 2)], &arrNew[(N * N) / 2]};
                matrixBlockReplacement(blocksD, blocksNewD, N);
                matrixPrint(arrNew, N);

                break;
            }
            case 3: {
                break;
            }
            case 4: {                
                int operationType;
                cout << "\n" << "Enter an operation type (0:+, 1:-, 2:*. 3:/): ";
                cin >> operationType;
                
                if (!cin.good() || operationType < 0 || operationType > 3) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                int a;
                cout << "\n" << "Enter an integer: ";
                cin >> a;
                if (!cin.good()) {
                    cout << "\n" << "You entered an incorrect value";
                    break;
                }

                matrixOperation(arr, N, operationType, a);
                matrixPrint(arr, N);
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
        
        char clearMatrix;
        cout << "\n" << "Clear the result matrix? (Y/N) ";
        cin >> clearMatrix;
        
        if (clearMatrix == 'Y' || clearMatrix == 'y') {
            matrixFill(arr, N);
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