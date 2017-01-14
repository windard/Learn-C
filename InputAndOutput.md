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

## 排序算法

### 冒泡排序

以排序为递增数组为例，将待排序的相邻数据元素两两比较，若为递减，则交换两元素。当从前往后依次扫描比较之后，最大的数会被放在最后一个位置，这个过程就被称为一次排序。

第二次排序则只需到倒数第二个位置就可以结束，扫描结束时，次大值被放在倒数第二个位置。

这个过程重复进行，直到所有待排数据按从小到大排列。由于在排序过程中，小的数像气泡一样逐渐上升，而大的数则逐渐下沉，所以形象的将这种排序算法称为冒泡排序。

```
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,t;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);
		
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i; j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}
```

```
original :   10   1  23  -5   0  78  11 104  65  -1  12  23  36   3  53
Sorted   :   -5  -1   0   1   3  10  11  12  23  23  36  53  65  78 104
```

一点点小小的改进，如果在某一次的扫描过程中没有发生替换，则说明数组已经完成排序，无需继续扫描。

```
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,t,flag;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);
		
	for (i = 0; i < N; i++) {
		flag = 1;
		for (j = 0; j < N - i; j++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 0;
			}
		}
		if (flag) break;
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}
```

### 选择排序

以排序为递增数组为例，从 a[0] ~ a[N] 中选出最小的数，将它与第 0 个数元素交换。

然后从 a[1] ~ a[N] 中选出最小的数，将它与第 1 个元素交换。

这个过程重复进行，直到完成排序。

```
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,min,index,t;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	for (i = 0; i < N; i++) {
		min = a[i];
		index = i;
		for (j = i; j < N; j++) {
			if (a[j] < min){
				min = a[j];
				index = j;
			}
		}
		t = a[i];
		a[i] = a[index];
		a[index] = t;
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}
```

```
original :   10   1  23  -5   0  78  11 104  65  -1  12  23  36   3  53
Sorted   :   -5  -1   0   1   3  10  11  12  23  23  36  53  65  78 104
```

一点点小小的改进，不一定要在每一次找到最小的值再替换，只要找到比现有的值小的时候就可以替换了。

```
#include "stdio.h"

#define N 15

int main(int argc, char const *argv[])
{
	int 	i,j,t;
	int 	a[N] = {10, 1, 23, -5, 0, 78, 11, 104, 65, -1, 12, 23, 36, 3, 53};

	printf("original : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			if (a[j] < a[i]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	printf("\nSorted   : ");
	for (i = 0; i < N; i++) printf("%4d", a[i]);

	return 0;
}
```