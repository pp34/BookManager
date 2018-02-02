#ifndef  _CRLF_H
#define _CRLF_H

#include <iostream>
#include <fstream>
#include <string>

#define __WIN_DOS_FILE__    0
#define __UNIX_LINUX_FILE__ 1
#define __MAC_OS_FILE__     2

using __SYSTEM_TYPE__ = int;

__SYSTEM_TYPE__ SYSTYPE = 0;    // default windows


__SYSTEM_TYPE__ which_type_is(std::ifstream& file){

    char ctmp;
    file.seekg( 0, std::ios::end );
    auto file_end = file.tellg();
    file.seekg( 0, std::ios::beg );
    auto file_start = file.tellg();
    auto file_lenth = file_end - file_start;
    if( file.ignore( file_lenth, '\r' ).good() ){    //  ֱ��ȡһ��,����CRͣ
        ctmp = file.get();
        if( ctmp == '\n' ){
            return __WIN_DOS_FILE__;        //  CRLF: WINDOWS/DOS - Style
        }
        else{                               //  Only CR: MAC OS - Style
            return __MAC_OS_FILE__;
        }
    }
    else
    {
        file.seekg( 0, std::ios::beg );               //  ֱ��ȥ���ļ�ͷ
        if ( file.ignore( file_lenth, '\n' ).good() )     //  ֱ��ȡһ��,����CRͣ
        {
            //  ��Ϊ���жϹ�CR�������ֱ����ΪLFǰ����ַ�����CR
            return __UNIX_LINUX_FILE__;
        }
        else{
            file.clear();
            return -1;
        }
    }
    file.seekg( 0, std::ios::beg );              //  ��ԭָ��λ��
}

void getCRLF( std::ifstream& file ){
    char tmp;
    switch ( SYSTYPE )
    {
        case 0: //  CRLF MODE
            tmp = file.get();
            tmp = file.get();
            break;
        case 1: //  LF MODE
            tmp = file.get();
            break;
        case 2: //  CR MODE
            tmp = file.get();
            break;
        default://  default windows
            tmp = file.get();
            tmp = file.get();
            break;
    }
}

#endif // 
