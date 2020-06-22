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
//	static char *src = NULL; //������һ�ηǷָ��ַ����ַ���λ��,���ͼʾ
//	const char *indelim = delim;//��delim��һ������
//	int flag = 1, index = 0;
//
//	//ÿһ�ε���strtok,flag��Ƕ���ʹ�ó���ֻ��¼�µ�һ���Ƿָ�����λ��,�Ժ���ַǷָ������ٴ���
//
//	char *temp = NULL; //����ķ���ֵ
//
//	if (str == NULL)
//	{
//		str = src;//��strΪNULL���ʾ�ó������������һ�����µ��ַ���
//	}
//	for (; *str; str++)
//	{
//		delim = indelim;
//		for (; *delim; delim++)
//		{
//			if (*str == *delim)
//			{
//				*str = NULL; //���ҵ�delim�и���Ȥ���ַ�,�����ַ���ΪNULL
//				index = 1; //��������ѳ��ָ���Ȥ�ַ�
//				break;
//			}
//		}
//		if (*str != NULL && flag == 1)
//		{
//			temp = str; //ֻ��¼�µ�ǰ��һ���Ǹ���Ȥ�ַ���λ��
//			flag = 0;
//		}
//		if (*str != NULL && flag == 0 && index == 1)
//		{
//			src = str;//�ڶ��γ��ַǸ���Ȥ�ַ���λ��(֮ǰһ�����ֹ�����Ȥ�ַ�)
//			return temp;
//		}
//	}
//	src = str;
//
//	//ִ�иþ����һֱδ���ֹ�����Ȥ�ַ�,����˵�ڳ����˸���Ȥ���ַ���,��û�ٳ��ֹ��Ǹ���Ȥ�ַ�
//
//	return temp;
//}


char *my_strtok(char *str1, const char *sep)
{
	static char *temp = NULL;//�����ϴβ�Ϊ�ָ������ַ�
	if (str1 == NULL && (str1 = temp) == NULL)//�ж�����str1�Ƿ�ΪNULL����ΪNULL������һ�������temp��ַ����str1
	{
		return NULL;
	}
	char *s = NULL;//����ֵ
	const char *t = NULL;
	int flag = 1;//��¼��һ�β�Ϊ�յĵ�ַ
	int index = 0;//�����и���������仯
	for (; *str1 != '\0'; str1++)
	{
		t = sep;
		for (; *t != '\0'; t++)
		{
			if (*str1 == *t)
			{
				*str1 = '\0';//�ÿ�
				index = 1;//���и���������仯
				break;
			}
		}
		if (*str1 != '\0' && flag == 1)//ÿһ�ε��õĵ�һ�β�Ϊ�յĵ�ַ
		{
			s = str1;//����ֵָ�������ʼ��ַ
			flag = 0;
		}
		if (*str1 != '\0' && flag == 0 && index==1)//���и�����꣬�Һ�����ֲ�Ϊ�յ��ַ���ǰ���Ѿ����ֹ��и��
		{
			temp = str1;//temp����str1��ʱ�ĵ�ַ����Ϊ�´δ���nullʱ�������ַ
			return s;//���ص�һ�β�Ϊ�յĵ�ַ
		}
	}
	temp = str1;//����û���и����ֱ����temp�������ĵ�ַ
	return s;//������ʼ��ַ
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