#include "maze.h"


void StackInit(Stack *s, int capacity)
{
	assert(s && capacity>0);
	DataType *p = (DataType *)malloc(sizeof(DataType)*capacity);
	assert(p);
	s->array = p;
	memset(s->array, 0, sizeof(DataType)*capacity);
	s->capacity = capacity;
	s->top = 0;
}

void StackCheckMem(Stack *s)
{
	if (s->capacity == s->top)
	{
		s->capacity *= 2;
		DataType *p = (DataType *)realloc(s->array, sizeof(DataType)* (s ->capacity));
		assert(p);
		s->array = p;
	}
}

void StackPush(Stack *s, DataType data)
{
	assert(s);
	StackCheckMem(s);
	s->array[s->top++] = data;
}

void StackPop(Stack *s)
{
	assert(s);
	if (s->top == 0)
		return;
	else
	{
		--s->top;
	}
}

DataType StackTop(Stack *s)
{
	assert(s);
	return s->array[s->top-1];
}

int StackSize(Stack *s)
{
	assert(s);
	return s->top;
}

int StackEmpty(Stack *s)
{
	assert(s);
	if (s->top == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//��ӡ�Թ�
void MazePrint(Maze *m)
{
	assert(m);
	size_t i = 0;
	for (; i < N; i++)
	{
		size_t j = 0;
		for (; j < N; j++)
		{
			printf("%d  ", m->arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

//�Թ���ʼ��
void MazeInit(Maze *m, int a[][N])
{
	assert(m);
	size_t i = 0;
	for (; i < N; i++)
	{
		size_t j = 0;
		for (; j < N; j++)
		{
			m->arr[i][j] = /*a[i*N + j];*/a[i][j];
		}
	}
	m->enter._row = 5;
	m->enter._col = 1;
}

int CheckIsAccess(Maze *m, Pos next)
{
	if (next._col >= 0 && next._col < 6
		&& next._row >= 0 && next._row < 6
		&& m->arr[next._row][next._col]  == 1)
	{
		return 1;
	}
	else
		return 0;
}

void MazeGetPath(Maze *m)
{
	assert(m);
	Stack s;
	StackInit(&s, 1);
	StackPush(&s, m->enter);//�����������ջ
	m->arr[m->enter._row][m->enter._col] = 2;//�߹���·���Ϊ2�����ݵ�·���Ϊ3
	while (StackEmpty(&s) != 0)
	{
		Pos cur = StackTop(&s);
		//curȡֵ���ֿ�����
		//1. ���
		//2. ��һ�������ߵ�λ��
		//3. ���ݵ���һ��λ��

		////�߹���·���Ϊ2
		//m->arr[cur._row][cur._col] = 2;

		//�����6���ǳ���
		if (cur._col == N - 1)
		{
			printf("�ҵ�ͨ·��\n");
			return;
		}
		Pos next = cur;

		//��
		next._row -= 1;
		if (CheckIsAccess(m, next) != 0)
		{
			m->arr[next._row][next._col] = 2;//�߹���·���Ϊ2�����ݵ�·���Ϊ3
			StackPush(&s, next);//��������ջ
			MazePrint(m);

			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (CheckIsAccess(m, next) != 0)
		{
			m->arr[next._row][next._col] = 2;//�߹���·���Ϊ2�����ݵ�·���Ϊ3
			StackPush(&s, next);//��������ջ
			MazePrint(m);

			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckIsAccess(m, next) != 0)
		{
			m->arr[next._row][next._col] = 2;//�߹���·���Ϊ2�����ݵ�·���Ϊ3
			StackPush(&s, next);//��������ջ
			MazePrint(m);

			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (CheckIsAccess(m, next) != 0)
		{
			m->arr[next._row][next._col] = 2;//�߹���·���Ϊ2�����ݵ�·���Ϊ3
			StackPush(&s, next);//��������ջ
			MazePrint(m);

			continue;
		}
		//����
		next = cur;
		m->arr[next._row][next._col] = 3; //�߹���·���Ϊ2�����ݵ�·���Ϊ3
		MazePrint(m);
		StackPop(&s);
	}
	printf("û��ͨ·\n");
}

//ջ�Ŀ���
void StackCopy(Stack *s1,Stack *s2)
{
	assert(s1 && s2);
	if (s1->top == 0)
	{
		s2->top = 0;
	}
	else
	{
		if (s1->top > s2->capacity)
		{
			DataType *p = (DataType *)realloc(s2->array, s1->top*sizeof(DataType));
			assert(p);
			s2->array = p;
			s2->capacity = s1->top;
		}
		s2->top = s1->top;
		memcpy(s2->array, s1->array, sizeof(DataType)*s1->top);
	}
}

//�ݹ�
void MazeGetShortPath(Maze *m, Pos cur,Stack *path,Stack *shortpath)
{
	Pos next, pos;

	StackPush(path, cur);
	//���߹���·���
	m->arr[cur._row][cur._col] = 2;
	if (cur._col == N - 1)
	{
		if (StackSize(shortpath) == 0 || StackSize(path) < StackSize(shortpath))
		{
			StackCopy(path, shortpath);
		}

		/*pos = StackTop(path);
		m->arr[pos._row][pos._col] = 1;
		StackPop(path);

		return;*/

	}
	//up
	next = cur;
	next._row -= 1;
	if (CheckIsAccess(m, next) == 1)
	{
		MazeGetShortPath(m,next,path,shortpath);
	}

	//down
	next = cur;
	next._row += 1;
	if (CheckIsAccess(m, next) == 1)
	{
		MazeGetShortPath(m, next, path, shortpath);

	}

	//left
	next = cur;
	next._col -= 1;
	if (CheckIsAccess(m, next) == 1)
	{
		MazeGetShortPath(m, next, path, shortpath);

	}

	//right
	next = cur;
	next._col += 1;
	if (CheckIsAccess(m, next) == 1)
	{
		MazeGetShortPath(m, next, path, shortpath);

	}
	pos = StackTop(path);
	m->arr[pos._row][pos._col] = 1;
	StackPop(path);
}


//�沨�����ʽ
//atoiת����




