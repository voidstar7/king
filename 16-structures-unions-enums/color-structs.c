#include <stdio.h>
#include <stdbool.h>

struct color 
{
	int red;
	int green;
	int blue;
};

struct color make_color(int red, int green, int blue);
int get_red(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(void)
{
	int r1, g1, b1, 
			r2, g2, b2;
	struct color 
		color1, 
		color2,
		color1bright,
		color2dark;

	printf("color1: Enter RGB value (R G B): ");
	scanf(" %d %d %d", &r1, &g1, &b1);
	printf("color2: Enter RGB value (R G B): ");
	scanf(" %d %d %d", &r2, &g2, &b2);

	color1 = make_color(r1, g1, b1);
	color2 = make_color(r2, g2, b2);

	printf("color1: %d, %d, %d\n",
			color1.red,
			color1.green,
			color1.blue);

	printf("color1: red: %d\n", get_red(color1));
	
	printf("color2: %d, %d, %d\n",
			color2.red,
			color2.green,
			color2.blue);

	if (equal_color(color1, color2))
		printf("the colors are equal\n");
	else
		printf("the colors are not equal\n");

	color1bright = brighter(color1);
	printf("color1 (brighter): %d, %d, %d\n",
			color1bright.red,
			color1bright.green,
			color1bright.blue);

	color2dark = darker(color2);
	printf("color2 (darker): %d, %d, %d\n",
			color2dark.red,
			color2dark.green,
			color2dark.blue);

	return 0;
}

struct color make_color(int red, int green, int blue)
{
	struct color newColor;

	// nested inner/outer ternary conditions
	newColor.red = (red > 255) ? 255 : ((red < 0) ? 0 : red);
	newColor.green = (green > 255) ? 255 : ((green < 0) ? 0 : green);
	newColor.blue = (blue > 255) ? 255 : ((blue < 0) ? 0 : blue);

	return newColor;
}

int get_red(struct color c)
{
	return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
	bool equal =
	(
	 color1.red == color2.red &&
	 color1.green == color2.green &&
	 color1.blue == color2.blue 
	) ? true : false;

	return equal;
}

struct color brighter(struct color c)
{
	for (;;)
	{
		if (c.red == 0 &&
				c.green == 0 &&
				c.blue == 0)
		{
			c.red = 3; 
			c.green = 3; 
			c.blue = 3;
			break;
		}
		else
		{
			if (c.red > 0 && c.red < 3)
				c.red = 3 / .70;
			else if ((c.red / .70) > 255)
				c.red = 255;
			else
				c.red /= .70;

			if (c.green > 0 && c.green < 3)
				c.green = 3 / .70;
			else if ((c.green / .70) > 255)
				c.green = 255;
			else
				c.green /= .70;

			if (c.blue > 0 && c.blue < 3)
				c.blue = 3 / .70;
			else if ((c.blue / .70) > 255)
				c.blue = 255;
			else
				c.blue /= .70;
		}
		break;
	}
	return c;
}

struct color darker(struct color c)
{
	c.red *= .70;
	c.green *= .70;
	c.blue *= .70;
	return c;
}
