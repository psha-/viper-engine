#include "mesh.h"
#include <vector>

Mesh::Mesh()
{
}

Mesh::Mesh(const std::string& filename)
{

    IndexedModel model = OBJModel(filename).ToIndexedModel();
    InitMesh(model);
}


Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indicies)
{
    IndexedModel model;
    addVertices(vertices, indicies, model);
    InitMesh(model);
}

void Mesh::addVertices(std::vector<Vertex> vertices, std::vector<unsigned int> indicies, IndexedModel& model)
{
    for( auto it = vertices.begin(); it != vertices.end(); it++ ) {
        model.positions.push_back(*it->getPos());
        model.texCoords.push_back(*it->getTexCoord());
        model.normals.push_back(*it->getNormal());
    }

    for( auto it = indicies.begin(); it != indicies.end(); it++)
    {
        model.indices.push_back(*it);
    }

}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArryObject);
}

void Mesh::InitMesh( const IndexedModel& model )
{
    m_drawCount = model.indices.size();

    glGenVertexArrays(1, &m_vertexArryObject);
    glBindVertexArray(m_vertexArryObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);




    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXTCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.normals.size()*sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size()*sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArryObject);

    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}
