#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL_CITIES	4

struct co_ordinates{
	int x;
	int y;
};

double mindistance = 9999999.999;
char min_permut[5]; 

char cities_names[] = {'A', 'B', 'C', 'D', 0};

struct co_ordinates *fill_distance(){
	// minimum x,y = 1,1
	// maximum x,y = 26,26
	int i;//j,k = 0;
	struct co_ordinates *c = malloc(sizeof(struct co_ordinates)*TOTAL_CITIES);
	
	for(i = 0;i < TOTAL_CITIES;i++){
		c[i].x = 1+(rand()%27);
		c[i].y = 1+(rand()%27);
	}
	return c;
}

void swap_cities(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void swap_coordinates(struct co_ordinates *a, struct co_ordinates *b){
	struct co_ordinates temp = *a;
	*a = *b;
	*b = temp;
}

inline double distance(struct co_ordinates c1, struct co_ordinates c2){
	return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y,2));
}

void permute(struct co_ordinates *c, int s){
	int i;
	if (s == TOTAL_CITIES){
		double d = 0.0;
		for(i = 0;i < TOTAL_CITIES-1;i++){
			d += distance(c[i], c[i+1]);
		}
		if (d < mindistance){
			mindistance = d;
			memcpy(min_permut, cities_names, TOTAL_CITIES);
		}

		printf("For permutation %s, distance = %f\n", cities_names, d);
	}else{
		for(i = s;i < TOTAL_CITIES;i++){
			swap_cities(&cities_names[s], &cities_names[i]);
			swap_coordinates(&c[s], &c[i]);
			permute(c, s+1);
			swap_cities(&cities_names[s], &cities_names[i]);
			swap_coordinates(&c[s], &c[i]);
		}
	}
}

void solveTSP(struct co_ordinates *c){
	//char startVertex = 'A';
	permute(c, 1);
	printf("The minimum distance = %f obtained for permutation = %s\n", 
								mindistance, min_permut);
}

int main(){
	struct co_ordinates *c = fill_distance();
	solveTSP(c);
	free(c);
	return 0;
}