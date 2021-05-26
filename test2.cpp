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

//哨兵模式 插入排序
void InsertSort(int a[], int n)
{
	int i, j;
	for (i =2;i<n;++i){
		a[0] = a[i];
		for (j = i - 1;j > 0 && a[j] > a[0];j--) {
			a[j+1] = a[j];
		}

		a[j + 1] = a[0];
	}
}

//快排
int partition(int arr[], int low, int high)
{
	int base_value = arr[low];
	while (low<high){
		//右边查找
		while (low<high &&arr[high]>=base_value){
			high--;
		}

		arr[low] = arr[high];
		//左边查找
		while (low<high &&arr[low]<=base_value){
			++low;
		}

		arr[high] = arr[low];
	}

	arr[low] = base_value;
	return low;
}

void qsort2(int arr[], int low, int high)
{
	if (low>=high){
		return;
	}

	int pivo = partition(arr, low, high);
	qsort2(arr, low, pivo - 1);
	qsort2(arr, pivo + 1, high);
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
             j--;
		}
	}

	//调整基准值
	arr[i] = base_value;
	//向左边找
	desc_quick_sort(arr, begin, i - 1);
	//向边边找
	desc_quick_sort(arr, i + 1, end);
}

//右边为基准点
void asc_quick_sort1(int src[], int begin, int end)
{
	if (begin > end) {
		return;
	}

	//右边为基准,左小右大
	int base_value = src[end];
	int low = begin;
	int high = end;
	while (low<high){
		//先向左边搜索
		while (low<high &&src[low]< base_value){
			low++;
		}
		if (low<high){
			src[high] = src[low];
			high--;
		}

		//向右边搜索
		while (low<high && src[high]>base_value){
			high--;
		}

		if (low<high){
			src[low] = src[high];
		}
	}

	//基准值回归
	src[high] = base_value;
	//向左边找
	asc_quick_sort1(src, begin, high - 1);
	//向右边找
	asc_quick_sort1(src, high + 1, end);

}


//右边为基准点
void desc_quick_sort1(int src[], int begin, int end)
{
	if (begin > end) {
		return;
	}

	//右边为基准,左大右小
	int base_value = src[end];
	int low = begin;
	int high = end;
	while (low < high) {
		//先向左边搜索
		while (low < high && src[low] > base_value) {
			low++;
		}
		if (low < high) {
			src[high] = src[low];
			high--;
		}

		//向右边搜索
		while (low<high && src[high]<base_value) {
			high--;
		}

		if (low < high) {
			src[low] = src[high];
		}
	}

	//基准值回归
	src[high] = base_value;
	//向左边找
	desc_quick_sort1(src, begin, high - 1);
	//向右边找
	desc_quick_sort1(src, high + 1, end);

}

综上以上所诉的，快速排序
以个基准点进行两端划分，若划分成右边大，左边小的，则
先进行右边比较，如何右边的值，大于基准值，右边的下标，就递减，否则把当前的值付给当前的小端点，
小端点的索引值加一,
接着进行左边比较，如果左边的值，大于基准值，就替换，小端索引值加加，否则，前进一个小端的索引，
继续比较，
知道，左右索引都向一个点聚集位置，
然后递归左边比较和右边比较(第一个元素和最后一个元素进行交换,然后与剩余元素进行比较)

堆排序
//创建最大堆
void max_heap_build(int a[], int start, int end)
{
	int dad = start;
	int son = 2 * dad + 1;
	while (son<=end){
		if (son+1<=end&&a[son]< a[son+1]){
			++son;
		}

		if (a[dad]>a[son]){
			break;
		}

		int temp = a[son];
		a[son] = a[dad];
		a[dad] = temp;
		dad = son;
		son = 2 * dad + 1;
	}
}


void max_heap_build(int arr[], int start, int end)
{
	int parent_index = start;
	int son_index = 2 * parent_index;
	while (son_index <= end) {
		if (son_index + 1 <= end && arr[son_index] < arr[son_index + 1]) {
			++son_index;
		}

		if (arr[parent_index] >=arr[son_index]) {
			break;
		}

		int temp = arr[son_index];
		arr[son_index] = arr[parent_index];
		arr[parent_index] = temp;
		parent_index = son_index;
		son_index = 2 * parent_index;
	}
}

void min_heap_build(int a[], int start, int end)
{
	int dad = start;
	int son = 2 * dad;
	while (son <= end) {
		//先比较叶子节点
		if (son + 1 <= end && a[son] > a[son + 1]) {
			++son;
		}

		//然后再比较根节点
		if (a[dad] <=a[son]) {
			break;
		}

		int temp = a[son];
		a[son] = a[dad];
		a[dad] = temp;
		dad = son;
		son = 2 * dad;
	}
}

void heap_sort(int arr[], int data_size)
{
	for (int i = data_size >> 1;i > 0;--i) {
		//min_heap_build(arr, i-1, data_size - 1);
		max_heap_build(arr, i - 1, data_size - 1);
	}

	for (int i = data_size - 1;i >0;--i) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		max_heap_build(arr, 0,i-1);
		//min_heap_build(arr, 0, i - 1);
	}

}








 //最大堆排序
void max_heap_sort(int a[], int data_size)
{
	int i, j;
	//先求出root的索引，再求出叶子节点索引
	for (i=data_size>>1;i>=0;i--){
		max_heap_build(a,i,data_size - 1);
	}

	//然后将堆顶和最后一个元素进行交换，然后对堆顶进行调整
	for (i = data_size -1;i > 0;i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		max_heap_build(a, 0,i-1);
	}
}

//小堆创建
void min_heap_build(int a[], int start, int end)
{
	int dad = start;
	int son = 2 * dad + 1;
	while (son<=end){
		//先比较叶子节点
		if (son+1<=end&&a[son]>a[son+1]){
			++son;
		}

		//然后再比较根节点
		if (a[dad]<a[son]){
			break;
		}

		int temp = a[son];
		a[son] = a[dad];
		a[dad] = temp;
		dad = son;
		son = 2 * dad + 1;
	}
}

//小堆排序
void min_heap_sort(int a[], int end)
{
	int i, j;
	for (i=end>>1;i>=0;i--){
		min_heap_build(a, i, end - 1);
	}

	for (i=end-1;i>0;i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		min_heap_build(a, 0, i - 1);
	}
}























归并排序
int* data_ptr = (int*)malloc(data_size * sizeof(int));
void asc_merge(int arr[], int low, int mid, int high)
{
	int i, j, k;
	//先拷贝数组元素
	for (i = low;i <= high;i++) {
		data_ptr[i] = arr[i];
	}

	//两两比较，进行合并
	i = low;
	j = mid + 1;
	//k是控制数组的下标
	for (k = low;i <= mid && j <= high;k++) {
		(data_ptr[i] <= data_ptr[j]) ? arr[k] =
			data_ptr[i++] : arr[k] = data_ptr[j++];
	}

	//扫尾工作
	while (i <= mid) {
		arr[k++] = data_ptr[i++];
	}

	while (j <= high) {
		arr[k++] = data_ptr[j++];
	}

}












void asc_merge_sort(int arr[],int low,int high)
{
	if (low==high){
		return;
	}

	//二路分组
	int mid = (low + high) / 2;
	asc_merge_sort(arr, low, mid);//向左半区进行划分
	asc_merge_sort(arr, mid + 1, high);//向右半区进行划分
	asc_merge(arr, low,mid,high);//合并所有分路
}

void desc_mege(int arr[], int low, int mid, int high)
{
	int i, j, k;
	//先拷贝数组元素
	for (i = low;i <= high;i++) {
		data_ptr[i] = arr[i];
	}

	//两两比较，进行合并
	i = low;
	j = mid + 1;
	//k是控制数组的下标
	for (k = low;i <= mid && j <= high;k++) {
		(data_ptr[i] >= data_ptr[j]) ? arr[k] =
			data_ptr[i++] : arr[k] = data_ptr[j++];
	}

	//扫尾工作
	while (i <= mid) {
		arr[k++] = data_ptr[i++];
	}

	while (j <= high) {
		arr[k++] = data_ptr[j++];
	}

}

void desc_merge_sort(int arr[], int low, int high)
{
	//二路分划的化,要除以2，恒等
	if (low == high) {
		return;
	}

	int mid = (low + high) / 2;
	desc_merge_sort(arr, low, mid);//向左划分
	desc_merge_sort(arr, mid + 1, high);//向右划分
	desc_mege(arr, low, mid, high);
}





























计数排序
void asc_count_sort(int* arr, int len) {
	if (arr == nullptr){
		return;
	}
	int min = arr[0], max = arr[0];
	for (int i=1;i<len;++i){
		if (arr[i]>max){
			max = arr[i];
		}
		if (arr[i]<min){
			min = arr[i];
		}
	}
	//求出距离之差
	int size = max - min + 1;
	int* count_ptr = (int*)malloc(sizeof(arr[0]) * size);
	memset(count_ptr, 0, sizeof(arr[0]) * size);
	for (int i =0;i<len;++i){
		//统计自己出现的次数
		count_ptr[arr[i] - min]++;
	}
	//再进行,再进行，当前项和前一项相加
	for (int i =1;i<size;++i){
		count_ptr[i] += count_ptr[i - 1];
	}
	int* psort = (int*)malloc(sizeof(arr[0]) * len);
	memset(psort, 0, sizeof(arr[0]) * len);
	//反向填充目标数组
	for (int i=len-1;i>=0;i--){
		count_ptr[arr[i] - min]--;
		psort[count_ptr[arr[i] - min]] = arr[i];
	}
	for (int i = 0; i < len; i++) {
		arr[i] = psort[i];
	}
	free(count_ptr);
	free(psort);
	count_ptr = NULL;
	psort = NULL;
}

void desc_count_sort(int* arr, int len) {
	if (arr == nullptr) {
		return;
	}
	int min = arr[0], max = arr[0];
	for (int i = 1;i < len;++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	//求出距离之差
	int size = max - min + 1;
	int* count_ptr = (int*)malloc(sizeof(arr[0]) * size);
	memset(count_ptr, 0, sizeof(arr[0]) * size);
	for (int i = 0;i < len;++i) {
		//统计自己出现的次数
		count_ptr[arr[i] - min]++;
	}
	//再进行,再进行，当前项和前一项相加
	for (int i = 1;i < size;++i) {
		count_ptr[i] += count_ptr[i - 1];
	}
	int* psort = (int*)malloc(sizeof(arr[0]) * len);
	memset(psort, 0, sizeof(arr[0]) * len);
	//反向填充目标数组
	for (int i = len - 1;i >= 0;i--) {
		count_ptr[arr[i] - min]--;
		psort[count_ptr[arr[i] - min]] = arr[i];
	}
	for (int i = len - 1;i >= 0;i--) {
		arr[len-i-1] = psort[i];
	}
	free(count_ptr);
	free(psort);
	count_ptr = NULL;
	psort = NULL;
}
