#include "main.h"

using namespace std;
int main(){

    BookList bl;                   // 图书数据结构体
    SalesData sd;                  // 会员账户数据结构体
    DB test(".salesdata");
    sd = test.read_salesfile( sd );
    //bl = book_db.read_bookfile( bl );
    //sd = vip_db.read_customerfile( sd );
    //sd = loan_db.read_loanfile( sd );
    //sd = clerk_db.read_clerkfile( sd );

    //pp::hall();
    //pp::what_is_sta( bl, sd );

    return 0;
}

