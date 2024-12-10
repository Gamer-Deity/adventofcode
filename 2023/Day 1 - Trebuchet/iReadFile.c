#include "iReadFile.h"

int iReadFile(const char* fName, char*** pcText, const unsigned int MAX_LINES, const unsigned int SIZE_STR) {
	FILE *f;
	char *sLine;
	int i;
	
	sLine = (char*)malloc(SIZE_STR * sizeof(char));
	*pcText = (char**)malloc(MAX_LINES * sizeof(char*));
	f = fopen(fName, "rt");
	if (sLine == NULL || *pcText == NULL || f == NULL) return -1;
	
	i = 0;
	while (!feof(f) && i < MAX_LINES) {
		(*pcText)[i] = (char*)malloc(SIZE_STR * sizeof(char));
		if ((*pcText)[i] == NULL) return -1;

		memset((*pcText)[i], 0, SIZE_STR);
		if (fgets((*pcText)[i], SIZE_STR, f) == NULL) break; /* szNum - > linha lida */
    	    	
    	i++;
    }

	fclose(f);
    return 0;
}
