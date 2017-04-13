## C语言中的输入和输出函数

输入函数 `getchar` , `gets` , `scanf` , `getche` , `getch`

输出函数 `putchar` , `puts` , `printf`

`getche` , `getchar` , `getch` 的区别和联系

相同

1. 三者都是输入一个字符

差异

1. `getche` 和 `getch` 的头文件是 `conio.h`，`getchar` 的头文件是 `stdio.h`
2. `getche` 和 `getchar` 输入回显，`getch` 输入不回显。 
3. `getche` 和 `getch` 输入一个字符，返回一个字符，`getchar` 输入直至回车符才返回，但是只接受一个字符，剩余字符会被保留在缓存区。
4. `getch` 因其不回显，一般常用于 `按任意键继续`。

`scanf` 最常用的输入方式，头文件 `stdio.h` 。

`gets` 读入字符换，以回车结束，但是字符串中不包括回车符，以 `\0` 代替回车符返回，头文件 `stdio.h`，返回字符串指针，一般使用 `puts` 输出 。

### 实例

从键盘连续输入字符，到输入回车符为止，统计输入的字符个数。

```
#include "stdio.h"
#include "conio.h"

int main(int argc, char const *argv[])
{
	char 	ch;
	int 	len = 0;
	puts("Type in a sentence, then press <ENTER>");
	while((ch=getch()) != '\r'){
		putchar(ch);
		len++;
	}
	printf("\nSentence is %d characters longs.\n", len);
	return 0;
}
```