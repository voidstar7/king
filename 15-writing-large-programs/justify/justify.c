#include <string.h>
#include "line.h"
#include "word.h"

bool lastLine = false;

// usage: ./justify <quote where quote = the name of the file to be justified

int main(void)
{
	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();
	for (;;)
	{
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0)
		{
			lastLine = true;
			write_line(lastLine);
			return 0;
		}

		if (word_len + 1 > space_remaining())
		{
			write_line(lastLine);
			clear_line();
		}
		add_word(word);
	}
}
