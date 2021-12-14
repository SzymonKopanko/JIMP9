

typedef struct {
	int n;   // liczba równań
	double **a; // macierz
	double *wskaznik; // pomocniczy wskaźnik na zaalokowany obszar, przechowujący macierz
	double *b; // wektor prawych stron
} * ukladr_t;


ukladr_t Matrix_Read( char *nazwa_pliku,ukladr_t ukr );


ukladr_t ukr;
