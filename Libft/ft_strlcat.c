#include <string.h>
#include <stdio.h>

int ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  d;
    size_t  s;
    int srcsize;
    int dLen;

    dLen = strlen(dst);
    d = dLen;
    printf("%zu\n",d);
    s = 0;
    while (src[s] != '\0' && d + 1 < dstsize)
    {
        dst[d] = src[s];
        s++;
        d++;
    }
    dst[d] = '\0';
    srcsize = strlen(src);
    printf("%d\n", srcsize);
    return(dLen + srcsize);
}

/*int main() 
{
    char destination[20] = "";
    const char *source = "world!";

    size_t result = strlcat(destination, source, sizeof(destination));

    printf("Concatenated string: %s\n", destination);
    printf("Total length: %zu\n", result);

    return 0;
}*/