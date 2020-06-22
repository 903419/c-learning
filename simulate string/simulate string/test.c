#include "main.h"

char *my_strncpy(char *dst, const char *src, size_t num)
{
	char *temp = dst;
	int i = 0;
	for (; i < (int)num; i++)
	{
		if (*src != '\0')
		{
			*dst = *src;
			dst++, src++;
		}
		else
		{
			*dst = '\0';
			dst++;
		}
	}
	return temp;
}


char *my_strncat(char *dst, const char *src, size_t num)
{
	char *temp = dst;
	while (*dst != 0)
	{
		dst++;
	}
	int i = 0;
	for (; i < (int )num; i++)
	{
		if(*src=='\0')
		{ 
			break;
		}
		else 
		{
			*dst = *src;
			dst++, src++;
		}
	}
	*dst = '\0';
	return temp;
}


//char *strtok(char *str, const char *delim)
//{
//	static char *src = NULL; //记下上一次非分隔字符串字符的位置,详见图示
//	const char *indelim = delim;//对delim做一个备份
//	int flag = 1, index = 0;
//
//	//每一次调用strtok,flag标记都会使得程序只记录下第一个非分隔符的位置,以后出现非分隔符不再处理
//
//	char *temp = NULL; //程序的返回值
//
//	if (str == NULL)
//	{
//		str = src;//若str为NULL则表示该程序继续处理上一次余下的字符串
//	}
//	for (; *str; str++)
//	{
//		delim = indelim;
//		for (; *delim; delim++)
//		{
//			if (*str == *delim)
//			{
//				*str = NULL; //若找到delim中感兴趣的字符,将该字符置为NULL
//				index = 1; //用来标记已出现感兴趣字符
//				break;
//			}
//		}
//		if (*str != NULL && flag == 1)
//		{
//			temp = str; //只记录下当前第一个非感兴趣字符的位置
//			flag = 0;
//		}
//		if (*str != NULL && flag == 0 && index == 1)
//		{
//			src = str;//第二次出现非感兴趣字符的位置(之前一定出现过感兴趣字符)
//			return temp;
//		}
//	}
//	src = str;
//
//	//执行该句表明一直未出现过感兴趣字符,或者说在出现了感兴趣的字符后,就没再出现过非感兴趣字符
//
//	return temp;
//}


char *my_strtok(char *str1, const char *sep)
{
	static char *temp = NULL;//保存上次不为分隔符的字符
	if (str1 == NULL && (str1 = temp) == NULL)//判定传输str1是否为NULL，若为NULL，将上一个保存的temp地址赋给str1
	{
		return NULL;
	}
	char *s = NULL;//返回值
	const char *t = NULL;
	int flag = 1;//记录第一次不为空的地址
	int index = 0;//若有切割符，发生变化
	for (; *str1 != '\0'; str1++)
	{
		t = sep;
		for (; *t != '\0'; t++)
		{
			if (*str1 == *t)
			{
				*str1 = '\0';//置空
				index = 1;//有切割符，发生变化
				break;
			}
		}
		if (*str1 != '\0' && flag == 1)//每一次调用的第一次不为空的地址
		{
			s = str1;//返回值指向这个起始地址
			flag = 0;
		}
		if (*str1 != '\0' && flag == 0 && index==1)//将切割符走完，且后面出现不为空的字符，前面已经出现过切割符
		{
			temp = str1;//temp保存str1此时的地址，作为下次传入null时的输入地址
			return s;//返回第一次不为空的地址
		}
	}
	temp = str1;//里面没有切割符，直接令temp等于最后的地址
	return s;//返回起始地址
}

void my_memmove(const void *dst, const void * src, int count)
{
	assert(dst);
	assert(src);
	if ((char *)dst > (char *)src && (char *)dst < (char *)src + count)
	{
		(char *)dst = (char *)dst + count-1;
		(char *)src = (char *)src + count-1;
		while (count)
		{
			*(char *)dst = *(char *)src;
			(char *)dst = (char *)dst - 1;
			(char *)src = (char *)src - 1;
			count--;
		}
	}
	else
	{
		while (count)
		{
			*(char *)dst = *(char *)src;
			(char *)dst = (char *)dst + 1;
			(char *)src = (char *)src + 1;
			count--;
		}
	}
}


void my_memcpy(void *dst, void *src, int count)
{
	int i = 0;
	char *s1 = (char *)dst;
	char *s2 = (char*)src;
	for (; i < count; i++)
	{
		*s1 = *s2;
		s1 = s1 + 1;
		s2 = s2 + 1;
	}
}

char *my_strstr(const char *str1, const char * str2)
{
	assert(str1);
	assert(str2);
	int i = 0; 
	char *cp = (char *)str1;
	char *s1 = (char *)str1;
	char *s2 = (char *)str2;
	if (*s2)
	{
		while (*cp)
		{
			s1 = cp;
			s2 = (char *)str2;
			while (*s2 && *s1 && *s1 == *s2)
			{
				s1++;
				s2++;
			}
			if (*s2 == '\0')
			{
				return cp;
			}
			cp++;

		}
		return NULL;
	}
	else
		return NULL;
}


int my_strlen(char *str)
{
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;	
}


void Cpy(char *str1, char *str2)
{
	while (*str2)
	{
		*str1 = *str2;
		str1++, str2++;
	}
	*str1 = *str2;
}


int Cmp(char *str1, char *str2)
{
	int num = 0;
	while (*str1 || *str2)
	{
		num = *(unsigned char*)str1 - *(unsigned char*)str2;
		str1++, str2++;
		if (num != 0)
		{
			break;
		}
	}
	if (num > 0)
	{
		return 1;
	}
	else if (num < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

void Link(char *str1, char *str2, int num1, int num2)
{
	int i = 0;
	for (; i <= num2; i++)
	{
		str1[i + num1] = str2[i];
	}
}