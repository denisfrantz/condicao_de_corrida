#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int a = 4;

void WINAPI ThreadUm(void){
	Sleep(50);
	a = a + 3;
}

void WINAPI ThreadDois(void){
	Sleep(50);
	a = a * 2;
}

int main(void){
	unsigned long ID;
	HANDLE hThreadUm, hThreadDois;
	
	hThreadUm = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) 
	ThreadUm, NULL, 0, &ID);
	
	hThreadDois = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) 
	ThreadDois, NULL, 0, &ID);
	
	Sleep(100);
	
	printf ("Condicao de Corrida: %d\n", a);
	TerminateThread(ThreadUm, 0);
	TerminateThread(ThreadDois, 0);
	
	system("pause");
	
	return 0;
}
