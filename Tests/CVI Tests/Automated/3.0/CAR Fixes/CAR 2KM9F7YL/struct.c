#include <userint.h>
#include <ansi_c.h>
struct _x
{
	char str[5];
};


int __declspec(dllexport) structByValue (struct _x s1, struct _x s2)
{
	int passed =   s1.str[0] == 10 
				&& s1.str[1] == 20
				&& s1.str[2] == 30
				&& s1.str[3] == 40
				&& s1.str[4] == 50
				&& s2.str[0] == 60
				&& s2.str[1] == 70
				&& s2.str[2] == 80
				&& s2.str[3] == 90
				&& s2.str[4] == 100;
		
	return passed;
}

int __declspec(dllexport) structByValue2 (struct _x s1, int i)
{
	int passed =   s1.str[0] == 10 
				&& s1.str[1] == 20
				&& s1.str[2] == 30
				&& s1.str[3] == 40
				&& s1.str[4] == 50
				&& i == 100;
	return passed;
}

int __declspec(dllexport) structByValue3 (int i, struct _x s1)
{
	int passed =  s1.str[0] == 10 
				&& s1.str[1] == 20
				&& s1.str[2] == 30
				&& s1.str[3] == 40
				&& s1.str[4] == 50
				&& i == 100;	
	return passed;
}
