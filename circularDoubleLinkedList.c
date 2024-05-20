#include <stdio.h>
#include <stdlib.h>

typedef struct node *address;
struct node{
    int data;
    address prev, next;
};

address listFirst = NULL, listLast = NULL;

address createNode(int nilai){
    //alokasi node
    address p = (address) malloc(sizeof(struct node));
    p->data = nilai;
    p->prev = p->next = NULL;
    return (p);
}

void insertLast(int nilai){
    address val = createNode(nilai);

    if (listFirst == NULL && listLast == NULL){
        listFirst = val;
        listLast = val;
        val->next = listFirst;
        val->prev = listLast;
    } else {
        listLast->next = val;
        val->prev = listLast;
        listLast = val;
        listFirst->prev = listLast;
        listLast->next = listFirst;
    }
}

void viewBeforeAscend(){
    address val = listLast;

    if (listFirst == NULL && listLast == NULL){
        printf("[]\n\n");
    } else {
        do {
            printf("Address: %p, Data: [%d]\n", (void*)val, val->data);
            val = val->next;
        } while (val != listLast);
        printf("\n\n");
    }
}

void sortFunction(){
    int sizeArray = 0;
    address val = listFirst;
    do{
        sizeArray++;
        val = val->next;
    } while (val != listFirst);

    int *array = (int*)malloc(sizeArray * sizeof(int));
    address *alamat = (address*)malloc(sizeArray * sizeof(address));

    for (int i = 0; i < sizeArray; i++){
        array[i] = val->data;
        alamat[i] = val;
        val = val->next;
    }    

    for (int i = 0; i < sizeArray-1; i++){
        for (int j = 0; j < sizeArray - i - 1; j++){
            if (array[j] > array[j+1]){
                int tempData = array[j];
                array[j] = array[j+1];
                array[j+1] = tempData;
                
                address tempAlamat = alamat[j];
                alamat[j] = alamat[j+1];
                alamat[j+1] = tempAlamat;
            }
        }
    }

    for (int i = 0; i < sizeArray; i++){
        printf("Address: %p, Data: [%d]\n", (void*)alamat[i], array[i]);
    }
    printf("\n\n");

    free(alamat);
    free(array);
}

void viewAfterAscend(){
    sortFunction();
}

int main(int argc, char const *argv[]){
    int pilihan;
    
    do{
        viewBeforeAscend();
        printf("1. Insert Last\n");
        printf("2. Lihat node sebelum Ascending\n");
        printf("3. Lihat node setelah Ascending\n");
        printf("0. Exit\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan){
            case 1:
                int total, nilai;

                printf("Masukkan Total: ");
                scanf("%d", &total);

                printf("Masukkan Nilai: ");
                for (int i = 0; i < total; i++){
                    scanf("%d", &nilai);
                    insertLast(nilai);
                }
                break;
            case 2:
                viewBeforeAscend();
                break;
            case 3:
                viewAfterAscend();
                break;
            default:
                break;
        }
    } while (pilihan != 0);
    
    return 0;
}
