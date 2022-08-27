#include"seqlist.h"
void TestSeqlist1()//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
{
	 struct Seqlist s1;
	 SeqlistInit(&s1);
	 SeqlistPushBack(&s1, 1);
	 SeqlistPushBack(&s1, 2);
	 SeqlistPushBack(&s1, 3);
	 SeqlistPushBack(&s1, 4);
	 SeqlistPushBack(&s1, 5);
	 SeqlistPushBack(&s1, 6);
	 SeqlistPrint(&s1);
	 SeqlistPopback(&s1);
	 SeqlistPrint(&s1);
	 SeqlistPushFront(&s1, 9);
	 SeqlistPrint(&s1);
	 SeqlistPushFront(&s1, 8);
	 SeqlistPrint(&s1);
	 SeqlistPopFront(&s1);
	 SeqlistPrint(&s1);
	 SeqlistInsert(&s1, 4, 23);
	 SeqlistPrint(&s1);
	 SeqlistInsert(&s1, 2, 64);
	 SeqlistPrint(&s1);
	 SeqlistErase(&s1, 5);
	 SeqlistPrint(&s1);
	 SeqlistDestory(&s1);
	 SeqlistPrint(&s1);
}
int main()
{
	TestSeqlist1();
	return 0;
}