#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//5位运动员参加10mi台跳水比赛，有人让她们预测一下比赛结果
//A说：B第二，我第三   这里面的每一个语句都只对一半，我们给他们整成判断语句，如果相加为1说明只有半句 是真的
//B说：我第二，E第四
//C说：我第一，D第二
//D说：C最后，我第三
//E说：我第四，A第一
//比赛结束后，每位选手只说对了一半，请编程确定比赛名次
//对于每一位选手来说都有可能是1-5名次
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1;a <= 5;a++)
//	{
//		for (b = 1;b <= 5;b++)
//		{
//			for (c = 1;c <= 5;c++)
//			{
//				for (d = 1;d <= 5;d++)
//				{
//					for (e = 1;e <= 5;e++)
//					{
//						if ((b == 2) + (a == 3) == 1 &&
//							(b == 2) + (e == 4) == 1 &&
//							(c == 1) + (d == 2) == 1 &&
//							(c == 5) + (d == 3) == 1 &&
//							(e == 4) + (a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)  //这个就很好的把名次重叠的排除掉了
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//}


//free不会改变指针变量里面的内容
//野指针是指向未分配或者已经释放的内存地址
//指针数组  char*(*arr)[10]
//对于指针这一块必须重新好好的再看一遍


//文件操作
//文件一般包括程序文件和数据文件
//数据文件被称为文本文件或者二进制文件
//比如整数10000   当你把10000放到文本文件下的时候他需要从内存中向外存拿数据存储，但这里是以字符的形式来存储的 ‘1’ ‘0’ 以字符形式5个字节
// 但是当你以二进制的形式来拿数据的时候 ，你会发现一个整形在内存中的存储只占用4个字节

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");  //打开一个test.txt的文本文件，在里面以二进制的形式写入
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//在gcc编译器下   我们会发现printf  和  我们的屏幕之间是存在一个输出缓冲区的  当你把数据先放到输出缓冲区内等被填满了之后才会 他才会输出
//文件的打开和关闭  fopen   fclose
//在编写程序的时候，再打开文件的同时，都会返回一个FILE* 的指针变量指向该文件，也相当于建立了指针和文件的关系
//在你创建test.txt 之前会在之前创建一个test.txt的文件信息区
//.. 表示上一级路径
//. 表示当前路径
#include<string.h>
#include<errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");   //以写的形式打开一个文件
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputc('b',pf);//  表示我把东西向文件中输出
//	fputc('i', pf);
//	fputc('t', pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgetc（字符输入函数）  和 fputc  f开头表示是对文件进行操作
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");   //以写的形式打开一个文件
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件  且这个fgetc一次只读一个字符
//	char ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgets 可以从键盘 屏幕 文件等任何地方来得到字符
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputs("hello", pf);
//	fputs("world", pf);
//	//读文件
//	//fgets(buf, 1024, pf);
//	//printf("%s", buf);   //buf里面本来就带了一个\0 所以这里可以省略一个\0
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//从键盘读取一行文本信息
//	char buf[1024] = { 0 };
//	//fgets(buf, 1024, stdin);
//	//fputs(buf, stdout);
//	gets(buf);
//	puts(buf);
//	return 0;
//}

//fscanf 格式化输入函数  
//fprintf 格式化输出函数
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"bit" };  // 这里的3.14f  这个f表示的是float型 ，如果不写默认为double型
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//格式化的形式写文件  ---意味着你可以自己来确定自己所想要输入文件的内容格式（int float char）
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);  //  这里的fprintf只是比正常的printf多了一个 stream的变量引入
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = {0};  
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//格式化输入数据
//	fscanf(pf,"%d %f %s",&(s.n),&(s.score),s.arr);  //  这里的fscanf只是比正常的scanf多了一个 stream的变量引入
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr); 
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr);  //  这里的.2表示打印小数点后面2位
//	return 0;
//}

//对比一下一组函数
//scanf/fscanf/sscanf
//printf/fprintf/sprintf

//scanf/printf 是针对标准输入流/标准输出流的格式化输入/输出语句
//fscanf/fprintf  是针对所有输入流/所有输出流的格式化输入/输出语句
//sscanf / sprintf    sprintf 有能力把 一个结构体内的内容转换成一个字符串 直接改变了这个输出的类型
//
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100, 3.14, "bit"};
//	char buf[1024] = { 0 };
//	struct S tmp = { 0 };
//
//	//把格式化的数据转换成字符串存储在buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//printf("%s\n", buf);
//	//从buf中读取格式化的数据到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);  //这个直接把我刚才放在buf里面的字符串直接转换为结构体里面的每个变量
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	return 0;
//}

//以二进制的形式进行读写操作
//fread    fwrite
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S s = { "张三",20,55.6 };
//	FILE* pf = fopen("test.txt", "wb");  //  这里的wb表示是以二进制的形式进行写入
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	二进制形式写入
//	fwrite(&s, sizeof(struct S), 1, pf);
//	关闭
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


struct S
{
	char name[20];
	int age;
	double score;
};

int main()
{
	struct S tmp = {0};
	FILE* pf = fopen("test.txt", "rb");  //  这里的wb表示是以二进制的形式进行写入
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//二进制形式读文件
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf", tmp.name, tmp.age, tmp.score);
	//关闭
	fclose(pf);
	pf = NULL;
	return 0;
}
