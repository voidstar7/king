#ifndef LINE_H
#define LINE_H

// clears the current line
void clear_line(void);

// adds word to the end of the current line. If this is not the first word on the line, puts one space before word
void add_word(const char *word);

// returns the number of characters left in the current line
int space_remaining(void);

// writes the current line with justification
void write_line(void);

// writes the current line without justification. If the line is empty, does nothing
void flush_line(void);

// counts the number of spaces in a line
int count_spaces(char line[], int len);

// copies original line into updated line with extra spaces to justify
void copy_line(int extra_spaces);

#endif
