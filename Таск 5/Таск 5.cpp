#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    int SIZE = rand() % 21 + 10;
    int* arr = new int[SIZE];
    int maxI=0, minI=0, x = 0, y=0;
    bool re;
    for (int i = 0; i < SIZE; )
    {
        re = false;
        int newvalue = rand() % 101;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] == newvalue)
            {
                re = true;
                break;
            }
        }

        if (!re)
        {
            arr[i] = newvalue;
            i++;
        }

    }

    cout << "Случайно сгенерированный массив: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxI = i;
        }
    }

    cout << "\nМаксимальный элемент массива = " << max << " и находится на позиции под номером " << maxI << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minI = i;
        }
    }
    cout << "Минимальный элемент массива = " << min <<" и находится на позиции под номером " << minI << endl;
    x = maxI;
    y = minI;
    if (minI == maxI + 1||maxI == minI + 1)
    {
        cout << "max и min соседние элементы: массив изменен не будет, попробуйте еще раз" << endl;
    }
    
    else if (minI == maxI + 2 || maxI == minI + 2)
    {
        cout << "между max и min всего один элемент: массив изменен не будет, попробуйте еще раз" << endl;
    }

    else
    {
        while (x != y)
        {


            if (x < y && y - x > 1)
            {
                x += 1;
                y -= 1;
                swap(arr[x], arr[y]);
            }
            else if (x > y && x - y > 1)
            {
                x -= 1;
                y += 1;
                swap(arr[x], arr[y]);
            }
            else if( y - x == 1|| x - y == 1)
            {
                
                x = y;

            }
          
        }
        cout << "Пересобранный массив: ";
    for (int i = 0; i < SIZE; i++)
        {


            cout << arr[i] << " ";
        }

        delete[] arr;
    }
}
    
