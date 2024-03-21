/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author
*/

#include "date.h"

cDate::cDate(){}

cDate::~cDate(){}

void cDate::UpdateNow(){
    m_oYearMonthDay = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
}

std::chrono::year_month_day cDate::GetNow(){
    UpdateNow();
    return(m_oYearMonthDay);
}

std::chrono::year cDate::GetYear(){
    UpdateNow();
    return(m_oYearMonthDay.year());
}

std::chrono::month cDate::GetMonth(){
    UpdateNow();
    return(m_oYearMonthDay.month());
}

std::chrono::day cDate::GetDay(){
    UpdateNow();
    return(m_oYearMonthDay.day());
}