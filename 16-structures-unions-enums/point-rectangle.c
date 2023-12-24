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
	struct point center;

	width = r.lowerRight.x - r.upperLeft.x;
	height = r.upperLeft.y - r.lowerRight.y;

	center.x = r.lowerRight.x - (width / 2);
	center.y = r.upperLeft.y - (height / 2);

	printf("Width: %d\n", width);
	printf("Height: %d\n", height);
	printf("Area: %d\n", width * height);
	printf("Center: (%d, %d)\n", center.x, center.y);

}
