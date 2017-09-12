#include<stdio.h>

struct Person
{
	char name[20];
	int hight;
	int weight;
};

void Output(struct Person* person)
{
	printf("\n\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\t%d\t%d\n", person[i].name, person[i].hight, person[i].weight);
	}

	return;
}

struct Person Input(void)
{
	struct Person tempPerson;

	scanf("%s %d %d", tempPerson.name, &tempPerson.hight, &tempPerson.weight);

	return tempPerson;
}

void swap(struct Person* a, struct Person* b)
{
	struct Person temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void sort(struct Person* person)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (person[i].hight > person[j].hight)
			{
				swap(&person[i], &person[j]);
			}
		}
	}

	return;
}

int main(void)
{
	struct Person person[5];

	for (int i = 0; i < 5; i++)
	{
		person[i] = Input();
	}

	sort(person);

	Output(person);

	return 0;
}