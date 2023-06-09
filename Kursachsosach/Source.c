#include <stdio.h>
#include <stdlib.h>
typedef struct _predloz//���������� ��������� ������ ����������� ������
{
    char* slovo;//��������� �� ������� �������
    struct _predloz* next_slovo;//��������� �� ��������� �������
} predloz;

typedef struct _text//���������� ��������� ������ ����������� ������
{
    predloz* predl;//��������� �� ������� �������
    struct _text* next_predl;//��������� �� ��������� �������
} text;
typedef struct _ochered//���������� ���������  �������
{
    text* first;//��������� �� ������ �������
    text* last;//��������� �� ����� �������
    int size;//����������� �������
} ochered;
void print_spisok(predloz* head, predloz* ptr)//����� ������
{
    int i;
    // system("cls");
    while (head != NULL)
    {
        if (head == ptr)//���� ������ ������� ���������

        {
            for (i = 0; head->slovo[i] != '\n'; i++)//������ �������� ������
                printf("\x1b[31m%c\x1b[0m", head->slovo[i]);//����������� ������� ��������� �������
            printf(" ");
        }
        else
        {
            for (i = 0; head->slovo[i] != '\n'; i++)//������ �������� ������
                printf("%c", head->slovo[i]);
            printf(" ");
        }
        head = head->next_slovo;//���������� ���������
    }
    printf("\n");
    return;
}
void print_spisok(predloz* head, predloz* ptr)//������� ������
{
    predloz* tmp_predl = head;
    while (tmp_predl != NULL)//���� ��������� �� NULL
    {
        head = head->next_slovo;
        free(tmp_predl);//������� ����
        tmp_predl = head;
    }
    printf("list is empty\n");
    return head;
}
int check_end(predloz* ptr)//�������� � ����� �� ���������
{
    predloz* tmp = ptr;
    if (tmp->next_slovo == NULL)//���� ��� ���������� ��������
    {
        printf("Ukaz in the end\n");//��������� � �����
    }
    else
        printf("Ukaz not in the end\n");//��������� �� � �����

    return 0;
}
int check_pust(predloz* head)//�������� �� ����/�� ���� �� ������
{
    system("cls");
    if (head == NULL)//���� ������ ����� 
    {
        printf("Spisok pust\n");//������ ����
        return 0;
    }
    else
    {
        printf("Spisok ne pust\n");//������ �� ����
        return 1;
    }
}
predloz* get_elem(predloz* head, predloz* ptr)//����� �������� �� ����������
{
    predloz* temp = ptr;

    if (temp->next_slovo != NULL)//���� ���� ��������� �������
    {
        temp = temp->next_slovo;//������������ ���������
        return temp;
    }
    else
    {
        print_spisok(head, ptr);//����� ������
        printf("Net sled elem\n");
        return NULL;
    }
}
predloz* set_start(predloz* head)//������� ��������� � ������ ������
{
    printf("Yes!\n");
    return head;//���������� ������
}
predloz* pokaz_elem(predloz* head, predloz* ptr)//������ �������� ������ �� ����������
{
    predloz* tmp_predl = ptr->next_slovo;//�������� ��������� �� ��������� �������
    if (tmp_predl==NULL)
    {
        return NULL;
    }
    else
    {
        ptr->next_slovo = ptr->next_slovo->next_slovo;//������������ ���������
        return tmp_predl;
    }
}
predloz* go_next(predloz* head, predloz* ptr)//����� ��������� �����
{
    predloz* tmp = ptr;//�������� ������� �������
    if (tmp->next_slovo != NULL)//���� ���� ��������� �������
    {
        tmp = tmp->next_slovo;//������������ ���������
        ptr = tmp;
        print_spisok(head, ptr);//����� ������
    }
    else
    {
        print_spisok(head, ptr);//����� ������
        printf("Ukaz in the end\n");//���������. ��� ��� ���������� ��������
    }
    return ptr;
}
void vyvod_elementa(predloz* elem)//����� �������� ������
{
    int i;
    predloz* tmp = elem;
    for (i = 0; tmp->slovo[i] != '\n'; i++)
    {
        printf("%c", tmp->slovo[i]);//������� ������ �����
    }
    printf("\n");
    return;
}
void remove_elem(predloz* head, predloz* ptr)//�������� �������� �� ����������
{
    predloz* tmp_predl;
    if (ptr->next_slovo != NULL)
    {
        tmp_predl = ptr->next_slovo;
        ptr->next_slovo = ptr->next_slovo->next_slovo;//������������ ����������
        free(tmp_predl);//������� ����
    }
    else
        printf("Next elem is empty\n");
    print_spisok(head, ptr);//����� ������
    return;
}

predloz* create_node()// �������� �������� ������
{
    char c = ' ';
    int i = 0;
    predloz* node = (predloz*)malloc(sizeof(predloz));//������������ ��������� ������ ��� predloz �������
    if (node == NULL)//�������� �� NULL
    {
        printf("Not memorry\n");
        // exit(1);
    }
    node->slovo = (char*)malloc(sizeof(char*));//������������ ��������� ������ ��� predloz �������
    if (node->slovo == NULL)//�������� �� NULL
    {
        printf("Not memorry\n");
        free(node);
        // exit(1);
    }
    printf("Vvedite slovo\n");
    c = getchar();// ���� ����� �����������
    c = ' ';
    for (i; c != '\n'; i++)
    {
        node->slovo = realloc(node->slovo, (i + 1) * sizeof(char));//������������ ���������� ������ ��� char
        if (!node->slovo)// �������� �� NULL
        {
            printf("Not memorry!\n");
            free(node);//������� ����
            // exit(1);
        }
        c = getchar();
        node->slovo[i] = c;// ��������� � ������ ������
    }
    node->slovo[i] = 0;
    node->next_slovo = NULL;
    return node;
}

void change_elem(predloz* head, predloz* ptr)//��������� �������� �� ����������
{
    predloz* temp = ptr;//����� ������� �������
    predloz* pointer = ptr;
    if (temp->next_slovo != NULL)
    {
        temp = temp->next_slovo;
    }
    else
    {
        printf("there is no word behind the pointer\n");//���������� ��� ��� �������� �� ����������
        return;
    }
    predloz* new_elem = create_node();//�������� �������� ������
    pointer->next_slovo = new_elem;
    new_elem->next_slovo = temp->next_slovo;//������������ ����������
    free(temp);//������� ����
    print_spisok(head, ptr);//����� ������ ����
    return;
}
predloz* menu1(ochered*ocher)//���� ��� ��������� ������������ ������
{
    //predloz* head = (predloz*)malloc(sizeof(predloz));//������������ ��������� ������ ��� predloz �������
    predloz* head = ocher;
    head = NULL;
    int num;
    predloz* ptr = head;
    predloz* show = NULL;
    int st1;
    system("cls");
    while (1) {
        printf("Press 1 to start predloz\n");//������ ������ �� �������
        scanf_s("%d", &st1);
        if (st1 == 1)
            break;

        
        system("cls");
    }
    system("cls");
    while (1)
    {
        printf("Menu\n");//������ ��������� ������������ ������
        printf("1-Clear\n");
        printf("2-Pust or not\n");
        printf("3-Uk na start\n");
        printf("4-Uk end?\n");
        printf("5-Uk vpered\n");
        printf("6-Vzyat elem za ukaz\n");
        printf("7-Delete elem za uk\n");
        printf("8-Show elem za uk\n");
        printf("9-Change elem\n");
        printf("10-Add elem\n");
        printf("11-Raspechat struct\n");
        printf("12-Zakonch spisok\n");
        printf("Vvedite znach: ");
        scanf_s("%d", &num);
        switch (num)
        {
        case 1:
            system("cls");//������� �������
            if (head == NULL)
                printf("Spisok pust\n");
            else
                head = clear_1(head);//������� ������ ����
            break;
        case 2:
            if (check_pust(head))//�������� �� ����/ �� ���� �� ������
            {
                print_spisok(head, ptr);// ����� ������
            }
            break;
        case 3:
            system("cls");// ������� �������
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                ptr = set_start(head);//������� ��������� � ������ ������
                print_spisok(head, ptr);//����� ������
            }
            break;
        case 4:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                print_spisok(head, ptr);//����� ������
                check_end(ptr);//�������� �� ��, ����� �� ��������� � ����� ������
            }
            break;
        case 5:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                ptr = go_next(head, ptr);//������� ��������� �����
            break;
        case 6:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                show = pokaz_elem(head, ptr);//������ �������� �� ����������
                print_spisok(head, ptr);//����� ������
                if (show == NULL)
                {
                    print_spisok(head, ptr);//����� ������
                    printf("Not next elem!\n");
                }
                else {
                    show->next_slovo = NULL;
                    print_spisok(show, ptr);//����� ������
                }
               /* if (show->next_slovo == NULL)
                {
                    print_spisok(head, ptr);
                    printf("Not next elem!\n");
                }*/
            }
            break;
        case 7:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                remove_elem(head, ptr);//�������� �������� �� ����������

            break;
        case 8:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                // elem = get_elem(head, ptr);
                if (get_elem(head, ptr) != NULL)//����� �������� �� ����������
                {
                    print_spisok(head, ptr);//����� ������
                    vyvod_elementa(get_elem(head, ptr));//����� �������� �� ����������
                }
            }
            break;
        case 9:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                change_elem(head, ptr);//��������� �������� �� ����������
            break;
        case 10:
            system("cls");
            if (head == NULL)
            {
                head = (predloz*)malloc(sizeof(predloz));//������������ ��������� ������ ��� predloz �������
                head = create_node();//�������� �������� ������
                ptr = head;
            }
            else
            {
                if (ptr->next_slovo == NULL)
                {
                    ptr->next_slovo = create_node();//�������� ���������� �������� ������
                }
                else
                {
                    predloz* tmp_predl = head->next_slovo;//����������� ���������� ��������
                    ptr->next_slovo = create_node();//�������� ���������� ��������
                    ptr->next_slovo->next_slovo = tmp_predl;//������������ ����������
                }
            }
            print_spisok(head, ptr);//����� ������
            break;
        case 11:
            system("cls");//������� �������
            if (head == NULL)
                printf("Spisok pust\n");
            else
                print_spisok(head, ptr);//����� ������
            break;
        case 12:
            system("cls");// ������� �������
            /*if (head == NULL)
             {
                printf("the offer is empty, there is nothing to return\n");
                break;
            }*/
            return head;//������� ������ � ���� �������� ������
            break;
        default:
            printf("Vvedeno ne to znach, try again!\n");//��������� � ���, ��� ������� ������������ �������� switch

            // system("cls");
        }
    }
}
predloz* menu2(predloz* head)
{
    //predloz* head = (predloz*)malloc(sizeof(predloz));
    //head = NULL;
    int num;
    predloz* ptr = head;
    predloz* show = NULL;
    int st1;
    system("cls");
    while (1) {
        printf("Press 1 to start predloz\n");
        scanf_s("%d", &st1);
        if (st1 == 1)
            break;
       system("cls");
    }
    system("cls");
    while (1)
    {
        printf("Menu\n");
        printf("1-Clear\n");
        printf("2-Pust or not\n");
        printf("3-Uk na start\n");
        printf("4-Uk end?\n");
        printf("5-Uk vpered\n");
        printf("6-Vzyat elem za ukaz\n");
        printf("7-Delete elem za uk\n");
        printf("8-Show elem za uk\n");
        printf("9-Change elem\n");
        printf("10-Add elem\n");
        printf("11-Raspechat struct\n");
        printf("12-Zakonch spisok\n");
        printf("Vvedite znach: ");
        scanf_s("%d", &num);
        switch (num)
        {
        case 1:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                head = clear_1(head);
            break;
        case 2:
            if (check_pust(head))
            {
                print_spisok(head, ptr);
            }
            break;
        case 3:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                ptr = set_start(head);
                print_spisok(head, ptr);
            }
            break;
        case 4:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                print_spisok(head, ptr);
                check_end(ptr);
            }
            break;
        case 5:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                ptr = go_next(head, ptr);
            break;
        case 6:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                show = pokaz_elem(head, ptr);
                print_spisok(head, ptr);
                if (show == NULL)
                {
                    print_spisok(head, ptr);
                    printf("Not next elem!\n");
                }
                else {
                    show->next_slovo = NULL;
                    print_spisok(show, ptr);
                }
                /* if (show->next_slovo == NULL)
                 {
                     print_spisok(head, ptr);
                     printf("Not next elem!\n");
                 }*/
            }
            break;
        case 7:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                remove_elem(head, ptr);
            break;
        case 8:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                // elem = get_elem(head, ptr);
                if (get_elem(head, ptr) != NULL)
                {
                    print_spisok(head, ptr);
                    vyvod_elementa(get_elem(head, ptr));
                }
            }
            break;
        case 9:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                change_elem(head, ptr);
            break;
        case 10:
            system("cls");
            if (head == NULL)
            {
                head = (predloz*)malloc(sizeof(predloz));
                head = create_node();
                ptr = head;
            }
            else
            {
                if (ptr->next_slovo == NULL)
                {
                    ptr->next_slovo = create_node();
                }
                else
                {
                    predloz* tmp_predl = head->next_slovo;
                    ptr->next_slovo = create_node();
                    ptr->next_slovo->next_slovo = tmp_predl;
                }
            }
            print_spisok(head, ptr);
            break;
        case 11:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                print_spisok(head, ptr);
            break;
        case 12:
            system("cls");
           /* if (head == NULL)
            {
                printf("the offer is empty, there is nothing to return\n");
                break;
            }*/
            return head;
            break;
        default:
            printf("Vvedeno ne to znach, try again!\n");

            // system("cls");
        }
    }
}
ochered* create_ochered()//�������� ���� �������
{
    ochered* ocher = (ochered*)malloc(sizeof(ochered));//������������ ��������� ������ ��� text �������
    ocher->size = 0;
    ocher->first = NULL;
    ocher->last = NULL;
    return ocher;
}
void add_to_end(ochered* ocher)//���������� � ����� �������
{
    if (ocher->first == NULL)//���� ������� �����
    {
        text* tmp_text = (text*)malloc(sizeof(text));//������������ ��������� ������  ��� text �������
        if (tmp_text == NULL)//�������� �� NULL
        {
            printf("not memorry\n");
        }
        tmp_text->predl = menu1( tmp_text->predl);//������� � ���� ������� ������
        tmp_text->next_predl = NULL;
        ocher->size++;
        ocher->first = tmp_text;//����� ������ ���� � ������ �������
        ocher->last = tmp_text;//����� ������ ���� � ����� �������
    }
    else
    {
        text* tmp_text = (text*)malloc(sizeof(text));//������������ ��������� ������ ��� text �������
        if (tmp_text == NULL)//�������� �� NULL
        {
            printf("not memorry\n");
        }
        tmp_text->predl = menu1(tmp_text->predl);// ������� � ���� ������� ������
        tmp_text->next_predl = NULL;
        ocher->last->next_predl = tmp_text;//����� ������ ���� � ����� �������
        ocher->last = tmp_text;
        ocher->size++;
    }
    return ;
}
void print_spisok_ochered(predloz* head)//����� ������� �� ��������
{
    int i;
    while (head != NULL)
    {

        for (i = 0; head->slovo[i] != '\n'; i++)// � ������� ����� ������� ����������� ����� �� \n
            printf("%c", head->slovo[i]);
        printf(" ");
        head = head->next_slovo;// ��������� � ���������� �����
    }
    printf("\n");
    return;
}
void print_ochered(ochered* ocher)//����� ���� �������
{
    //system("cls");
    if (!ocher->first)
        printf("the queue is empty\n");//���� ������� �����, �� ���� ��������������� ���������
    text* tmp_text = ocher->first;//������� ������ �������
    while (tmp_text)
    {
        print_spisok_ochered(tmp_text->predl);//����� ������� �� ��������
        tmp_text = tmp_text->next_predl;
    }
    return;
}
void pust_or_not_ocher(ochered* ocher)
{
    system("cls");//������� �������
    if (!ocher->first)
        printf("The queue is empty\n");//���� ������� �����, �� ���� ��������������� ���������
    else
        printf("The queue is not empty\n");//���� ������� �� �����, �� ���� ��������������� ���������
    return;
}
void show_start_elem(ochered* ocher)
{
    system("cls");
    if (!ocher->first)
        printf("the queue is empty\n");//���� ������� �����, �� ���� ��������������� ���������
    else
        print_spisok_ochered(ocher->first->predl);//����� ������� �� ��������
    return;
}
void del_start_ochered(ochered* ocher)

{
    system("cls");
    if (!ocher->first)
    {
        printf("the queue is empty\n");//���� ������� �����, �� ���� ��������������� ���������
        return;
    }
    text* tmp_text;
    if (ocher->first == ocher->last)
    {
        tmp_text = ocher->first;//������� ������ �������
        ocher->first = NULL;
        ocher->last = NULL;
        clear_1(tmp_text->predl);//������� ������ ���� ������� ����� � ������ �������� �������
        free(tmp_text);//������ ����
    }
    else
    {
        tmp_text = ocher->first;//������� ������ �������
        ocher->first = ocher->first->next_predl;//������ ���������
        clear_1(tmp_text->predl);//������� ������ ���� ������� ����� � ������ �������� �������
        free(tmp_text);//������ ����
    }
    return;
}
void get_elem_start_ocher(ochered* ocher)//������ ������� �������� �������
{
    system("cls");
    if (!ocher->first)
    {
        printf("the queue is empty\n");//���� ������� �����, �� ���� ��������������� ���������
        return;
    }
    text* tmp_text;
    if (ocher->first == ocher->last)
    {
        tmp_text = ocher->first;//������� ���������
        ocher->first = NULL;
        ocher->last = NULL;
        print_spisok_ochered(tmp_text->predl);//����� ������� �� ��������
        clear_1(tmp_text->predl);//������� ������ ���� ������� ����� � ������ �������� �������
        free(tmp_text);//������ ����
    }
    else
    {
        tmp_text = ocher->first;//������� ���������
        ocher->first = ocher->first->next_predl;
        print_spisok_ochered(tmp_text->predl);//����� ������� �� ��������
        clear_1(tmp_text->predl);//������� ������ ���� ������� ����� � ������ �������� �������
        free(tmp_text);//������ ����
    }
    return;
}
void clear_ocher(ochered* ocher)// ������� �������
{
    if (!ocher->first)
    {
        printf("the queue is empty\n"); //���� ������� �����, �� ���� ��������������� ���������
        return;
    }
    while (ocher->first)
    {
        del_start_ochered(ocher);//�������� ������� �������� �������
    }
    return;
}
void change_elem_start_ocher(ochered* ocher)// ��������� ������� �������� �������
{
    if (!ocher->first)
    {
        printf("the queue is empty\n");// ���� ������� �����, �� ���� ��������������� ���������
        return;
    }
    //clear_1(ocher->first->predl);
    //ocher =change_ocher(ocher);
    ocher->first->predl=menu2(ocher->first->predl);//������� � ���� ������� ������ ��� ��������� ������� �������� �������
    return;
}
void menu(ochered*ocher,int k,int d)//���� ��� ��������� �������
{
    system("cls");//������� �������
    while (1)
    {
       // system("cls");
        int num1;
        printf("Menu\n");// ������ ��������� �������
        printf("1-Clear\n");
        printf("2-Pust or not\n");
        printf("3-Show start elem\n");
        printf("4-Delete start\n");
        printf("5-Get elem from start\n");
        printf("6-Change elem from start\n");
        printf("7-Add elem to the end\n");
        printf("8-Print ochered\n");
        printf("9-Zakoncit ochered\n");
        printf("Vvedite znach: ");
        scanf_s("%d", &num1);
        switch (num1)
        {
        case 1:
            system("cls");
            d = 0;
            clear_ocher(ocher);//������� ���� �������
            break;
        case 2:
            system("cls");
            pust_or_not_ocher(ocher);//�������� ����� ������� ��� ���
            break;
        case 3:
            system("cls");
            show_start_elem(ocher);//����� ������� �������� �������
            break;
        case 4:
            system("cls");
            del_start_ochered(ocher);//�������� ������� �������� �������
            d = d - 1;;
            break;
        case 5:
            system("cls");
            get_elem_start_ocher(ocher);//������ �������� �� ������ �������
            printf("\n");
            print_ochered(ocher);//������� �������
            d--;
            break;
        case 6:
            system("cls");
            change_elem_start_ocher(ocher);//��������� ������� �������� �������
            break;
        case 7:
            d++;
            if (d > k) {
                printf("Ochered is full,you cant add element\n");//��������� ���� ������� �����������
                d--;
            }
            else
                 add_to_end(ocher);//���������� �������� � ����� �������
            break;
        case 8:
            system("cls");
            print_ochered(ocher);//������� �������
            break;
        case 9:
            system("cls");
            clear_ocher(ocher);//������� ������� � ������� � main
            return;
            break;
        default:
            printf("Vvedeno ne to znach, try again!\n");//��������� � ���, ��� ������� ������������ �������� switch
        }
    }
}
int main()
{
    int st;
    while (1){
    printf("Press 1 to start ochered\n");//������ ������ � ��������
    printf("Press 2 if you do not want to start ochered\n");
    scanf_s("%d", &st);
    if (st == 1) {
        ochered* ocher = create_ochered();//�������� �������� �������
            int k,d=0;
        int k_el =0;
        printf("How much elements in ochered?\n");
        scanf_s("%d", &k);//����� �����������
        menu(ocher,k,d);//������� � ���� �������� ������
    }
    else if (st == 2)
        exit(1);
        system("cls");
    }
    return 0;
}