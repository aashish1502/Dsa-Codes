#include <stdio.h>
#include <stddef.h>

size_t stringLength(const char* source)
{
    if(source == NULL) { return 0; }

    size_t length = 0;
    while(*source != '\0') {
        length++;
        source++;
    }
    return length;  
}

static size_t getHash(const char source)
{
    size_t length = 1;
    size_t hash = 0;
    {
        char c = source;
        int a = c - '0';
        hash = (hash * 10) + a;     
    } 

    return hash;
}


#define TABLE_SIZE (16)

int main()
{

    char reg[10];
    printf("Enter Reg no: ");
    scanf("%s",reg);

    for(size_t i = 0; i < (sizeof(reg) / sizeof(reg[0])); i++) {
        const char source = reg[i];  
        size_t hash = getHash(source);
        printf("%s <==> %zu\n", source, (hash % TABLE_SIZE));

    }   

    return 0;
}