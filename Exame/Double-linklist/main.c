#include <stdio.h>

// กำหนดโครงสร้างข้อมูลของโหนดใน double linked list
struct Node {
    int data; //เก็บข้อมูลในโหนด
    struct Node* prev; //เก็บที่อยู่โหนดก่อนหน้า
    struct Node* next;//เก็บที่อยู่โหนดถัดไป
};

//StartList ใช้กำหนดค่าเริ่มต้นให้link list ที่ส่งเข้ามาในnodeList โดยให้ prev,next ทุกโหนดเป็นค่าว่าง (NULL)
void StartList(struct Node* nodeList, int size) {
    for (int i = 0; i < size; i++) {
        nodeList[i].prev = NULL;
        nodeList[i].next = NULL;
    }
}

//เพิ่มโหนดใหม่ในlink list โดยโหนดที่เพิ่มใหม่จะเพิ่มไว้ที่ท้ายสุด
void add(struct Node* head, struct Node* nodeList, int new_data, int size) {
    struct Node* new_node = head; //ชี้ไปโหนดแรกของlink list ที่เริ่มต้น

        //วนลูปไปจนกว่า new_node จะชี้ไปที่โหนดสุดท้ายของ link list (ที่ next เป็น NULL)
    while (new_node->next != NULL) {
        new_node = new_node->next;
    }

        // วนลูปผ่าน nodeList เพื่อหาโหนดว่างใน nodeList เพื่อเพิ่มข้อมูลใหม่ลงไป
    for (int i = 0; i < size; i++) {

                // หาว่าโหนดใน nodeList ว่างเปล่าหรือไม่ โดยตรวจสอบว่า prev และ next ของโหนดนั้นๆ มีค่าเป็น NULL หรือไม่
        if (nodeList[i].prev == NULL && nodeList[i].next == NULL) {
            nodeList[i].data = new_data; //เพิ่มข้อมูลใหม่ในโหนดที่ตรวจเจอว่าว่าง
            nodeList[i].prev = new_node; //ชี้ไปโหนดสุดท้าย
            new_node->next = &nodeList[i];//ชี้ไปโหนดใหม่ที่เพิ่มมา
            return;
        }
    }
}

//สลับข้อมูลตำแหน่ง A B
void swapNode(struct Node* head, int posA, int posB) {
        //ชี้ไปที่โหนดตัวแรกของ linked list (นับจากโหนดhead)
    struct Node* nodeA = head->next;
    struct Node* nodeB = head->next;
    int count = 0;//นับตำแหน่ง

         //วนลูปนกว่า nodeA จะชี้ไปที่โหนดตำแหน่ง posA หรือจนกว่าจะหมด โดยเพิ่ม count ทีละ 1
    while (nodeA != NULL && count != posA) {
        nodeA = nodeA->next;
        count++;
    }

        //รีเซ็ตค่า count และวนลูปใหม่หาโหนด ที่ตำแหน่ง posB
    count = 0;
    while (nodeB != NULL && count != posB) {
        nodeB = nodeB->next;
        count++;
    }

        //ตรวจว่าพบโหนดที่ตำแหน่ง posA และ posB หรือไม่
    if (nodeA == NULL || nodeB == NULL) {
        printf("Invalid positions!\n");
        return;
    }

        //สลับค่าข้อมูลระหว่างโหนดที่ posA และ posB
    int temp = nodeA->data;
    nodeA->data = nodeB->data;
    nodeB->data = temp;
}

//แสดงข้อมูลทั้งหมด
void printList(struct Node* head) {
    struct Node* current = head->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int dataSize, posA, posB;
    printf("Enter data size: ");
    scanf("%d", &dataSize);

    struct Node head; //ประกาศตัวแปร head เป็นโหนดแรกของlink list
    struct Node nodeList[dataSize]; //ใช้เก็บโหนดที่สร้าง

   StartList(nodeList, dataSize); //รียกใช้ฟังก์ชัน StartList

        //กำหนดค่าเริ่มต้น เป็นค่าว่าง
    head.data = -1;
    head.prev = NULL;
    head.next = NULL;

    for (int i = 0; i < dataSize; i++) {
        int newData;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &newData);
        add(&head, nodeList, newData, dataSize);
    }

    printf("Linked list before swapping: ");
    printList(&head);

    printf("Enter positions to swap (A B): ");
    scanf("%d %d", &posA, &posB);

    swapNode(&head, posA, posB);

    printf("Linked list after swapping: ");
    printList(&head);

    return 0;
}
