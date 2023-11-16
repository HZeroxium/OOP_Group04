#include "cEntity.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// CONSTRUCTORS - DESTRUCTORS //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cEntity::cEntity(unsigned int uPosX, unsigned int uPosY)
{
    m_uPosX = uPosX;
    m_uPosY = uPosY;
}

cEntity::cEntity(const cEntity &entity)
{
    m_uPosX = entity.m_uPosX;
    m_uPosY = entity.m_uPosY;
}

cEntity::~cEntity() = default;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// GETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int cEntity::getPosX() const
{
    return m_uPosX;
}

unsigned int cEntity::getPosY() const
{
    return m_uPosY;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// SETTERS /////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cEntity::setPosX(unsigned int uPosX)
{
    m_uPosX = uPosX;
}

void cEntity::setPosY(unsigned int uPosY)
{
    m_uPosY = uPosY;
}