#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
#include "obj_loader.h"
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
    public:
        Vertex(const glm::vec3& p, const glm::vec2& tc, const glm::vec3& n = glm::vec3(0,0,0)):
        pos(p),
        texCoord(tc),
        normal(n)
        {}

        const glm::vec3* const getPos() const
        {
            return &pos;
        }

        const glm::vec2* const getTexCoord() const
        {
            return &texCoord;
        }

        const glm::vec3* const getNormal() const
        {
            return &normal;
        }

    protected:
    private:
        glm::vec3 pos;
        glm::vec2 texCoord;
        glm::vec3 normal;
};

class Mesh
{
    public:
        Mesh(std::vector<Vertex> vertices);
        Mesh(const std::string& filename);
        Mesh();
        void addVertices(std::vector<Vertex> vertices, IndexedModel& model);
        void InitMesh(const IndexedModel& model);
        void Draw();
        virtual ~Mesh();
    protected:
    private:
        Mesh(const Mesh& other);
        void operator=(const Mesh& other);

        enum
        {
            POSITION_VB,
            TEXTCOORD_VB,
            NORMAL_VB,
            INDEX_VB,
            NUM_BUFFERS
        };

        GLuint m_vertexArryObject;
        GLuint m_vertexArrayBuffers[NUM_BUFFERS];
        unsigned int m_drawCount;
};

#endif // MESH_H
