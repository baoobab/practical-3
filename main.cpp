#include <iostream>
#include "windows.h"
using namespace std;


int getRandomValueFromRange(int leftLimit, int rightLimit) {
    return leftLimit + rand() % (rightLimit - leftLimit + 1);
}

void arrPrint(int *arr, const int N) {
    for (int *next = arr, *prev = arr, *end = arr + N * N - 1; next <= end; next++) {
        if (next - N == prev) {
            cout << "\n";
            prev = next;
        }
        printf("%02d ", *next);
        // Sleep(200);
        // cout << *next << " ";
    }    
    cout << "\n\n";
}


int main() {
    const int N = 6;
    int arr[N * N] = {};
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
        arrPrint(arr, N);
        Sleep(1000);

        for (int *next = upRightCorner + N, *end = downRightCorner; next <= end; next += N) {
            // *next = getRandomValueFromRange(1, arrSize);
            *next = cnt;
            cnt++;
        }      
        arrPrint(arr, N);
        Sleep(1000);

        if (cnt > N * N) break;

        for (int *next = downRightCorner - 1, *end = downLeftCorner; next >= end; next--) {
            // *next = getRandomValueFromRange(1, arrSize);
            *next = cnt;
            cnt++;
        } 
        arrPrint(arr, N);
        Sleep(1000);

        for (int *next = downLeftCorner - N, *end = upLeftCorner + N; next >= end; next -= N) {
            // *next = getRandomValueFromRange(1, arrSize);
            *next = cnt;
            cnt++;
        }      
        arrPrint(arr, N);
        Sleep(1000);

        k++;
    }

    return 0;
}



// int main() {
//     const int N = 3;
//     const int arrSize = N * N;
//     // int arr[arrSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int arr[arrSize] = {};
//     int cnt = 1;
//     int sizer = N;

//     // cout << arr[ N - 1] << " " << arr[ arrSize - 1];
//     // cin >> cnt;
//     int test;
    // int *leftBorder = arr; 
    // int *rightBorder = &arr[N - 1];
    // int *topBorder = &arr[2 * N - 1];
    // int *bottomBorder = &arr[arrSize - 1];
//     int *pleftBorder = arr; 
//     int *prightBorder = &arr[N - 1];
//     int *ptopBorder = &arr[2 * N - 1];
//     int *pbottomBorder = &arr[arrSize - 1];

//     bool horizontalReverse = false;
//     bool verticalReverse = false;

//     while (cnt <= arrSize) {
//         // горизонтальный цикл
//         if (horizontalReverse) {
            // for (int *next = rightBorder, *end = leftBorder; next <= end; next--) {
            //     // *next = getRandomValueFromRange(1, arrSize);
            //     *next = cnt;
            //     cnt++;
            // }  
//             horizontalReverse = false;  
//             leftBorder = leftBorder - (sizer - 2);
//             rightBorder = rightBorder + (sizer - 2);
            
//             prightBorder = rightBorder;
//             pleftBorder = leftBorder;
//         } else {
//             for (int *next = leftBorder, *end = rightBorder; next <= end; next++) {
//                 // *next = getRandomValueFromRange(1, arrSize);
//                 *next = cnt;
//                 cnt++;
//             }   
//             horizontalReverse = true;  
//             leftBorder = leftBorder + 1 + (N - (sizer - 1));
//             rightBorder = rightBorder + (sizer - 3);

//             prightBorder = rightBorder;
//             pleftBorder = leftBorder; 
//         }
    
//         arrPrint(arr, N);
//         cin >> test;

//         // вертикальный цикл
//         if (verticalReverse) {
//             for (int *next = bottomBorder, *end = topBorder; next <= end; next -= sizer) {
//                 // *next = getRandomValueFromRange(1, arrSize);
//                 *next = cnt;
//                 cnt++;
//             }    
//             verticalReverse = false;
//             topBorder = topBorder + sizer - 1;
//             bottomBorder = bottomBorder + sizer - 1;

//             ptopBorder = topBorder;
//             pbottomBorder = bottomBorder;
//         } else {
            // for (int *next = topBorder, *end = bottomBorder; next <= end; next += sizer) {
            //     // *next = getRandomValueFromRange(1, arrSize);
            //     *next = cnt;
            //     cnt++;
            // }      
//             verticalReverse = false;
//             topBorder = leftBorder + sizer;
//             bottomBorder = bottomBorder - (sizer + 1) * 2; 

//             ptopBorder = topBorder;
//             pbottomBorder = bottomBorder;
//         }
        
//         arrPrint(arr, N);
//         cin >> test;
//         sizer--;

//     }

//     return 0;
// }