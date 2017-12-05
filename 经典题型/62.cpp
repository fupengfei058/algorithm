/*查找和排序_计数排序*/
class CountingSort {
public:
    int* countingSort(int* A, int n) {
       int min = A[0],max = A[0];
       for(int i=0;i<n;i++)
       {
           min = min<A[i]?min:A[i];
           max = max>A[i]?max:A[i];
       }
       int* temp = new int[max-min+1]();
       for(int i=0;i<n;i++)
       {
           temp[A[i]-min]++;
       }
       int pos=0;
       for(int i=0;i<max-min+1;i++)
       {
           while(temp[i]-- > 0)
           {
               A[pos++] = i+min;
           }
       }
       return A;
    }
};