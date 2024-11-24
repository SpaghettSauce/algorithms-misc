
#include <stdio.h>
#include <windows.h>
#include <process.h>

void routine(void *a)
{
	int n = *(int *) a;  //приписываем n значение int a
	Sleep(n * 100); //спим 10 мс
	printf("%d ", n);
}

void sleepSort(int arr[], int n)
{
	HANDLE threads[n]; //референсы на потоки, у каждого потока свой элемент в массиве

	for (int i = 0; i < n; i++)
		threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]); //новый поток через routine, 0 - системный (???)

	WaitForMultipleObjects(n, threads, TRUE, INFINITE); //не запускает main пока все потоки не завершились (n кол-во,True - все потоки, infinite, предел ожидания)
	return;
}

int main()
{
	int arr[] = {5,3,10,1};
	int n = sizeof(arr) / sizeof(arr[0]);

	sleepSort (arr, n);

	return(0);
}
