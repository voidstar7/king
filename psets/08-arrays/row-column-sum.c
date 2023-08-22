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
	int i, j, k, total, quizIndex = 0, quizScore = 0, count = 0;
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

	// total and average scores for each student 
	printf("\n");
	for (i = 0; i < S; i++)
	{
		total = 0;
		for (j = 0; j < Q; j++)
		{
			total += matrix[i][j];
		}
		printf("Student %d: total = %d / average = %d\n", i + 1, total, total / Q);
	}
	total = 0;
	printf("\n");


	// lowest, highest, and average scores for each quiz
	for (i = 0; i < Q; i++)
	{
		total = 0;
		for (j = 0; j < S; j++)
		{
			total += matrix[j][i];
		}
		printf("%d ", total);
	}
	printf("\n");
	return 0;
}
