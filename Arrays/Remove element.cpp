void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}
int removeElement(int* nums, int numsSize, int val){
    mergeSort(nums,0,numsSize-1);
    int count=0;
    int pos;
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]==val){
            count++;
        }
    }
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]==val){
            pos=i;
            break;
        }
    }
    int ans=numsSize-count;
    for(int i=pos ; i<numsSize-count ; i++){
        nums[i]=nums[i+count];
    }
    return ans;
    

}