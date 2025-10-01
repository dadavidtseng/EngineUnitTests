//----------------------------------------------------------------------------------------------------
// GameCommon.cpp
//----------------------------------------------------------------------------------------------------
#include "Game/GameCommon.hpp"


//----------------------------------------------------------------------------------------------------
bool IsMostlyEqual(float const a,
                   float const b,
                   float const epsilon)
{
    return
        (a >= (b - epsilon)) &&
        (a <= (b + epsilon));
}

//----------------------------------------------------------------------------------------------------
bool IsMostlyEqual(Vector2Class const& vec2,
                   float const         x,
                   float const         y)
{
    return
        IsMostlyEqual(vec2.x, x) &&
        IsMostlyEqual(vec2.y, y);
}

//----------------------------------------------------------------------------------------------------
bool IsMostlyEqual(Vector2Class const& vec2a,
                   Vector2Class const& vec2b)
{
    return
        IsMostlyEqual(vec2a.x, vec2b.x) &&
        IsMostlyEqual(vec2a.y, vec2b.y);
}

//----------------------------------------------------------------------------------------------------
bool IsMostlyEqual(AABB2Class const& box1,
                   AABB2Class const& box2)
{
    return
        IsMostlyEqual(box1.AABB2_Mins, box2.AABB2_Mins) &&
        IsMostlyEqual(box1.AABB2_Maxs, box2.AABB2_Maxs);
}

//----------------------------------------------------------------------------------------------------
bool IsMostlyEqual(AABB2Class const& box,
                   float const       minX,
                   float const       minY, float const maxX,
                   float const       maxY)
{
    return
        IsMostlyEqual(box.AABB2_Mins, minX, minY) &&
        IsMostlyEqual(box.AABB2_Maxs, maxX, maxY);
}
