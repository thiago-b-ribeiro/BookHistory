/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author
*/

#ifndef DATE_H
#define DATE_H

#include <chrono>
#include <string>

class cDate{
    public:
        cDate();
        ~cDate();
        void UpdateNow();
        std::chrono::year_month_day GetNow();
        std::chrono::year GetYear();
        std::chrono::month GetMonth();
        std::chrono::day GetDay();
    
    private:
        std::chrono::year_month_day m_oYearMonthDay;
};

#endif