#include <stdio.h>

struct point { int x, y; };
struct rectangle { struct point upperLeft, lowerRight; };

int main(void)
{
	struct point ul, lr;
	struct rectangle r;

	printf("Upper left (x): ");
	scanf("%d", &r.upperLeft.x);
	printf("Upper left (y): ");
	scanf("%d", &r.upperLeft.y);

	printf("Lower right (x): ");
	scanf("%d", &r.lowerRight.x);
	printf("Lower left (y): ");
	scanf("%d", &r.lowerRight.y);

}
