#pragma once
#include "stdafx.h"

#ifndef _WINDOWS
#include "opengl_utils.h"
#endif

using namespace std;
using namespace OpenGLUtils;

//#define SCREENSHOT

namespace Offender {

    #define POSITION_HANDLE 0
    #define NORMAL_HANDLE   1

    #define OBJ_NUMTYPE float
    typedef sqmat<OBJ_NUMTYPE,4> ObjMat;
    typedef Triple<OBJ_NUMTYPE> ObjPos;
    typedef Vector<OBJ_NUMTYPE> ObjVec;
    typedef Quaternion<OBJ_NUMTYPE> ObjQuat;

    typedef struct ObjectVertex
    {
        GLfloat position[3];
        GLfloat normal[3];
    } ObjectVertex;

     // Forward declaration
    class World;
    class RenderGroup;
    class Mesh;

    class Object {
        private:
            World*                  m_world;
            RenderGroup*            m_rendergroup;
            ObjMat                  m_ModelMatrix;
            ObjPos                  m_Position;
            ObjVec                  m_Velocity;
            ObjQuat                 m_Orientation;
            GLboolean               m_DeathThroes;
        public:
            Object(World*, RenderGroup*, ObjPos, ObjVec, ObjQuat);
            GLboolean               Draw();
            virtual GLboolean       DrawMeshes(RenderGroup*) =0;
            virtual GLboolean       Move() =0;
            virtual void            CollisionHandler() =0;
            virtual OBJ_NUMTYPE     GetCollisionRadius() =0;
            ObjMat*                 GetModelMatrix() { return &m_ModelMatrix; };
            void                    SetModelMatrix() { m_ModelMatrix = ModelMatrix(m_Position, m_Orientation); };
            void                    SetModelMatrix(ObjMat l_matrix) { m_ModelMatrix = l_matrix; };
            World*                  GetWorld() { return m_world; };
            ObjPos                  GetPosition() { return m_Position; };
            void                    SetPosition(ObjPos l_newpos) { m_Position = l_newpos; };
            ObjVec                  GetVelocity() { return m_Velocity; };
            void                    SetVelocity(ObjVec l_newvel) { m_Velocity = l_newvel; };
            ObjQuat                 GetOrientation() { return m_Orientation; };
            void                    SetOrientation(ObjQuat l_Orientation) { m_Orientation = l_Orientation; };
            void                    ModifyOrientation(ObjQuat l_Orientation) { m_Orientation = l_Orientation * m_Orientation; };
            //void                    SetCollisionRadius(OBJ_NUMTYPE l_radius) { m_CollisionRadius = l_radius; };
            GLboolean               GetDeathThroes() { return m_DeathThroes; };
            void                    SetDeathThroes(GLboolean l_death) { m_DeathThroes = l_death; };
    };

} // namespace Offender
