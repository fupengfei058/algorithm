/*查找和排序_堆排序*/
class HeapSort {
public:
    void heapJust(int* A,int index,int size)
    {
        int child = 2*index+1;//左孩子
        int temp;
        while(child<size)
        {
            //找最大左孩子
            if((child+1<size)&&(A[child+1]>A[child]))
            {
                child++;
            }
            if(A[child]<A[index])//调整完毕
            {
                break;
            }
            temp = A[index];
            A[index] = A[child];
            A[child] = temp;

            index = child;
            child = 2*index+1;
        }
    }
    int* heapSort(int* A, int n) {
        int temp;
        //依次调整堆
        for(int i = n/2-1; i>=0; i--)
        {
            heapJust(A,i,n);
        }
        //每次找最大的放在数组末尾
        while(n!=0)
        {
            temp = A[0];
            A[0] = A[n-1];
            A[n-1] = temp;
            n--;
            heapJust(A,0,n);
        }
      	return A;
    }
};