插入排序
//递增排序
void asc_insert_sort(int arr[], int data_size)
{
	int i, j;
	for (i=1;i<data_size;++i){
		//当前的元素,如果小于前一个元素
		if (arr[i]<arr[i-1] ){
			int temp = arr[i];
			for (j = i;j>0&&arr[j - 1] > temp;--j) {
				arr[j] = arr[j-1];
			}

			arr[j] = temp;
		}
	}
}

//递减排序
void desc_insert_sort(int arr[], int data_size)
{
	int i, j;
	for (i=1;i<data_size;++i){
		if (arr[i]>arr[i-1]){
			int temp = arr[i];
			for (j=i;j>0&&arr[j-1]<temp;--j){
				arr[j] = arr[j-1];
			}

			arr[j] = temp;
		}
	}
}








希尔排序
//递增排序
void asc_shell_sort(int arr[], int data_size)
{
	int grap, i, j;
	//注意grap是要大于0
	for (grap = data_size>>1;grap>0;grap=grap>>1){
		for (i=grap;i<data_size;++i){
			if (arr[i]<arr[i-grap]){
				int temp = arr[i];
				for (j = i;j > 0 && arr[j-grap] >temp;j -= grap) {
					arr[j] = arr[j - grap];
				}

				arr[j] = temp;
			}
		}
	}
}

//递减排序
void desc_shell_sort(int arr[], int data_size)
{
	int grap, i, j;
	//注意grap是要大于0
	for (grap = data_size >> 1;grap > 0;grap = grap >> 1) {
		for (i = grap;i < data_size;++i) {
			if (arr[i] > arr[i - grap]) {
				int temp = arr[i];
				//最后先定位位置，前一个下标
				for (j = i-grap;j >=0 && arr[j] <temp;j -= grap) {
					arr[j+grap] = arr[j];
				}

				arr[j+grap] = temp;
			}
		}
	}
}


选择排序
void asc_select_sort(int arr[],int data_size)
{
	int i, j;
	for (i=0;i<data_size;i++){
		int min_index = i;
		for (j=i+1;j<data_size;j++){
			if (arr[min_index]>arr[j]){
				min_index = j;
			}
		}

		if (min_index != i){
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}

void desc_select_sort(int arr[], int data_size)
{
	int i, j;
	for (i = 0;i < data_size;i++) {
		int min_index = i;
		for (j = i + 1;j < data_size;j++) {
			if (arr[min_index] < arr[j]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}



冒泡排序 基本思想就是一个数经过一次排序后，最大的数，或最小的数，放在最低端，也就是最后，这就是冒泡排序
//递增排序
void asc_bubble_sort(int arr[], int data_size)
{
	int i, j;
	for (i =0;i<data_size;i++){
		for (j=0;j<data_size-i-1;++j){
			if (arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}

//递减排序
void desc_bubble_sort(int arr[], int data_size)
{
	int i, j;
	for (i = 0;i < data_size;i++) {
		for (j = 0;j < data_size - i - 1;++j) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}











二分法查找(二分查找)
//二分法查找(适用于数组,不适合于链表,查找的前提是必须顺序存储)
int half_search(int arr[],int search_value,int data_size)
{
	int low = 0;
	int high = data_size - 1;

	while (low<high){
		int mid = (low + high) / 2;
		if (search_value == arr[mid]){
			return mid;
		}

		if (search_value<arr[mid]){
			high = mid - 1;
		}

		if (search_value>arr[mid]){
			low = mid + 1;
		}
	}

	return 0;
}
















快速排序，应用场景，不适合指针，只适合链表
//升序排序
void asc_quick_sort(int src[], int begin, int end)
{
	if (begin > end) {
		return;
	}

	int base_value = src[begin];
	int i = begin;
	int j = end;
	while (i < j) {
		while (i<j && src[j]>base_value) {
			j--;
		}

		if (i < j) {
			src[i] = src[j];
			++i;
		}

		while (i < j && src[i] < base_value) {
			i++;
		}

		if (i < j) {
			src[j] = src[i];
			j--;
		}
	}

	//基准值回归
	src[i] = base_value;
	//向左边找
	asc_quick_sort(src, begin, i - 1);
	//向右边找
	asc_quick_sort(src, i + 1, end);
}



//快速排序
//降序排序
void desc_quick_sort(int arr[], int begin, int end)
{
	if (begin >end){
		return;
	}

	//定义一个基准值
	int base_value = arr[begin];
	int i = begin;
	int j = end;
	while (i<j){
			//划分右边小的
		while (i<j&&arr[j]<base_value){
			j--;
		}

		if (i<j){
			arr[i] = arr[j];
			++i;
		}

		//划分左边大
		while (i<j&&arr[i]>base_value){
			++i;
		}

		if (i<j){
			arr[j] = arr[i];
		}
	}

	//调整基准值
	arr[i] = base_value;
	//向左边找
	desc_quick_sort(arr, begin, i - 1);
	//向边边找
	desc_quick_sort(arr, i + 1, end);
}

综上以上所诉的，快速排序
以个基准点进行两端划分，若划分成右边大，左边小的，则
先进行右边比较，如何右边的值，大于基准值，右边的下标，就递减，否则把当前的值付给当前的小端点，
小端点的索引值加一,
接着进行左边比较，如果左边的值，大于基准值，就替换，小端索引值加加，否则，前进一个小端的索引，
继续比较，
知道，左右索引都向一个点聚集位置，
然后递归左边比较和右边比较
