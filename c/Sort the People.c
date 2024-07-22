#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int height;
} Person;

int compare(const void* a, const void* b) {
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    return personB->height - personA->height; 
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    if (namesSize != heightsSize) {
        *returnSize = 0;
        return NULL;
    }
    
    Person* people = (Person*)malloc(namesSize * sizeof(Person));
    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }
    
    qsort(people, namesSize, sizeof(Person), compare);
    
    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = people[i].name;
    }
    
    free(people);
    
    *returnSize = namesSize;
    return sortedNames;
}
//  test case
int main() {
    char* names1[] = {"Mary", "John", "Emma"};
    int heights1[] = {180, 165, 170};
    int namesSize1 = sizeof(names1) / sizeof(names1[0]);
    int heightsSize1 = sizeof(heights1) / sizeof(heights1[0]);
    int returnSize1;
    char** sortedNames1 = sortPeople(names1, namesSize1, heights1, heightsSize1, &returnSize1);

    printf("Sorted names: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%s ", sortedNames1[i]);
    }
    printf("\n");

    free(sortedNames1);

    return 0;
}
