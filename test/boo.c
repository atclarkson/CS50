#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main(void)
{
    setlocale(LC_ALL, "");
    wchar_t pumpkin = 0x1F383;
    printf("%lc\n", pumpkin);
    printf("A very Happy Halloween!");
    printf("A Scary Happy Halloween!"); // Cool
}
