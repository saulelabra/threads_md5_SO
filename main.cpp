//Saúl Enrique Labra Cruz A01020725
//Actividad 4 - Hilos
//21 - Septiembre - 2018
//Nota: para compilar --> g++ -std=c++11 main.cpp md5.cpp -lpthread

#include "md5.h"
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#define NUM_THREADS 5

using namespace std;

void md5L(string dict, string pwdEnc, int tid)
{
	string check;

	ifstream file;
	file.open(dict.c_str());

	while(file >> check)
	{
		if(md5(check) == pwdEnc)
		{
			cout << "La palabra es: " << check << " en diccionario " << tid << endl;
		}
	}

	file.close();
}
int main()
{
	string pwd = "revoluciones";
	string dictNam[] = {"diccionario1.txt", "diccionario2.txt", "diccionario3.txt", "diccionario4.txt", "diccionrio5.txt"};

	string md5Pwd = md5(pwd);
	cout << "Se prueba la entrada: " << md5Pwd << endl;

	thread thds[NUM_THREADS];

	for(int i=0; i<NUM_THREADS; i++)
	{
		thds[i] = thread(md5L, dictNam[i], md5Pwd, i);
	}

	for(int i=0; i<NUM_THREADS; i++)
	{
		thds[i].join();
	}

    return 0;
}
