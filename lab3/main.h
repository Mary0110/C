
void fill(int** field);
void printField(int** field);
void place(int** field);
int surround(int a, int b, int hor, int size, int** field);
int checkShips(int** field);
void clear(int** field);
int horCheck(int** field, int b, int a, int size);
int horFill(int** field, int b, int a, int size);
int verFill(int** field, int b, int a, int size);
int verCheck(int** field, int b, int a, int size);
