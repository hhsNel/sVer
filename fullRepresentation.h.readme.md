full representation - a representation of the file fully containg it
(Function) `void` `insertCharToBuffer`  
(Argument 0)
		`char` `c` - char to be inserted  
(Argument 1)
		`char *` `buffer` - buffer to be inserted into  
(Argument 2)
		`size_t *` `index` - position after the last character  
(Function) `fullRepresentation` `generateFullRepresentation`  
(Argument 0)
		`FILE *` `fin` - file to be converted  
generates a full representation from a text file
(Function) `void` `saveFullRepresentation`  
(Argument 0)
		`fullRepresentation` `fr` - representation to be saved  
(Argument 1)
		`FILE *` `fout` - where to write to  
