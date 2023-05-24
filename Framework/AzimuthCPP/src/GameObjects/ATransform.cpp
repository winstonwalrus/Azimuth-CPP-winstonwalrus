#include "Azimuth/GameObjects/ATransform.h"

#include <glm/ext/matrix_transform.hpp>

#include <glm/glm.hpp>

#include <glm/gtc/quaternion.hpp>

#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <raylib/raylib.h>

using glm::quat;
using glm::vec3;
using glm::vec4;

ATransform*& ATransform::Parent()
{
    return m_parent;
}

void ATransform::SetParent(ATransform* _parent)
{
    if (_parent == nullptr)
    {
        if (m_parent != nullptr)
        {
            m_parent->RemoveChild(this);
        }
    }
    else
    {
        _parent->AddChild(this);
    }
}

float ATransform::Rotation() const
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(GlobalTransform(), scale, rot, trans, skew, persp);

    return glm::eulerAngles(rot).z * RAD2DEG;
}

float ATransform::LocalRotation() const
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(m_transform, scale, rot, trans, skew, persp);

    return glm::eulerAngles(rot).z * RAD2DEG;
}

void ATransform::SetRotation(const float& _newRot)
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(m_transform, scale, rot, trans, skew, persp);

    m_transform = glm::translate(mat4(1.f), trans) *
        glm::toMat4(glm::angleAxis(_newRot * DEG2RAD, vec3(0.f, 0.f, 1.f))) *
        glm::scale(mat4(1.f), scale);
}

void ATransform::UpdateRotation(const float& _amount)
{
    m_transform = m_transform * glm::toMat4(glm::angleAxis(_amount * DEG2RAD, vec3(0.f, 0.f, 1.f)));
}

void ATransform::Position(float& _x, float& _y) const
{
    const vec2 pos = Position();
    _x = pos.x;
    _y = pos.y;
}

vec2 ATransform::Position() const
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(GlobalTransform(), scale, rot, trans, skew, persp);

    return trans;
}

void ATransform::LocalPosition(float& _x, float& _y) const
{
    const vec2 pos = LocalPosition();
    _x = pos.x;
    _y = pos.y;
}

vec2 ATransform::LocalPosition() const
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(m_transform, scale, rot, trans, skew, persp);

    return trans;
}

void ATransform::SetPosition(const float& _newX, const float& _newY)
{
    SetPosition({ _newX, _newY });
}

void ATransform::SetPosition(const vec2& _newPos)
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(m_transform, scale, rot, trans, skew, persp);

    m_transform = glm::translate(mat4(1.f), vec3(_newPos, 0.f)) *
        glm::toMat4(rot) *
        glm::scale(mat4(1.f), scale);
}

void ATransform::UpdatePosition(const float& _newX, const float& _newY)
{
    UpdatePosition({ _newX, _newY });
}

void ATransform::UpdatePosition(const vec2& _newPos)
{
    m_transform = glm::translate(m_transform, vec3(_newPos, 0.f));
}

void ATransform::Scale(float& _x, float& _y) const
{
    const vec2 scale = Scale();
    _x = scale.x;
    _y = scale.y;
}

vec2 ATransform::Scale() const
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(GlobalTransform(), scale, rot, trans, skew, persp);

    return scale;
}

void ATransform::LocalScale(float& _x, float& _y) const
{
    const vec2 scale = LocalScale();
    _x = scale.x;
    _y = scale.y;
}

vec2 ATransform::LocalScale() const
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(m_transform, scale, rot, trans, skew, persp);

    return scale;
}

void ATransform::SetScale(const float& _newX, const float& _newY)
{
    SetScale({ _newX, _newY });
}

void ATransform::SetScale(const vec2& _newScale)
{
    vec3 scale;
    quat rot;
    vec3 trans;
    vec3 skew;
    vec4 persp;

    glm::decompose(m_transform, scale, rot, trans, skew, persp);

    m_transform = glm::translate(mat4(1.f), trans) *
        glm::toMat4(rot) *
        glm::scale(mat4(1.f), vec3(_newScale, 1.f));
}

void ATransform::UpdateScale(const float& _newX, const float& _newY)
{
    UpdateScale({ _newX, _newY });
}

void ATransform::UpdateScale(const vec2& _newScale)
{
    m_transform = glm::scale(m_transform, vec3(_newScale, 1.f));
}

void ATransform::TRS(const vec2& _pos, const float& _angle, const vec2& _scale)
{
    SetPosition(_pos);
    SetRotation(_angle);
    SetScale(_scale);
}

mat4 ATransform::GlobalTransform() const
{
    return m_parent != nullptr ? m_parent->m_transform * m_transform : m_transform;
}

void ATransform::AddChild(ATransform* _child)
{
    m_listUpdates.emplace_back([&, this]()
        {
            if (_child->m_parent != nullptr)
                _child->m_parent->RemoveChild(_child);

            _child->m_parent = this;
            m_children.emplace_back(_child);
        });
}

void ATransform::RemoveChild(ATransform* _child)
{
    m_listUpdates.emplace_back([&, this]()
        {
            if (_child->m_parent == this)
            {
                _child->m_parent = nullptr;

                const list<ATransform*>::iterator iter = std::ranges::find(m_children, _child);
                if (iter != m_children.end())
                    m_children.erase(iter);
            }
        });
}

void ATransform::Update()
{
    for (auto iter = m_listUpdates.begin(); iter != m_listUpdates.end(); ++iter)
        (*iter)();

    m_listUpdates.clear();

    for (auto iter = m_children.begin(); iter != m_children.end(); ++iter)
        (*iter)->Update();
}
