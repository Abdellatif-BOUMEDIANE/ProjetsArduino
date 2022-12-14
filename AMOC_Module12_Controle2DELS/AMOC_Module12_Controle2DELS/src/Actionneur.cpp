#include "Actionneur.h"

Actionneur::Actionneur(int const& p_id, String const& p_despcription) : m_id(p_id), m_description(p_despcription)
{ 
    
}

const String& Actionneur::description()
{
    return this->m_description;
}

const int Actionneur::id()
{
    return this->m_id;
}