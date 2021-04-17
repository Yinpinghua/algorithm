#include <iostream>
#include <vector>

void bubble_sort2(int* a, int len)
{
	int i, j;
	for (i = 0;i < len - 1;i++) {
		for (int j = 0;j < len - 1 - i;j++) {
			//从大到小
			//if (a[j] < a[j+1]) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

//选择排序
void selection_sort(int a[], int len)
{
	int i, j;
	for (i = 0;i < len - 1;++i) {
		int min = i;
		for (int j = i + 1;j < len;j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}

		if (min != i) {
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

//快速排序
void quicksort(int a[], int left, int right) {
	int i, j;
	if (left > right) {
		return;
	}

	//默认小区间范围内的值(基准数归位)
	int base_value = a[left];
	i = left;
	j = right;
	while (i < j) {
		//从大的开始找
		while (a[j] >= base_value && i < j && j--);

		//找到大值再分治一次
		a[i] = a[j];
		//从小开始找
		while (a[i] <= base_value && i < j && i++);
		//找到小值再分治一次
		a[j] = a[i];
	}

	//没有数，可以比了，基准数归位
	a[i] = base_value;
	//递归左边去找
	quicksort(a, left, i - 1);
	//递归右边去找
	quicksort(a, i + 1, right);
}

//插入排序
void insert_sort(int array[], int n)
{
	int i, j, temp;
	for (i = 1;i < n;i++) {
		if (array[i] < array[i - 1]) {
			temp = array[i];
			//前一个元素
			for (j = i;array[j - 1] > temp;j--) {
				array[j] = array[j - 1];
			}

			array[j] = temp;
		}
	}
}

//希尔排序
void sheel_sort1(int array[], int n)
{
	int i, j, temp;
	//希尔排序的步长
	int gap = n;
	do {
		//假设按照区间划分 
		gap = gap / 3 + 1;
		for (i = gap;i < n;i++)
		{
			//取值步长控制
			if (array[i] < array[i - gap])
			{
				//未排序区的第一个数
				temp = array[i];
				//以及排序区的值
				for (j = i - gap;array[j] > temp;j -= gap)
				{
					array[j + gap] = array[j];
				}
				array[j + gap] = temp;
			}
		}
	} while (gap > 1);

}

//希尔排序
void sheel_sort2(int array[], int len)
{
	//可以理解为列数
	int grap = 1;
	//一直找到奇数列
	while (grap < len / 3) {
		grap = 3 * grap + 1;
	}

	while (grap > 1) {
		for (int i = grap; i >= grap && array[i] < array[i - grap]; i -= grap) {
			int temp = array[i];
			array[i] = array[i - grap];
			array[i - grap] = temp;
		}

		grap = grap / 3;
	}
}

//c++实现求最长子序列的值
int longestCommonSubsequence(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int max_len = 0;
	int max_row;
	//这里还有个思想就是,把统计次数放入1条对接角线
	std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

	for (int i = 1;i < len1 + 1;i++) {
		for (int j = 1;j < len2 + 1;j++) {
			if (str1[i - 1] == str1[j - 1]) {
				//增加前一行和后一列的值
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				//注意,前一行和后一列要进行比较
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}
	return dp[len1][len2];
}

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

//创建最大堆
void max_heapify(int arr[], int start, int end) {
	// 建立父节点索和子节点的索引
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		// 先比較兩個子節點大小，選擇最大的
		if (son + 1 <= end && arr[son] < arr[son + 1]) {
			son++;
		}

		//如果父節點大於子節點代表調整完畢，直接跳出函數
		if (arr[dad] > arr[son]) {
			break;
		}

		// 否則交換父子內容再繼續子節點和孫節點比较
		int temp = arr[son];
		arr[son] = arr[dad];
		arr[dad] = temp;
		dad = son;
		son = dad * 2 + 1;
	}
}

void min_heapify(int arr[], int start, int end) {
	// 建立父节点索和子节点的索引
	int dad = start;
	int son = dad * 2 + 1;
	int temp = arr[dad];
	while (son <= end) {
		// 先比較兩個子節點大小，選擇最小的
		if (son + 1 <= end && arr[son] > arr[son + 1]) {
			son++;
			continue;
		}

		if (temp < arr[son]) {
			break;
		}

		int temp = arr[son];
		arr[son] = arr[dad];
		arr[dad] = temp;
		dad = son;
		son = 2 * dad + 1;
	}
}

void max_heap_sort(int arr[], int len) {
	int i;
	// 初始化，i從最後一個父節點開始調整
	for (i = len / 2 - 1; i >= 0; i--) {
		max_heapify(arr, i, len - 1);
	}

	// 先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
	for (i = len - 1; i > 0; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		max_heapify(arr, 0, i - 1);
	}
}

void min_heap_sort(int arr[], int len) {
	int i;
	//初始化，并先调整父节点
	for (i = len / 2 - 1; i >= 0; i--) {
		min_heapify(arr, i, len - 1);
	}

	// 先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
	for (i = len - 1; i > 0; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		min_heapify(arr, 0, i - 1);
	}
}

int main()
{
	int arr[] = { 9,11,1,3,2,8,10,100,23 };
	int len = (int)sizeof(arr) / sizeof(*arr);
	//min_heap_sort(arr, len);
	max_heap_sort(arr, len);

	int ads = longestCommonSubsequence("abcdedwwwdd", "acewd");
	int arrry[] = { 5,3,3,4,3,8,9 ,10,11 };
	int data_size = sizeof(arrry) / sizeof(arrry[0]);
	bubble_sort2(arrry, data_size);
	//sheel_sort2(arrry, data_size);

	//int arrry[] = {2,3,6,2,4,5};
	//int data_size = sizeof(arrry) / sizeof(arrry[0]);
	//sheel_sort2(arrry, data_size);
	//int value = 2 / 3;
	//int arrry[10] = { 1,2,4,9,5,6,8,10,11,12 };	
	//int arrry[] = { 5,3,3,4,3,8,9 ,10,11 };
	//int arrry[] = { 5,3,4,4,3,8,9,5,10,11 };
	//int data_size = sizeof(arrry) / sizeof(arrry[0]);
	//sheel_sort1(arrry, data_size);
	//insert_sort(arrry, data_size);
	//int arrry[10] = { 1,2,4,9,5,6,8,10,11,12 };
	//std::cout << "快速排序:" << std::endl;
	////int arrry[] ={ 5,3,3,4,3,8,9 ,10,11 };
	//int data_size = sizeof(arrry) / sizeof(arrry[0]);

	//std::cout << "排序前:";
	//for (int i = 0;i < data_size;i++) {
	//	std::cout << arrry[i]<<" ";
	//}
	//
	//std::cout << std::endl;
	//quicksort(arrry, 0, data_size-1);
	//std::cout << "排序后:";
	//for (int i =0;i<data_size;i++){
	//	std::cout << arrry[i]<<" ";
	//}
	////selection_sort(arrr,10);
	////bubble_sort2(arrr,10);
}
