#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);

	memset(ps, 0, sizeof(SeqList));
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);

	free(ps->a);	
	ps->a = NULL;	
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);

	int i;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void CheckCapcity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		(ps->capacity==0)?(ps->capacity=4): (ps->capacity*=2);
		SLDataType* newArr = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
		if (newArr != NULL)
		{
			ps->a = newArr;
		}
		else
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}
	
}
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);

	CheckCapcity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);

	CheckCapcity(ps);

	int end = ps->size-1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	int front = 1;
	while (front < ps->size)
	{
		ps->a[front - 1] = ps->a[front];
		front++;
	}
	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);

	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);

	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && ps <= ps->size);

	CheckCapcity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];	
		end--;
	}
	ps->a[end] = x;
	ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos > 0 && pos < ps->size);

	int begin = pos;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}

void SeqListModify(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(pos > 0 && pos < ps->size);

	ps->a[pos] = x;	
}