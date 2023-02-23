
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
   ElemType data;
   struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree Create();/* 细节在此不表 */

void Levelorder(BiTree T);

int main()
{
   BiTree T = Create();
   printf("Levelorder:"); Levelorder(T); printf("\n");
   return 0;
}
/* 你的代码将被嵌在这里 */
