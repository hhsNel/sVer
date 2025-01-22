#ifndef FULL_REPRESENTATION_H
#define FULL_REPRESENTATION_H

/*
 $m (full representation - a representation of the file fully containg it)
*/
struct fullRepresentation {
	char **lines;
	uint64_t linesNr;
}

#define FR_ESCAPE_CHAR '\0'

inline void insertCharToBuffer(char c, char *buffer, size_t *index) {
#define BUFFER_SIZE 64
	if(*index % BUFFER_SIZE == 0) {
		buffer = realloc(buffer, *index + BUFFER_SIZE);
	}
	buffer[*index] = c;
	*index += 1;
#undef BUFFER_SIZE
}

fullRepresentation generateFullRepresentation(FILE* fin) {
	char c = '\0';
	char *buffer = NULL;
	size_t lastIndex = 0;
	char** lines = NULL;
	uint64_t lineIndex = 0;
	while(c != EOF) {
		c = (char)fgetc(fin);
		if(c == '\n') {
#define LINE_BUFFER_SIZE 16
				if(lineIndex % LINE_BUFFER_SIZE == 0) {
					lines = realloc(lines, lineIndex + LINE_BUFFER_SIZE);
				}
				buffer = realloc(buffer, lastIndex);
				buffer[lastIndex] = '\0';
				lines[lineIndex++] = buffer;
				buffer = NULL;
				lastIndex = 0;
#undef LINE_BUFFER_SIZE
		}
		insertCharToBuffer(c, buffer, &index);
	} 
	lines = realloc(lines, lineIndex-1);
	fullRepresentation fr;
	fr.lines = lines;
	fr.linesNr = lineIndex-1;
	return fr;
}

void saveFullRepresentation(fullRepresentation fr, FILE* fout) {
	uint64_t i;
	for(i = 0; i < fr.linesNr; ++i) {
		char *iter;
		for(iter = fr.lines[i]; *iter != '\0'; ++iter) {
			fputc(*iter, fout);
		}
		fputc(FR_ESCAPE_CHAR, fout);
		fputc(FR_ESCAPE_CHAR, fout);
	}
	fputc(FR_ESCAPE_CHAR, fout);
	fputc(FR_ESCAPE_CHAR+1, fout);
}

#endif

