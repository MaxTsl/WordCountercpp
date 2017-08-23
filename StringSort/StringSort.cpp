// StringSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

inline bool myfunction(const char* ch1, const char* ch2)
{ 
	return strcmp(ch1, ch2) < 0; 
}

int main()
{
	clock_t t = clock(), t1, t2, t3;

	size_t length = 90000000;
	char*   max_buf = new char[length];
	char**	ptrs = new char*[length/2];
	int cnt = 0, k = 0;
	long simbols = 0;

	FILE*         ifp;  // input  file pointer
	if ((ifp = fopen("111.txt", "r")) == NULL) return 0;
	size_t        nread;
	simbols = nread = fread(max_buf, sizeof(char), sizeof(char) * length, ifp);

	bool Begin =false;
	unsigned char ch;
	for (int i = 0; i < nread; i++)
	{
		ch = max_buf[i];
		if (ch != 32)
			// если надо добыть только слова и буквенные части из абракадабры смешанной с символами и знаками
		/*if (ch < 47 ||
			(ch> 60 && ch < 65)
			|| (ch>90 && ch < 97)
			|| (ch>122 && ch < 192))*/
		{
			Begin = true;
			max_buf[i] = '\0';
		}
		else
		{
			if (Begin)
			{
				ptrs[k] = &max_buf[i];
				++k;
				Begin = false;
			}
		}

	}
	t1 = clock();
	sort(ptrs, ptrs+k, myfunction);
	t2 = clock();
	fclose(ifp);
	int count = 1;
	ofstream off("out.txt");
	for (int i = 1; i < k; i++)
	{
		if (strcmp(ptrs[i-1] , ptrs[i]) == 0)
			++count;
		else
		{
			off <<ptrs[i - 1]  << " " << count << "\n";
			count = 1;
		}

	}
	off.close();
	t3= clock();


	
	printf("read+divode took me %d \n", t1 - t );
	printf("sort took me %d \n", t2 - t1);
	printf("out took me %d \n", t3 - t2);
	t = clock() - t;
	printf("it took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
	printf("bufers = %d,simbols = %d count words = %d. \n", cnt, simbols, k);
	system("PAUSE");
    return 0;
}

