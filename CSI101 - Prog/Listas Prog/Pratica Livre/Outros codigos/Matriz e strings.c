#include <stdio.h>

#define N   5
#define M   10

int main( void ) 
{
    char lines[N][M];
    size_t n = 0;

    while( n < N && fgets( lines[n], sizeof( *lines ), stdin ) != NULL ) 
        ++n;

    for ( size_t i = 0; i < n; i++ ) 
        puts( lines[i] );

    return 0;
}