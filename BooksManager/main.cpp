#include "main.h"

//using namespace std;
int main(){

    BookList bl;                   // ͼ�����ݽṹ��
    SalesData sd;                  // ��Ա�˻����ݽṹ��

    sd = sales_db.read_salesfile( sd );
    bl = book_db.read_bookfile( bl );

    pp::hall();
    pp::what_is_sta( bl, sd );

    return 0;
}

