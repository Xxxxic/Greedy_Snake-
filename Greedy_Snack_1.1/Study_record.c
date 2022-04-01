void store();

void store()
{
	//strchr找前面的套路
	/*
	char s[] = "Hello world.";
	char* p = strchr(s, 'l');
	char c = *p;
	*p = '\0';			//找到p的位置 记录下并换为'\0' 此时s所☞为前面的
	char* t = (char*)malloc(strlen(s) + 1);
	strcpy(t, s);
	printf("%s\n", t);
	free(t);
	//*p=c;		//之前存下来的c 用来恢复s原来的样子
	*/

	//冒泡排序
	/*
	struct student {
		char Name[21];
		int score;
	};								//结构体要在使用前先声明，只要不在后面就行  在main函数里面也可以
	struct student stu[100], t;
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %s", &stu[i].score, &stu[i].Name);
	//core:down
	for (i = 0; i < n - 1; i++)			//n-1 rounds
	{
		for (j = 0; j < n - i; j++)			//until the num unseated
		{
			if (stu[j].score < stu[j + 1].score) {
				t = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = t;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s\n", stu[i].Name);
	}*/

	/*快速排序*/
	/*自己写的半成品 可以运行 无法排序*/
	//void quicksort(int* num, int left, int right)
	//{
	//	int temp;
	//	int flag_left = left - 1, flag_right = right - 1;
	//	int cnt = 0;
	//	int sign = left;
	//	//set left started
	// 
	//	while (flag_left != flag_right)
	//	{
	//		if (cnt % 2 == 0)	//move right
	//		{
	//			if (num[flag_right] < num[left]) {
	//				temp = num[left];
	//				num[left] = num[flag_right];
	//				num[flag_right] = temp;
	//				cnt++;
	//				continue;
	//				/*sign = flag_right;*/	//record the core number
	//			}
	//			else
	//				flag_right--;
	//		}
	//		if (cnt % 2 != 0)	//move left
	//		{
	//			if (num[flag_left] < num[left]) {
	//				temp = num[left];
	//				num[left] = num[flag_left];
	//				num[flag_left] = temp;
	//				cnt++;
	//				continue;
	//			}
	//			else
	//				flag_left++;
	//		}
	//	}
	//	/*quicksort(num, left, );
	//	quicksort(num, , right);*/
	//}
	/*啊哈*/
	/*void quicksort(int* num, int left, int right)
{
	int temp, t;

	if (left > right)
		return;

	temp = num[left];		//基准数
	int i = left, j = right;
	while (i != j)
	{
		while (num[j] >= temp && i < j) {
			j--;		//先右从左
		}
		while (num[i] <= temp && i < j) {
			i++;
		}

		if (i < j) {
			t = num[i]; num[i] = num[j]; num[j] = t;
		}

		//归位基准数
		num[left] = num[i];
		num[i] = temp;

		quicksort(num, left, i - 1);
		quicksort(num, i + 1, right);
	}
}*/

	/*输出不重复的*/
	/*建新数组存*/
	/*
	int i=0;
	while(num[i]>=0)
	{
		if (num[i + 1] != res[i])
		{
			res[i + 1] = num[i + 1];
		}
		i++;
	}

	i = 0;
	while (res[i] >= 0) {
		printf("%d ", res[i]);
		i++;
	}*/
	/*优化 仅是输出*/
	/*for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {			
			printf("%d", a[i]);
		}
	}*/

	/*二维数组*/
	/*//desgined by Xxxxic version1.1
	//buy:二维数组的指针表示 1.*((p+n)+m) 2.p[n*M+m]  （N行M列

	#define N_stu 2
	#define N_sub 3

	void avg(double *p);
	void avg_i(double (*p)[N_sub], int ID);

	void avg(double* p)
	{
		double sum = 0;
		for (int i = 0; i < N_stu; i++)
		{
			for (int j = 0; j < N_sub; j++)
			{
				sum += p[i* N_sub+j];
			}
		}
		printf("%.2lf\n", sum / (N_stu*N_sub));
	}

	void avg_i(double(*p)[N_sub], int ID)
	{
		double sum = 0.0;
		for (int i = 0; i < N_sub; i++)
			{
				sum += *(*(p+ID)+i);
			}
	
		printf("%.2lf\n", sum / N_sub);
	}
	*/

	/*队列*/
	/*struct queue {
	int data[100];
	int head;
	int tail;
};

int main()
{	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		struct queue q;
		int n;
		scanf("%d", &n);
		q.head = 0;
		q.tail = n;
		for (int i = 0; i < n; i++)		//input
		{
			scanf("%d", &q.data[q.tail]);
			q.tail++;
		}
		//move head insted of delete
		while (q.head < q.tail)
		{
			//打印队首 并将队首出队
			printf("%d ", q.data[q.head]);
			q.head++;
			//先将新队首加至队尾
			q.data[q.tail] = q.data[q.head];
			q.head++;
			//再将队首出队
			q.tail++;
		}
		printf("\n");
	}
	return 0;
}*/

	/*链表的基本操作*/
	/*
	typedef int ElementType;// typedef在C语言中可用来为数据类型定义别名
	//typedef double ElementType;
	typedef struct LNode* List;
	struct LNode {
		ElementType data; // 此处等价于int Data；
		List next;
	};
	
	//基本操作集
	List makeEmpty();//初始化一个空的链表，生成仅含第0个节点为头空结点的空链表
	List findKth(int k, List ptrL);//根据位序k，返回相应结点指针，k的范围[0,length(ptrL)]
	List findX(ElementType X, List ptrL);//链表ptrL中查找X的第一次出现的结点指针
	bool deleteKth(int k, List ptrL); //删除指定位序k的结点,k的范围[1,length(ptrL)]
	bool insert(ElementType X, int k, List ptrL); //在位序k前插入一个新结点，使新结点在位序k, k的范围[1,length(ptrL)+1]
	int length(List L);//返回线性表L的长度n，头空结点不计入长度
	
	//其他操作（可由基本操作集实现
	List createLink(int n, ElementType* arr); // 将arr数组中的n个数按位序从小到大顺序创建链表
	void destroyLink(List ptrL);//销毁链表，释放内存
	void printLink(List ptrL);//按从头至尾的顺序输出链表每个节点的val值
	
	bool deleteKth(int k, List ptrL)
	{
		if (k>=1&&k<length(ptrL))
		{
			List p, s;
			p = findKth(k - 1, ptrL);
			s = findKth(k , ptrL);
			p->next = s->next;
			free(s);
		}
		else {
			printf("the index to delete is invalid, please delete another node.\n");
		}
	}
	bool insert(ElementType X, int k, List ptrL)//建议调用findKth(k-1,ptrL) 和 length(ptrL)完成
	{
		if (k >= 1 && k <= (length(ptrL) + 1) {
			List p;
				p = findKth(k - 1, ptrL);
				List s;
				s = (List)malloc(sizeof(struct LNode));
				s->data = X;
				s->next = p->next;
				p->next = s;
		}
		else
		{
			printf("flase.");
		}
	}
	bool deleteKthEnd(int k, List ptrL)
	{
		if (k >= 1 && k <= length(ptrL))
		{
			List p = findKth(length(ptrL) - k,ptrL);
			List s = findKth(length(ptrL) - k+1,ptrL);
			p ->next = s->next;
			free(s);
		}
	}

	*/

	/*员工管理系统1*/
	//void registerStaff(int n, staff* head)
	//{
	//	staff* p;
	//	p = head; //用于遍历的指针
	//	for (int i = 0; i < n; i++)
	//	{
	//		staff* new = (staff*)malloc(sizeof(struct Staff));
	//		scanf("%d %d %d %s", &new->id, &new->age, &new->wages, new->name);
	//		new->next = NULL;
	//		p->next = new;    //用来找到表尾
	//		p = new;            //指向新表尾
	//	}
	//}
	//void getMaxWages(staff* head)
	//{
	//	staff* p = head; //用于遍历的指针
	//	staff* max = (staff*)malloc(sizeof(struct Staff));
	//	max->wages = 0;
	//	while (p != NULL)           //找到最大的wage 存到max里面
	//	{
	//		if (max->wages < p->wages) {
	//			max = p;
	//		}
	//		p = p->next;
	//	}
	//	//delete
	//	staff* search = head;
	//	while (search->next != max) {
	//		search = search->next;
	//	}   //找到max前一位
	//	search->next = max->next;
	//	max->next = head->next;
	//	head->next = max;     //接入表头
	//}

	/*对链表的排序*/
	/*这是个有bug的代码 要知道给链表排序太不直观了
	更好的方案是采用结构体数组*/
	//void judge(int n, int s)
	//{
	//	//get children's information
	//	chi* head = (chi*)malloc(sizeof(struct Children));
	//	head->next = NULL;
	//	for (int i = 0; i < n; i++)
	//	{
	//		chi* new = (chi*)malloc(sizeof(chi));
	//		scanf("%d %d", &new->a, &new->b);
	//		new->cha = new->b - new->a;
	//		new->next = NULL;
	//		head->next = new;
	//	}
	//	//链表的排序（交换节点） 差-升序
	//	chi* pre, * cur, * nex, * end;
	//	end = NULL;
	//	while (head->next != end)
	//	{
	//		for (pre = head, cur = pre->next, nex = cur->next; nex != end; pre = pre->next, cur = cur->next, nex = nex->next)
	//		{
	//			if (cur->cha > nex->cha) {
	//				pre->next = nex;
	//				cur->next = nex->next;
	//				nex->next = cur;
	//				chi* temp = cur; cur = nex; nex = temp;
	//			}
	//		}
	//		end = cur;
	//	}
	//	//对排序后的判断
	//	chi* p = head;
	//	int flag = 1;
	//	while (p->next != NULL)
	//	{
	//		if (p->a + s < p->b) {
	//			flag = 0;
	//			break;
	//		}
	//		if (p->a + s >= p->b) {
	//			s += p->a;
	//		}
	//		p = p->next;
	//	}
	//	if (flag)
	//		printf("YES");
	//	else
	//		printf("NO");
	//}
	
	

}