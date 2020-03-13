#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int x;
    long int y;
}Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
}Triangle;

typedef struct {
    Point centre;
    long int radius;
}Circle;

int whatshape(char a[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        if (a[i] == ' ')
            break;
        if ((a[i] == 'c' || a[i] == 'C') && (a[i + 1] == 'i' || a[i + 1] == 'I')
            && (a[i + 2] == 'r' || a[i + 2] == 'R')
            && (a[i + 3] == 'c' || a[i + 3] == 'C')
            && (a[i + 4] == 'l' || a[i + 4] == 'L')
            && (a[i + 5] == 'e' || a[i + 5] == 'E')) {
            for (j = i + 6; a[j] != '('; j++) {
                if (a[j] == ' ' || a[j] == '(')
                    break;
                else
                    return 0;
            }
            return 1;
        } else
            return 0;
        if ((a[i] == 't' || a[i] == 'T') && (a[i + 1] == 'r' || a[i + 1] == 'R')
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
    int k = 0;
    j = 0;
    for (k; a[k] != '\0'; k++) {
        if (a[k] == '(')
            j++;
    }
    if (j != 1)
        return 0;
    for (k = 0; a[k] != '('; k++)
        ;

    for (i = k + 1; i < n; i++) {
        if ((a[i] < 0x30 && a[i] > 0x39) && a[i] != ' ' && a[i] != ','
            && a[i] != ')')
            return 0;
        if (a[i] == ')') {
            for (j = i + 1; j < n; j++) {
                if (a[j] == ' ')
                    break;
                if (a[j] == '\0' || a[j] == '\n')
                    return 1;
                else {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int coordinates(int shape, char a[], int n)
{
    int i;
    int m;
    for (i = 0; a[i] != '('; i++)
        ;

    if (shape == 1) {
        i += 1;
        m = 2;
        if ((a[i] < 0x30 && a[i] > 0x39) && a[i] != ' ')
            return 0;
        do {
            if ((a[i] == ',' || a[i] == ')') && (m == 1 || m == 2))
                return 0;
            if ((a[i] < 0x30 && a[i] > 0x39) && a[i] != ',' && a[i] != ' ')
                return 0;
            if ((a[i] >= 0x30 && a[i] <= 0x39)) {
                if (m == 1 && (a[i + 1] == ',' || a[i + 1] == ' ')) {
                    m = m - 1;
                }
                if (a[i + 1] == ' ' && m == 2) {
                    m = m - 1;
                }
            }
            i = i + 1;
        } while (m != 0);
        m = 1;
        if (a[i] == ' ') {
            do {
                if (a[i] != ',' && a[i] != ' ')
                    return 0;
                if (a[i] == ',')
                    m--;
                i++;
            } while (m != 0);
            m = 1;
            do {
                if ((a[i] < 0x30 && a[i] > 0x39) && a[i] != ' ')
                    return 0;
                if ((a[i] >= 0x30 && a[i] <= 0x39)
                    && (a[i + 1] == ' ' || a[i + 1] == ')'))
                    m--;
                if (a[i] == ')' && m == 1)
                    return 0;
                i++;
            } while (m != 0);
            for (i; a[i] != ')'; i++) {
                if (a[i] == ' ')
                    break;
                else
                    return 0;
            }
            return 1;
        }
        if (a[i] == ',') {
            m = 1;
            do {
                if ((a[i] < 0x30 && a[i] > 0x39) && a[i] != ' ')
                    return 0;
                if ((a[i] >= 0x30 && a[i] <= 0x39)
                    && (a[i + 1] == ' ' || a[i + 1] == ')'))
                    m--;
                if (a[i] == ')' && m == 1)
                    return 0;
                i++;
            } while (m != 0);
            for (i; a[i] != ')'; i++) {
                if (a[i] == ' ')
                    break;
                else
                    return 0;
            }
            return 1;
        } else
            return 0;
    }
}

void write(char arr[], Circle circ[], int j)
{
    char* a;
    char* end;
    a = &arr[0];
    int i;
    for(i = 0; arr[i] !='('; i++)
        a++;
    a++;
    circ[j].centre.x = strtol(a, &end,10);
    circ[j].centre.y = strtol(end, &end, 10);
    a = &arr[0];
    for(i=0 ; arr[i] !=','; i++)
        a++;
    a++;
    circ[j].radius = strtol(a, NULL, 10);
}

int main()
{
    char arr[1000];
    Circle circ[10];
    for (int i = 0; i < 1000; i++)
        arr[i] = '\0';
    fgets(arr, 1000, stdin);
    int Whatshape, Hooks, Coordinates;
    Whatshape = whatshape(arr, 1000);
    Hooks = hooks(arr, 1000);
    Coordinates = coordinates(Whatshape, arr, 1000);
    if (Whatshape == 1 && Hooks == 1 && Coordinates == 1)
    {
        printf("All Good\n");
        write(arr, circ,0);
        printf("x = %ld, y = %ld, radius = %ld", circ[0].centre.x,circ[0].centre.y, circ[0].radius);
    }
    else
        printf("Error\n Shape = %d\n Hooks = %d\n Coordinates = %d\n",
               Whatshape,
               Hooks,
               Coordinates);
    return 0;
}