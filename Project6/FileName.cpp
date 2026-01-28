#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <fstream>
using namespace std;

mutex m;

void saveFile()
{
	m.lock();
	{
		ofstream out("file.txt", ios::trunc);
		if (out.is_open())
		{
			for (size_t i = 1; i < 100; i++)
			{
				i = rand() % 100;
				out << i << endl;
			}
			out.close();
		}
		m.unlock();
	}
}
void readFile()
{

	m.lock();
	ifstream in("file.txt");
	int num;
	if (in. is_open())
	{
		while (in >> num)
		{
			cout << num << endl;
			Sleep(200);
		}
	}
	m.unlock();
}
int main(   )
{
	thread t1(saveFile);
	Sleep(100);
	thread t2(readFile);

	t1.join();

	t2.join();


}