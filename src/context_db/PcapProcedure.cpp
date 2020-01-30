#include <iostream>
#include <context_db/PcapProcedure.hpp>

PcapProcedure::PcapProcedure(void)
{
    this->procedureId = 0;
    this->procedureStatus = 0;
}

PcapProcedure::PcapProcedure(boost::uint32_t procedureId)
{
    this->procedureId = procedureId;
    this->procedureStatus = 0;
}


void PcapProcedure::print() 
{
    std::cout << "Value = (" << this->procedureId << "," 
                        << this->procedureStatus << ")" << "\n";
}
