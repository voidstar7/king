#include <stdio.h>
#include <ctype.h>

#define S 5
#define Q 5
#define DIGIT (int)(buffer[i] - 48)

// Prompts for 5 quiz grades for 5 students, then computes:
// total and average score for each student
// average score, high score, and low score for each quiz

int main(void)
{
	int matrix[S][Q];
	int i, j, k, temp, quizIndex = 0, quizScore = 0, count = 0;
	char buffer[100];
	char c; 

	for (k = 0; k < S; k++)
	{
		printf("Student %d quiz scores: ", k + 1);
		while (1)
		{
			c = getchar();
			if (c == 10)
				break;
			buffer[count] = c;
			count++;
		}
		buffer[count] = '\0';
		for (i = 0; i <= count; i++)
		{
			if (isdigit(buffer[i]))
			{
				if (quizScore == 0)	
					quizScore += DIGIT;
				else
					quizScore = quizScore * 10 + DIGIT;
				continue;
			}
			matrix[k][quizIndex] = quizScore;
			quizScore = 0;
			quizIndex++;
		}
		quizIndex = 0;
		count = 0;
	}

	// total scores for each student 
	printf("\n");
	for (i = 0; i < S; i++)
	{
		printf("Student %d total scores (all quizzes): ", i + 1);
		temp = 0;
		for (j = 0; j < Q; j++)
		{
			temp += matrix[i][j];
		}
		printf("%d\n", temp);
	}
	temp = 0;
	printf("\n");


	/*
	printf("Column totals: ");
	for (i = 0; i < Q; i++)
	{
		temp = 0;
		for (j = 0; j < S; j++)
		{
			temp += matrix[j][i];
		}
		printf("%d ", temp);
	}
	printf("\n");
	return 0;
	*/
}
