#include <iostream>
#include <windows.h>


using namespace std;
int* arr;
int n;

void Worker(LPVOID cru)
{
    int sum = 0;
    int even = 0;   
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
            even++;
        }
        
    }
    cout << endl << "������� �������� �������� ��������� �������: " << sum/even;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    HANDLE hHandle;
    DWORD dwMilliseconds;

    int inc = 10;

    cout << "������� ������ �������: ";
    cin >> n;
    cout << "������� ��� �������� �������: " << endl;
    int* tmp;
    arr = new int[n];
    tmp = arr;
    for  (int i = 0; i < n; i++,*tmp++)
    {
        cin >> *tmp;
    }
    hHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)
        Worker, 0, inc, &dwMilliseconds);
    if (hHandle == NULL)
    {
        return GetLastError();
    }
    WaitForSingleObject(hHandle, INFINITE);
    CloseHandle(hHandle);
}

