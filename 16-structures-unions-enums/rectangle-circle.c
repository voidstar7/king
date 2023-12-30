#include <stdio.h>
#include <math.h>

#define RECTANGLE 1
#define CIRCLE 2

struct point { int x, y; };
struct shape
{
	int shape_kind;
	struct point center;
	union
	{
		struct { int height, width; } rectangle;
		struct { int radius; } circle;
	} u;
} s, t, u;

double area(struct shape s);
struct shape move(struct shape s);
struct shape scale(struct shape t);

int main(void)
{
	printf("Select shape (1) rectangle (2) circle: ");
	scanf("%d", &s.shape_kind);
	printf("Enter center coordinates (x, y): ");
	scanf("%d, %d", &s.center.x, &s.center.y);

	if (s.shape_kind == RECTANGLE)
	{
		s.u.rectangle.height = 25;
		s.u.rectangle.width = 8;
		printf("Area: %d\nCenter: (%d, %d)\n", 
				(int)area(s),
				s.center.x, 
				s.center.y);
	}
	else
	{
		s.u.circle.radius = 5;
		printf("Area: %lf\nCenter: (%d, %d)\n", 
				area(s),
				s.center.x, 
				s.center.y);
	}

	t = move(s);
	printf("Center: (%d, %d)\n", t.center.x, t.center.y);

	u = scale(t);
	if (u.shape_kind == CIRCLE)
		printf("New radius: %d\n", u.u.circle.radius);
	else
		printf("New width: %d\nNew height: %d\n",
				u.u.rectangle.width,
				u.u.rectangle.height);

	return 0;
}

double area(struct shape s)
{
	if (s.shape_kind == RECTANGLE)
		return s.u.rectangle.width * s.u.rectangle.height;
	else 
		return M_PI * pow(s.u.circle.radius, 2);
}

struct shape move(struct shape s)
{
	int leftRight, upDown;

	printf("Move shape right/left (+/-): ");
		scanf("%d", &leftRight);
	printf("Move shape up/down (+/-): ");
		scanf("%d", &upDown);
	
	s.center.x += leftRight;
	s.center.y += upDown;

	return s;
}

struct shape scale(struct shape t)
{
	double scale;

	printf("Enter a scale factor: ");
	scanf("%lf", &scale);

	if (t.shape_kind == CIRCLE)
		t.u.circle.radius *= scale;
	else
	{
		t.u.rectangle.height *= scale;
		t.u.rectangle.width *= scale;
	}
	return t;
}
