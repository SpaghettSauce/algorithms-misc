#include <iostream>
#include <vector>
#include <algorithm>

const int RUN = 32;

int GetMinrun(int n) //находим минимум размер для подмассива
	{
	    int r = 0;           
	    while (n >= 64) 
        { //хз 64 лучшее что может быть
	        r |= n & 1;
	        n >>= 1;
	    }
	    return n + r;
	} 

void insertionSort(std::vector<int>& arr, int left, int right) 
{ //для сортировки маленьких кусков массива
    for (int i = left + 1; i <= right; i++)
     {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(std::vector<int>& arr, int l, int m, int r) 
{ //делим массив на две части, и из этих частей собираем нвоый массив
    int len1 = m - l + 1, len2 = r - m;
    std::vector<int> left(len1), right(len2);
    
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) 
    {
        if (left[i] <= right[j]) 
        {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) 
    {
        arr[k] = left[i];
        i++; k++;
    }

    while (j < len2) 
    {
        arr[k] = right[j];
        j++; k++;
    }
}

void timSort(std::vector<int>& arr, int n) 
{
    for (int i = 0; i < n; i += RUN) //сначала делим массив на маленькие куски и сортируем insertion сортом
        insertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size) 
    {   //собираем эти куски и сортируем мерджем
        for (int left = 0; left < n; left += 2 * size) 
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int main() {
    std::vector<int> arr = {5, 21, 7, 23, 19, 1, 3, 4, 6, 9, 8, 12};
    int n = arr.size();
    int Q = GetMinrun(n);
    std::cout << "Массив: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";
    
    timSort(arr, n);
    
    std::cout << "Отсортил: ";
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";
    
    return 0;
}
