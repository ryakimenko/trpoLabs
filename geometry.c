#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
};
typedef struct Triangle {
    struct Point p1;
    struct Point p2;
    struct Point p3;
};
typedef struct Circle {
    struct Point centre;
    float radius;
};

int whatshape(char a[], int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        if (a[i] == ' ')
            break;
        if ((a[i] == 'c' || a[i] == 'C')
            && (a[i + 1] == 'i' || a[i + 1] == 'I')
            && (a[i + 2] == 'r' || a[i + 2] == 'R')
            && (a[i + 3] == 'c' || a[i + 3] == 'C')
            && (a[i + 4] == 'l' || a[i + 4] == 'L')
            && (a[i + 5] == 'e' || a[i + 5] == 'E')) 
        {
            for(j = i+6; a[j] != '('; j++)
            {
                if(a[j] == ' ' || a[j] == '(')
                    break;
                else
                    return 0;
            }
            return 1;
        }
        else 
            return 0;
            if ((a[i] == 'T' || a[i] == 'T')
                && (a[i + 1] == 'r' || a[i + 1] == 'R')
                && (a[i + 2] == 'i' || a[i + 2] == 'I')
                && (a[i + 3] == 'a' || a[i + 3] == 'A')
                && (a[i + 4] == 'n' || a[i + 4] == 'N')
                && (a[i + 5] == 'g' || a[i + 5] == 'G')
                && (a[i + 6] == 'e' || a[i + 6] == 'E'))
                return 2;
            else 
                return 0;
    }
}

int hooks(char a[], int n)
{
    int i, j;
    for(i = 0; a[i] != '('; i++)
    for(i=i+1; i<n; i++)
    {
        if(( a[i]>= 48 && a[i] <= 57) || a[i] = ' ' || a[i] == ',')
            break;
        if(a[i] == ')')
        {
            for(i= i+1; i<n; i++)
            {
            if(a[i] == ' ')
                break;
            if(a[i] == EOF)
                return 1;
            else
                return 0;
            }
        }
        else
            return 0;  
    }

}

int coordinates(int shape, char a[], int n)
{
    int i, j, k;
    if (shape == 1) {
        for (i = 0; i < n; i++) {
            if (a[i] == ' ' || (a[i] >= 65 && a[i] <= 90)
                || (a[i] >= 97 && a[i] <= 122))
                break;
            if (a[i] == '(') {
                for (j = i + 1; a[j] >= 48 && a[j] <= 57; j++) {
                    if (a[j] == ' ')
                        break;
                }
                for(j; a[j] != ' '; j++){
                    
                }
            }
        }
    }
}

int main()
{
    return 0;
}