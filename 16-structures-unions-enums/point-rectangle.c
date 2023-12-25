#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };
struct rectangle { struct point upperLeft, lowerRight; };

void operate(struct rectangle r);
struct rectangle shift(struct rectangle r, int x, int y);
bool check_coordinates(struct rectangle s, struct point isInRectangle);

int main(void)
{
	struct point ul, lr, isInRectangle;
	struct rectangle r;

	printf("Upper left (x, y): ");
	scanf("%d, %d", &r.upperLeft.x, &r.upperLeft.y);
	printf("Lower right (x, y): ");
	scanf("%d, %d", &r.lowerRight.x, &r.lowerRight.y);

	operate(r);
	return 0;
}

void operate(struct rectangle r)
{
	int width, height, upDown, rightLeft;
	struct point center, isInRectangle;
	struct rectangle s;

	width = r.lowerRight.x - r.upperLeft.x;
	height = r.upperLeft.y - r.lowerRight.y;

	center.x = r.lowerRight.x - (width / 2);
	center.y = r.upperLeft.y - (height / 2);

	printf("Width: %d\nHeight: %d\nArea: %d\nCenter: (%d, %d)\n", width, height, width * height, center.x, center.y);

	printf("Rectangle upper left: (%d, %d)\nRectangle lower right: (%d, %d)\n",
			r.upperLeft.x, r.upperLeft.y,
			r.lowerRight.x, r.lowerRight.y);

	// positive = up, negative = down
	printf("Shift up/down (+/-): ");
	scanf("%d", &upDown);

	// positive = right, negative = left
	printf("Shift right/left (+/-): ");
	scanf("%d", &rightLeft);

	s = shift(r, upDown, rightLeft);
	printf("Shifted rectangle upper left: (%d, %d)\nShifted rectangle lower right: (%d, %d)\n",
			s.upperLeft.x, s.upperLeft.y,
			s.lowerRight.x, s.lowerRight.y);

	printf("Enter coordinates (x, y): ");
	scanf("%d, %d", &isInRectangle.x, &isInRectangle.y);
	if (check_coordinates(s, isInRectangle))
		printf("Coordinates are within the shifted rectangle\n");
	else
		printf("Coordinates are not within the shifted rectangle\n");
}

struct rectangle shift(struct rectangle r, int x, int y)
{
	r.upperLeft.x += x;
	r.upperLeft.y += y;
	r.lowerRight.x += x;
	r.lowerRight.y += y;
	return r;
}

bool check_coordinates(struct rectangle s, struct point isInRectangle)
{
	if (isInRectangle.x > s.lowerRight.x ||
			isInRectangle.y > s.upperLeft.y)
		return false;
	return true;
}

