#include <stdio.h>
#include <stdlib.h>
typedef struct _predloz//объявление структуры данных односвязный список
{
    char* slovo;//указатель на текущий элемент
    struct _predloz* next_slovo;//указатель на следующий элемент
} predloz;

typedef struct _text//объявление структуры данных односвязный список
{
    predloz* predl;//указатель на текущий элемент
    struct _text* next_predl;//указатель на следующий элемент
} text;
typedef struct _ochered//объявление структуры  очередь
{
    text* first;//указатель на начало очереди
    text* last;//указатель на конец очереди
    int size;//размерность очереди
} ochered;
void print_spisok(predloz* head, predloz* ptr)//вывод списка
{
    int i;
    // system("cls");
    while (head != NULL)
    {
        if (head == ptr)//если голова текущий указатель

        {
            for (i = 0; head->slovo[i] != '\n'; i++)//вывожу элементы списка
                printf("\x1b[31m%c\x1b[0m", head->slovo[i]);//подсвечиваю текущий указатель красным
            printf(" ");
        }
        else
        {
            for (i = 0; head->slovo[i] != '\n'; i++)//вывожу элементы списка
                printf("%c", head->slovo[i]);
            printf(" ");
        }
        head = head->next_slovo;//передвигаю указатель
    }
    printf("\n");
    return;
}
void print_spisok(predloz* head, predloz* ptr)//очистка списка
{
    predloz* tmp_predl = head;
    while (tmp_predl != NULL)//пока указатель не NULL
    {
        head = head->next_slovo;
        free(tmp_predl);//очистка узла
        tmp_predl = head;
    }
    printf("list is empty\n");
    return head;
}
int check_end(predloz* ptr)//проверка в конце ли указатель
{
    predloz* tmp = ptr;
    if (tmp->next_slovo == NULL)//если нет следующего элемента
    {
        printf("Ukaz in the end\n");//указатель в конце
    }
    else
        printf("Ukaz not in the end\n");//указатель не в конце

    return 0;
}
int check_pust(predloz* head)//проверка на пуст/не пуст ли список
{
    system("cls");
    if (head == NULL)//если голова пуста 
    {
        printf("Spisok pust\n");//список пуст
        return 0;
    }
    else
    {
        printf("Spisok ne pust\n");//список не пуст
        return 1;
    }
}
predloz* get_elem(predloz* head, predloz* ptr)//показ элемента за указателем
{
    predloz* temp = ptr;

    if (temp->next_slovo != NULL)//если есть следующий элемент
    {
        temp = temp->next_slovo;//переставляем указатель
        return temp;
    }
    else
    {
        print_spisok(head, ptr);//вывод списка
        printf("Net sled elem\n");
        return NULL;
    }
}
predloz* set_start(predloz* head)//возврат указателя в начало списка
{
    printf("Yes!\n");
    return head;//возвращаем голову
}
predloz* pokaz_elem(predloz* head, predloz* ptr)//взятие элемента списка за указателем
{
    predloz* tmp_predl = ptr->next_slovo;//копируем указатель на следующий элемент
    if (tmp_predl==NULL)
    {
        return NULL;
    }
    else
    {
        ptr->next_slovo = ptr->next_slovo->next_slovo;//переставляем указатель
        return tmp_predl;
    }
}
predloz* go_next(predloz* head, predloz* ptr)//сдвиг указателя вперёд
{
    predloz* tmp = ptr;//копируем текущую позицию
    if (tmp->next_slovo != NULL)//если есть следующий элемент
    {
        tmp = tmp->next_slovo;//переставляем указатели
        ptr = tmp;
        print_spisok(head, ptr);//вывод списка
    }
    else
    {
        print_spisok(head, ptr);//вывод списка
        printf("Ukaz in the end\n");//сообщение. что нет следующего элемента
    }
    return ptr;
}
void vyvod_elementa(predloz* elem)//вывод элемента списка
{
    int i;
    predloz* tmp = elem;
    for (i = 0; tmp->slovo[i] != '\n'; i++)
    {
        printf("%c", tmp->slovo[i]);//выводим строку слова
    }
    printf("\n");
    return;
}
void remove_elem(predloz* head, predloz* ptr)//удаление элемента за указателем
{
    predloz* tmp_predl;
    if (ptr->next_slovo != NULL)
    {
        tmp_predl = ptr->next_slovo;
        ptr->next_slovo = ptr->next_slovo->next_slovo;//перестановка указателей
        free(tmp_predl);//очистка узла
    }
    else
        printf("Next elem is empty\n");
    print_spisok(head, ptr);//вывод списка
    return;
}

predloz* create_node()// создание элемента списка
{
    char c = ' ';
    int i = 0;
    predloz* node = (predloz*)malloc(sizeof(predloz));//динамическое выделение памяти под predloz элемент
    if (node == NULL)//проверка на NULL
    {
        printf("Not memorry\n");
        // exit(1);
    }
    node->slovo = (char*)malloc(sizeof(char*));//динамическое выделение памяти под predloz элемент
    if (node->slovo == NULL)//проверка на NULL
    {
        printf("Not memorry\n");
        free(node);
        // exit(1);
    }
    printf("Vvedite slovo\n");
    c = getchar();// ввод слова посимвольно
    c = ' ';
    for (i; c != '\n'; i++)
    {
        node->slovo = realloc(node->slovo, (i + 1) * sizeof(char));//динамическое добавление памяти под char
        if (!node->slovo)// проверка на NULL
        {
            printf("Not memorry!\n");
            free(node);//очистка узла
            // exit(1);
        }
        c = getchar();
        node->slovo[i] = c;// добавляем в строку символ
    }
    node->slovo[i] = 0;
    node->next_slovo = NULL;
    return node;
}

void change_elem(predloz* head, predloz* ptr)//изменение элемента за указателем
{
    predloz* temp = ptr;//копия текущей позиции
    predloz* pointer = ptr;
    if (temp->next_slovo != NULL)
    {
        temp = temp->next_slovo;
    }
    else
    {
        printf("there is no word behind the pointer\n");//сообщениеб что нет элемента за указателем
        return;
    }
    predloz* new_elem = create_node();//создание элемента списка
    pointer->next_slovo = new_elem;
    new_elem->next_slovo = temp->next_slovo;//перестановка указателей
    free(temp);//очистка узла
    print_spisok(head, ptr);//вывод списка слов
    return;
}
predloz* menu1(ochered*ocher)//меню для обработки односвязного списка
{
    //predloz* head = (predloz*)malloc(sizeof(predloz));//динамическое выделение памяти под predloz элемент
    predloz* head = ocher;
    head = NULL;
    int num;
    predloz* ptr = head;
    predloz* show = NULL;
    int st1;
    system("cls");
    while (1) {
        printf("Press 1 to start predloz\n");//начало работы со списком
        scanf_s("%d", &st1);
        if (st1 == 1)
            break;

        
        system("cls");
    }
    system("cls");
    while (1)
    {
        printf("Menu\n");//пункты обработки односвязного списка
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
            system("cls");//очистка консоли
            if (head == NULL)
                printf("Spisok pust\n");
            else
                head = clear_1(head);//очистка списка слов
            break;
        case 2:
            if (check_pust(head))//проверка на пуст/ не пуст ли список
            {
                print_spisok(head, ptr);// вывод списка
            }
            break;
        case 3:
            system("cls");// очистка консоли
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                ptr = set_start(head);//возврат указателя в начало списка
                print_spisok(head, ptr);//вывод списка
            }
            break;
        case 4:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                print_spisok(head, ptr);//вывод списка
                check_end(ptr);//проверка на то, стоит ли указатель в конце списка
            }
            break;
        case 5:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                ptr = go_next(head, ptr);//сдвигаю указатель вперёд
            break;
        case 6:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                show = pokaz_elem(head, ptr);//взятие элемента за указателем
                print_spisok(head, ptr);//вывод списка
                if (show == NULL)
                {
                    print_spisok(head, ptr);//вывод списка
                    printf("Not next elem!\n");
                }
                else {
                    show->next_slovo = NULL;
                    print_spisok(show, ptr);//вывод списка
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
                remove_elem(head, ptr);//удаление элемента за указателем

            break;
        case 8:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
            {
                // elem = get_elem(head, ptr);
                if (get_elem(head, ptr) != NULL)//показ элемента за указателем
                {
                    print_spisok(head, ptr);//вывод списка
                    vyvod_elementa(get_elem(head, ptr));//вывод элемента за указателем
                }
            }
            break;
        case 9:
            system("cls");
            if (head == NULL)
                printf("Spisok pust\n");
            else
                change_elem(head, ptr);//изменение элемента за указателем
            break;
        case 10:
            system("cls");
            if (head == NULL)
            {
                head = (predloz*)malloc(sizeof(predloz));//динамическое выделение памяти под predloz элемент
                head = create_node();//создание элемента списка
                ptr = head;
            }
            else
            {
                if (ptr->next_slovo == NULL)
                {
                    ptr->next_slovo = create_node();//создание следующего элемента списка
                }
                else
                {
                    predloz* tmp_predl = head->next_slovo;//копирование следующего элемента
                    ptr->next_slovo = create_node();//создание следующего элемента
                    ptr->next_slovo->next_slovo = tmp_predl;//перестановка указателей
                }
            }
            print_spisok(head, ptr);//вывод списка
            break;
        case 11:
            system("cls");//очистка консоли
            if (head == NULL)
                printf("Spisok pust\n");
            else
                print_spisok(head, ptr);//вывод списка
            break;
        case 12:
            system("cls");// очистка консоли
            /*if (head == NULL)
             {
                printf("the offer is empty, there is nothing to return\n");
                break;
            }*/
            return head;//возврат головы в меню верхнего уровня
            break;
        default:
            printf("Vvedeno ne to znach, try again!\n");//сообщение о том, что введено неправильное значение switch

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
ochered* create_ochered()//создание узла очереди
{
    ochered* ocher = (ochered*)malloc(sizeof(ochered));//динамическое выделение памяти под text элемент
    ocher->size = 0;
    ocher->first = NULL;
    ocher->last = NULL;
    return ocher;
}
void add_to_end(ochered* ocher)//добавление в конец очереди
{
    if (ocher->first == NULL)//если очередь пуста
    {
        text* tmp_text = (text*)malloc(sizeof(text));//динамическое выделение памяти  под text элемент
        if (tmp_text == NULL)//проверка на NULL
        {
            printf("not memorry\n");
        }
        tmp_text->predl = menu1( tmp_text->predl);//переход в меню нижнего уровня
        tmp_text->next_predl = NULL;
        ocher->size++;
        ocher->first = tmp_text;//кладу список слов в начало очереди
        ocher->last = tmp_text;//кладу список слов в конец очереди
    }
    else
    {
        text* tmp_text = (text*)malloc(sizeof(text));//динамическое выделение памяти под text элемент
        if (tmp_text == NULL)//проверка на NULL
        {
            printf("not memorry\n");
        }
        tmp_text->predl = menu1(tmp_text->predl);// переход в меню нижнего уровня
        tmp_text->next_predl = NULL;
        ocher->last->next_predl = tmp_text;//кладу список слов в конец очереди
        ocher->last = tmp_text;
        ocher->size++;
    }
    return ;
}
void print_spisok_ochered(predloz* head)//вывод очереди по элементу
{
    int i;
    while (head != NULL)
    {

        for (i = 0; head->slovo[i] != '\n'; i++)// с помощью цикла выводим посимвольно слово до \n
            printf("%c", head->slovo[i]);
        printf(" ");
        head = head->next_slovo;// переходим к следующему слову
    }
    printf("\n");
    return;
}
void print_ochered(ochered* ocher)//вывод всей очереди
{
    //system("cls");
    if (!ocher->first)
        printf("the queue is empty\n");//есди очередь пуста, то есть соответствующее сообщение
    text* tmp_text = ocher->first;//копирую первый элемент
    while (tmp_text)
    {
        print_spisok_ochered(tmp_text->predl);//вывод очереди по элементу
        tmp_text = tmp_text->next_predl;
    }
    return;
}
void pust_or_not_ocher(ochered* ocher)
{
    system("cls");//очистка консоли
    if (!ocher->first)
        printf("The queue is empty\n");//есди очередь пуста, то есть соответствующее сообщение
    else
        printf("The queue is not empty\n");//есди очередь не пуста, то есть соответствующее сообщение
    return;
}
void show_start_elem(ochered* ocher)
{
    system("cls");
    if (!ocher->first)
        printf("the queue is empty\n");//есди очередь пуста, то есть соответствующее сообщение
    else
        print_spisok_ochered(ocher->first->predl);//вывод очереди по элементу
    return;
}
void del_start_ochered(ochered* ocher)

{
    system("cls");
    if (!ocher->first)
    {
        printf("the queue is empty\n");//есди очередь пуста, то есть соответствующее сообщение
        return;
    }
    text* tmp_text;
    if (ocher->first == ocher->last)
    {
        tmp_text = ocher->first;//копирую первый элемент
        ocher->first = NULL;
        ocher->last = NULL;
        clear_1(tmp_text->predl);//очистка списка слов который лежит в первом элементе очереди
        free(tmp_text);//очиска узла
    }
    else
    {
        tmp_text = ocher->first;//копирую первый элемент
        ocher->first = ocher->first->next_predl;//двигаю указатель
        clear_1(tmp_text->predl);//очистка списка слов который лежит в первом элементе очереди
        free(tmp_text);//очищаю узел
    }
    return;
}
void get_elem_start_ocher(ochered* ocher)//взятие первого элемента очереди
{
    system("cls");
    if (!ocher->first)
    {
        printf("the queue is empty\n");//есди очередь пуста, то есть соответствующее сообщение
        return;
    }
    text* tmp_text;
    if (ocher->first == ocher->last)
    {
        tmp_text = ocher->first;//копирую указатель
        ocher->first = NULL;
        ocher->last = NULL;
        print_spisok_ochered(tmp_text->predl);//вывод очереди по элементу
        clear_1(tmp_text->predl);//очистка списка слов который лежит в первом элементе очереди
        free(tmp_text);//очищаю узел
    }
    else
    {
        tmp_text = ocher->first;//копирую указатель
        ocher->first = ocher->first->next_predl;
        print_spisok_ochered(tmp_text->predl);//вывод очереди по элементу
        clear_1(tmp_text->predl);//очистка списка слов который лежит в первом элементе очереди
        free(tmp_text);//очищаю узел
    }
    return;
}
void clear_ocher(ochered* ocher)// очистка очереди
{
    if (!ocher->first)
    {
        printf("the queue is empty\n"); //есди очередь пуста, то есть соответствующее сообщение
        return;
    }
    while (ocher->first)
    {
        del_start_ochered(ocher);//удаление первого элемента очереди
    }
    return;
}
void change_elem_start_ocher(ochered* ocher)// изменение первого элемента очереди
{
    if (!ocher->first)
    {
        printf("the queue is empty\n");// есди очередь пуста, то есть соответствующее сообщение
        return;
    }
    //clear_1(ocher->first->predl);
    //ocher =change_ocher(ocher);
    ocher->first->predl=menu2(ocher->first->predl);//переход в меню нижнего уровня для обработки первого элемента очереди
    return;
}
void menu(ochered*ocher,int k,int d)//меню для обработки очереди
{
    system("cls");//очистка консоли
    while (1)
    {
       // system("cls");
        int num1;
        printf("Menu\n");// пункты обработки очереди
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
            clear_ocher(ocher);//очистка всей очереди
            break;
        case 2:
            system("cls");
            pust_or_not_ocher(ocher);//проверка пуста очередь или нет
            break;
        case 3:
            system("cls");
            show_start_elem(ocher);//показ первого элемента очереди
            break;
        case 4:
            system("cls");
            del_start_ochered(ocher);//удаление первого элемента очереди
            d = d - 1;;
            break;
        case 5:
            system("cls");
            get_elem_start_ocher(ocher);//взятие элемента из начала очереди
            printf("\n");
            print_ochered(ocher);//печатаю очередь
            d--;
            break;
        case 6:
            system("cls");
            change_elem_start_ocher(ocher);//изменение первого элемента очереди
            break;
        case 7:
            d++;
            if (d > k) {
                printf("Ochered is full,you cant add element\n");//сообщение если очередь переполнена
                d--;
            }
            else
                 add_to_end(ocher);//добавление элемента в конец очереди
            break;
        case 8:
            system("cls");
            print_ochered(ocher);//печатаю очередь
            break;
        case 9:
            system("cls");
            clear_ocher(ocher);//очистка очереди и переход в main
            return;
            break;
        default:
            printf("Vvedeno ne to znach, try again!\n");//сообщение о том, что введено неправильное значение switch
        }
    }
}
int main()
{
    int st;
    while (1){
    printf("Press 1 to start ochered\n");//начало работы с очередью
    printf("Press 2 if you do not want to start ochered\n");
    scanf_s("%d", &st);
    if (st == 1) {
        ochered* ocher = create_ochered();//создание элемента очереди
            int k,d=0;
        int k_el =0;
        printf("How much elements in ochered?\n");
        scanf_s("%d", &k);//задаю размерность
        menu(ocher,k,d);//переход в меню верхнего уровня
    }
    else if (st == 2)
        exit(1);
        system("cls");
    }
    return 0;
}