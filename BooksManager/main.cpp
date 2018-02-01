#include "main.h"

//using namespace std;
int main(){

    BookList bl;                   // 图书数据结构体
    SalesData sd;                  // 会员账户数据结构体

    sd = sales_db.read_salesfile( sd );
    bl = book_db.read_bookfile( bl );

    pp::hall();
    pp::what_is_sta( bl, sd );

    return 0;
}

