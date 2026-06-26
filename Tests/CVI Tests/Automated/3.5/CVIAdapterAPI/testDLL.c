
long __declspec(dllexport) test(long *iSize, char cName[512])
{
	return (long) cName[*iSize];
}
