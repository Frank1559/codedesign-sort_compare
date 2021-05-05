void HeapAdjust(int a[],int s,int m){
        int rc,j;
        rc = a[s];
        for(j=2*s;j<=m;j=j*2){
                if(j<m&&a[j]<a[j+1]) j++;
                if(rc>a[j]) break;
                a[s]=a[j];s=j;
        }
        a[s] = rc;
}

void HeapSort(int a[],int n){
        int temp,i,j;
        for(i=n/2;i>0;i--){
                HeapAdjust(a,i,n);
        }
         for(i=n;i>0;i--){
                temp=a[1];
                a[1]=a[i];
                a[i]=temp;
                HeapAdjust(a,1,i-1);
        }
}

void s_HeapAdjust(char *a[],int s,int m){
    int j;
    char *rc;
    rc = a[s];
    for(j=2*s;j<=m;j=j*2){
        if(j<m&&strcmp(a[j], a[j+1]) < 0) j++;
        if(strcmp(rc, a[j]) > 0) break;
        a[s]=a[j];s=j;
    }
    a[s] = rc;
}


void s_HeapSort(char *a[],int n){
    int i;
    char *temp;

    for(i=n/2;i>0;i--){
        s_HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--){
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        s_HeapAdjust(a,1,i-1);
    }
}

int s_quick_sort(char *arr[], int low, int high){
    int pivot_point, i, j;
    char *pivot_item, *temp;

    if(high <= low) return 0;

    pivot_item = arr[low];
    j = low;
    //尋找比樞紐小的數
    for(i=low+1;i<high;i++){
        //跳過等於或大於的數
        if(strcmp(arr[i], pivot_item) >= 0) continue;
        j++;
        //交換 array[i], array[j]
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    //將樞紐位址移到中間
    pivot_point = j;
    //交換 array[low], array[pivot_point]
    temp = arr[low];
    arr[low] = arr[pivot_point];
    arr[pivot_point] = temp;

    //遞迴處理左側區段
    s_quick_sort(arr, low, pivot_point-1);
    //遞迴處理右側區段
    s_quick_sort(arr, pivot_point+1, high);
    return 0;
}

int quick_sort(int *array, int low, int high){
    int pivot_point, pivot_item, i, j, temp;

    //指標交界結束排序
    if(high <= low) return 0;
    //紀錄樞紐值
    pivot_item = array[low];
    j = low;
    //尋找比樞紐小的數
    for(i=low+1;i<high;i++){
        //跳過等於或大於的數
        if(array[i] >= pivot_item) continue;
        j++;
        //交換 array[i], array[j]
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    //將樞紐位址移到中間
    pivot_point = j;
    //交換 array[low], array[pivot_point]
    temp = array[low];
    array[low] = array[pivot_point];
    array[pivot_point] = temp;

    //遞迴處理左側區段
    quick_sort(array, low, pivot_point-1);
    //遞迴處理右側區段
    quick_sort(array, pivot_point+1, high);
    return 0;
}

void merge(int arr[], int head, int mid, int tail){
    int lenA = mid - head + 1;
    int lenB = tail - (mid + 1) + 1;
    int A[lenA];
    int B[lenB];

    //Copy data to temp arrays A[] and B[]
    int i, j, k;
    for(i = 0; i < lenA; i++){
        A[i] = arr[head + i];
    }
    for(j = 0; j < lenB; j++){
        B[j] = arr[mid + 1 + j];
    }

    // Merge two temp arrays back into arr[head..tail]
    i = 0;
    j = 0;
    k = head;
    //while array A and B haven't finished scanning
    while(i < lenA && j < lenB){
        if(A[i] < B[j]){
            arr[k] = A[i];
            i++;
        }
        else{
            arr[k] = B[j];
            j++;
        }
        k++;
    }

//Copy the remaing elements into arr[], if A[] haven't finished scanning
    while(i < lenA){
        arr[k] = A[i];
        i++;
        k++;
    }
//Copy the remaing elements into arr[], if B[] haven't finished scanning
    while(j < lenB){
        arr[k] = B[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int head, int tail){
    if(head < tail){
        int mid = (head + tail) / 2;
        merge_sort(arr, head, mid);
        merge_sort(arr, mid+1, tail);
        merge(arr, head, mid, tail);
    }
}

void s_merge(char *arr[], int head, int mid, int tail){
        int lenA = mid - head + 1;
        int lenB = tail - (mid + 1) + 1;
        char *A[lenA];
        char *B[lenB];

        //Copy data to temp arrays A[] and B[]
        int i, j, k;
        for(i = 0; i < lenA; i++){
                A[i] = arr[head + i];
        }
        for(j = 0; j < lenB; j++){
                B[j] = arr[mid + 1 + j];
        }
        // Merge two temp arrays back into arr[head..tail]
        i = 0;
        j = 0;
        k = head;
        //while array A and B haven't finished scanning
        while(i < lenA && j < lenB){
                if(strcmp(A[i], B[j]) < 0){
                        arr[k] = A[i];
                        i++;
                }
                else{
                        arr[k] = B[j];
                        j++;
                }
                k++;
        }
        //Copy the remaing elements into arr[], if A[] haven't finished scanning
        while(i < lenA){
                arr[k] = A[i];
                i++;
                k++;
        }
        //Copy the remaing elements into arr[], if B[] haven't finished scanning
        while(j < lenB){
                arr[k] = B[j];
                j++;
                k++;
        }
}

void s_merge_sort(char *arr[], int head, int tail){
        if(head < tail){
                int mid = (head + tail) / 2;
                s_merge_sort(arr, head, mid);
                s_merge_sort(arr, mid+1, tail);
                s_merge(arr, head, mid, tail);
        }
}
