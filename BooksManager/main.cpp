#include "main.h"


int main(){

    Loan tmp;
    {
        double price = 34.35;
        Title title{ "《百年孤独》","加西亚·马尔克斯","9787544253994" };
        Book book(  title , price );
        Customer customer{ "pp","rd257", "a123456" };
        Date date{ 2018, Month::Febr };
        Loan lobj{ ( book ), ( customer ), ( date ) };
        Loan tmp;
        tmp = lobj;
        lobj.display();
    }
    tmp.display();
    return 0;
}
