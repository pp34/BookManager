#include "main.h"


std::ostream & print( std::ostream &os, Book &book );

int main(){

    double price = 34.35;
    Title title{ "������¶���","�����ǡ������˹","9787544253994" };
    Book book( title , price );
    Customer customer{ "rd257", "a123456", "pp" };
    Date date{ 2018, Month::Jan };
    Loan lobj{ book, customer, date };

    lobj.display();

    return 0;
}
