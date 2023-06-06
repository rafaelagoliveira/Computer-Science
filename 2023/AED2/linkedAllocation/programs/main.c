#include "GraphicInterface.h"
#include "MemoryManager.h"

int main() {
    int mBytes, tBytes, idBlock, userChoice;
    SimpleNode *listAvaliableBlocks = initializeListAvaliableBlocks();
    DoubleNode *listAllocatedBlocks = initializeListAllocatedBlocks();

    do {
        printf("\nEnter the storage capacity of the memory unit: ");
        scanf("%d", &mBytes);

        if (mBytes <= 0) {
            printf("\nInvalid value!\n");
        }

    } while (mBytes <= 0);

    insertListAvaliableBlocks(&listAvaliableBlocks, 0, mBytes);

    gfx_init(WIDTH, HEIGHT, "Linked Allocation");

    do {
        background();
        gfxShowMemoryManager(listAvaliableBlocks, listAllocatedBlocks, mBytes);
        gfx_paint();

        printf("\n0 - Exit\n1 - Allocate block\n2 - Desallocate block\n--> ");
        scanf("%d", &userChoice);

        switch (userChoice) {
        case 0:
            gfx_quit();
            printf("\nFinished!\n");
            deallocationAllBlocks(&listAvaliableBlocks, &listAllocatedBlocks);
            break;
        case 1:

            do {
                printf("\nEnter the number of bytes you want to allocate: ");
                scanf("%d", &tBytes);

                if (tBytes <= 0) {
                    printf("\nInvalid value!\n");
                }

            } while (tBytes <= 0 || tBytes > mBytes);

            allocation(&listAvaliableBlocks, &listAllocatedBlocks, tBytes, mBytes);
            break;
        case 2:
            printf("\nEnter the ID of the block you want to desallocate: ");
            scanf("%d", &idBlock);
            
            DoubleNode *aux = searchListAllocatedBlocks(&listAllocatedBlocks, idBlock);

            if (aux == NULL) {
                printf("\nBlock not found!\n");
                break;
            }

            deallocation(&listAvaliableBlocks, &listAllocatedBlocks, idBlock);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
        }

    } while (userChoice != EXIT_SUCCESS);

    return EXIT_SUCCESS;
}
