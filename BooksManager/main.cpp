#include "main.h"


int main(){

    Loan tmp;
    {
        double price = 34.35;
        Title title{ "������¶���","�����ǡ������˹","9787544253994" };
        Book book{ title , price };
        Customer customer{ "pp","rd257", "a123456" };
        Date date{ 2018, Month::Febr };
        Loan lobj{ ( book ), ( customer ), ( date ) };
        tmp = lobj;
        //printDate( std::cout, tmp );
    }
    tmp.printDate( std::cout );
    return 0;
}

int &q( int i){ return i; }