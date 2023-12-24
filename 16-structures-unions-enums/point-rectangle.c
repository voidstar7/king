#include <stdio.h>

struct point { int x, y; };
struct rectangle { struct point upperLeft, lowerRight; };

void operate(struct rectangle r);

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

	operate(r);
	return 0;
}

void operate(struct rectangle r)
{
	int width, height;

	width = r.lowerRight.x - r.upperLeft.x;
	height = r.upperLeft.y - r.lowerRight.y;
	printf("Area: %d\n", width * height);
}
