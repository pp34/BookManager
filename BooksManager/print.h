#ifndef  PRINT_H
#define  PRINT_H


#include <iostream>

#ifndef _NAME_PP
#define _NAME_PP


namespace pp
{

    void hall();
    void borrow();




    void find_bookName();
    void find_isbn();

    void tips();
    void error();
    void what_is_sta();
    void get_sta( std::istream& in );
    int sta{ 0 };
    std::string page;
};


void pp::hall(){

    std::cout << "1������ͼ��" << std::endl;
    std::cout << "2���黹ͼ��" << std::endl;
    std::cout << "3������ά�����" << std::endl;
    std::cout << "4������Աά�����" << std::endl;
    std::cout << "5���뿪" << std::endl;
    pp::tips();

    pp::page = "hall";
    pp::sta = 0;
}

void pp::borrow(){
    std::cout << "1����������" << std::endl;
    std::cout << "2������ISBN" << std::endl;
    std::cout << "3������" << std::endl;
    std::cout << "5���뿪" << std::endl;
    pp::tips();

    pp::page = "borrow";
    pp::sta = 1;
}

void pp::find_bookName(){

    std::cout << "������" << std::endl;

    pp::page = "find_bookName";
    pp::sta = 0;
}
void pp::find_isbn(){

    std::cout << "ISBN��" << std::endl;

    pp::page = "find_isbn";
    pp::sta = 0;
}

void pp::what_is_sta(){
    while (1)
    {
        pp::get_sta( std::cin );
        std::cout << "\n\n";
        if ( pp::page == "hall" )
        {
            switch ( pp::sta )
            {
                case 1:pp::borrow(); break;
                case 2:break;
                case 3:break;
                case 4:break;
                case 5:exit( 0 ); break;
                default:pp::error(); break;
            }
        }
        else if( pp::page == "borrow" ){
            switch ( pp::sta )
            {
                case 1:pp::find_bookName(); break;
                case 2:pp::find_isbn(); break;
                case 3:pp::page = "hall"; pp::hall(); break;
                case 5:exit( 0 ); break;
                default:pp::error(); break;
            }
        }
        else {}
    } 
}

void pp::get_sta( std::istream& in){
    in >> pp::sta;
}

void pp::tips(){
    std::cout << "\n��ʾ���������Ž��в���: _\b";
}

void pp::error(){
    std::cout << "\n�������룺��������ȷ�ı�Ž��в���: _\b";
}

#endif
#endif


