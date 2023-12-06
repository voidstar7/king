#ifndef LINE_H
#define LINE_H

// clears the current line
void clear_line(void);

// adds word to the end of the current line. If this is not the first word on the line, puts one space before word
void add_word(const char *word);

// returns the number of characters left in the current line
void space_remaining(void);

// writes the current line with justification
void write_line(void);

// writes the current line without justification. If the line is empty, does nothing
void flush_line(void);

#endif
