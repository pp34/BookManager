#include "main.h"

int main(){
    Title title{ "《百年孤独》","加西亚·马尔克斯","9787544253994" };
    Book book{ title , 36.36 };
    Customer customer{ "rd257", "a123456", "pp" };
    Date date{ 2018, Month::Jan };
    Loan lobj{ book, customer, date };
    lobj.display();
    return 0;
}