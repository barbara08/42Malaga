#include <unistd.h>
void rotate_silent(int stack[], int len)
{
    int i;
    int first;

    if (len < 2)
        return;

    i = 0;
    first = stack[0];
    while (i < len - 1)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[len - 1] = first;
}

void reverse_rotate_silent(int stack[], int len)
{
    int last;
    int i;

    if (len < 2)
        return;

    last = stack[len - 1];
    i = len - 1;
    while (i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = last;
}

void rotate(int stack[], int len)
{
    rotate_silent(stack, len);
}

void reverse_rotate(int stack[], int len)
{
    reverse_rotate_silent(stack, len);
}

void ra(int a[], int len_a)
{
    rotate_silent(a, len_a);
    write(1, "ra\n", 3);
}

void rb(int b[], int len_b)
{
    rotate_silent(b, len_b);
    write(1, "rb\n", 3);
}

void rr(int a[], int len_a, int b[], int len_b)
{
    rotate_silent(a, len_a);
    rotate_silent(b, len_b);
    write(1, "rr\n", 3);
}

void rra(int a[], int len_a)
{
    reverse_rotate_silent(a, len_a);
    write(1, "rra\n", 4);
}

void rrb(int b[], int len_b)
{
    reverse_rotate_silent(b, len_b);
    write(1, "rrb\n", 4);
}

void rrr(int a[], int len_a, int b[], int len_b)
{
    reverse_rotate_silent(a, len_a);
    reverse_rotate_silent(b, len_b);
    write(1, "rrr\n", 4);
}